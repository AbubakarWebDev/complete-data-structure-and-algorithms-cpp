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


HeapSort: It is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for the remaining elements until all elements are covered. At the end the array is sorted completely.

Working of Heap Sort:
First we create a Max-Heap, then the largest item is stored at the root node.
Swap: Remove the root element and put at the end of the array (nth position). Put the last item of the tree (heap) at the vacant place.
Remove: Reduce the size of the heap by 1.
Heapify: Heapify the root element again so that we have the highest element at root.
The process is repeated until all the items of the list are sorted.


Some of the important functions are given below that are used in Heapsort:

2) extractMax(): Removes the maximum element from MaxHeap. Time Complexity of this Operation is O(Logn) as this operation needs to maintain the heap property (by calling heapify()) after removing root.

3) increaseKey(): increases value of key. The time complexity of this operation is O(Logn). If the increases key value of a node is smaller than the parent of the node, then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.

5) delete(): Deleting a key also takes O (Logn) time. We replace the key to be deleted with positive infinite (+∞) by calling increaseKey(). After increaseKey(), the positive infinite value must reach root, so we call extractMax() to remove the key.

6) Heapify: It is the process of converting a binary tree into a Heap data structure. A binary tree being a tree data structure where each node has at most two child nodes.

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

Process: The last element is 4.

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

How to Build max-heap From Any Random complete binary tree or array:
To build a max-heap from any tree, we can thus start heapifying each sub-tree from the bottom up and end up with a max-heap after the function is applied to all the elements including the root element.
In the case of a complete tree, the first index of a non-leaf node is given by n/2 - 1. All other nodes after that are leaf-nodes and thus don't need to be heapified.

Time and Space Complexity:
Heap Sort has O(nlog n) time complexities for all the cases ( best case, average case, and worst case). Let us understand the reason why. The height of a complete binary tree containing n elements is log n

As we have seen earlier, to fully heapify an element whose subtrees are already max-heaps, we need to keep comparing the element with its left and right children and pushing it downwards until it reaches a point where both its children are smaller than it.

In the worst case scenario, we will need to move an element from the root to the leaf node making a multiple of log(n) comparisons and swaps.

During the build_max_heap stage, we do that for n/2 elements so the worst case complexity of the build_heap step is n/2*log n ~ nlog n.

During the sorting step, we exchange the root element with the last element and heapify the root element. For each element, this again takes log n worst time because we might have to bring the element all the way from the root to the leaf. Since we repeat this n times, the heap_sort step is also nlog n.

Also since the build_max_heap and heap_sort steps are executed one after another, the algorithmic complexity is not multiplied and it remains in the order of nlog n.

Also it performs sorting in O(1) space complexity. Compared with Quick Sort, it has a better worst case ( O(nlog n) ). Quick Sort has complexity O(n^2) for worst case. But in other cases, Quick Sort is fast. Introsort is an alternative to heapsort that combines quicksort and heapsort to retain advantages of both: worst case speed of heapsort and average speed of quicksort.

Worst Case Complexity: O(nlog n)
Best Case Complexity: O(nlog n)
Average Case Complexity: O(nlog n)
Space Complexity: O(1)

Stable Sorting Algorithm: A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input unsorted array.

In-Place Sorting Algorithm: A sorting algorithm is said to be In-Place if it directly modifies the list that is received as input instead of creating a new list that is then modified. In-Place, Sorting Algorithm updates input only through replacement or swapping of elements.

Heap sort is in-place sorting algorithm, but It is not Stable Sorting Algorithm.
********************************************************************************/


// program for implementation of Heap Sort For Max-Heap
#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int size, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < size && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < size && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, size, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int size)
{
	// Build heap (rearrange array)
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	// One by one extract an element from heap
	for (int i = size - 1; i > 0; i--) 
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}
