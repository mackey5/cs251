#include <iostream>
#include <string>

using namespace std;
//int totalWords;

// Main function for sorting the file
void extern_sort(string in_fname, string out_fname,
		string chunk_location, int chunk_size);

//merges the sorted arrays
void merge(string *elements, int start, int middle, int end);

// Pick your favorite n*log(n) sorting algorithm here!		
void sort(string *elements, int start, int end); 

// Write a temporary chunk file
void write_chunk(string fileName, int numItems);

// Merges the k temporary files
void k_merge(string chunk_location, string out_fname, int num_chunks);
