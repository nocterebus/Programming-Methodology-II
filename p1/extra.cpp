

/*
Justen Yeung 150005872
Programingmethodology

Extra Credit
the program will automatically perform parts 1 2 and 3 (1,2,10 tellers)
for the same incomming times of customerss. The customer arrival times and process times are 
randomly generated with a poisson generator
*/ 

//header file
#include "initialp.h"

int main (int argc, char** argv){
	//create queue of customers
	std::queue<customer> cust;
	//vector to help customers come in order
	std::vector<customer> sorter;
	//customers per minute
	//ask how many customers a minute
	std::cout<<"input an integer of how many customers a minute: ";
	int custs = 10;
	std::cin>>custs;
	//times between events (seconds a minute)
	int inter = 60;
	//mean arrival time for customers a minute
	//ask what the average time in a minute that a customer comes in
	std::cout<<"input the poisson mean time a minute that customers come in in seconds\n i.e. 30 is the 30 second mark. values greater than 60 will be modulod: ";
	float cmin = 30;
	std::cin>>cmin;
	while (cmin >= 60){
		cmin = cmin - 60;
	}
	//mean processing time for customers (minutes)
	//ask what the average processing time for a customer is 
	std::cout<<"input the poisson mean time of minutes that a customer takes to be processed in seconds\n i.e. '150' is 150 seconds: ";
	float ptime = 5;
	std::cin>>ptime;

	//fill simulation with 10 1 minute events
	for (int i = 0; i < 10; ++i){
		//custs customers per event, randomly distributed within the event
		std::vector<customer> incomming = eventpoi(i*inter, inter, custs, cmin, ptime);
		for (int j = 0; j < custs; ++j){
			sorter.push_back(incomming[j]);
		}
	}
	//select sort incomming so that customers come in order
	for (int i = sorter.size()-1; i >= 0; --i){
		//make variable save latest customer, initialized at first one
		customer latest = sorter[0];
		//save latest customer original position
		int place = 0;
		//find latest customer
		for (int j = 0; j <= i; ++j){
			if (sorter[j].arrival > latest.arrival){
				latest = sorter[j];
				place = j;
			}
		}
		//put later customers toward back
		sorter[place] = sorter[i];
		sorter[i] = latest;
	}
	//copy sorted customers into queue
	for (int i = 0; i < sorter.size(); ++i){
		cust.push(sorter[i]);
	}

	//create banks with different number of tellers
	bank bank1(1);
	bank bank2(2);
	bank bank10(10);
	//put queue in the banks (all banks will have the same queue)
	bank1.line = cust;
	bank2.line = cust;
	bank10.line = cust;

	//initialize timers for the 3 separate cases
	int timer1 = 0;
	int timer2 = 0;
	int timer10 = 0;

	//bank with 1 teller
	bank1.sim();
	//bank wit h2 tellers\
	std::cout<<"bank2 line size : "<<bank2.line.size()<<"\n";
	bank2.sim();
	// //bank with 10 tellers
	bank10.sim();

	//average wait time in each case
	//bank1
	float wait1 = bank1.average();
	// //bank2
	float wait2 = bank2.average();
	// //bank10
	float wait10 = bank10.average();

	std::cout<<"average time of wait for 1 tellers is : "<<wait1<<" seconds ("<<wait1/60<<" minutes)\n";
	std::cout<<"average time of wait for 2 tellers is : "<<wait2<<" seconds ("<<wait2/60<<" minutes)\n";
	std::cout<<"average time of wait for 10 tellers is : "<<wait10<<" seconds ("<<wait10/60<<" minutes)\n";

	outwritec(bank1,"1_teller_poisson.txt");
	outwritec(bank2,"2_tellers_poisson.txt");
	outwritec(bank10,"10_tellers_poisson.txt");

	outwritev(bank1,"1_teller_poisson.txt");
	outwritev(bank2,"2_tellers_poisson.txt");
	outwritev(bank10,"10_tellers_poisson.txt");

	return 0;
}












