#include "ExternalSort.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;
//int totalWords = 0;

/*
	External Sorting algorithm.
	Step 1: Reads the input file one chunk at a time
	Step 2: Sorts each chunk
	Step 3: Writes each chunk to a temporary file
	Step 4: Performs a k-wise merge on the temporary files

*/
void extern_sort(string in_fname, string out_fname,
		string chunk_location, int chunk_size)
{
	ifstream inputFile;
	//ofstream outputFile;
	inputFile.open(in_fname);		//declare and open input file
	//outputFile.open(out_fname);		//declare and open output file
	//totalWords = 0;	
	int chunkFiles = 1;
	//cout << chunk_size << endl;
	string output;
	int flag = 1;
	inputFile >> output;
	while (!inputFile.eof()) {
	  int tempChunk = chunk_size;
	  //string output;
	  //inputFile >> output;
	  //if(inputFile.eof()) flag = 0; //if reached EOF, end loop
	  std::ostringstream num;	//creates number for end of file
	  num << std::setw(5) << std:: setfill('0') << chunkFiles;	//creates format for end of file
	  string file = chunk_location + "/chunk" + num.str();	//MAKES FILE
	  ofstream outputFile2;
	  outputFile2.open(file);
	  //cout << file << endl;	//DELETE THIS, DEBUGGING
	  
	  string elements[chunk_size];
	  int i = 0;
	  //tempChunk--;
	  while (tempChunk-- && !inputFile.eof()) {
	    elements[i] = output;
	    inputFile >> output;
	    i++;
	    //totalWords++;
	  }
	  i--;
	  //cout << i << endl;
	  //cout << "sort" << i << endl;
	  sort(elements, 0, i);		//calls sort
	  //cout << "end sort" << endl;
	  for (int i = 0; i < chunk_size; i++) {
	    if (!elements[i].empty()) {
	      outputFile2 << elements[i] << endl;
	    }
	  }
	  outputFile2.close();
	  chunkFiles++;
	}
	//cout << "end sort" << endl;
	//cout << chunkFiles << endl;
	chunkFiles--;
	k_merge(chunk_location, out_fname, chunkFiles);		
	
	inputFile.close();			//close input file
	//outputFile.close();
	//outputFile2.clost();
	return;
} 

void merge(string *elements, int start, int middle, int end) {

	//string *left = elements + start*sizeof(string);		//begginning of left array
	//string *right = elements + (middle+1)*sizeof(string);	//end of left array and begin of right
	//string *end = elements + end*sizeof(string);		//end of right array

	

}
/*
	Your favorite n*log(n) sorting algorithm.
	Be sure that you use an in-place version of the algorithm.
	i.e. It does not generate a new array to return, but rather
	works by swapping elements in the input array.
	
	Possible options:
		-Quicksort
		-Mergesort
		-Heapsort
		
*/

void sort(string *elements, int start, int end) {
	//cout << *elements << endl;
	//elements++;
	//cout << *elements << endl;
	if (end - start <= 0) {
	  return;
	}
	int middle = (start + end)/2;	//gets middle of array
	sort(elements, start, middle); //recursive left side
	sort(elements, middle+1, end); //recusive right side
//merge(elements, start, middle, end);
	string *leftSide = elements + start;	//pointer to beginning of left side
	string *rightSide = elements + middle+1;	//pointer to beginning or right side
	
	int left = start;
	int right = middle+1;
	while (left <= middle && right <= end) {
	  //if (!rightSide) return;
	  string tempLeft = *leftSide;
	  //string temp = *rightSide;
	  
	  if (tempLeft.compare(*rightSide) <= 0) {
	    leftSide++;
	    left++;
	  } else {
	    string temp = *rightSide;
	    //move everything up one
	    //*rightSide = *leftSide;
	    //cout  << "right" << endl;
	    string *resetRight = rightSide;
	    int tempNum = right;
	    int flag = 0;
	    
	    while (right != left) {
	      //cout << "here" << endl;
	      *rightSide = *(rightSide-1);
	      rightSide--;
	      right--;
	      flag = 1;
	    }
	    //*rightSide = *leftSide;
	    //cout << "end" << endl;
	    rightSide = resetRight;
	    *leftSide = temp;
	    leftSide++;
	    rightSide++;
	    left++;
	    right = tempNum;
	    right++;
	    if (flag == 0) right++;
	    middle++;
	    //if (middle == end) return;
	    //if (right == end) return;
	    //cout << "end" << endl;
	    //if (!rightSide) return;
	  }
	}
	return;
}

// Merges the k temporary files
void k_merge(string chunk_location, string out_fname, int num_chunks)
{
	ofstream output;		//outpute file
	output.open(out_fname);

	ifstream files[num_chunks];	//array of pointers to input files

	int k = 1;
	
	for (int i = 0; i < num_chunks; i++) {
	  std::ostringstream num;				//opens all the files needed
	  num << std::setw(5) << std::setfill('0') << k;
	  string test = chunk_location + "/chunk" + num.str();
	  files[i].open(test);	
	  k++;
	}
	
	int empty = 0;					//gets first word of each file
	string top[num_chunks];
	for (int i = 0; i < num_chunks; i++) {
	  files[i] >> top[i];
	}
	//string min = top[0];
	while (empty != num_chunks) {			//finds "min" word, and outputs to output file, continues to end
	  
	  string min = top[0];
	  int where = 0;
	  for (int i = 0; i < num_chunks; i++) {
	    if (min.compare(top[i]) > 0 && !top[i].empty()) {
	      min = top[i];
	      where = i;
	    }
	    else if (min.empty() && !top[i].empty()) {
	      min = top[i];
	      where = i;
	    }
	  }
	  if (!min.empty()) {
	    output << min << endl;	//if string is not empty, outputs to output file
	    //totalWords--;
	  }
	  files[where] >> top[where];			//gets next word from 
	  if (files[where].eof()) { 			//chunk is empty
	    empty++;
	    top[where] = string(); ///what do I need to set this to???
	  }
	}
	//cout << "finished" << endl;
	output.close();
	return;
}
