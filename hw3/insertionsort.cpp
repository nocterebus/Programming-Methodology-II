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
        //increment compares again
        ++compares;
        //insert number;
        sorted[place] = insertn;
        //increment moves
        ++moves;
    }
}

int main (int argc, char** argv){
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
        insert(dus2, c2, m2); 
        //output sorted data to output text file
        outwrite(dus2, "dus-2.txt");
        //sort sorted vector again to count differences in compares/moves
        insert(dus2, sc2, sm2);

        //read from dus-4.txt file and make vector
        std::vector<int> dus4 = make("dus-4.txt");
        //sort vector and count compares and moves
        insert(dus4, c4, m4); 
        //output sorted data to output text file
        outwrite(dus4, "dus-4.txt");
        //sort sorted vector again to count differences in compares/moves
        insert(dus4, sc4, sm4);

        //read from dus-6.txt file and make vector
        std::vector<int> dus6 = make("dus-6.txt");
        //sort vector and count compares and moves
        insert(dus6, c6, m6); 
        //output sorted data to output text file
        outwrite(dus6, "dus-6.txt");
        //sort sorted vector again to count differences in compares/moves
        insert(dus6, sc6, sm6);

        //read from dus-8.txt file and make vector
        std::vector<int> dus8 = make("dus-8.txt");
        //sort vector and count compares and moves
        insert(dus8, c8, m8); 
        //output sorted data to output text file
        outwrite(dus8, "dus-8.txt");
        //sort sorted vector again to count differences in compares/moves
        insert(dus8, sc8, sm8);

        //read from dus-10.txt file and make vector
        std::vector<int> dus10 = make("dus-10.txt");
        //sort vector and count compares and moves
        insert(dus10, c10, m10); 
        //output sorted data to output text file
        outwrite(dus10, "dus-10.txt");
        //sort sorted vector again to count differences in compares/moves
        insert(dus10, sc10, sm10);

        //read from dus-12.txt file and make vector
        std::vector<int> dus12 = make("dus-12.txt");
        //sort vector and count compares and moves
        insert(dus12, c12, m12); 
        //output sorted data to output text file
        outwrite(dus12, "dus-12.txt");
        //sort sorted vector again to count differences in compares/moves
        insert(dus12, sc12, sm12);

        //read from dus-16.txt file and make vector
        std::vector<int> dus16 = make("dus-16.txt");
        //sort vector and count compares and moves
        insert(dus16, c16, m16); 
        //output sorted data to output text file
        outwrite(dus16, "dus-16.txt");
        //sort sorted vector again to count differences in compares/moves
        insert(dus16, sc16, sm16);

        if (in20 == "yes"){
            //read from dus-20.txt file and make vector
            std::vector<int> dus20 = make("dus-20.txt");
            //sort vector and count compares and moves
            insert(dus20, c20, m20); 
            //output sorted data to output text file
            outwrite(dus20, "dus-20.txt");
            //sort sorted vector again to count differences in compares/moves
            insert(dus20, sc20, sm20);
        }
        if (in24 == "yes"){
            //read from dus-24.txt file and make vector
            std::vector<int> dus24 = make("dus-24.txt");
            //sort vector and count compares and moves
            insert(dus24, c24, m24); 
            //output sorted data to output text file
            outwrite(dus24, "dus-24.txt");
            //sort sorted vector again to count differences in compares/moves
            insert(dus24, sc24, sm24);
        }
        //inform user of run times
        std::cout<<"insertion sort ";
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
        insert(users, cf, mf); 
        //output sorted data to output text file
        outwrite(users, file);
        //sort sorted vector again to count differences in compares/moves
        insert(users, scf, smf);


        std::cout<<file<<" had   "<<cf<<" comparisons and       "<<mf<<" moves.\n";
        std::cout<<"sorted"<<file<<" had "<<scf<<" comparisons and      "<<smf<<" moves.\n";
    }
    //terminate program
    return 0;
}

