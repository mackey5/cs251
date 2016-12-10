 #include <iostream>
 #include <string>
 #include "graph.h"
 
 using namespace std;
 
 // Part 1: Find tickets for an airline passenger
 void P5_part1()
 {
	 string cmd1,cmd2;
	 Graph g;
	 
	 int airports, routes;
	 double price = 0;
	 
	 cin >> airports;
	 cin >> routes;
	 
	 for (int i = 0; i < routes; i++) {
	   cin >> cmd1;
	   cin >> cmd2;
	   cin >> price;
	   g.addRoute(cmd1, cmd2, price);
	 }

	 cin >> cmd1;
	 while(cmd1 != "END") // Find tickets until END appears
	 {
		 cin >> cmd2;
		 g.find_ticket(cmd1, cmd2);
		 cin >> cmd1;
	 }
 }
 
 // Part 2: Perform an eulerian tour of the graph.
 void P5_part2()
 {
	 string cmd1, cmd2;
	 double price;
	 Graph g;
	 
	 int airports, routes;
	 cin >> airports;
	 cin >> routes;
	
	 for (int i = 0; i < routes; i++) {
	   cin >> cmd1;
	   cin >> cmd2;
	   cin >> price;
	   g.addRoute(cmd1,cmd2,price);
	 }
	 cin >> cmd1;
	 g.eulerian_tour(cmd1);
 }
 
 int main()
 {
	 int cmd;
	 cin >> cmd;
	 if(cmd == 1) P5_part1();
	 else if(cmd == 2) P5_part2();
	 return 0;
 }
