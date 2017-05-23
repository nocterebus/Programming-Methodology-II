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
#include "datadus-2.h"
#include "datadus-4.h"
#include "datadus-6.h"
#include "datadus-8.h"
#include "datadus-10.h"
#include "datadus-12.h"
#include "datadus-16.h"
//#include "datadus-20.h"
//#include "datadus-24.h"

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
	long int sc2 = 0;
	long int sm2 = 0;
	long int sc4 = 0;
	long int sm4 = 0;
	long int sc6 = 0;
	long int sm6 = 0;
	long int sc8 = 0;
	long int sm8 = 0;
	long int sc10 = 0;
	long int sm10 = 0;
	long int sc12 = 0;
	long int sm12 = 0;
	long int sc16 = 0;
	long int sm16 = 0;
	long int sc20 = 0;
	long int sm20 = 0;
	long int sc24 = 0;
	long int sm24 = 0;
	
//function to print out runtimes for user
void results(){

	std::cout<<"Runtimes:\n";
	
	if (c2 != 0){
		std::cout<<"dus-2 had	 "<<c2<<" comparisons and 		"<<m2<<" moves.\n";
		std::cout<<"sorteddus-2 had	 "<<sc2<<" comparisons and 		"<<sm2<<" moves.\n\n";
	}
	if (c4 != 0){
		std::cout<<"dus-4 had	 "<<c4<<" comparisons and 		"<<m4<<" moves.\n";
		std::cout<<"sorteddus-4 had	 "<<sc4<<" comparisons and 		"<<sm4<<" moves.\n\n";
	}
	if (c6 != 0){
		std::cout<<"dus-6 had	 "<<c6<<" comparisons and 		"<<m6<<" moves.\n";
		std::cout<<"sorteddus-6 had	 "<<sc6<<" comparisons and 		"<<sm6<<" moves.\n\n";
	}
	if (c8 != 0){
		std::cout<<"dus-8 had	 "<<c8<<" comparisons and 		"<<m8<<" moves.\n";
		std::cout<<"sorteddus-8 had	 "<<sc8<<" comparisons and 		"<<sm8<<" moves.\n\n";
	}
	if (c10 != 0){
		std::cout<<"dus-10 had	 "<<c10<<" comparisons and 	"<<m10<<" moves.\n";
		std::cout<<"sorteddus-10 had "<<sc10<<" comparisons and 	"<<sm10<<" moves.\n\n";
	}
	if (c12 != 0){
		std::cout<<"dus-12 had	 "<<c12<<" comparisons and 	"<<m12<<" moves.\n";
		std::cout<<"sorteddus-12 had "<<sc12<<" comparisons and 	"<<sm12<<" moves.\n\n";
	}
	if (c16 != 0){
		std::cout<<"dus-16 had	 "<<c16<<" comparisons and 	"<<m16<<" moves.\n";
		std::cout<<"sorteddus-16 had "<<sc16<<" comparisons and 	"<<sm16<<" moves.\n\n";
	}
	if (c20 != 0){
		std::cout<<"dus-20 had	 "<<c20<<" comparisons and 		"<<m20<<" moves.\n";
		std::cout<<"sorteddus-20 had "<<sc20<<" comparisons and 	"<<sm20<<" moves.\n\n";
	}
	if (c24 !=0){
		std::cout<<"dus-24 had	 "<<c24<<" comparisons and 		"<<m24<<" moves.\n";
		std::cout<<"sorteddus-24 had "<<sc24<<" comparisons and 	"<<sm24<<" moves.\n";
	}
}
#endif
