/*
Justen Yeung 150005872
Hw2 Towers of Hanoi (recursive)

1. Implement a recursive solution to the Towers of Hanoi using the pseudo-code 
	discussed in class.  It should be written to calculate the number of "moves"  
	for an arbitrary value of N, where N is the number of disc. How many 
	moves are made for N=10?  Plot the number of moves as a function of N, for 
	as many N as your computer/implementation will allow. 

2. Using the pseduo-code, trace the recursive calls for N = 4. 

3. Implement an iterative solution to the Towers of Hanoi. 

4. Compare the timings of your iterative and recursive implementations, as  a 
function of N. Discuss your answer. 
*/


#include <iostream>
#include <stack>

int main (int argc, char** argv){
	//create stacks to hold how many disks are in towers a, b, and c
	std::stack<int> a;
	std::stack<int> b;
	std::stack<int> c;
	//create and initialize a variable to hold the user's input of number of disks
	int N = 0;
	//create and initialize a variable to hold the number of moves made
		//note that we must alternate moving the smallest and second smallest stack
	long int move = 0;
	//Ask the user to input how many disks there will be in the problem
	std::cout << "Enter how many disks there will be in the Towers of Hanoi please (e.g. 4):";
	//Save the user's input into N
	std::cin >> N;
	//set the source tower a to have number of disks N
	for (int i = N; i >= 1; --i){
		a.push(i);
	}
	//perform iterative solution

	//If N is odd
	if (N % 2 == 1) {
		while (b.size() < N){
			//move between towers a and b
			if (move % 3 == 0){
				//if tower a is empty move top of tower b to a
				if (a.empty()){
					a.push(b.top());
					b.pop();
					//increment move
						++move;
				}
				//if tower b is empty move top of tower a to b
				else if (b.empty()){
					b.push(a.top());
					a.pop();
					//increment move
						++move;
				}
				else {
					//if top of b is less than top of a, move top of b to a
					if (b.top() < a.top()) {
						a.push(b.top());
						b.pop();
						//increment move
						++move;
					}
					//else top of a is less than top of b, move top of a to b
					else {
						b.push(a.top());
						a.pop();
						//increment move
						++move;
					}
				}
			}
			//move between towers a and c
			else if (move % 3 == 1){
				//if tower a is empty move top of tower c to a
				if (a.empty()){
					a.push(c.top());
					c.pop();
					//increment move
						++move;
				}
				//if tower c is empty move top of tower a to c
				else if (c.empty()){
					c.push(a.top());
					a.pop();
					//increment move
						++move;
				}
				else {
					//if top of c is less than top of a, move top of c to a
					if (c.top() < a.top()) {
						a.push(c.top());
						c.pop();
						//increment move
						++move;
					}
					//else top of a is less than top of c, move top of a to c
					else {
						c.push(a.top());
						a.pop();
						//increment move
						++move;
					}
				}
			}
			//move between towers b and c
			else if (move % 3 == 2){
				//if tower b is empty move top of tower c to b
				if (b.empty()){
					b.push(c.top());
					c.pop();
					//increment move
						++move;
				}
				//if tower c is empty move top of tower b to c
				else if (c.empty()){
					c.push(b.top());
					b.pop();
					//increment move
						++move;
				}
				else {
					//if top of b is less than top of c, move top of b to c
					if (b.top() < c.top()) {
						c.push(b.top());
						b.pop();
						//increment move
						++move;
					}
					//else top of c is less than top of b, move top of c to b
					else {
						b.push(c.top());
						c.pop();
						//increment move
						++move;
					}
				}
			}
		}
	}
	//If N is even
	else if (N % 2 == 0) {
		while (c.size() < N){
			//move between towers a and b
			if (move % 3 == 0){
				//if tower a is empty move top of tower b to a
				if (a.empty()){
					a.push(b.top());
					b.pop();
					//increment move
						++move;
				}
				//if tower b is empty move top of tower a to b
				else if (b.empty()){
					b.push(a.top());
					a.pop();
					//increment move
						++move;
				}
				else {
					//if top of b is less than top of a, move top of b to a
					if (b.top() < a.top()) {
						a.push(b.top());
						b.pop();
						//increment move
						++move;
					}
					//else top of a is less than top of b, move top of a to b
					else {
						b.push(a.top());
						a.pop();
						//increment move
						++move;
					}
				}
			}
			//move between towers a and c
			else if (move % 3 == 1){
				//if tower a is empty move top of tower c to a
				if (a.empty()){
					a.push(c.top());
					c.pop();
					//increment move
						++move;
				}
				//if tower c is empty move top of tower a to c
				else if (c.empty()){
					c.push(a.top());
					a.pop();
					//increment move
						++move;
				}
				else {
					//if top of c is less than top of a, move top of c to a
					if (c.top() < a.top()) {
						a.push(c.top());
						c.pop();
						//increment move
						++move;
					}
					//else top of a is less than top of c, move top of a to c
					else {
						c.push(a.top());
						a.pop();
						//increment move
						++move;
					}
				}
			}
			//move between towers b and c
			else if (move % 3 == 2){
				//if tower b is empty move top of tower c to b
				if (b.empty()){
					b.push(c.top());
					c.pop();
					//increment move
						++move;
				}
				//if tower c is empty move top of tower b to c
				else if (c.empty()){
					c.push(b.top());
					b.pop();
					//increment move
						++move;
				}
				else {
					//if top of b is less than top of c, move top of b to c
					if (b.top() < c.top()) {
						c.push(b.top());
						b.pop();
						//increment move
						++move;
					}
					//else top of c is less than top of b, move top of c to b
					else {
						b.push(c.top());
						c.pop();
						//increment move
						++move;
					}
				}
			}
		}
	}
	std::cout<<"The number of moves was: "<<move<<"\n";
	//Terminate the program
	return 0;
}
