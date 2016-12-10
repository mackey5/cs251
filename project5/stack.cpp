 #include "stack.h"
 #include <utility>

struct node {
  pair<int,int> nums;
  struct node *next;
};


struct node *head;

 Stack::Stack()
 {
	 //TODO: Write the constructor
	 //head = 0;
	 head = NULL;
 }
 
 void Stack::push(pair<int,int> arg)
 {
	 //TODO: Write the push method
	 //pair<int,int> test= pair<int,int>;
	 struct node *add = new node;
	 add->nums = arg;
	 add->next = NULL;
	 if (head == NULL) {
	   add->next = NULL;
	 }
	 else {
	   add->next = head;
	 }
	 head = add;
 }
 
 pair<int,int> Stack::pop()
 {
	 //TODO: Write the pop method
	 if (head == NULL) {
	   //cout << "empty" << endl;
	   pair<int,int> empty = make_pair(-1,-1);
	   return empty;
	 }
	 else {
	   struct node *temp;
	   temp = head;
	   head = head->next;
	   return temp->nums;
	 }
 }

