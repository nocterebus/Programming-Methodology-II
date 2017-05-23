/*
Justen Yeung 150005872
Homework 1
Probelm 1
	Implement the algorithm kSmall for two methods for chosing the pivot: 
(i) Use the first value of the array as the pivot, 
(ii) Use the value that is at the "middle index value" 
	of the array as the pivot (you will need to define 
	the "middle index value" carefully). Run your 
	algorithm on the data set provided here (and available under resources). 
	Show the value of the pivot at each recursive call when finding the 42nd smallest number.


load instructions
navigate to the file containing this program in the command prompt window
g++ -std=c++11 ./ksmall.cpp
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <array>

//vector will be partitioned setting all numbers less than pivot value to the left of the pivot index, 
	//and all numbers larger to the right of the pivot index.
//version where pvalue is first element value

int ksmalli(int k, std::vector<int> arrray, int begin, int end){
	//set p index to first element
	int p = begin;
	std::cout<<"pivot value "<<arrray[p]<<"\n";
	//create a switch index
	int s = end;
	int e = end;
	//create variables to assist with switching p to s for partitioning
	int val1;
	int val2;
	//while iterating through the vector, if there is a number greater than the pivot, push it to the
	//back of the vector and move the swap index back one. Almost like inverted quicksort
	for (int i = begin+1; i < end; ++i){
		for(int t = i; t <= s; ++t){
			if (arrray[i] >= arrray[p]){
				arrray.push_back(arrray[i]);
				//erase pushed element
				arrray.erase(arrray.begin()+i);
				--s;
			}
		}
	}
	//swap values at swap and pivot and move pivot to swap
	val1 = arrray[p];
	val2 = arrray[s-1];
	arrray[p] = val2;
	arrray[s-1] = val1;
	p = s-1;
	//if k = pivot index
	if (k == p){
		return arrray[p];
	}
	//if k < pivot index go to array to left of pivot index
	else if (k < p){
		return ksmalli(k, arrray, begin, p-1);
	}
	//if k > pivot index go to array to right of pivot index
	else if (k > p){
		return ksmalli(k, arrray, p+1, end);
	}
}		
//attempting to generate the 42nd number using the middle index as the pivot and this method
//generates a segmentation fault.
// int ksmallii(int k, std::vector<int> arrray, int begin, int end){
// 	//set p index to first element
// 	int p = ((begin+end)/2);
// 	std::cout<<"pivot value "<<arrray[p]<<"\n";
// 	//move the middle index to the front and create variable to assist with moving
// 	int val1;
// 	int val2;
// 	int e = begin;
// 	val1 = arrray[p];
// 	val2 = arrray[e];
// 	arrray[p] = val2;
// 	arrray[e] = val1;
// 	p = begin;
// 	std::cout<<p<<"\n";
// 	std::cout<<"pivot value "<<arrray[p]<<"\n";
// 	//create a switch index
// 	int s = end;
// 	for (int i = begin+1; i < end; ++i){
// 		for(int t = i; t <= s; ++t){
// 			if (arrray[i] >= arrray[p]){
// 				arrray.push_back(arrray[i]);
// 				arrray.erase(arrray.begin()+i);
// 				--s;
// 			}
// 		}
// 	}
// 	val1 = arrray[p];
// 	val2 = arrray[s-1];
// 	arrray[p] = val2;
// 	arrray[s-1] = val1;
// 	p = s-1;
// 	//if k = pivot index
// 	if (k == p){
// 		return arrray[p];
// 	}
// 	//if k < pivot index go to array to left of pivot index
// 	else if (k < p){
// 		return ksmalli(k, arrray, begin, p-1);
// 	}
// 	//if k > pivot index go to array to right of pivot index
// 	else if (k > p){
// 		return ksmalli(k, arrray, p+1, end);
// 	}
// }			

int main(int argc, char** argv){
	//create a variable to hold the integer on a line read from the data file
	std::string line;
	//open the data file
	std::ifstream data ("hw1-data.txt");
	//create an array to hold the data
	std::vector<int> Array;
	//check if the data file has been opened
	if (data.is_open()){
		//the data file has been opened. Create a variable to help place the data in the order it was given
		//while there are lines of data to be read, place each number in the given order into the array
		while (getline (data,line)){
			//place the number into the array
			Array.push_back(std::stoi(line));	
		}
	//close the data file
	data.close();
	}
	//if the data file could not be opened, inform the user and terminate program
	else {
		std::cout<<"unable to open file\n";
		//terminate program
		return 0;
	}

	//set desired k value
	int k = 42;
	//find value of kth smallest number
	int val = ksmalli(k, Array, 0, Array.size()-1);//should be 165
	std::cout<<"Using the value of the first element of the array as a pivot results in the trace\n";
	std::cout<<"The "<<k<<" smallest number is "<< val<<"\n";
	
	// val = ksmallii(k, Array, 0, Array.size()-1);//should be 165
	// std::cout<<"Using the value of the middle element of the array as a pivot results in the trace\n";
	// std::cout<<"The "<<k<<" smallest number is "<< val<<"\n";
	// //terminate program
	return 0;
}