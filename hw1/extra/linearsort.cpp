#include "hw1-data.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <array>

int main(int argc, char** argv){
	//create a variable to hold the integer on a line read from the data file
	std::string line;
	//open the data file
//std::ifstream data ("hw1-data.txt");
	//create an array to hold the data
	std::vector<int> Array;// = derta;
	//check if the data file has been opened
/*	if (data.is_open()){
		//the data file has been opened. Create a variable to help place the data in the order it was given
		//while there are lines of data to be read, place each number in the given order into the array
		while (getline (data,line)){
			//place the number into the array
			Array.push_back(std::stoi(line));	
		}
	//close the data file
	data.close();
	std::cout <<Array.size()<<"file closed\n";
	}
	//if the data file could not be opened, inform the user and terminate program
	else {
		std::cout<<"unable to open file\n";
		//terminate program
		return 0;
	}
*/
	for (int i = 0; i < derta.size(); ++i){
		Array.push_back(derta[i]);
	}
	int k = 0;
	int l = 0;
	for (int i = 0; i < Array.size(); ++i){
		for (int j = i; j < Array.size(); ++j){
			if (Array[j] < k){
				k = Array[j];
			}
			if (Array[j]<Array[i]){
				k = Array[j];
				l = Array[i];
				Array[i] = k;
				Array[j] = l;
			}
		}
	}
	for (int i = 0; i < Array.size(); ++i){
		std::cout<<Array[i]<<"\n";
	}

	std::cout<<Array.size()<<"\n";
	std::cout<<"The 42nd smallest number is "<<Array[41]<<"\n";


	//terminate program
	return 0;
}