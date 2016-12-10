#ifndef __HEAP_H__
#define __HEAP_H__
#include <string>

      
class TreeNode {
    public:
    int value;
    int key;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode* parent;
    
    TreeNode(int key, int value) {
        this->key = key;
        this->value = value;
        leftChild = NULL;
        rightChild = NULL;
	parent = NULL;
    }
    
    /*
     * @Overload operator
     */
    bool operator < (const TreeNode& anotherNode);
    
    /*
     * @Overload operator
     */
    bool operator > (const TreeNode& anotherNode);
    
};


class BinaryHeap {
    private:
    bool isMaxHeap;
    TreeNode * root;
    int heapSize, max;
    
    public:
    /*
    * If isMaxHeap == true, initialize as a MaxHeap.
    * Else, initialize as a MinHeap.
    */
    BinaryHeap(bool isMaxHeap);
    
    /*
    * Given an array of TreeNode elements, create the heap.
    * Assume the heap is empty, when this is called.
    */
    void heapify(int size, TreeNode * nodes);
    
    /*
    * insert the node into the heap.
    * return false, in case of failure.
    * return true for success.
    */
    
    //returns parent of the last node
    TreeNode * lastNode();
    void swap(TreeNode * previous, TreeNode * current);    
    //upheap if max heap
    void upHeapMax(TreeNode * node);

    void upHeapMin(TreeNode * node);
    
    //downheap if min heap
    void downHeapMax(TreeNode * node);

    void downHeapMin(TreeNode * node);
    
    //inserts new node at last inserting point
    bool insert(TreeNode * node);
    
    //returns root
    void peak();
    
    /*
     * Return the minimum element of the min-heap [max element of max-heap]
     */
    TreeNode * extract();
    
    /*
     * Return the current size of the Heap.
     */
    int size();
};

#endif
