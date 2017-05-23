/*
Justen Yeung 150005872
Hw5 Assignment 1 Heapsort
Using the data set from earlier sorting homeworks, plot and 
analyze the runtime performance of HeapSort. [6 points]
*/ 

//Include header file that contains file reader and writer
#include "initial.h"

//left child is 2*i + 1
//right child is 2*i + 2
//parent is (i-1)/2 (rounds down automatically)

//algorithm to fix anything wrong in the heap
void HEEP(std::vector<int>& items, long int size, long int index, long int& count, long int& moves){
    //left leaf index
    long int L = index*2+1;
    //right leaf index
    long int R = L+1;
    //largest number's index of parent, left, and right leaf
    long int largest = index;
    //check if left leaf exists
    if (L < size){
        ++count; //comparison made
        //check if left leaf is larger than parent
        if (items[index] < items[L]){    
            largest = L;   
        }
    }

    //check if right leaf exists
    if (R < size){
        ++count; //comparison made
        //check if right leaf is largest of all three
        if (items[largest]<items[R]){
            largest = R;
        }
    }
    //check if the heap needs any switches and trickle down result
    if (largest != index){
        std::swap(items[largest],items[index]);
        ++moves;
        HEEP(items, size, largest, count, moves);
    }
}

//build heap
void maxheap(std::vector<int>& items, long int lastindex, long int& count, long int& moves){
    //only need to fix heaps(nodes) with children
    for (long int i = (lastindex-1)/2; i >= 0; --i){
        HEEP(items, items.size(), i, count, moves);
    }
}

//Heapsort
void HeapSort(std::vector<int>& items, long int size, long int& count, long int& moves){
    //begin sorting
    for (long int i = items.size()-1; i >=1; --i){
        //swap/move root toward back of array (sorted portion)
        std::swap(items[0], items[i]);
        //decrement size of region that still needs to be sorted
        --size;
        //begin trickling down 
        HEEP(items, size, 0, count, moves);
    }
}



int main (int argc, char** argv){
     //prompt the user if they want to use their own data file, if not it will sort through dus files
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
        maxheap(dus2, dus2.size()-1, c2, m2); 
        //sort sorted vector again to count differences in compares/moves
        HeapSort(dus2, dus2.size(), hc2, hm2);
        //output sorted data to output text file
        outwrite(dus2, "dus-2.txt");

        //read from dus-4.txt file and make vector
        std::vector<int> dus4 = make("dus-4.txt");
        //sort vector and count compares and moves
        maxheap(dus4, dus4.size()-1, c4, m4); 
        //sort sorted vector again to count differences in compares/moves
        HeapSort(dus4, dus4.size(), hc4, hm4);
        //output sorted data to output text file
        outwrite(dus4, "dus-4.txt");

        //read from dus-6.txt file and make vector
        std::vector<int> dus6 = make("dus-6.txt");
        //sort vector and count compares and moves
        maxheap(dus6, dus6.size()-1, c6, m6); 
        //sort sorted vector again to count differences in compares/moves
        HeapSort(dus6, dus6.size(), hc6, hm6);
        //output sorted data to output text file
        outwrite(dus6, "dus-6.txt");

        //read from dus-8.txt file and make vector
        std::vector<int> dus8 = make("dus-8.txt");
        //sort vector and count compares and moves
        maxheap(dus8, dus8.size()-1, c8, m8); 
        //sort sorted vector again to count differences in compares/moves
        HeapSort(dus8, dus8.size(), hc8, hm8);
        //output sorted data to output text file
        outwrite(dus8, "dus-8.txt");

        //read from dus-10.txt file and make vector
        std::vector<int> dus10 = make("dus-10.txt");
        //sort vector and count compares and moves
        maxheap(dus10, dus10.size()-1, c10, m10); 
        //sort sorted vector again to count differences in compares/moves
        HeapSort(dus10, dus10.size(), hc10, hm10);
        //output sorted data to output text file
        outwrite(dus10, "dus-10.txt");

        //read from dus-12.txt file and make vector
        std::vector<int> dus12 = make("dus-12.txt");
        //sort vector and count compares and moves
        maxheap(dus12, dus12.size()-1, c12, m12); 
        //sort sorted vector again to count differences in compares/moves
        HeapSort(dus12, dus12.size(), hc12, hm12);
        //output sorted data to output text file
        outwrite(dus12, "dus-12.txt");

        //read from dus-16.txt file and make vector
        std::vector<int> dus16 = make("dus-16.txt");
        //sort vector and count compares and moves
        maxheap(dus16, dus16.size()-1, c16, m16); 
        //sort sorted vector again to count differences in compares/moves
        HeapSort(dus16, dus16.size(), hc16, hm16);
        //output sorted data to output text file
        outwrite(dus16, "dus-16.txt");

        if (in20 == "yes"){
            //read from dus-20.txt file and make vector
            std::vector<int> dus20 = make("dus-20.txt");
            //sort vector and count compares and moves
            maxheap(dus20, dus20.size()-1, c20, m20); 
            //sort sorted vector again to count differences in compares/moves
            HeapSort(dus20, dus20.size(), hc20, hm20);
            //output sorted data to output text file
            outwrite(dus20, "dus-20.txt");
        }

        if (in24 == "yes"){
            //read from dus-24.txt file and make vector
            std::vector<int> dus24 = make("dus-24.txt");
            //sort vector and count compares and moves
            maxheap(dus24, dus24.size()-1, c24, m24); 
            //sort sorted vector again to count differences in compares/moves
            HeapSort(dus24, dus24.size(), hc24, hm24);
            //output sorted data to output text file
            outwrite(dus24, "dus-24.txt");
        }
        //inform user of run times
        std::cout<<"HeapSort";
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
        long int hcf = 0;    //sorted compares counter
        long int hmf = 0;    //sorted moves counter
        //read from file.txt file and make vector
        std::vector<int> users = make(file);
        //sort vector and count compares and moves
        maxheap(users, users.size()-1, cf, mf); 
        //sort sorted vector again to count differences in compares/moves
        HeapSort(users, users.size(), hcf, hmf);
        //output sorted data to output text file
        outwrite(users, file);


        std::cout<<file<<" had   "<<cf<<" comparisons and       "<<mf<<" moves.\n";
        std::cout<<"sorted"<<file<<" had "<<hcf<<" comparisons and      "<<hmf<<" moves.\n";
    }
    //terminate program
    return 0;
}