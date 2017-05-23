#include "initial.h"
#include "datadus-2.h"
#include "datadus-4.h"
#include "datadus-6.h"
//#include "datadus-8.h"
//#include "datadus-10.h"
//#include "datadus-12.h"
//#include "datadus-16.h"
//#include "datadus-20.h"
//#include "datadus-24.h"

void change (std::vector<int> arr, int a, int b){
	std::vector<std::vector<int>> all;
	all[0] = arr;
}

int main (int argc, char** argv){
	std::vector<int> ba = {1, 2, 3, 4};
	std::vector<std::vector<int>> ars;
	ars[0] = ba;
	//std::vector<int> baa = ars[0];
	for (int i = 0; i < ba.size(); ++i){
		std::cout<<ba[i]<<"\n";
	}

	return 0;
}