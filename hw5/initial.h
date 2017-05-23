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
std::vector<int> make (std::string file){
	//open the data file
	std::ifstream data (file);
	//create a vector to hold the data
	std::vector<int> unsorted;
	//create a variable to hold the integer on a line read from the data file
	std::string line;
	//check if dus-2.txt has been opened
	if (data.is_open()){
		//data file has been opened.
		//while there are lines to be read, place each number in the order given into the array
		while (getline (data,line)){
			//place number into the array
			unsorted.push_back(std::stoi(line));
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
void outwrite (std::vector<int> sorteddata, std::string file){
	//create output file
	std::ofstream outdata ("sorted"+file);
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
	long int c2 = 0;
	long int m2 = 0;
	long int c4 = 0;
	long int m4 = 0;
	long int c6 = 0;
	long int m6 = 0;
	long int c8 = 0;
	long int m8 = 0;
	long int c10 = 0;
	long int m10 = 0;
	long int c12 = 0;
	long int m12 = 0;
	long int c16 = 0;
	long int m16 = 0;
	long int c20 = 0;
	long int m20 = 0;
	long int c24 = 0;
	long int m24 = 0;
//initialize compare counters and move counters for sorted data
	long int hc2 = 0;
	long int hm2 = 0;
	long int hc4 = 0;
	long int hm4 = 0;
	long int hc6 = 0;
	long int hm6 = 0;
	long int hc8 = 0;
	long int hm8 = 0;
	long int hc10 = 0;
	long int hm10 = 0;
	long int hc12 = 0;
	long int hm12 = 0;
	long int hc16 = 0;
	long int hm16 = 0;
	long int hc20 = 0;
	long int hm20 = 0;
	long int hc24 = 0;
	long int hm24 = 0;
	
void results(){

	std::cout<<"Runtimes:\n";
	
	if (c2 != 0){
		std::cout<<"heaping dus-2 needed	 "<<c2<<" comparisons and 		"<<m2<<" moves.\n";
		std::cout<<"heaped dus-2 had	 "<<hc2<<" comparisons and 		"<<hm2<<" moves.\n\n";
	}
	if (c4 != 0){
		std::cout<<"heaping dus-4 needed	 "<<c4<<" comparisons and 		"<<m4<<" moves.\n";
		std::cout<<"heaped dus-4 had	 "<<hc4<<" comparisons and 		"<<hm4<<" moves.\n\n";
	}
	if (c6 != 0){
		std::cout<<"heaping dus-6 needed	 "<<c6<<" comparisons and 		"<<m6<<" moves.\n";
		std::cout<<"heaped dus-6 had	 "<<hc6<<" comparisons and 		"<<hm6<<" moves.\n\n";
	}
	if (c8 != 0){
		std::cout<<"heaping dus-8 needed	 "<<c8<<" comparisons and 		"<<m8<<" moves.\n";
		std::cout<<"heaped dus-8 had	 "<<hc8<<" comparisons and 		"<<hm8<<" moves.\n\n";
	}
	if (c10 != 0){
		std::cout<<"heaping dus-10 needed	 "<<c10<<" comparisons and 		"<<m10<<" moves.\n";
		std::cout<<"heaped dus-10 had 	"<<hc10<<" comparisons and 		"<<hm10<<" moves.\n\n";
	}
	if (c12 != 0){
		std::cout<<"heaping dus-12 needed	 "<<c12<<" comparisons and 		"<<m12<<" moves.\n";
		std::cout<<"heaped dus-12 had 	"<<hc12<<" comparisons and 		"<<hm12<<" moves.\n\n";
	}
	if (c16 != 0){
		std::cout<<"heaping dus-16 needed	 "<<c16<<" comparisons and 	"<<m16<<" moves.\n";
		std::cout<<"heaped dus-16 had 	"<<hc16<<" comparisons and 	"<<hm16<<" moves.\n\n";
	}
	if (c20 != 0){
		std::cout<<"heaping dus-20 needed	 "<<c20<<" comparisons and 	"<<m20<<" moves.\n";
		std::cout<<"heaped dus-20 had "<<hc20<<" comparisons and 	"<<hm20<<" moves.\n\n";
	}
	if (c24 !=0){
		std::cout<<"heaping dus-24 needed	 "<<c24<<" comparisons and 	"<<m24<<" moves.\n";
		std::cout<<"heaped dus-24 had "<<hc24<<" comparisons and 	"<<hm24<<" moves.\n";
	}
}
#endif
