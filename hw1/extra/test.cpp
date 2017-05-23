/*
ノート
C++
*/
#include <iostream>
#include <vector>

int ksmalli(int k, std::vector<int> arrray, int begin, int end){
	//set p index to first element
	int p = begin;

	std::cout<<arrray[p]<<"is the ";
	//create a switch index
	int s = end;
	//create variables to assist with switching p to s for partitioning
	int val1;
	int val2;
	for (int i = begin+1; i < end; ++i){
		for(int t = i; t <= s; ++t){
			if (arrray[i] >= arrray[p]){
				arrray.push_back(arrray[i]);
				arrray.erase(arrray.begin()+i);
				--s;
			}
		}
	}
	val1 = arrray[p];
	val2 = arrray[s];
	arrray[p] = val2;
	arrray[s] = val1;
	p = s;

	std::cout<<p+1<<" smallest\n";
	//if k = pivot index
	if (k == p){
		return arrray[p];
	}
	//if k < pivot index go to array to left of pivot index
	else if (k < p){
		return ksmalli(k, arrray, begin, p-1);
	}
	//if k > pivot index go to array to right of pivot index
	else if (k > p){
		return ksmalli(k, arrray, p+1, end);
	}
}	


int main(int argc,char** argv){
	// std::cout<<"(0+3)/2 = "<< (0+3)/2<<"\n";
	// std::cout<<"(0+4)/2 = "<< (0+4)/2<<"\n"; 
	// std::cout<<"(0+1)/2 = "<< (0+1)/2<<"\n";
	// std::cout<<"(1+1)/2 = "<< (1+1)/2<<"\n";

	// std::vector<int> vecta = {0,1, 2, 3, 4, 5, 6};
	// for (int i = 0; i < vecta.size(); ++i){
	// 	std::cout<<vecta[i]<<" ";
	// }
	// std::cout<<"\n";
	// vecta.erase(vecta.begin()+2);
	// for (int i = 0; i < vecta.size(); ++i){
	// 	std::cout<<vecta[i]<<" ";
	// }
	// std::cout<<"\n";
	// int va1 = vecta[2];
	// int va2 = vecta[5];
	// for (int i = 0; i < vecta.size(); ++i){
	// 	std::cout<<vecta[i]<<" ";
	// }
	// std::cout<<"\n";





	std::vector<int> vectaa = {12, 13, 15, 2,3,1,0,4,16,11,20,7,5,6,10,9,17,18,8,14,19};
	for (int i = 0; i < vectaa.size(); ++i){
		std::cout<<vectaa[i]<<" ";
	}
	std::cout<<"\n";
	int val = ksmalli(3, vectaa, 0, vectaa.size());
	
	std::cout<<"3 smallest = "<<val<<"\n";





	int a = 0;
	//create a switch index
	int b = vectaa.size();
	int e = vectaa.size();
	//create variables to assist with switching p to s for partitioning
	int v1;
	int v2;
	for (int i = 1; i <= e; ++i){
		for(int t = i; t <= b; ++t){
			if (vectaa[i] >= vectaa[a]){
				vectaa.push_back(vectaa[i]);
				vectaa.erase(vectaa.begin()+i);
				--b;
				std::cout<<"b is "<<b<<"\n";
			}
		}
	}
	v1 = vectaa[a];
	v2 = vectaa[b-1];
	vectaa[a] = v2;
	vectaa[b-1] = v1;
	// a = b-1;
	for (int i = 0; i < vectaa.size(); ++i){
		std::cout<<vectaa[i]<<" ";
	}
	std::cout<<"\nb is "<<b<<"\n";


}