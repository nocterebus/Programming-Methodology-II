/*
Justen Yeung 150005872
Hw4 Quicksort

Each sort will automatically include the provided data/text files.
They also will output the sorted data into text files with respective names.

We will partition from the user specified element
*/ 


//Include header file that contains file reader and writer
#include "initial.h"

//Partitioner that also "sorts" for quicksort
std::vector<int>::iterator part (std::vector<int>::iterator begin, std::vector<int>::iterator end, long int& compares, long int& moves, int type){
	//arguments (beginning iterator, end iterator, number of compares, number of moves, partition from end(1) middle(2) begin(>=3))
    //Do not proceed if the range is empty/size 1 (shouldn't be called since quicksort algorithm also has this guard)
	if (std::distance(begin,end) < 2){
		//return end
		return end;
	}
    //partition from end
    if (type == 1){
        //initialize pivot to last element
        std::vector<int>::iterator pivot = end-1;
        //initialize split to last element
        std::vector<int>::iterator split = pivot;
        for (std::vector<int>::iterator i = split; i >= begin; --i){
            //iterate split and swap if we find something less than or equal to *pivot
            if (*i > *pivot){
                //advance split
                --split;
                //swap split with i
                std::swap(*i, *split);
                //iterate moves;
                ++moves;
            }
            //iterate compares
            ++compares;
        }
        //swap split with pivot
        std::swap(*split, *pivot);
        //iterate moves
        ++moves;
        //return the pivot which is now at split
        pivot = split;
        return pivot;
    }
    //partition from middle
    else if (type == 2){
        //measure distance/2 between begin and end
        int mid = std::distance(begin,end)/2;
        //initialize middle iterator to begin iterator
        std::vector<int>::iterator middle = begin;
        //advance middle iterator to middle
        std::advance(middle, mid);
        //initialize pivot to middle element
        std::vector<int>::iterator pivot = middle;
        //initialize split to middle element
        std::vector<int>::iterator split = pivot;
        //create a right side iterator
        std::vector<int>::iterator right = middle+1;
        //create a left side iterator
        std::vector<int>::iterator left = middle-1;
        //begin sorting starting with right side
        while (right < end){
            if (*right < *pivot){
                //increment split to the right
                ++split;
                //swap values at split and pivot making *split>*pivot...*right
                std::swap(*split, *pivot);
                //swap values at right and pivot making *right<*pivot...*split
                if (split != right){
                    std::swap(*pivot,*right);
                }
                //move pivot to original value's place
                pivot = split;
                //increment moves
                ++moves;
            }
            //increment right iterator
            ++right;
            //increment compares
            ++compares;
        }
        //begin sorting left side
        while (left >= begin){
            if (*left > *pivot){
                //decrement split to left
                --split;
                //swap values at split and pivot making *split>*pivot...*right
                std::swap(*split, *pivot);
                //swap values at left and pivot making *right<*pivot...*split
                 if (split != left){
                    std::swap(*pivot,*left);
                }
                //move pivot to original value's place
                pivot = split;
                //increment moves
                ++moves;
            }
            //decrement left iterator
            --left;
            //increment compares
            ++compares;
        }
        //return the pivot which is at split
        return pivot;

    }
    //partition from beginning
    else {
        //initialize pivot to first element
        std::vector<int>::iterator pivot = begin;
        //initialize split to first element
        std::vector<int>::iterator split = pivot;
        for (std::vector<int>::iterator i = split; i != end; ++i){
            //iterate split and swap if we find something less than or equal to *pivot
            if (*i < *pivot){
                //advance split
                ++split;
                //swap split with i
                std::swap(*i, *split);
                //iterate moves;
                ++moves;
            }
            //iterate compares
            ++compares;
        }
        //swap split with pivot
        std::swap(*split, *pivot);
        //iterate moves
        ++moves;
        //return the pivot which is now at split
        pivot = split;
        return pivot;
    }
}


//recursive function for quicksort
void quick(std::vector<int>::iterator begin, std::vector<int>::iterator end, long int& compares, long int& moves, int type){
	//exit recursion when partition size is 1 or 0
	if (std::distance(begin,end) < 2){
		return;
	}
	//sort and partition 
	std::vector<int>::iterator middle = part(begin, end, compares, moves, type);
	//quicksort side closer to begin
	quick(begin, middle, compares, moves, type);
	//don't include middle in the sorting
	quick(middle+1, end, compares, moves, type);
}

int main(int argc, char** argv) {
    //initialize the type of quicksort to be executed to first element
    int type = 2;
    //request the type of quicksort the user wished to implement
    std::cout<<"From which element would you like to execute quicksort from?\n Enter integer 1 to sort from last element,2 to sort from middle element, or any other integer for first element: ";
    std::cin>>type;

        //sort vector and count compares and moves
        quick(dus2.begin(), dus2.end(), c2, m2, type); 
        //output sorted data to output text file
        outwrite(dus2, "dus-2.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus2.begin(), dus2.end(), sc2, sm2, type);

        //sort vector and count compares and moves
        quick(dus4.begin(), dus4.end(), c4, m4, type); 
        //output sorted data to output text file
        outwrite(dus4, "dus-4.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus4.begin(), dus4.end(), sc4, sm4, type);

        //sort vector and count compares and moves
        quick(dus6.begin(), dus6.end(), c6, m6, type); 
        //output sorted data to output text file
        outwrite(dus6, "dus-6.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus6.begin(), dus6.end(), sc6, sm6, type);

        //sort vector and count compares and moves
        quick(dus8.begin(), dus8.end(), c8, m8, type); 
        //output sorted data to output text file
        outwrite(dus8, "dus-8.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus8.begin(), dus8.end(), sc8, sm8, type);

        //sort vector and count compares and moves
        quick(dus10.begin(), dus10.end(), c10, m10, type); 
        //output sorted data to output text file
        outwrite(dus10, "dus-10.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus10.begin(), dus10.end(), sc10, sm10, type);

        //sort vector and count compares and moves
        quick(dus12.begin(), dus12.end(), c12, m12, type); 
        //output sorted data to output text file
        outwrite(dus12, "dus-12.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus12.begin(), dus12.end(), sc12, sm12, type);

        //sort vector and count compares and moves
        quick(dus16.begin(), dus16.end(), c16, m16, type); 
        //output sorted data to output text file
        outwrite(dus16, "dus-16.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus16.begin(), dus16.end(), sc16, sm16, type);

        results();
    //terminate program
	return 0;
}




