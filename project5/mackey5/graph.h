#include <iostream>
#include <string>
//#include "stack.h"

using namespace std;

class Graph
{
	public:
		// Constructor
		Graph(); 
		
		void addRoute(const string &source, const string &desination, double price);
		// Part 1: Find a ticket using Dijkstra
		void find_ticket(const string &source,const string &destination); 
		
		// Part 2: Try to do a tour of all cities
		void eulerian_tour(const string &source); 
	
	// Add any needed private methods here
	// print method
		void print(int parent[], const string &source);
};
