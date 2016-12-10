#include <iostream>
#include "stack.h"
#include "deque.h"

using namespace std;
//int find(pair<int,int>);

void read_part_1()
{
	//Read the number of commands to execute
    Stack s;
    int n;
    cin >> n;
    
    // Initialize your stack here...
    
    char command1;
    int value1,value2;
    
    while (n--) 
    {
        cin >> command1;
        if (command1 == 'i')
        {
            cin >> value1 >> value2;
	    pair<int,int> arg = make_pair(value1,value2);
	    s.push(arg);            
            // push the values in your stack here.
        }
        if (command1 == 'p')
        {
            // Call Pop here, and print the values.
	    pair<int, int> print = s.pop();
	    if (print.first == -1 && print.second == -1) {
	      cout << "empty\n" << endl;
	    }
	    else {
	      cout << print.first << " " << print.second << endl;
            }
	}
    }
}

void read_part_2()
{
	int num_rows,num_cols;
	Stack s;	
	//Read in the number of rows and cols in the puzzle
	cin >> num_rows >> num_cols;

	//Declare the word search array
	char search[num_rows][num_cols];

	//Fill in the array
	for (int i = 0; i < num_rows; i++) {
	  for (int j = 0; j < num_cols; j++) {
	    char temp;
	    cin >> temp;
	    search[i][j] = temp;
	  }
	}
	//Read in the word we're looking for
	string word;
	cin >> word;
	int length = word.length();
	
	int letter = 0;		//current letter
	int previous = 0;	//flag to see if the letter was found
	int notFound = 0;	//flag to see if the word is found
	//int found = 0;
	int rid = 0;		//flag to see if the previous letter was popped
	Stack old;
	pair<int,int> oldPrev = make_pair(-2,-2);	//old pair, set to (-2,-2) because that is impossible
	//TODO: Part 1b: Run the word search
	while (letter < length && notFound == 0) {
	  previous = letter;				//resets the flag
	  for (int i = 0; i < num_rows; i++) {
	    for (int j = 0; j < num_cols; j++) {
	      if (rid == 1) {				//checks to see if the previous letter was popped
	        i = oldPrev.first;			//if yes, assigns I and J to continue searching from point
		j = oldPrev.second + 1;
		rid = 0;				//resets flag
	      }
	      if (search[i][j] == word[letter]) {	//match found
	          pair<int,int> prev = s.pop();		//pop previous letter cords
		  s.push(prev); 				//push back to stack
		  if (prev.first == -1) {			//if stack is empty, push on to stack
		    pair<int, int> add = make_pair(i,j);
		    s.push(add);
		    letter++;
		  }
		  //if stack is not empty, check to see if it is surrounding the previous letter
		  else if ((i >= prev.first -1 && i <= prev.first +1) && (j >= prev.second -1 && j <= prev.second +1)) {
	            pair<int,int> add = make_pair(i,j); //make pair of first letter and push to stack
	            s.push(add);
		    letter++;
		   }
		}
	   }
	  }
		if (previous == letter) {	//next letter was not found
		  oldPrev = s.pop();		//pops previous letter
		  letter--;
		  rid = 1;			//sets flag to continue
		  if (oldPrev.first == -1 || oldPrev.second == -1) {	//stack empty, word not found
		    notFound = 1;
		  }
		}
	}    
	if (notFound == 1) {			//if the word is not found, print " not found" 
	  cout << "not found\n" << endl;
	 }
		
	//print the stack
	if (notFound == 0) {				//only executes if the word is found	
	  int reverse[word.length()][2];			//puts stack into array to print in correct order
	  for (int i = 0; i < word.length(); i++) {	//
	    pair<int,int> temp = s.pop();
	    if (temp.first == -1) {}
	    else {
	      reverse[i][0] = temp.first;
	      reverse[i][1] = temp.second;
	    }
	  }
	
	  for (int i = length - 1; i >= 0; i--) {
	    cout << reverse[i][0] << " " << reverse[i][1] << endl;
	   }
	 }
}

void read_part_3()
{
	//Read in the number of commands to execute
	Deque d;
	int n, num;
	//Deque d;
	cin >> n;
	char command1,command2;
	while(n--)
	{
		cin >> command1;
		if (command1 == 'e') {
		  cin >> command2 >> num;
		  if (command2 == 'f') {
		  	d.enqueue_front(num);
		  }
		  else if (command2 == 'b') {
		  	d.enqueue_back(num);
		  }
		}
		else if (command1 == 'd') {
		  cin >> command2;
		  if (command2 == 'f') {
		  	int temp = d.dequeue_front();
			if (temp == -1) 
			  cout << "empty\n" << endl;
			else
			  cout << temp << endl;
		  }
		  else if (command2 == 'b') {
		  	int temp = d.dequeue_back();
			if (temp == -1)
			  cout << "empty\n" << endl;
			else
			  cout << temp << endl;
		  }
		}
		else if (command1 == 's') {
			int s = d.get_array_size();
			cout << s << endl;
		}
		// process command1 and command2
	}
}

void read_input()
{
	int project_part;
	//Read the first line of the test case
	cin >> project_part;
	
	switch(project_part)
	{
		case 1:
			read_part_1();
			break;
		case 2:
			read_part_2();
			break;
		case 3:
			read_part_3();
			break;
	}
}

int main()
{
	// Read in the test case
	read_input();
	return 0;
}
