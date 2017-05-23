#include "initial.h"




int main(int argc, char** argv){

	std::vector<std::string> test = make ("dus-2.txt");
	outwrite(test, "dus-2.h");
	
	test = make ("dus-4.txt");
	outwrite(test, "dus-4.h");

	test = make ("dus-6.txt");
	outwrite(test, "dus-6.h");

	test = make ("dus-8.txt");
	outwrite(test, "dus-8.h");

	test = make ("dus-10.txt");
	outwrite(test, "dus-10.h");

	test = make ("dus-12.txt");
	outwrite(test, "dus-12.h");

	test = make ("dus-16.txt");
	outwrite(test, "dus-16.h");

	test = make ("dus-20.txt");
	outwrite(test, "dus-20.h");

	test = make ("dus-24.txt");
	outwrite(test, "dus-24.h");

	return 0;
}