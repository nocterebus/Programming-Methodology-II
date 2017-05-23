/*
Justen Yeung 150005872
Homework 1
Probelm 1
	Chapter 1 Excercize 2b

load instructions on windows
navigate to the file containing this program in the command prompt window
g++ -std=c++11 advancedate.cpp -o a
*/

#include <iostream>

//class Date
class Date {
//class Date's publicly accessable elements
public:
	//month represented by an integer
	int month;
	//day represented by an integer
	int day;
	//year represented by an integer
	int year;

	//class constructor
	Date (int m, int d, int y) {
		month = m;
		day = d;
		year = y;
	};
	//function to advance date
	Date adv() {
		//advance by 1 day
		++day;
		//check if the month is feburary
		if(month == 2) {
			//check if it is a leap year
			if (year%4 == 0){
				//check if the given day was the last day of the month
				if (day >29) {
					//day was the last day so set day to 1
					day = 1;
					//advance month
					++month;
				}
			}
			//if the month is not a leap year from years 0 - 4000
			if (day >28){
				//if the given day was the last day of the month set day to 1
				day = 1;
				//advance month
				++month;
			}
		}
		//check if the month is one with 30 days
		else if (month == 4 or month == 6 or month == 9 or month == 11) {
			//check if the day was the last day of the month
			if (day >30) {
				//day was the last day so set day to 1
				day = 1;
				//advance the month
				++month;
			}
		}
		//any other month has 31 days
		else {
			//check if the day was the last day of the month
			if (day > 31) {
				//check if it is december
				if (month == 12) {
					//new year
					day = 1;
					month = 1;
					++year;
				}
				//if the month was not december
				else {
					//set the day back to 1
					day = 1;
					//advance month
					++month;
				}
			}
		}
	};
};





//The main program

int main(int argc, char** argv){
	//create variables to hold date inputs from the user
	int y,m,d;

	//ask for the user to input a year
	std::cout << "Please enter a year: \n";
	//if the user enters an integer
	if(std::cin >> y){
		//check to make sure the integer can actually be a year
		if (y < 0){
			//if they don't enter a legitimate year, punish by making them restart the program.
			std::cout << "That year does not exist. Please restart the program.\n";
			//end the program
			return 0;
		}
	}
	//If the user did not input an integer
	else {
		//invalid input
		std::cout << "That year does not exist. Please restart the program.\n";
		//end the program
		return 0;
	}

	//ask for the user to input a month
	std::cout << "Please enter an integer valued 1 to 12 for a month where 1 stands for January and 12 for December respectively: \n";
	//if the user enters an integer
	if(std::cin >> m){
		//check to make sure the integer actually corresponds to a month
		if (m < 1 or m > 12){
			//invalid month
			std::cout << "That month does not exist. Please restart the program.\n";
			//end the program
			return 0;
		}
	}
	//If the user did not input an integer
	else {
		//invalid input
		std::cout << "That month does not exist. Please restart the program.\n";
		//end the program
		return 0;
	}

	//ask for the user to input a day
	std::cout << "Please enter an appropriate integer valued 1 to 31 for day for in month: \n";
	//if the user enters an integer
	if(std::cin >> d){
		//no months have more than 31 days
		if (d < 1 or d > 31){
			//invalid day
			std::cout << "That day does not exist. Please restart the program.\n";
			//end the program
			return 0;
		}	
		//check to make sure the integer actually corresponds to a month
		//check if the year is a leap year
		if (y%4 ==0) {
			//if the month is february
			if (m == 2){
				//check if the day is valid
				if (d < 1 or d > 29){
				//invalid day
				std::cout << "That day does not exist. Please restart the program.\n";
				//end the program
				return 0;
				}
			}
		}
		//check if the month is february in a normal year
		if (m == 2){
				//check if the day is valid
				if (d < 1 or d > 28){
				//invalid day
				std::cout << "That day does not exist. Please restart the program.\n";
				//end the program
				return 0;
				}
		}
		//check if the month has 30 days
		if (m == 4 or m == 6 or m == 9 or m == 11){
				if (d < 1 or d > 30){
				//invalid day
				std::cout << "That day does not exist. Please restart the program.\n";
				//end the program
				return 0;
			}
		}
	}
	//If the user did not input an integer
	else {
		//invalid input
		std::cout << "That day does not exist. Please restart the program.\n";
		//end the program
		return 0;
	}
	//all given inputs were valid
	//create a date of class Date
	Date date(m,d,y);
	//advance date by 1 day
	date.adv();
	//print the result
	std::cout << "Month "<< date.month <<", Day "<< date.day <<", year " << date.year<<"\n";
	//exit the program
	return 0;
}
