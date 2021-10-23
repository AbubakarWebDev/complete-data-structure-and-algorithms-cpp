/*******************************************************************************
A Heap is a special Tree-based data structure in which the tree is a complete binary tree and in which all the nodes of the tree are in a specific order. Heaps can be of two types:

1) Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.

2) Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.

A Binary Heap is a Binary Tree with following properties:

1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

How is Binary Heap represented?
A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as an array. The root element will be at Arr[0].

Arr[(i-1)/2]	Returns the parent node when child present at 'i'
Arr[(2*i)+1]	Returns the left child node when Parent present at 'i'
Arr[(2*i)+2]	Returns the right child node when Parent present at 'i'

Let us Suppose the size of an array "N" then The Range of leaves in an Array = (N / 2) to (N - 1)
Let us Suppose the size of array "N" then The Range of Internal Nodes in an Array = 0 to ((N / 2) - 1)

The traversal method use to achieve Array representation is Level Order. Let See the example below for more concept clarification.

            0
          /   \
         3     6
       /  \   /
      5   9  8

Array Representation:   1   3   6   5   9   8
                        ^   ^   ^   ^   ^   ^
Array indexes:          0   1   2   3   4   5


Applications of Heaps:
1) Heap Sort: Heap Sort uses Binary Heap to sort an array in O(nLogn) time.

2) Priority Queue: Priority queues can be efficiently implemented using Binary Heap because it supports insert(), delete() and extractmax(), decreaseKey() operations in O(logn) time. Binomoial Heap and Fibonacci Heap are variations of Binary Heap. These variations perform union also efficiently.

3) Graph Algorithms: The priority queues are especially used in Graph Algorithms like Dijkstra’s Shortest Path and Prim’s Minimum Spanning Tree.

4) Many problems can be efficiently solved using Heaps. See following for example.
    a) K’th Largest Element in an array.
    b) Sort an almost sorted array/
    c) Merge K Sorted Arrays.


Operations on Min Heap:
1) getMini(): It returns the root element of Min Heap. Time Complexity of this operation is O(1).

2) extractMin(): Removes the minimum element from MinHeap. Time Complexity of this Operation is O(Logn) as this operation needs to maintain the heap property (by calling heapify()) after removing root.

3) decreaseKey(): Decreases value of key. The time complexity of this operation is O(Logn). If the decreases key value of a node is greater than the parent of the node, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.

4) insert(): Inserting a new key takes O(Logn) time. We add a new key at the end of the tree. IF new key is greater than its parent, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.

5) delete(): Deleting a key also takes O (Logn) time. We replace the key to be deleted with minus infinite (-∞) by calling decreaseKey(). After decreaseKey(), the minus infinite value must reach root, so we call extractMin() to remove the key.

6) Heapify: It is the process of converting a binary tree into a Heap data structure. A binary tree being a tree data structure where each node has at most two child nodes.

7) HeapSort: It is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for the remaining elements until all elements are covered. At the end the array is sorted completely.

Deletion in Heap: Given a Binary Heap and an element present in the given Heap. The task is to delete an element from this Heap. The standard deletion operation on Heap is to delete the element present at the root node of the Heap. That is if it is a Max Heap, the standard deletion operation will delete the maximum element and if it is a Min heap, it will delete the minimum element.

Process of Deletion:
Since deleting an element at any intermediary position in the heap can be costly, so we can simply replace the element to be deleted by the last element and delete the last element of the Heap.

1) Replace the root or element to be deleted by the last element.
2) Delete the last element from the Heap.
3) Since, the last element is now placed at the position of the root node. So, it may not follow the heap property. Therefore, heapify the last node placed at the position of root.

Suppose the Heap is a Max-Heap as:
      10
    /    \
   5      3
  / \
 2   4

The element to be deleted is root, i.e. 10.

Process: 
The last element is 4.

Step 1: Replace the last element with root, and delete it.
      4
    /  \
   5    3
  / 
 2   

Step 2: Heapify root.
Final Heap:
      5
    /  \
   4    3
  / 
 2 


Insertion in Heaps: The insertion operation is also similar to that of the deletion process. Given a Binary Heap and a new element to be added to this Heap. The task is to insert the new element to the Heap maintaining the properties of Heap.

Process of Insertion: Elements can be inserted to the heap following a similar approach as discussed above for deletion. The idea is to:

1) First increase the heap size by 1, so that it can store the new element.
2) Insert the new element at the end of the Heap.
3) This newly inserted element may distort the properties of Heap for its parents. So, in order to keep the properties of Heap, heapify this newly inserted element following a bottom-up approach.

Suppose the Heap is a Max-Heap as:
      10
    /    \
   5      3
  / \
 2   4

The new element to be inserted is 15.

Process:
Step 1: Insert the new element at the end.
      10
    /    \
   5      3
  / \    /
 2   4  15

Step 2: Heapify the new element following bottom-up approach.
-> 15 is greater than its parent 3, swap them.
      10
    /    \
   5      15
  / \    /
 2   4  3

-> 15 is again greater than its parent 10, swap them.
      15
    /    \
   5      10
  / \    /
 2   4  3

Therefore, the final heap after insertion is:
      15
    /    \
   5      10
  / \    /
 2   4  3

********************************************************************************/


// C++ Implementation of MinHeap:
#include <iostream>
using namespace std;

class MinHeap
{
    int *array;     // pointer to array of elements in heap
    int capacity;   // maximum possible size of min heap
    int heap_size;  // Current number of elements in min heap

public:
    // Constructor
    MinHeap(int capacity);

    // to heapify a subtree with the root at given index
    void MinHeapify(int);

    // to get index of parent node at index i
    int parent(int i) { return (i - 1) / 2; }

    // to get index of left child of node at index i
    int left(int i) { return (2 * i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2 * i + 2); }

    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    // Returns the minimum key (key at root) from min heap
    int getMin() { return array[0]; }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);

    // Sort Heap Array w.r.t Descending Order and print it
    void heapSort();

    // print complete Heap in the form of array
    void printHeap();
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    array = new int[cap];
    for (int i = 0; i < cap; i++)
    {
        array[i] = 0;
    }
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    array[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && array[parent(i)] > array[i])
    {
        swap(array[i], array[parent(i)]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than array[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    array[i] = new_val;
    while (i != 0 && array[parent(i)] > array[i])
    {
        swap(array[i], array[parent(i)]);
        i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0) {
        return INT_MAX;
    }

    if (heap_size == 1)
    {
        heap_size--;
        return array[0];
    }

    // Store the minimum value, and remove it from heap
    int root = array[0];
    array[0] = array[heap_size - 1];
    array[heap_size - 1] = root;  // for Heap sort
    heap_size--;
    MinHeapify(0);

    return root;
}

// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && array[l] < array[i])
        smallest = l;
    
    if (r < heap_size && array[r] < array[smallest])
        smallest = r;
    
    if (smallest != i)
    {
        swap(array[i], array[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::heapSort()
{
    for (int i = 0; i < capacity; i++)
    {
        if (array[i] != 0)
        {
            extractMax();
        }
    }

    cout << "\n";
    for (int i = 0; i < capacity; i++)
    {
        if (array[i] != 0)
        {
            cout << array[i] << ", ";
        }
    }
    cout << "\n";
}

void MinHeap::printHeap() 
{
    cout << "\n";
    for (int i = 0; i < capacity; i++)
    {
        cout << array[i] << ", ";
    }
    cout << "\n";
}

// Driver program to test above functions
int main()
{
    MinHeap h(6);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);  
    h.printHeap();
    h.heapSort();
    return 0;
}