#include <iostream>
#include <cstdlib>
#include <cstring>

#include "heap.h"

using namespace std;

int *table1;
int *table2;
//BinaryHeap b;

int hash1(int n, int length) {
  return n % length;		//hash function of num mod length
}

int hash2(int n, int length) {
  return n % (length - 1);	//hash function of num mod (length - 1)
}

int loops, length;		//global variables for the length and # of loops

bool LookUp(int table1[], int table2[], int num, int flag) {		//flag is 1 if I want it to print
  int maxLoops = loops;						//variable to not alter the global variable
  int temp = 0;
  
  if (table1[hash1(num, length)] == num) {
    if (flag == 1)
      cout << num << " at T1[" << hash1(num, length) <<  "]" << endl;	//if printing wanted, prints
    return true;
  }
  else if (table2[hash2(num, length)] == num) {
    if (flag == 1)
      cout << num << " at T2[" << hash2(num, length) << "]" << endl;
    return true;
  }
  return false;
}

void insert (int num);

void rehash(int array1[], int array2[], int num) {
  length *= 2;
  int *new1 = new int[length];
  int *new2 = new int[length];
  for (int i = 0; i < length; i++) {		//initialize to 0
    new1[i] = 0;
    new2[i] = 0;
  }
  //int *temp1 = table1;
  //int *temp2 = table2;
  table1 = new1;			//sets table pointer to new
  table2 = new2;

  for (int i = 0; i < length*2; i++) {
    if (i < (length/2)) {
      if (array1[i] != 0) {
        insert(array1[i]);
      }
      if (array2[i] != 0) {
        insert(array2[i]);
      }
    }
  }
    
  insert(num);
}  


void insert(int num) {
 if (LookUp(table1, table2, num, 0)) {
   if (table1[hash1(num, length)] == num) {
     cout << num << " already in T1[" << hash1(num, length) << "]" << endl;
   } else if (table2[hash2(num, length)] == num) {
     cout << num << " already in T2[" << hash2(num, length) << "]" << endl;
   }
   return;
 }
 int maxloops = loops;
 int temp = 0;

 while (maxloops--) {
   if (table1[hash1(num, length)] == 0) {
     table1[hash1(num, length)] = num;
     cout << num << " in T1[" << hash1(num, length) << "]!" << endl;
     return;
   }
   else {
     temp = table1[hash1(num, length)];
     table1[hash1(num, length)] = num;
     cout << num << " in T1[" << hash1(num, length) << "]" << endl;
     num = temp;

     if (table2[hash2(num, length)] == 0) {
       table2[hash2(num, length)] = num;
       cout << num << " in T2[" << hash2(num, length) << "]!" << endl;
       return;
     }
     else {
       temp = table2[hash2(num, length)];
       table2[hash2(num, length)] = num;
       cout << num << " in T2[" << hash2(num, length) << "]" << endl;
       num = temp;
     }
   }
  }
 cout << "maxloop reached" << endl;
 rehash(table1, table2, num);
}

bool remove(int table1[], int table2[], int num) {

    if (table1[hash1(num, length)] == num) {
      cout << num << " out T1[" << hash1(num, length) << "]" << endl;
      table1[hash1(num, length)] = 0;
      return true;
    }
    else if (table2[hash2(num, length)] == num) {
      cout << num << " out T2[" << hash2(num, length) << "]" << endl;
      table2[hash2(num, length)] = 0;
      return true;
    }
    else {
      cout << "no out " << num << endl;
      return false;
    }
}
 
void CuckooHashing() {
    // TODO : add your logic here.
  int num;
  char choice;
  cin >> length >> loops;	//get length and max loops

  table1 = new int[length];		//declare 2 hash tables that are global
  table2 = new int[length];
  for (int i = 0; i < length; i++) {
    table1[i] = 0;
    table2[i] = 0;
  }
  
  while (cin >> choice) {			//Perform constantly
    cin >> num;

    if (choice == 'i') {
       insert(num);
    }
    else if (choice == 'r') {
      bool removed = false;			//removed is false if the number was not removed, true if removed
      removed = remove(table1, table2, num);
      
    }
    else if (choice == 'l'){
      bool lookup = LookUp(table1, table2, num, 1);	//sees if num is in either table
      if (lookup == false) {		//if number not in hashtable, print out no num
        cout << "no " << num << endl;
      }
    }
  }
}

void BinaryHeapi() {
    // TODO : add your logic here.
    int commands, inc;
    BinaryHeap b = BinaryHeap(true);
    char choice;
    cin >> commands;
    while (commands--) {
      cin >> choice;
      if (choice == 'c') {
        cin >> inc;
        if (inc == 1){
          //BinaryHeap b = BinaryHeap(true);
	}
        else if (inc == 2) {
          b = BinaryHeap(false);
	}

      }
      else if (choice == 'i') {
        //insert
	int key, value;
	cin >> key >> value;
	TreeNode *n = new TreeNode(key, value); // = TreeNode(key, value);
	b.insert(n);
      }
      else if (choice == 'p') {
        //peek
	b.peak();
      }
      else if (choice == 'e') {
        //extract
	b.extract();
      }
      else if (choice == 'h') {
        //heapify
	int total, num;
	cin >> total;
	while (total--) {
	  cin >> num;
	  TreeNode *n = new TreeNode(num, 0);
	  b.insert(n);
	}
      }
      else if (choice == 's') {
        cout << b.size() << endl;
      }
    }
}

void HeapSort() {
    // TODO : add your logic here.
  int inc, commands;
  cin >> inc >> commands;
  if (inc == 1)
    inc = 0;
  else
    inc = 1;
  BinaryHeap b = BinaryHeap(inc);
  int command2 = commands;
  while (command2--) {
    int key, value;
    cin >> key >> value;
    TreeNode * n = new TreeNode(key, value);
    b.insert(n);
  }
  char q;
  cin >> q;
  while (commands--) {
    b.extract();
  }
}


/* Main function */
int main(int argc, char** argv) {

    /* Read the option */
    int option;
    std::cin >> option;

    /* Call the respective function */
    switch(option) {

        /* Cuckoo Hashing */
        case 1:
            CuckooHashing();
        break;

        /* Binary Heap */
        case 2:
            BinaryHeapi();
        break;
        
        case 3:
            HeapSort();
        break;

        /* Wrong option */
        default:
            std::cout << "Wrong option" << std::endl;

    }

    /* Close the program */
	return 0;
}

