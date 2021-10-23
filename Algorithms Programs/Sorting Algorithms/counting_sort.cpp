/*
Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing). Then doing some arithmetic to calculate the position of each object in the output sequence. Let us understand it with the help of an example. 

Working of Counting Sort: 
let an array of size 7 = [4, 2, 2, 8, 3, 3, 1]

1) Find out the maximum element (let it be max) from the given array.

arr[] =     [4,  2,  2,  8,  3,  3,  1]    // max = arr[3] = 8
Indexes:     0   1   2   3   4   5   6

2) Initialize an count array of length (max + 1) with all elements 0. This array is used for storing the count of the elements in the array.

count[] =     [0,  0,  0,  0,  0,  0,  0,  0,  0]  
Indexes:       0   1   2   3   4   5   6   7   8

3) Store the count of each element at their respective index in count array. For example: if the count of element 3 is 2 then, 2 is stored in the 3rd position of count array. If element "5" is not present in the array, then 0 is stored in 5th position.

count[] =     [0,  1,  2,  2,  1,  0,  0,  0,  1]  
Indexes:       0   1   2   3   4   5   6   7   8

4) Store cumulative sum of the elements of the count array. It helps in placing the elements into the correct index of the sorted array. The modified count array indicates the position of each object in the output sequence.

count[] =     [0,  1,  3,  5,  6,  6,  6,  6,  7]  
Indexes:       0   1   2   3   4   5   6   7   8

5) create output array same as the size of original array. The indexes of updated count array represent the values of original array and the values of updated count array represent the indexes in the output array. So, According to this mapping scheme when we will start placing in the output array. first we decreasing its count by 1 for each element in the value of updated count array and then we place it in the output array.

arr[] =       [4,  2,  2,  8,  3,  3,  1]

Indexes:       0   1   2   3   4   5   6   7   8
count[] =     [0,  1,  3,  5,  6,  6,  6,  6,  7]

Indexes:       0   1   2   3   4   5   6
output[] =    [1,  2,  2,  3,  3,  4,  8]


Pseudo Code: 
Procedure countingSort(array, size)

  max <- find largest element in array
  initialize count array of (max + 1) size with all zeros
  initialize output array same as the size of original array with all zeros.

  for i <- 0 to size
    Find the count of each element of original array
    and Store at their respective index in count array
  
  for j <- 1 to (max + 1)
    Store cumulative sum of the elements of the count array
    and store this cumulative sum in count array itself
  
  for k <- size down to 0
    First decrease count of each element of original array in count array by 1
    and then find the index of each element of the original array in output array

EndProcedure countingSort

Time and Space Complexity:
Overall complexity = O(max)+O(size)+O(max)+O(size) = O(max+size)

Worst Case Complexity: O(n+k)
Best Case Complexity: O(n+k)
Average Case Complexity: O(n+k)
In all the above cases, the complexity is the same because no matter how the elements are placed in the array, the algorithm goes through n+k times.

There is no comparison between any elements, so it is better than comparison based sorting techniques. But, it is bad if the integers are very large because the array of that size should be made.

Space Complexity: The space complexity of Counting Sort is O(max). Larger the range of elements, larger is the space complexity.

Stable Sorting Algorithm: A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input unsorted array.

In-Place Sorting Algorithm: A sorting algorithm is said to be In-Place if it directly modifies the list that is received as input instead of creating a new list that is then modified. In-Place, Sorting Algorithm updates input only through replacement or swapping of elements.

Counting sort is Stable sorting algorithm, but It is not In-Place Sorting Algorithm.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Counting sort in C++ programming
void countSort(int array[], int size) 
{
  int max = getMax(array, size);
  int count[max + 1];
  int output[size];

  // initialize count array of (max + 1) size with all zeros
  for (int i = 0; i < max + 1; ++i) {
    count[i] = 0;
  }

  // Find the count of each element of original array
  // and Store at their respective index in count array
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store cumulative sum of the elements of the count array
  // and store this cumulative sum in count array itself
  for (int i = 1; i < max + 1; i++) {
    count[i] = count[i] + count[i - 1];
  }

  // First decrease count of each element of original array in count array by 1 
  // and then find the index of each element of the original array in output array
  for (int i = size - 1; i >= 0; i--) {
    count[array[i]]--;
    output[count[array[i]]] = array[i];
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int array[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(array) / sizeof(array[0]);
  countSort(array, n);
  printArray(array, n);
}