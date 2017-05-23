

/*
Justen Yeung 150005872
Programingmethodology

Problem iv
the program will automatically perform parts 1 2 and 3 (1,2,10 tellers)
for the same incomming times of customerss. The incomming times were generated using rand()
*/ 

//header file
#include "initial.h"

int main (int argc, char** argv){
	//create queue of customers
	std::queue<customer> cust;
	//customers per minute
	int custs = 10;
	//time between events (here its seconds in a minute)
	int inter = 60;
	//processing time for customers (seconds)
	int ptime = 60;

	//fill simulation with 10 1 minute events
	for (int i = 0; i < 10; ++i){
		//10 customers per event, randomly distributed within the event
		std::vector<customer> incomming = event(i*inter, inter, custs, ptime);
		for (int j = 0; j < 10; ++j){
			cust.push(incomming[j]);
		}
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
	//bank wit h2 tellers
	bank2.sim();
	//bank with 10 tellers
	bank10.sim();

	//average wait time in each case
	//bank1
	float wait1 = bank1.average();
	//bank2
	float wait2 = bank2.average();
	//bank10
	float wait10 = bank10.average();

	std::cout<<"average time of wait for 1 tellers is : "<<wait1<<" seconds ("<<wait1/60<<" minutes)\n";
	std::cout<<"average time of wait for 2 tellers is : "<<wait2<<" seconds ("<<wait2/60<<" minutes)\n";
	std::cout<<"average time of wait for 10 tellers is : "<<wait10<<" seconds ("<<wait10/60<<" minutes)\n";

	outwritec(bank1,"1_teller.txt");
	outwritec(bank2,"2_tellers.txt");
	outwritec(bank10,"10_tellers.txt");

	outwritev(bank1,"1_teller.txt");
	outwritev(bank2,"2_tellers.txt");
	outwritev(bank10,"10_tellers.txt");

	return 0;
}












