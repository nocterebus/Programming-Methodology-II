/*
Justen Yeung 150005872
header file for project 1 extra credit
*/
#ifndef INITIALP_H_
#define INITIALP_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <fstream>
#include <string>
#include <chrono>
#include <random>

//create customer class
class customer{
public:
	//arrival time
	float arrival;
	//departure time
	float departure;
	//process time
	float protime;
	//time helped
	float helped;
	//wait time is time helped - arrival
	float waittime;
	//constructor
	customer();
	//specific constructor
	customer(float arri, float prtime){
		arrival = arri;
		protime = prtime;
	};

};

//create a virtual random generator
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine gen(seed);


//create an event of incomming customers at 1 minute intervals
std::vector<customer> eventpoi(float t, int interval, int customers, float arrivemean, float transpoi){
	//t is event time, interval is interval between events, customers is number of customers
	//arrivemean is poisson average of arrival times, transpoi is poisson average of transaction times
	//create a vector to hold customers
	std::vector<customer> incomming;

	//poisson number generator for arrivals
	std::poisson_distribution<int> distarrivals(arrivemean);
	//poisson number generator for processing times
	std::poisson_distribution<int> distprotimes(transpoi);

	for (int i = 0; i < customers; ++i){
		//create poisson random variable for arrival
		float arrive = distarrivals(gen);
		//create poisson random variable for transaction time
		float transactp = distprotimes(gen);
		//push back customer(incomming time, processing time for customer)
		incomming.push_back(customer(t+(arrive), transactp));
	}
	
	return incomming;
}
//create teller class (will be continaed in bank class later)
class teller{
public:
	//the begin time in which the teller services a customer
	float begin;
	//the end time in which the teller finishes servicing a customer
	float end;
	//initialize customer that the teller is helping
	customer client = customer(0,60);
	//teller constructor
	teller(customer c, float t){
		//time teller begins to help client
		begin = t;
		//time teller will be done helping client
		end = t + c.protime;
		//client is the customer
		client = c;
		//save when the client was helped just in case
		client.helped = t;
		//make note of how long the customer waited
		client.waittime = t - c.arrival;
		//make note of when the customer left
		client.departure = end;
	}
};

//the queue and tellers will be contained in the bank
class bank{
public:
	//number of tellers
	int tells = 1;
	//queue of tellers (will be used to tell how many tellers are available)
	std::queue<teller> resources;
	//the line at the bank
	std::queue<customer> line;
	//make a record of all customers that went to the bank
	std::vector<customer> business;

	//bank constructor
	bank(int T){
		tells = T;
	}
	//bank functions
	//complete processing customers (t = current time)
	void complete(int t){
		//check if there are any tellers helping anyone
		if (!resources.empty()){
			//first complete processing clients that are currently being helped
			while (resources.front().end == t){
				//save processed client statistics
				business.push_back(resources.front().client);
				//send off client and make a teller available
				resources.pop();
			}
		}
	}
	//process customers
	void process(int t){
		//process any customers who have arrived with available resources
		if (!line.empty()){
			while (line.front().arrival <= t and resources.size() < tells){
				//help first person on line
				resources.push(teller(line.front(),t));
				//remove first person on line from queue
				line.pop();
			}
		}
	}
	//average wait time
	float average(){
		//sum of wait times
		float sum = 0;
		for (int i = 0; i < business.size(); ++i){
			sum = sum + (business[i]).waittime;
		}
		//divide sum by total number of people
		sum = sum/(business.size());
		//return average
		return sum;
	}
	//vector to hold events, time event occured, and length of transaction
	std::vector<std::string> eventtype;
	std::vector<float> eventtime;
	std::vector<float> eventtrans;
	//simulator and event logger
	void sim(){
		//clock timer will iterate by event sub time unit
		int timer = 0;
		//line size
		int lines = line.size();
		//tellers occupied
		int resc = 0;
		//mock queue just to keep track of arrivals
		std::queue<customer> arrives = line;
		while (line.size() != 0 or resources.size() != 0){
			//ensure that the customers leave in the correct order by correcting resources queue order
			if (resources.size()>1){
				//make a vector to sort resources
				std::vector<teller> sorter;
				//make a copy of resources
				std::queue<teller> copy = resources;
				//push values in copy to sorter to sort and the selelct sort
				while (!copy.empty()){
					sorter.push_back(copy.front());
					copy.pop();
				}
				//select sort sorter
				for (int i = sorter.size()-1; i >= 0; --i){
					//make variable save latest customer, initialized at first one
					teller latest = sorter[0];
					//save latest teller original position
					int place = 0;
					//find latest teller
					for (int j = 0; j <= i; ++j){
						if (sorter[j].end > latest.end){
							latest = sorter[j];
							place = j;
						}
					}
					//put later customers toward back
					sorter[place] = sorter[i];
					sorter[i] = latest;
				}
				//put sorted vector back into copy in correct order
				for (int i = 0; i < sorter.size(); ++i){
					copy.push(sorter[i]);
				}
				//set resources to correct order
				resources = copy;
			}
			//first complete existing trasactions between tellers and clients
			complete(timer);
			//detect changes in amount of tellers occupied (indicates departures)
			if (resources.size() < resc){
				//check how many customers departed
				int departed = resc - resources.size();
				//log events
				for(int p = 0; p < departed; ++p){
					eventtype.push_back("d");
					eventtime.push_back(timer);
					eventtrans.push_back(0);
				}
			}
			//update how many tellers are occupied
			resc = resources.size();
			//track arrivals on the spot
			while (arrives.front().arrival == timer){
				eventtype.push_back("a");
				eventtime.push_back(timer);
				eventtrans.push_back(arrives.front().protime);
				arrives.pop();
			}
			//attend to first customer on line when teller is available
			process(timer);
			//update how many tellers are occupied
			resc = resources.size();
			//increment timer
			++timer;
		}
	}

};

//data file outwriters
//outwrites data about customers that came in
void outwritec (bank b,std::string file){
		//create output file
	std::ofstream outdata ("customers_with_"+file);
	//check if output file is open to input sorted array
	if (outdata.is_open()){
		//write each element of the array to a line
		for (int i = 0; i < b.business.size(); ++i){
			outdata<<"customer "<<i+1<<" arrived at "<<((b.business[i]).arrival)/60<<" minutes, 	waited for "<<((b.business[i]).waittime)/60<<" minutes, 	and departed at "<<((b.business[i]).departure)/60<<" minutes.\n";
		}
		//close the text file
		outdata.close();
	}
	//else the output file could not be created. inform user and terminate program
	else{
		std::cout<<"Unable to create customers_with_"<<file<<"\n";
	}
}
//outwrites data about events in time
void outwritev (bank b,std::string file){
		//create output file
	std::ofstream outdata ("events_with_"+file);
	//check if output file is open to input sorted array
	if (outdata.is_open()){
		outdata<<"a is for arrival, d is for departure, condition is the processing time.\n units of time: seconds for cleanliness\ntype	time	condition\n";
		//write each element of the array to a line
		for (int i = 0; i < b.eventtime.size(); ++i){
			outdata<<(b.eventtype)[i]<<"		"<<((b.eventtime)[i])<<"		"<<((b.eventtrans)[i])<<"\n";
		}
		//close the text file
		outdata.close();
	}
	//else the output file could not be created. inform user and terminate program
	else{
		std::cout<<"Unable to create events_with_"<<file<<"\n";
	}
}

#endif