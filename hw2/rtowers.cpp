/*
Justen Yeung 150005872
Hw2 Towers of Hanoi (recursive)

1. Implement a recursive solution to the Towers of Hanoi using the pseudo-code 
	discussed in class.  It should be written to calculate the number of "moves"  
	for an arbitrary value of N, where N is the number of disc. How many 
	moves are made for N=10?  Plot the number of moves as a function of N, for 
	as many N as your computer/implementation will allow. 

2. Using the pseduo-code, trace the recursive calls for N = 4. 

3. Implement an iterative solution to the Towers of Hanoi. 

4. Compare the timings of your iterative and recursive implementations, as  a 
function of N. Discuss your answer. 
*/

#include <iostream>
#include <string>
#include <ctime>

//Begin with 0 moves
long int move = 0;
//Create a function that will implement a recursive solution to Towers of Hanoi
	//using the pseudo-code discussed in class.
void rtowers(int count, std::string source, std::string destination, std::string spare){
	//To help with tracing, inform the user how the function is being called for problem 2.
		//If not tracing, the line directly below shall be commented out
	//std::cout<<"rtowers("<<count<<","<<source<<","<<destination<<","<<spare<<")\n";
	//Check if the disk on the pole can be moved (or move the top disk).
	if (count ==1){
		//The number of moves performed will be iterated by 1 each time the base case is fulfilled.
		move = ++move;
	}
	//else the disk cannot neccessarily be moved yet and recall the function.
	else{
		rtowers(count - 1, source, spare, destination);
		rtowers(1, source, destination, spare);
		rtowers(count - 1, spare, destination, source);
	}
}
int main (int argc, char** argv){
	//create strings to label the towers
	//source tower
	std::string sourcetower = "a";
	//destination tower
	std::string destinationtower = "b";
	//spare tower
	std::string sparetower = "c";
	//create and initialize a variable to hold the user's input of number of disks
	int N = 0;

	//Ask the user to input how many disks there will be in the problem
	std::cout << "Enter how many disks there will be in the Towers of Hanoi please (e.g. 4):";
	//Save the user's input into disks
	std::cin >> N;
	//execute recursive function
	rtowers(N, sourcetower, destinationtower, sparetower);
	//output the number of moves
	std::cout<<"The number of moves was: "<<move<<"\n";
	//Terminate the program
	return 0;
}
