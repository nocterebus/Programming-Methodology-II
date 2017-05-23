/*
Chaper 2, Exercise 3. 

write a recursive function that will compute the sum of the first n integers in an array of at least n integers
HINT: Begin with the nth integer
*/

#include <vector>
#include <iostream>

//create recursive summing function
int summ(int N, std::vector<int> vectaaa) {
	//if the index is not the smallest possible index, call the function again
	//at index-1 and add to current index
	if (N > 0){
		return summ(N-1,vectaaa) + vectaaa[N];
	}
	else {
		//base case return value at first index
		return vectaaa[N];
	}
}

int main(int argc,char** argv){
	//create a variable to hold n
	int n;
	//create a variable to hold the size of the array
	int a;
	//create a variable to hold the input values
	int input;
	//create a vector to hold all of the integers inputted
	std::vector<int> array;
	//ask the user to input up to what n they would like to sum (should not be negative)
	std::cout<<"Up to what integer place would you like to compute the sum of in your array (0 being the first): \n";
	if (std::cin>>n and n >=0){
		//ask the user to input how large their array will be and it should be larger than n
		std::cout<<"How large will your array be:\n";
		if (std::cin>>a){
			//check if the size of the array is smaller than n
			if(a<n){
				//array is too small
				std::cout<<"The array cannot be smaller than n. Please restart the program\n";
				//end the program
				return 0;
			}
		}
		else {
			//invalid input
			std::cout << "That was not a valid integer. Please restart the program\n";
			//end the program
			return 0;
		}
	}
	else {
		//invalid input
		std::cout << "That was not a valid integer. Please restart the program\n";
		//end the program
		return 0;
	}
	//ask the user to input values of an array
	std::cout<<"Please input integers of the array: \n";
	//continue pushing the inputted integers into the array until the array becomes filled
	for (int elements = 1; elements <= a; ++elements){
		//check that the user actually inputs an integer
		if(std::cin>>input){
			//push the integer into the back of the array
			array.push_back(input);
		}
		//if the user doesn't inputs something other than an integer, terminate program
		else {
			std::cout << "That was not an integer. Please restart the program\n";
			//end the program
			return 0;
		}
	}
	//output the sum
	std::cout<<"The sum of integers in the array up to index "<<n<<" is "<<summ(n,array)<<"\n";
	return 0;
}
