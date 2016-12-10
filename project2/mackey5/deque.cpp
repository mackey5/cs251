#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

using namespace std;
//int hello = malloc(10);
int *array;
#define start = 10;
int resize = 1;
//array = (int*)calloc(10, sizeof(array));
//int array[10];

Deque::Deque()
{
	//TODO: Write the Deque constructor
	//NOTE: Start with an array of size 10!
	//int array[] = malloc(sizeof(int)*10);
	array = NULL;
	array = (int*)calloc(10,sizeof(int));

	for (int i = 0; i < 10; i++) {
	  array[i] = -1;
	}
}

void Deque::enqueue_front(int n)
{
	//TODO: Front enqueue method
	//int size = get_array_size();
	if (is_full()) {
	  cout << "full" << endl;
	  reallocate();	
	}
	//check to reallocate first
	int insert = 0;
	while (array[insert] != -1) {
	  insert++;
	}
	for (int i = insert; i >=0; i--) {
	  array[i] = array[i - 1];
	  //array[insert-1] = -1;
	}
	array[0] = n;
	//array[size] = -1;
	//if (is_full())
	  //cout << "full" << endl;
	//for (int i = 0; i < 20; i++) {
	//  cout << array[i] << " ";
	//}
	
}

void Deque::enqueue_back(int n)
{
	//TODO: Back enqueue
	if (is_full())
	  reallocate();
	int size = get_array_size();
	for (int i = 0; i < size; i++) {
	  if (array[i] == -1) {
	    array[i] = n;
	    break;
	  }
	}
	//for (int i = 0; i < size; i++) {
	//  cout << array[i] << " ";
	//}
}

int Deque::dequeue_front()
{
	//TODO: front dequeue
	int number = array[0];
	int size = get_array_size();
	for (int i = 0; i < size; i++){
	    array[i] = array[i+1];
	}
	array[size-1] = -1;	
	return number;
}

int Deque::dequeue_back()
{
	//TODO: back dequeue
	int size = get_array_size();
	for (int i = 0; i < size; i++) {
	  if (array[i+1] == -1) {
	    int temp = array[i];
	    array[i] = -1;
	    return temp;
	  }
	}
	return -1;
}

bool Deque::is_full()
{
	//TODO: Determine if you need to double the array
	int size = get_array_size();
	//int count = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] == -1) {
		  return false;
		}
	}	  
	return true;
}

void Deque::reallocate()
{
	//TODO: Correctly reallocate memory for the deque. Use the doubling strategy.
	int size = get_array_size();
	int newSize = size * 2;
	
	//int arrayNew[newSize];
	array = (int*) realloc(array, newSize * sizeof *array);
	for (int i = size; i < newSize; i++) {
	  array[i] = -1;
	}
	resize++;
	/*
	for (int i = 0; i < newSize; i++) {
	  if (i < size)
	    arrayNew[i] = array[i];
	  else
	    arrayNew[i] = -1;
	}
	*/
}

int Deque::get_array_size()
{
	int total = 10;
	int i = resize;
	while (i != 1) {
	  total *= 2;
	  i--;
	}
	return total;
}
