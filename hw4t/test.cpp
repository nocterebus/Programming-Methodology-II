#include <vector>
#include <iostream>

int main(int argc, char** argv){
	int size = 1;
	std::vector<int> four(size);
	for (int i = 0; i < size; ++i){
	 	four[i] = i;
	}

	std::cout<<"array\n";
	for (int i = 0; i < size; ++i){
		std::cout<<four[i]<<"\n";
	}
	std::cout<<"distance = "<<std::distance(four.begin(),four.end())<<"\n"; 
	int mid = std::distance(four.begin(),four.end())/2;
	std::vector<int>::iterator middle = four.begin();
	std::advance(middle, mid);
	std::cout<<*middle<<" is middle\n";

        //initialize pivot to middle element
        std::vector<int>::iterator right1 = middle+1;
	std::cout<<*right1<<" is right1\n";
        //initialize split to middle element
        std::vector<int>::iterator left1 = middle-1;
	std::cout<<*left1<<" is left1\n";
	//std::vector<int>::iterator middle = std::distance(four.end(),four.begin())/2;
	std::cout<<"middle ";//<<middle<<"\n";


	return 0;
}