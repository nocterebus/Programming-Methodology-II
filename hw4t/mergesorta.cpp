/*
Justen Yeung 150005872
Hw4 Mergesort a
additional array/memory
i.e. make a copy vector and then rewrite back
Each sort will automatically include the provided data/text files.
They also will output the sorted data into text files with respective names.
*/ 


//Include header file that contains file reader and writer
#include "initial.h"

//sorter and merger for mergesort
void merge(std::vector<int>::iterator begin, std::vector<int>::iterator middle, std::vector<int>::iterator end, long int& compares, long int& moves){
	if (std::distance(begin,end) < 2){
		//return
		return;
	}
	//make copyspace to hold sorted and merged halves
	std::vector<int> sorted(std::distance(begin,end));
	//create iterators to represent left and right halves
	std::vector<int>::iterator left = begin;
	std::vector<int>::iterator right = middle;
	//begin mergine halves
	for (std::vector<int>::iterator copy = sorted.begin(); copy != sorted.end(); ++copy){
		//if left element is less than right element, place left element
		if (left < middle and *left <= *right){
			*copy = *left;
			//increment left iterator
			++left;
		}
		//if right element is less than left element, place right element
		else if (right < end and *right < *left){
			*copy = *right;
			//increment right iterator
			++right;
		}
		//if there are no more left elements, place right element
		else if (left == middle and right < end){
			*copy = *right;
			//increment right iterator
			++right;			
		}
		//if there are no more right elements, place left element
		else if (right == end and left < middle){
			*copy = *left;
			//increment left iterator
			++left;
		}
		//increment compares and moves
		++moves;
		++compares;
	}
	//create sorted vector iterator
	std::vector<int>::iterator it = sorted.begin();
	//copy sorted vector back into original array
	for (std::vector<int>::iterator place = begin; place != end; ++place){
		*place = *it;
		//increment sorted array iterator
		++it;
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

