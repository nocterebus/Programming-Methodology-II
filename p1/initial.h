/*
Justen Yeung 150005872
header file for project 1 bank.cpp
*/
#ifndef INITIAL_H_
#define INITIAL_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <fstream>
#include <string>
#include <chrono>

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

//create an event of incomming customers at 1 minute intervals
std::vector<customer> event(float t, int interval, int customers,float prtime){
	//t is event time, interval is interval between events, customers is number of customers
	//prtime is time to process customer (will either be a constant or a poisson)
	//create a vector to hold customers
	std::vector<customer> incomming;
	for (int i = 0; i < customers; ++i){
		//push back customer(incomming time, processing time for customer)
		incomming.push_back(customer(t+((rand()%rand()) % interval), prtime));
	}
	//select sort incomming so that customers come in order
	for (int i = customers-1; i >= 0; --i){
		//make variable save latest customer, initialized at first one
		customer latest = incomming[0];
		//save latest customer original position
		int place = 0;
		//find latest customer
		for (int j = 0; j <= i; ++j){
			if (incomming[j].arrival > latest.arrival){
				latest = incomming[j];
				place = j;
			}
		}
		//put later customers toward back
		incomming[place] = incomming[i];
		incomming[i] = latest;
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
		outdata<<"a is for arrival, d is for departure, condition is processing time.\n units of time: seconds for cleanliness\ntype	time	condition\n";
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