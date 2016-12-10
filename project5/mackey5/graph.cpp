#include <iostream>
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "graph.h"
//#include "stack.h"

using namespace std;

/*
	Graph class for use in Project 5.
	
	This provided code does not include any specific data structure
	for storing a graph, only a list of methods that will be called 
	from main. Based on the project handout and the lecture slides,
	select a method for storing the graph and implement it here.

*/

// Constructor for Graph. Read in data from the input
// and set up your data structures here.
int totalAirports;
double graph[2000][2000];
string airports[2000];
Graph::Graph()
{
	totalAirports = 0;
	for (int i = 0; i < 2000; i++) {
	  for (int j = 0; j < 2000; j++) {
	    graph[i][j] = 0;
	    //cout << "here" << endl;
	  }
	}
	for (int i = 0; i < 2000; i++) {
	  airports[i] = "";
	}
}

//adds route to the grapgh
void Graph::addRoute(const string &source, const string &desination, double price) {
	int start = 0;
	int end = 0;
	int flag = 0;
	for (int i = 0; i < totalAirports; i++) {		//sees if airport is already in the graph
	  if (airports[i].compare(source) == 0) {
	    start = i;
	    flag = 1;
	    break;
	  }
	}
	if (flag == 0) {				//airport not in graph, add it
	  airports[totalAirports] = source;
	  start = totalAirports;
	  totalAirports++;
	}
	flag = 0;
	for (int i = 0; i < totalAirports; i++) {		//sees if airport is in graph
	  if (airports[i].compare(desination) == 0) {
	    end = i;
	    flag = 1;
	    break;
	  }
	}
	if (flag == 0) {				//airport not in graph, add it
	  airports[totalAirports] = desination;
	  end = totalAirports;
	  totalAirports++;
	}
	graph[start][end] = price;		//assignes edge value
	graph[end][start] = price;
	//cout << airports[start] << endl;
	//cout << airports[end] << endl;
	//cout << graph[start][end] << endl;
/*	
	for (int i = 0; i < 2000; i++) {
	  for (int j = 0; j < 2000; j++) {
	    if (graph[i][j] != -1) {
	      cout << graph[i][j] << endl;
	      cout << airports[i] << endl;
	    }
	  }
	}
*/	

}

// Code for part 1. Print out the sequence of airports and price
// of the trip.
void Graph::find_ticket(const string &source,const string &destination)
{
	double distance[totalAirports];			//shortest distance array
	bool visited[totalAirports];			//if airport visited
	string route[totalAirports];			//route of shortest visited
	
	//Stack children[totalAirports];

	int sourceNum = -1, destNum = -1;
	for (int i = 0; i < totalAirports; i++) {		//find source airport
	  route[i] = source + " ";					//sets route to beginning source
	  if (airports[i].compare(source) == 0) {
	    sourceNum = i;
	    break;
	  }
	}
	
	for (int i = 0; i < totalAirports; i++) {		//find destination airport
	  if (airports[i].compare(destination) == 0) {
	    destNum = i;
	    break;
	  }
	}
	if (sourceNum == -1 || destNum == -1) {		//airports not in graph
	  cout << "not possible" << endl;
	  return;
	}

	int numNotVisited = totalAirports;	//total number of not visited nodes

	for (int i = 0; i < totalAirports; i++) {	//sets all current distance values
	  if (i == sourceNum) {
	    distance[i] = 0;
	    visited[i] = 0;
	  } else {
	    distance[i] = std::numeric_limits<double>::infinity();		//all others to infinited
	    visited[i] = 0;
	  }
	}
	//int n;	
	while (numNotVisited != 0) {
	  int n = -1;
	  double shortest = std::numeric_limits<double>::infinity();
	  for (int i = 0; i < totalAirports; i++) {
	      if (visited[i] == 0 && shortest > distance[i]) {		//make sure airport not visted, and it has a distance to it
	        n = i;
		shortest = distance[i];
	    }
	  }	  
	  if (shortest == std::numeric_limits<double>::infinity()) {	//not possible to reach airport
	    break;
	  }
	  for (int i = 0; i < totalAirports; i++) {
	    if (visited[i] == 0 && graph[n][i] != 0) {		//not visited node and route exists
	      if (distance[i] > distance[n] + graph[n][i] && graph[n][i] != 0) {	//if new distance is shorter than old
		route[i] = route[n] + airports[i] + " ";
		distance[i] = distance[n] + graph[n][i];
		}
	    }
	   }
	   visited[n] = 1;	//node has been visited
	   numNotVisited--;
	 }
	if (distance[destNum] == std::numeric_limits<double>::infinity()) {		//if not able to reach airport, not possible
	  cout << "not possible" << endl;
	} else {
	  std::cout << std::setprecision(2) << std::fixed;
	  cout << route[destNum] << distance[destNum] << endl;
	}
}

