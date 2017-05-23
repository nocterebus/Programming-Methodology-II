/*
Justen Yeung 150005872
Hw4 Quicksort

Each sort will automatically include the provided data/text files.
They also will output the sorted data into text files with respective names.

We will partition from the user specified element
Here moves is the number of swaps made (dependent) and comparisons is the number of comparisons made (should be tightly bound)
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
                //increment moves
                ++moves;
                //swap values at right and pivot making *right<*pivot...*split
                if (split != right){
                    std::swap(*pivot,*right);
                    //increment moves
                    ++moves;
                }
                //move pivot to original value's place
                pivot = split;
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
                //increment moves
                ++moves;
                //swap values at left and pivot making *right<*pivot...*split
                 if (split != left){
                    std::swap(*pivot,*left);
                    //increment moves
                    ++moves;
                }
                //move pivot to original value's place
                pivot = split;
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
    int type = 0;
    //request the type of quicksort the user wished to implement
    std::cout<<"From which element would you like to execute quicksort from?\n Enter integer 1 to sort from last element,2 to sort from middle element, or any other integer for first element: ";
    std::cin>>type;
   //prompt the user if they want to use their own data file, if not it will sert through dus files
    std::cout<<"Do you have a data file to sort through? Type (yes) if you do. \n Any other input would result in sorting through the dus files.\n";
    std::string request;
    std::cin>>request;
    if (request != "yes"){
        //prompt user for if they want to sort through dus-20 and dus-24
        std::cout<<"Would you like to sort thought dus-20? Type (yes) if you wish to proceed.\n Any other input will be assumed as no.\n";
        std::string in20;
        std::cin>>in20;
        std::cout<<"Would you like to sort thought dus-24? Type (yes) if you wish to proceed.\n Any other input will be assumed as no.\n";
        std::string in24;
        std::cin>>in24;

        //read from dus-2.txt file and make vector
        std::vector<int> dus2 = make("dus-2.txt");
        //sort vector and count compares and moves
        quick(dus2.begin(), dus2.end(), c2, m2, type); 
        //output sorted data to output text file
        outwrite(dus2, "dus-2.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus2.begin(), dus2.end(), sc2, sm2, type);

        //read from dus-4.txt file and make vector
        std::vector<int> dus4 = make("dus-4.txt");
        //sort vector and count compares and moves
        quick(dus4.begin(), dus4.end(), c4, m4, type); 
        //output sorted data to output text file
        outwrite(dus4, "dus-4.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus4.begin(), dus4.end(), sc4, sm4, type);

        //read from dus-6.txt file and make vector
        std::vector<int> dus6 = make("dus-6.txt");
        //sort vector and count compares and moves
        quick(dus6.begin(), dus6.end(), c6, m6, type); 
        //output sorted data to output text file
        outwrite(dus6, "dus-6.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus6.begin(), dus6.end(), sc6, sm6, type);

        //read from dus-8.txt file and make vector
        std::vector<int> dus8 = make("dus-8.txt");
        //sort vector and count compares and moves
        quick(dus8.begin(), dus8.end(), c8, m8, type); 
        //output sorted data to output text file
        outwrite(dus8, "dus-8.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus8.begin(), dus8.end(), sc8, sm8, type);

        //read from dus-10.txt file and make vector
        std::vector<int> dus10 = make("dus-10.txt");
        //sort vector and count compares and moves
        quick(dus10.begin(), dus10.end(), c10, m10, type); 
        //output sorted data to output text file
        outwrite(dus10, "dus-10.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus10.begin(), dus10.end(), sc10, sm10, type);

        //read from dus-12.txt file and make vector
        std::vector<int> dus12 = make("dus-12.txt");
        //sort vector and count compares and moves
        quick(dus12.begin(), dus12.end(), c12, m12, type); 
        //output sorted data to output text file
        outwrite(dus12, "dus-12.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus12.begin(), dus12.end(), sc12, sm12, type);

        //read from dus-16.txt file and make vector
        std::vector<int> dus16 = make("dus-16.txt");
        //sort vector and count compares and moves
        quick(dus16.begin(), dus16.end(), c16, m16, type); 
        //output sorted data to output text file
        outwrite(dus16, "dus-16.txt");
        //sort sorted vector again to count differences in compares/moves
        quick(dus16.begin(), dus16.end(), sc16, sm16, type);

        if (in20 == "yes"){
            //read from dus-20.txt file and make vector
            std::vector<int> dus20 = make("dus-20.txt");
            //sort vector and count compares and moves
            quick(dus20.begin(), dus20.end(), c20, m20, type); 
            //output sorted data to output text file
            outwrite(dus20, "dus-20.txt");
            //sort sorted vector again to count differences in compares/moves
            quick(dus20.begin(), dus20.end(), sc20, sm20, type);
        }
        if (in24 == "yes"){
            //read from dus-24.txt file and make vector
            std::vector<int> dus24 = make("dus-24.txt");
            //sort vector and count compares and moves
            quick(dus24.begin(), dus24.end(), c24, m24, type); 
            //output sorted data to output text file
            outwrite(dus24, "dus-24.txt");
            //sort sorted vector again to count differences in compares/moves
            quick(dus24.begin(), dus24.end(), sc24, sm24, type);
        }
        //inform user of run times
        std::cout<<"quick sort ";
        results();
    }
    else {
        //request for their data file name
        std::cout<<"What is your data text file's name? (e.x.) data.txt\n";
        std::string file;
        std::cin>>file;
        //integers to count runtimes
        long int cf = 0;     //compares counter
        long int mf = 0;     //moves counter
        long int scf = 0;    //sorted compares counter
        long int smf = 0;    //sorted moves counter
        //read from file.txt file and make vector
        std::vector<int> users = make(file);
        //sort vector and count compares and moves
        quick(users.begin(), users.end(), cf, mf, type); 
        //output sorted data to output text file
        outwrite(users, file);
        //sort sorted vector again to count differences in compares/moves
        quick(users.begin(), users.end(), scf, smf, type);


        std::cout<<file<<" had   "<<cf<<" comparisons and       "<<mf<<" moves.\n";
        std::cout<<"sorted"<<file<<" had "<<scf<<" comparisons and      "<<smf<<" moves.\n";
    }
    //terminate program
    return 0;
}



