#include <iostream>
#include <cstdlib>

#include "heap.h"

using namespace std;
int heapSize;
int max;
TreeNode * root;
TreeNode * lastNode();

    bool TreeNode::operator < (const TreeNode& anotherNode) {
        // TODO : add your logic here.
        return false;
    }
    
    bool TreeNode::operator > (const TreeNode& anotherNode) {
        // TODO : add your logic here.
        return false;
    }
    //TreeNode * lastNode(); 
    /*
    * If isMaxHeap == true, initialize as a MaxHeap.
    * Else, initialize as a MinHeap.
    */
    BinaryHeap::BinaryHeap(bool isMaxHeap) {
        // TODO : add your logic here.
	heapSize = 0;
	root = NULL;
	if (isMaxHeap) {
	  max = 1;
	} else {
	  max = 0;
	}
    }
    
    TreeNode * BinaryHeap::lastNode() {
      int size = heapSize + 1;
      int arraySize = 0;
      TreeNode  *current = root;
      //cout << root << endl;
      //cout << current << endl;
      //cout << current << endl;
      while (size) {
        arraySize++;
	size = size / 2;
      }
      size = heapSize + 1;
      int binary[arraySize];
      for (int i = 0; i < arraySize; i++) {
        binary[i] = 0;
      }

      int i = 0;
      while (size) {
        if (size % 2 == 1) {
	  binary[i] = 1;
	} else if (size % 2 == 0) {
	  binary[i] = 0;
	}
	i++;
	size = size / 2;
      }

      for (int j = arraySize - 2; j >= 0; j--) {
        if (binary[j] == 0) {
	  //current = current->leftChild;
	  if (current->leftChild == NULL) {
	    //cout << "left1" << endl;
	    return current;
	  } else {
	    //cout << "left2" << endl;
	    current = current->leftChild;
	  }
	  //cout << current << endl;
	  //cout << "went left" << endl;
	} else if (binary[j] == 1) {
	  if (current->rightChild == NULL) {
	    //cout << "right1" << endl;
	    return current;
	  } else {
	    //cout << "right2" << endl;
	    current = current->rightChild;
	  }
	  //cout << "went right" << endl;
	}
      }
	//cout << current << endl;
	return current;
    }

    //prints root of heap
    void BinaryHeap::peak() {
      if (root == NULL) {
        cout << "empty" << endl;
      } else {
        cout << root->key << " " << root->value << endl;
      }
    }

    //called on each command if it is a maxHeap
    void BinaryHeap::upHeapMax(TreeNode * previous) {
     
     TreeNode * current;
     if (previous->rightChild == NULL) {
       current = previous->leftChild;
     } else {
       current = previous->rightChild;
     }

     if (previous->key > current->key) {		//if heap order already ok, return
       return;
     }
     else {
       while (current->parent != NULL){
         if (previous->key > current->key) {
	   return;
	 }
	 else {					//swap current w/parent 
           int tempKey = previous->key;
	   int tempValue = previous->value;
	   previous->key = current->key;
	   previous->value = current->value;
	   current->key = tempKey;
	   current->value = tempValue;
	   current = previous;
	   previous = previous->parent;
	 }
       }
     }
     return;
    }

    void BinaryHeap::upHeapMin(TreeNode * previous) {
      TreeNode * current;
      if (previous->rightChild == NULL) {
        current = previous->leftChild;
      } else {
        current = previous->rightChild;
      }

      if (previous->key < current->key) {
        return;
      } else {
        while (current->parent != NULL) {
	  if (previous->key < current->key) {
	    return;
	  } else {
	    int tempKey = previous->key;
	    int tempValue = previous->value;
	    previous->key = current->key;
	    previous->value = current->value;
	    current->key = tempKey;
	    current->value = tempValue;
	    current = previous;
	    previous = previous->parent;
	  }
	}
      }
    }
    //called on each command if it is a minHeap
    void BinaryHeap::downHeapMax(TreeNode * previous) {
      int change = 1; 
      if (previous->leftChild == NULL) {
        return;
      }
      if (previous->key > previous->leftChild->key && previous->rightChild == NULL) {
        return;
      } else {
         while ((previous->leftChild != NULL || previous->rightChild != NULL) && change == 1) {
           change = 0;
	   if (previous->leftChild != NULL && previous->key < previous->leftChild->key && previous->leftChild->key > previous->rightChild->key) {
	     int tempKey = previous->key;
	     int tempValue = previous->value;
	     previous->key = previous->leftChild->key;
	     previous->value = previous->leftChild->value;
	     previous->leftChild->key = tempKey;
	     previous->leftChild->value = tempValue;
	     previous = previous->leftChild;
	     change = 1;
	    }	   
	   else if (previous->rightChild != NULL && previous->key < previous->rightChild->key && (previous->key + previous->rightChild->key > previous->key + previous->leftChild->key)) {
	     int tempKey = previous->key;
	     int tempValue = previous->value;
	     previous->key = previous->rightChild->key;
	     previous->value = previous->rightChild->value;
	     previous->rightChild->key = tempKey;
	     previous->rightChild->value = tempValue;
	     previous = previous->rightChild;
	     change = 1;
	   }
	 }
	 }
	 return;
    }
    void BinaryHeap::downHeapMin(TreeNode * previous) {
      int change = 1;
      if (previous->leftChild == NULL) {
        return;
      }
      if (previous->key < previous->leftChild->key && previous->rightChild == NULL) {
        return;
      } else {
        while (change == 1) {
	  change = 0;
	  //cout << previous->leftChild->key << endl;
	  if (previous->leftChild != NULL && previous->key > previous->leftChild->key && (heapSize == 2 || previous->rightChild == NULL || previous->leftChild->key < previous->rightChild->key)) {
	    int tempKey = previous->key;
	    int tempValue = previous->value;
	    previous->key = previous->leftChild->key;
	    previous->value = previous->leftChild->value;
	    previous->leftChild->key = tempKey;
	    previous->leftChild->value = tempValue;
	    previous = previous->leftChild;
	    change = 1;
	    if (heapSize == 2)
	      return;
	  }
	  else if (previous->rightChild != NULL && previous->key > previous->rightChild->key && heapSize >= 3 && (previous->rightChild->key < previous->leftChild->key)) {
	    int tempKey = previous->key;
	    int tempValue = previous->value;
	    previous->key = previous->rightChild->key;
	    previous->value = previous->rightChild->value;
	    previous->rightChild->key = tempKey;
	    previous->rightChild->value = tempValue;
	    previous = previous->rightChild;
	    change = 1;
	  }
	 }
	}
	return;
    }
    /*
    * Given an array of TreeNode elements, create the heap.
    * Assume the heap is empty, when this is called.
    */
    void BinaryHeap::heapify(int size, TreeNode * nodes) {
        // TODO : add your logic here.
	
    }
    
    /*
    * insert the node into the heap.
    * return false, in case of failure.
    * return true for success.
    */


    bool BinaryHeap::insert(TreeNode * node) {
        // TODO : add your logic here.
	if (root == NULL) {
	  root = node;
	  root->key = node->key;
	  root->value = node->value;
	  root->parent = NULL;
	  heapSize++;
	  //cout << root << endl;
	  return true;
	}
	else {
	  //TreeNode * current = lastNode();
	  TreeNode * current = lastNode();
	  //cout << current << endl;
	  if (heapSize % 2 == 1) {
	    current->leftChild = node;
	    current->leftChild->key = node->key;
	    current->leftChild->value = node->value;
	    current->leftChild->parent = current;
	    //current = current->leftChild;
	  } else if (heapSize % 2 == 0) {
	    current->rightChild = node;
	    current->rightChild->key = node->key;
	    current->rightChild->value = node->value;
	    current->rightChild->parent = current;
	    //current = current->rightChild;
	  }
	  heapSize++;
	  if (max == 1)
	    upHeapMax(current);
	  else if (max == 0)
	    upHeapMin(current);
	  //cout << root->key << " " << root->value << endl;
	  //cout << current->leftChild->key << " " << current->leftChild->value << endl;
	  return true;
	  }

        return false;
    }
    
    /*
     * Return the minimum element of the min-heap [max element of max-heap]
     */
    TreeNode * BinaryHeap::extract() {
        // TODO : add your logic here.
	
        cout << root->key << " " << root->value << endl;
	if (root->leftChild == NULL){
	  root = NULL;
	  heapSize--;
	  return NULL;
	}
	heapSize--;
	TreeNode * last = lastNode();
	heapSize++;
	/*
	if (last->rightChild != NULL) {
	  last = last->rightChild;
	} else if (last->leftChild != NULL) {
	  last = last->leftChild;
	}*/
	root->key = last->key;
	root->value = last->value;
	last->rightChild = NULL;
	last->leftChild = NULL;
	heapSize--;
	//last = NULL;
	delete last;
	last = NULL;
	/*
	if (last == NULL) {
	  cout << "yes" << endl;
	  cout << last << endl;
	}*/
	//heapSize--;
	if (max == 1)
	  downHeapMax(root);
	else if (max == 0)
	  downHeapMin(root);
	return NULL;
    }
    
    /*
     * Return the current size of the Heap.
     */
    int BinaryHeap::size() {
        // TODO : add your logic here.
        return heapSize;
    }
    
    void heapSort(TreeNode * elements, bool isReverseOrder) {
        // TODO : add your logic here.
    }
