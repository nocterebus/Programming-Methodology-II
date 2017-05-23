/*
Justen Yeung 150005872
Hw5 Assignment Extra credit
Eulerian circuit for Fig 20-40
*/ 
#include <iostream>
#include <vector>
#include <stack>
//A eulerian circuit exists only if the graph's vertices have 
//1. an even number of edges
//2. only up to 2 can have an odd number of edges,
bool Eulerian(std::vector<std::vector<int>> theGraph, std::vector<int>& circuit){
	//start with an empty stack and an empty circuit
	//check if the above conditions are satisfied
	int odds = 0;
	int start = 0;
	for (int V = 0; V < theGraph.size(); ++V){
		int edges = 0;
		for (int E = 0; E < theGraph[V].size(); ++E){
			//check how many edges the vertex has
			if (theGraph[V][E] == 1){
				++edges;
			}
		}
		if (edges%2 != 0){
			++odds;
			//save the odd edged vertex to start from
			start = V;
		}
	}
	if (odds > 2){
		return false;
	}

	else {
		//start with an empty stack to trace path taken and a vector for the path
		std::stack<int> took;
		std::vector<int> path;
		//count number of edges using a copy graph
		std::vector<std::vector<int>> copy = theGraph;
		int tedges = 0;
		//check where edges exist
		for (int j = 0; j < copy.size(); ++j){
			for (int k = 0; k < copy.size(); ++k){
				//count existing edge and remove it
				if (copy[j][k] == 1){
					copy[j][k] = 0;
					copy[k][j] = 0;
					++tedges;
				}
			}
		}
		//step counter
		int current = start;
		int trav = current;
		while (path.size() <= tedges){
			//currently we don't know if there is a next vertex we can travel to
			trav = current;
			//from current point find a edge to go to available edge
			for (int e = 0; e < theGraph.size(); ++e){
				if (theGraph[current][e] == 1){
					//save next vertex location (edge to traverse)
					trav = e;
				}
			}
			//if the current vertex has no more edges to traverse, begin backtracking
			if (current = trav){
				path.push_back(took.top());
				current = took.top();
				took.pop();
			}
			//else was an edge to traverse
			else {
				//remove traversed edge, save previous vertex
				theGraph[current][trav] = 0;
				theGraph[trav][current] = 0;
				took.push(current);
				current = trav;
			}
		}
	}
}

int main (int argc, char** argv){
	//Fig 20-39's graph
	std::vector<std::vector<int>> Graph;
	//vertex a
	Graph.push_back({0,1,0,0,1,0,0});
	//vertex b
	Graph.push_back({1,0,1,0,1,1,0});
	//vertex c
	Graph.push_back({0,1,0,1,0,1,1});
	//vertex d
	Graph.push_back({0,0,1,0,0,0,1});
	//vertex e
	Graph.push_back({1,1,0,0,0,1,1});
	//vertex f
	Graph.push_back({0,1,1,0,1,0,1});
	//vertex g
	Graph.push_back({0,0,1,1,1,1,0});
	//path thaken
	std::vector<int> taken;
	if (Eulerian(Graph,taken)){
		std::cout<<"There is a eulerian path. one of them is:\n"{
			for (int i = 0; i < taken.size(); ++i){
				if (taken[i]==0){
					std::cout<<"a ";
				}
				if (taken[i]==1){
					std::cout<<"b ";
				}
				if (taken[i]==2){
					std::cout<<"c ";
				}
				if (taken[i]==3){
					std::cout<<"d ";
				}
				if (taken[i]==4){
					std::cout<<"e ";
				}
				if (taken[i]==5){
					std::cout<<"f ";
				}
				if (taken[i]==6){
					std::cout<<"g ";
				}
			}
		}
	}
	std::cout<<"\n";
	else{
		std::cout<<"there is no eulerian path\n";
	}
	return 0;
}









