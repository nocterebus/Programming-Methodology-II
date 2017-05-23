/*
Justen Yeung 150005872
Hw4 mergesort b
in place

Each sort will automatically include the provided data/text files.
They also will output the sorted data into text files with respective names.
Here moves is the number of shifts made (dependent) and compares is the number of comparisons made (should be tightly bound)
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
		//if right element is less than left element, shift right element to correct spot (left iterator position)
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

int main (int argc, char** argv){
     //prompt the user if they want to use their own data file, if not it will sert through dus files
    std::cout<<"Do you have a data file to sort through? Type (yes) if you do. \n Any other input would result in sorting through the dus files.\n";
    std::string request;
    std::cin>>request;
    if (request != "yes"){
        //prompt user for if they want to sort through dus-20 and dus-24
        std::cout<<"would you like to sort thought dus-20? Type (yes) if you wish to proceed.\n Any other input will be assumed as no.\n";
        std::string in20;
        std::cin>>in20;
        std::cout<<"would you like to sort thought dus-24? Type (yes) if you wish to proceed.\n Any other input will be assumed as no.\n";
        std::string in24;
        std::cin>>in24;

        //read from dus-2.txt file and make vector
        std::vector<int> dus2 = make("dus-2.txt");
        //sort vector and count compares and moves
        mergesort(dus2.begin(), dus2.end(), c2, m2); 
        //output sorted data to output text file
        outwrite(dus2, "dus-2.txt");
        //sort sorted vector again to count differences in compares/moves
        mergesort(dus2.begin(), dus2.end(), sc2, sm2);

        //read from dus-4.txt file and make vector
        std::vector<int> dus4 = make("dus-4.txt");
        //sort vector and count compares and moves
        mergesort(dus4.begin(), dus4.end(), c4, m4); 
        //output sorted data to output text file
        outwrite(dus4, "dus-4.txt");
        //sort sorted vector again to count differences in compares/moves
        mergesort(dus4.begin(), dus4.end(), sc4, sm4);

        //read from dus-6.txt file and make vector
        std::vector<int> dus6 = make("dus-6.txt");
        //sort vector and count compares and moves
        mergesort(dus6.begin(), dus6.end(), c6, m6); 
        //output sorted data to output text file
        outwrite(dus6, "dus-6.txt");
        //sort sorted vector again to count differences in compares/moves
        mergesort(dus6.begin(), dus6.end(), sc6, sm6);

        //read from dus-8.txt file and make vector
        std::vector<int> dus8 = make("dus-8.txt");
        //sort vector and count compares and moves
        mergesort(dus8.begin(), dus8.end(), c8, m8); 
        //output sorted data to output text file
        outwrite(dus8, "dus-8.txt");
        //sort sorted vector again to count differences in compares/moves
        mergesort(dus8.begin(), dus8.end(), sc8, sm8);

        //read from dus-10.txt file and make vector
        std::vector<int> dus10 = make("dus-10.txt");
        //sort vector and count compares and moves
        mergesort(dus10.begin(), dus10.end(), c10, m10); 
        //output sorted data to output text file
        outwrite(dus10, "dus-10.txt");
        //sort sorted vector again to count differences in compares/moves
        mergesort(dus10.begin(), dus10.end(), sc10, sm10);

        //read from dus-12.txt file and make vector
        std::vector<int> dus12 = make("dus-12.txt");
        //sort vector and count compares and moves
        mergesort(dus12.begin(), dus12.end(), c12, m12); 
        //output sorted data to output text file
        outwrite(dus12, "dus-12.txt");
        //sort sorted vector again to count differences in compares/moves
        mergesort(dus12.begin(), dus12.end(), sc12, sm12);

        //read from dus-16.txt file and make vector
        std::vector<int> dus16 = make("dus-16.txt");
        //sort vector and count compares and moves
        mergesort(dus16.begin(), dus16.end(), c16, m16); 
        //output sorted data to output text file
        outwrite(dus16, "dus-16.txt");
        //sort sorted vector again to count differences in compares/moves
        mergesort(dus16.begin(), dus16.end(), sc16, sm16);

        if (in20 == "yes"){
            //read from dus-20.txt file and make vector
            std::vector<int> dus20 = make("dus-20.txt");
            //sort vector and count compares and moves
            mergesort(dus20.begin(), dus20.end(), c20, m20); 
            //output sorted data to output text file
            outwrite(dus20, "dus-20.txt");
            //sort sorted vector again to count differences in compares/moves
            mergesort(dus20.begin(), dus20.end(), sc20, sm20);
        }

        if (in24 == "yes"){
            //read from dus-24.txt file and make vector
            std::vector<int> dus24 = make("dus-24.txt");
            //sort vector and count compares and moves
            mergesort(dus24.begin(), dus24.end(), c24, m24); 
            //output sorted data to output text file
            outwrite(dus24, "dus-24.txt");
            //sort sorted vector again to count differences in compares/moves
            mergesort(dus24.begin(), dus24.end(), sc24, sm24);
        }
        //inform user of run times
        std::cout<<"mergesort sort ";
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
        mergesort(users.begin(), users.end(), cf, mf); 
        //output sorted data to output text file
        outwrite(users, file);
        //sort sorted vector again to count differences in compares/moves
        mergesort(users.begin(), users.end(), scf, smf);


        std::cout<<file<<" had   "<<cf<<" comparisons and       "<<mf<<" moves.\n";
        std::cout<<"sorted"<<file<<" had "<<scf<<" comparisons and      "<<smf<<" moves.\n";
    }
    //terminate program
    return 0;
}


