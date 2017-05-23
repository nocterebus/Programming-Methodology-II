/*
Justen Yeung 150005872
Hw5 Assignment 4a
implement the shortest-path algorithm. and modify it so that any vertex can be the origin
Dijkstra's shortest-path algorithm pg 625
*/ 
#include <iostream>
#include <vector>
#include <string>
#include <set>
//shortest Path algorithm based of Dijkstra pseudocod
void shortestPath(std::vector<std::vector<int>> theGraph, std::vector<int>& weight, int start){
	//Step1: initialization
	std::set<int> vertexSet;
	if (start >= theGraph.size() or start < 0){
		start = 0;
	}
	std::cout<<"starting vertex is "<<start<<"\n";
	vertexSet.insert(start);
	int n = theGraph.size();
	for (int v = 0; v < n; ++v){
		weight[v] = theGraph[start][v];
	}
	std::cout<<"subsequent vertices are ";
	//Step2 through n
	for (int step = 1; step < n; ++step){
		//find the smalleset weight[v] that is not in vertexSet
		std::set<int> available;
		for (int vert = 0; vert < n; ++vert){
			//check if the vertex is in vertexSet
			bool notinset = true;
			//iterate through vertexSet and check all vertexes that are already in it
			for (std::set<int>::iterator it = vertexSet.begin(); it != vertexSet.end(); ++it){
				if (*it == vert){
					//the vertex is already in vertexSet
					notinset = false;
				}
			}
			//if the vertex is not in the set, add to "not in vertexSet"
			if (notinset){
				available.insert(vert);
			}
		}
		//find vertex with shortest path
		int v = *available.begin();
		for (std::set<int>::iterator it = available.begin(); it != available.end(); ++it){
			if (weight[v] > weight[*it]){
				v = *it;
			}
		}
		//add v to vertexSet
		vertexSet.insert(v);
		std::cout<<v<<" ";
		//check weight[u] for all u not in vertexSet
		for(std::set<int>::iterator u = available.begin(); u != available.end(); ++u){
			if (weight[*u] > weight[v] + theGraph[v][*u] or (weight[*u] == 0 and theGraph[v][*u] != 0 and weight[v] != 0)){
				weight[*u] = weight[v] + theGraph[v][*u];
			}
		}
	}
}


int main (int argc, char** argv){
	//Fig 20-39's graph
	std::vector<std::vector<int>> Graph;
	//vertex zero
	Graph.push_back({0,2,4,6,99,99,99});
	//vertex one
	Graph.push_back({99,0,5,99,3,99,99});
	//vertex two
	Graph.push_back({99,99,0,2,2,99,99});
	//vertex three
	Graph.push_back({99,99,1,0,5,3,99});
	//vertex four
	Graph.push_back({99,99,3,99,0,5,1});
	//vertex five
	Graph.push_back({99,99,99,99,1,0,99});
	//vertex six
	Graph.push_back({99,99,99,99,99,2,0});


	//initial weight array
	std::vector<int> weightArray(Graph.size());
	//request what vertex to begin from
	std::cout<<"What vertex of Fig 20-39 would you like to start from? ex. 0\n(any invalid vertex will result in beginning from vertex 0)\n ";
	int s = 0;
	std::cin>>s;

	shortestPath(Graph, weightArray, s);
	std::cout<<"\nThe final weight array is: ";
	for (int i = 0; i < weightArray.size(); ++i){
		std::cout<<weightArray[i]<<" ";
	}
	return 0;
}









