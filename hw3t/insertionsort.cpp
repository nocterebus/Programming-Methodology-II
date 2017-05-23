/*
Justen Yeung 150005872
Hw3 Insertion Sort

Each sort will automatically include the provided data/text files.
They also will output the sorted data into text files with respective names.
*/ 

//Include header file that contains file reader and writer
#include "initial.h"

//insert sort
void insert (std::vector<int>& sorted, long  int& compares, long  int& moves){
    //create variable to help sort array
    //value of the insert number
    int insertn;
 //position where number will be inserted
    int place;
    //outer loop (iterates from the beginning+1)
    for (int ins = 1; ins < sorted.size(); ++ins){
        //save value of insert number
        insertn = sorted[ins];
        //initialize inner loop variable
        place = ins; 
        //if the insert number will not be moved, preamptively negate move increment
        if (sorted[ins] >= sorted[ins-1]){
            //negate move increment
            --moves;
        }
        //increment compares
        ++compares;
        //inner loop (iterates from ins toward the beginning)
        while (insertn < sorted[place-1] and place > 0){
            //increment compares
            ++compares;
            //shift number to the right
            sorted[place] = sorted[place-1];
            //decrement place
            --place;
        }
        //insert number;
        sorted[place] = insertn;
        //increment moves
        ++moves;
    }
}

int main (int argc, char** argv){

    insert(dus20, c20, m20); 
    insert(dus20, sc20, sm20);

    insert(dus24, c24, m24); 
    insert(dus24, sc24, sm24);

    //inform user of run times
    std::cout<<"insertion sort ";
    results();
    //terminate program
    return 0;
}

