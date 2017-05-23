/*
Justen Yeung 150005872
This header file provides a txt file reader and txt file writer for Hw3
*/ 

#ifndef INITIAL_H_
#define INITIAL_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//read data from file
std::vector<std::string> make (std::string file){
	//open the data file
	std::ifstream data (file);
	//create a vector to hold the data
	std::vector<std::string> unsorted;
	//create a variable to hold the integer on a line read from the data file
	std::string line;
	//check if dus-2.txt has been opened
	if (data.is_open()){
		//data file has been opened.
		//while there are lines to be read, place each number in the order given into the array
		while (getline (data,line)){
			//place number into the array
			unsorted.push_back(line + ",");
		}
		//close data file
		data.close();
	}
	//if data file could not be opened, inform the user
	else {
		std::cout<<"unable to open "<<file<<"\n";
	}
	//return the vector
	return unsorted;
}

//output arrays to a file
void outwrite (std::vector<std::string> sorteddata, std::string file){
	//create output file
	std::ofstream outdata ("data"+file);
	//check if output file is open to input sorted array
	if (outdata.is_open()){
		//write each element of the array to a line
		for (int i = 0; i < sorteddata.size(); ++i){
			outdata<<sorteddata[i]<<"\n";
		}
		//close the text file
		outdata.close();
	}
	//else the output file could not be created. inform user and terminate program
	else{
		std::cout<<"Unable to create sorted"<<file<<"\n";
	}
}

//initialize compare counters and move counters for unsorted data
	int c2 = 0;
	int m2 = 0;
	int c4 = 0;
	int m4 = 0;
	int c6 = 0;
	int m6 = 0;
	int c8 = 0;
	int m8 = 0;
	int c10 = 0;
	int m10 = 0;
	int c12 = 0;
	int m12 = 0;
	int c16 = 0;
	int m16 = 0;
	int c20 = 0;
	int m20 = 0;
	int c24 = 0;
	int m24 = 0;
//initialize compare counters and move counters for sorted data
	int sc2 = 0;
	int sm2 = 0;
	int sc4 = 0;
	int sm4 = 0;
	int sc6 = 0;
	int sm6 = 0;
	int sc8 = 0;
	int sm8 = 0;
	int sc10 = 0;
	int sm10 = 0;
	int sc12 = 0;
	int sm12 = 0;
	int sc16 = 0;
	int sm16 = 0;
	int sc20 = 0;
	int sm20 = 0;
	int sc24 = 0;
	int sm24 = 0;
	
//function to print out runtimes for user
void results(){

	std::cout<<"Runtimes:\n";
	std::cout<<"dus-2 had	 "<<c2<<" comparisons and 		"<<m2<<" moves.\n";
	std::cout<<"sorteddus-2 had	 "<<sc2<<" comparisons and 		"<<sm2<<" moves.\n";
	std::cout<<"dus-4 had	 "<<c4<<" comparisons and 		"<<m4<<" moves.\n";
	std::cout<<"sorteddus-4 had	 "<<sc4<<" comparisons and 		"<<sm4<<" moves.\n";
	std::cout<<"dus-6 had	 "<<c6<<" comparisons and 		"<<m6<<" moves.\n";
	std::cout<<"sorteddus-6 had	 "<<sc6<<" comparisons and 		"<<sm6<<" moves.\n";
	std::cout<<"dus-8 had	 "<<c8<<" comparisons and 		"<<m8<<" moves.\n";
	std::cout<<"sorteddus-8 had	 "<<sc8<<" comparisons and 		"<<sm8<<" moves.\n";
	std::cout<<"dus-10 had	 "<<c10<<" comparisons and 			"<<m10<<" moves.\n";
	std::cout<<"sorteddus-10 had "<<sc10<<" comparisons and 	"<<sm10<<" moves.\n";
	std::cout<<"dus-12 had	 "<<c12<<" comparisons and 			"<<m12<<" moves.\n";
	std::cout<<"sorteddus-12 had "<<sc12<<" comparisons and 	"<<sm12<<" moves.\n";
	std::cout<<"dus-16 had	 "<<c16<<" comparisons and 			"<<m16<<" moves.\n";
	std::cout<<"sorteddus-16 had "<<sc16<<" comparisons and 	"<<sm16<<" moves.\n";
	std::cout<<"dus-20 had	 "<<c20<<" comparisons and 			"<<m20<<" moves.\n";
	std::cout<<"sorteddus-20 had "<<sc20<<" comparisons and 	"<<sm20<<" moves.\n";
	std::cout<<"dus-24 had	 "<<c24<<" comparisons and 			"<<m24<<" moves.\n";
	std::cout<<"sorteddus-24 had "<<sc24<<" comparisons and 	"<<sm24<<" moves.\n";
}
#endif
