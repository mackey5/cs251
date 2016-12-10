#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ExternalSort.h"
#include "ExternalSearch.h"

using namespace std;

int main(int argc, const char* argv[])
{	
	if(argv[1] == string("1")) // Run P4 Part 1
	{
		extern_sort(argv[2], argv[3], argv[5], atoi(argv[4])); // arg2 = file to sort, arg3 = outputfile
	}							// arg4 = number of lines per chunk,
								//arg5 = directory to store chunks
	else if(argv[1] == string("2")) // Run P4 Part 2
	{
		int terms = argc;
		string file = argv[2];	//opens output file
		//ofstream output;
		//output.open(file);
		
		for (int i = 3; i < terms; i++) {
		  if (extern_search(file, argv[i])) {
		    cout << "found" << endl;	//\n or not?!
		  }
		  else {
		    cout << "missing" << endl;	//\n or not?!
		  }
		}
		//output.close();
	}
	return 0;
}
