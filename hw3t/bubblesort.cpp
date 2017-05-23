/*
Justen Yeung 150005872
Hw3 Bubble Sort

Each sort will automatically include the provided data/text files.
They also will output the sorted data into text files with respective names.
*/ 

//Include header file that contains file reader and writer
#include "initial.h"

//bubble sort
void bubble (std::vector<int>& sorted, long  int& compares, long  int& moves){
    //create variables to help sort array
    //value of place bubble number
    int bubblep; 
    //outer loop (iterates from the end to the beginning)
    for (int end = sorted.size()-1; end > 0; --end){
        //inner loop (iterates from beginning till end)
        for(int place = 1; place <= end; ++place){
            //save number in current value
            bubblep = sorted[place];
            //compare and swap if necessary
            if (sorted[place] < sorted[place-1]){
                //swap numbers
                sorted[place] = sorted[place-1];
                sorted[place-1] = bubblep;
                //increment moves
                ++moves;
            }
            //increment compares;
            ++compares;
        }
    }
}

int main (int argc, char** argv){
    bubble(dus6, c6, m6);
    bubble(dus6, sc6, sm6);
    //prompt user for if they want to sort through dus-20 and dus-24
    std::cout<<"would you like to sort thought dus-20? Type (yes) if you wish to proceed.\n Any other input will be assumed as no.\n";
    std::string in20;
    std::cin>>in20;
    std::cout<<"would you like to sort thought dus-24? Type (yes) if you wish to proceed.\n Any other input will be assumed as no.\n";
    std::string in24;
    std::cin>>in24;
    if (in20 == "yes"){
        bubble(dus20, c20, m20); 
        bubble(dus20, sc20, sm20);
    }
    if (in24 == "yes"){
        bubble(dus24, c24, m24); 
        bubble(dus24, sc24, sm24);
    }
    //inform user of run times
    std::cout<<"bubble sort ";
    results();
    //terminate program
    return 0;
}


 