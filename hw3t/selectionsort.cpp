/*
Justen Yeung 150005872
Hw3 Selection Sort

Each sort will automatically include the provided data/text files.
They also will output the sorted data into text files with respective names.
*/ 

//Include header file that contains file reader and writer
#include "initial.h"

//select sort
void select (std::vector<int>& sorted, long  int& compares, long  int& moves){
    //create variable to help sort array
    //value of the largest number
    int large;    
    //position of the largest number
    int pl;
    //outer loop (iterates from the end to the beginning)
    for (int end = sorted.size()-1; end > 0; --end){
        //initialize inner loop swapping variables
        large = sorted[end];
        pl = end;
        //inner loop (iterates from the beginning till end)
        for (int place = 0; place <= end; ++place){
            //if the current number is the largest , save value and place
            if (sorted[place] > large){
                large = sorted[place];
                pl = place;
            }
            //increment comparisons
            ++compares;
        }    
        //swap values
        sorted[pl] = sorted[end];
        sorted[end] = large;
        //increment moves
        ++moves;
        //if the selected number didn't change place, ther were no moves
        if (pl == end){
            //cancel moves increment
            --moves;
        }
    }
}
int main (int argc, char** argv){
    select(dus20, c20, m20); 
    select(dus20, sc20, sm20);

    select(dus24, c24, m24); 
    select(dus24, sc24, sm24);

    //inform user of run times
    std::cout<<"selection sort ";
    results();
    //terminate program
    return 0;
}


