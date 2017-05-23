/*
Justen Yeung 150005872
Hw4 Mergesort b
in place
(swap values)
Each sort will automatically include the provided data/text files.
They also will output the sorted data into text files with respective names.
*/ 


//Include header file that contains file reader and writer
#include "initial.h"

//in place sorter and merger for mergesort
void merge(std::vector<int>::iterator begin, std::vector<int>::iterator middle, std::vector<int>::iterator end, long int& compares, long int& moves){
	if (std::distance(begin,end) < 2){
		//return
		return;
	}
	//create iterators to represent left and right halves
	std::vector<int>::iterator left = begin;
	std::vector<int>::iterator right = middle;
	//create shifter to allow for in place merging (no use of additional vector)
	std::vector<int>::iterator shifter;
	//if left iterator reaches right iterator, right side is left and is already sorted so we can leave the loop. same for if right reaches end
	while (left < right and right < end){
		//if left element is less than right element, increment left iterator
		if (*left <= *right){
			++left;
		}
		//if right element is less than left element, shift "left side" over 1 and palce right element
		else /*(*right < *left)*/{
			//save position of right iterator for shifting
			shifter = right;
			//begin shifting
			while (shifter != left){
				std::swap(*shifter, *(shifter-1));
				//decrement shifter
				--shifter;
				//increment moves
				++moves;
			}
			//increment right and left iterator
			++right;
			++left;
		}
		++compares;
	}
}


//recursive function for quicksort
void mergesort(std::vector<int>::iterator begin, std::vector<int>::iterator end, long int& compares, long int& moves){
	//measure distance between begin and end
	int dist = std::distance(begin,end);
	//exit recursion when partition size is 1 or 0
	if (dist < 2){
		return;
	}
	//find middle to partition 
	std::vector<int>::iterator middle = begin;
	std::advance(middle, dist/2);
	//Recursively mergesort left and right side
	mergesort(begin, middle, compares, moves);
	mergesort(middle, end, compares, moves);
	//sorted merge the  two sides
	merge(begin, middle, end, compares, moves);
}

int main(int argc, char** argv) {
  	
    //sort vector and count compares and moves
    mergesort(dus2.begin(), dus2.end(), c2, m2); 
    //output sorted data to output text file
    outwrite(dus2, "dus-2.txt");

    //sort vector and count compares and moves
    mergesort(dus4.begin(), dus4.end(), c4, m4); 
    //output sorted data to output text file
    outwrite(dus4, "dus-4.txt");
    //sort sorted vector again to count differences in compares/moves
    //quick(dus4.begin(), dus4.end(), sc4, sm4, type);
    //terminate program
	return 0;
}