// Code for part 2. Print out the tour sequence or "not possible"
// if not all cities can be visited.
void Graph::eulerian_tour(const string &source) {
	double distance[totalAirports];	//min distance array
	bool visited[totalAirports];	//visted array
	int parent[totalAirports];	//parent array
	int sourceNum = -1;		//variable for source airport
	//int children[totalAirports];
	//int parent[totalAirports];
	//Stack children[totalAirports];

	for (int i = 0; i < totalAirports; i++) {
	  if (airports[i].compare(source) == 0) {
	    sourceNum = i;
	    break;
	  }
	}
	if (sourceNum == -1) {			//starting airport doesnt exist
	  cout << "not possible" << endl;
	  return;
	}
	//parent[sourceNum] = -1;
	for (int i = 0; i < totalAirports; i++) {
	  if (i == sourceNum ) {
	    distance[i] = 0;
	    parent[i] = -1;
	  } else {
	    distance[i] = std::numeric_limits<double>::infinity();
	    parent[i] = -1;
	  }
	  visited[i] = 0;
	  //parent[i] = -1;
	}
	int numNotVisited = totalAirports;
	while (numNotVisited != 0) {
	  
	  int n = -1; 
	  double shortest = std::numeric_limits<double>::infinity();
	  for (int i = 0; i < totalAirports; i++) {
	    if (visited[i] == 0 && shortest > distance[i]) {
	      n = i;
	      shortest = distance[i];
	    }
	  }
	  if (shortest == std::numeric_limits<double>::infinity()) break; 	//airport not found
	  //cout << n << endl;
	  for (int i = 0; i < totalAirports; i++) {
	    if (visited[i] == 0 && graph[n][i] != 0) {
	      if (distance[i] > distance[n] + graph[n][i] && graph[n][i] != 0) {
	        distance[i] = distance[n] + graph[n][i];
		parent[i] = n;
		}
       	     }
	  }
	  visited[n] = 1;
	  numNotVisited--;
	}
	for (int i = 0; i < totalAirports; i++) {			//not all airports connected
	  if (distance[i] == std::numeric_limits<double>::infinity()) {
	    cout << "not possible" << endl;
	    return;
	  }
	}
	//cout << source << endl;
	print(parent, source);	
}

void Graph::print(int parent[], const string &source) {
	int sourceNum;
	
	cout << source << endl;
	for (int i = 0; i < totalAirports; i++) {		//find source number
	  if (airports[i].compare(source) == 0) {
	    sourceNum = i;
	    break;
	  }
	}
	
	string children[totalAirports];			//array for children of current node
	/*for (int i = 0; i < totalAirports; i++) {
	  children[i] = "";
	}*/
	int totalChildren = 0;
	for (int i = 0; i < totalAirports; i++) {	//finds all children of current node
	  if (parent[i] == sourceNum) {
	    children[totalChildren] = airports[i];
	    totalChildren++;
	  }
	}
	for (int i = 0; i < totalChildren; i++) {	//sorts all the children
	  for (int j = 0; j < totalChildren-1; j++) {
	     if (children[j].compare(children[j+1]) > 0) {
	      string temp = children[j];
	      children[j] = children[j+1];
	      children[j+1] = temp;
	    }
	  }
	}
	
	for (int i = 0; i < totalChildren; i++) {	//call recusivly on all children of each node
	  Graph::print(parent,children[i]);
	}
}
