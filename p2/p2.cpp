/*
Justen Yeung 150005872
Djikstra's Algorithm
Floyd-Marshall's Algorithm
the source node will be 0 and the destination node will be 1
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <random>
#include <set>
////////////////////////////////////////////////////////////////////////////////
//random complete undirected graph generator
std::vector<std::vector<int>> cgraph(int size){
	//initialize an empty table
	std::vector<std::vector<int>> table;
	//make empty rows
	std::vector<int> emp(size,0);
	//push empty rows into table
	for (int r = 0; r < size; ++r){
		table.push_back(emp);
	}
	for (int i = 0; i < size; ++i){
		for (int j = i+1; j < size; ++j){
			//seed for random number generator
			int seed = std::chrono::system_clock::now().time_since_epoch().count();
			//random number generator
			std::default_random_engine gen(seed);
			//additional randomizer
			std::poisson_distribution<int> connect(1000);
			//additional randomizer
			int a = rand();
			//additional randomizer
			int connection = connect(gen);
			//random edge weight
			int rando = abs((a*connection)%5);
			//edge value from [1,5]
			rando = rando + 1;
			//undirected
			table[i][j] = rando;
			table[j][i] = table[i][j];
		}
	}
	return table;
}
////////////////////////////////////////////////////////////////////////////////
//Dijkstra
std::vector<int> Dijkstra(std::vector<std::vector<int>> theGraph, std::vector<int>& weight, int source, int& runt){
	//will return an edge to graph
	//will alter a weight graph
	//Step1: initialization
	
	//initialize visited verticies set
	std::set<int> vertexSet;
	//initialize all edgeto's to source(even if they won't connected)
	//after the function completes, all edge to's will be corrected
	std::vector<int> edgeto(theGraph.size(),source);
	//check source node value to see if it is in range
	if (source >= theGraph.size() or source < 0){
		source = 0;
	}
	//source has been visited so include in vertexSet
	vertexSet.insert(source);
	int n = theGraph.size();
	//create initial weight graph
	for (int v = 0; v < n; ++v){
		weight[v] = theGraph[source][v];
	}
	//Step2 through n
	for (int step = 1; step < n; ++step){
		//find the smalleset weight[v] that is not in vertexSet and currently reachable
		std::set<int> available;
		for (int vert = 0; vert < n; ++vert){
			//check if current vertex is in vertexSet
			bool notinset = true;
			//iterate through vertexSet and check if current indexed vertex already in vertexSet
			for (std::set<int>::iterator it = vertexSet.begin(); it != vertexSet.end(); ++it){
				if (*it == vert){
					//the vertex is already in vertexSet
					notinset = false;
				}
				//increment runtime;
				++runt;
			}
			//if the vertex is not in the set, add to "available" verticies
			if (notinset){
				available.insert(vert);
			}
		}
		//find vertex with shortest path, initialize "next" to lowest vertex index value
		int v = *available.begin();
		//make an edge to vertex to keep track of edge taken
		int from = *available.begin();
		//iterate through available vertices and check their weights in current weight graph
		for (std::set<int>::iterator it = available.begin(); it != available.end(); ++it){
			//note *it is the vertex index value and not the weight
			if (weight[v] > weight[*it]){
				v = *it;
			}
			//increment runtime
			++runt;
		}
		//add v to vertexSet
		vertexSet.insert(v);
		//check weight[u] for all u not in vertexSet
		for(std::set<int>::iterator u = available.begin(); u != available.end(); ++u){
			//*u is unvisited vertex index value
			if (weight[*u] > weight[v] + theGraph[v][*u]){
				//update weights with new vertex to branch from
				weight[*u] = weight[v] + theGraph[v][*u];
				//update edgeto graph with new vertex
				edgeto[*u] = v;
			}
			//increment runtime
			++runt;
		}
	}
	//return edge to graph;
	return edgeto;
}

//Find "hops" from the source node (0) to the destination node (1) using an edge to graph
float hopd(std::vector<int> edto, int source, int dest){
	//initialize hops to 0
	float hop = 0;
	//begin from destination and trace back to source
	for (int vertex = dest; vertex != source; vertex = edto[vertex]){
		hop = hop + 1.0;
	}
	return hop;
}
////////////////////////////////////////////////////////////////////////////////
//Floyd-Marshall (return a shortest "next to" graph)
std::vector<std::vector<int>> Floyd(std::vector<std::vector<int>> theGraph, int& runt){
	//initialize a "next to" graph
	//this will determine the next node in the shortest path to designated node
	std::vector<int> empty;
	for (int n = 0; n < theGraph.size(); ++n){
		empty.push_back(n);
	}
	std::vector<std::vector<int>> next(theGraph.size(), empty);
	//begin finding minimum weight matrix along with filling "next to" matrix
	for (int mid = 0; mid < theGraph.size(); ++mid){
		for (int i = 0; i < theGraph.size(); ++i){
			for (int j = 0; j < theGraph.size(); ++j){
				if (theGraph[i][j] > theGraph[i][mid] + theGraph[mid][j]){
					theGraph[i][j] = theGraph[i][mid] + theGraph[mid][j];
					//keep track of shortest path to j from i
					next[i][j] = next[i][mid];
				}
				++runt;
			}
		}
	}
	return next;
}
//hop counter and also alters a distance tracker
int hopf(std::vector<std::vector<int>> theGraph, std::vector<std::vector<int>> next, int source, int dest){
		//initialize hops to 0
		int h = 0;
		//traverse graph while keeping track of hops made
		while (source != dest){
			int n =  next[source][dest];
			source = n;
			++h;
		}
		return h;
}
//distance tracker
int disf(std::vector<std::vector<int>> theGraph, std::vector<std::vector<int>> next, int source, int dest){
		//initialize distance to 0
		int d = 0;
		//traverse graph while keeping track of distance traveled
		while (source != dest){
			int n =  next[source][dest];
			d = d + theGraph[source][n];
			source = n;
		}
		return d;
}


//CHANGE THIS NUMBER TO CHANGE NUMBER OF SIMULATIONS AT EACH SIZE	
int hun = 100;
int main (int argc, char** argv){
	std::cout<<"The source vertex will be 0 and the destination vetex will be 1\n ";
	int s = 0;//source
	int d = 1;//destination
	//initialize dijkstra's hop and distances
	float HOPD = 0; 
	float DISD = 0;
	int runD = 0;
	//initialize floyd-marshall's hop and distances
	float HOPF = 0; 
	float DISF = 0;
	int runF = 0;
	//graphs ranging from size 64 to 8192
	std::cout<<"size	dist. av.	hops av.	run av.\n";
	for (int size = 64; size <= 8192; size = size*2){
		//initialize dijkstra's variables
		//weight array
		std::vector<int> weightArray(size);
		HOPD = 0;//reset number of hops
		DISD = 0;//reset distance
		runD = 0;
		//initialize floyd-marshall's variables
		HOPF = 0;//reset number of hops
		DISF = 0;//reset distance
		runF = 0;
		//hun graphs at each size
		for(int sim = 0; sim < hun; ++sim){
			//Graph
			std::vector<std::vector<int>> Graph = cgraph(size);
			//dijkstra's
			std::vector<int> eto = Dijkstra(Graph, weightArray, s, runD);
			//add results to hop and distance trackers
			HOPD = HOPD + hopd(eto, s, d);
			DISD = DISD + weightArray[d];
			//floyd-marshall's
			std::vector<std::vector<int>> nxt = Floyd(Graph, runF);
			HOPF = HOPF + hopf(Graph,nxt,s,d);
			DISF = DISF + disf(Graph,nxt,s,d);
		}
		//divide hop and distance trackers by simulations to get average
		HOPD = HOPD / hun;
		DISD = DISD / hun;
		runD = runD / hun;
		HOPF = HOPF / hun;
		DISF = DISF / hun;
		runF = runF / hun;

		std::cout<<"d "<<size<<"	";
		std::cout<<DISD<<"		"<<HOPD<<"		"<<runD<<"\n";
		std::cout<<"f "<<size<<"	";
		std::cout<<DISF<<"		"<<HOPF<<"		"<<runF<<"\n";
	}
	return 0;
}