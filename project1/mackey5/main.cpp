/**
 *  CS251 - Spring 2016: Project 1 Solution
 *  Dylan Mackey
 */

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
    /* Use either optionA or optionB: */
    int columns;
    /* Option A: input/output using C like notation */
    FILE *inputfile = stdin;
    FILE *outputfile = stdout;

	/* Option B: input/output using C++ like notation would use "cin" and "cout" to read/write to stdin/stdout */
	if (!inputfile) {
	  cout << "Error opening file\n";
	}
	else {
	 //int c = 0;
	 //cin.get(c);
	 //columns = c;
	 cin >> columns;
	 int dashes = 6*columns - 3;
	 for (int j = 0; j < dashes; j++)
	   cout << "-";
	 cout << "\n";
	 
	 while (cin.peek() != EOF) {
	   int numbers[columns];
	   int i = 0;
	   while (i < columns) {
	     cin >> numbers[i];
	     i++;
	   }

	   for (i = 0; i < columns; i++) {
	     if (numbers[i] / 100 >= 1) 
	       cout << numbers[i];
	     else if (numbers[i] / 10 >= 1)
	       cout << " " << numbers[i];
	     else 
	       cout << "  " << numbers[i];
	     if (i != columns-1) 
	       cout << " | ";
	   }
	   cout << "\n";
	   }
	   for (int j = 0; j < dashes; j++) {
	     cout << "-";
	   }
	  }

    /* ------------------------------------ */
    /* process input files and write output */
    /* ------------------------------------ */
	
    /* Close files if using C like notation */
    fclose(inputfile);
    fclose(outputfile);

    /* Exit the program */
 return 0;
}
