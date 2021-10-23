/*
Radix sort is a sorting algorithm that sorts the elements by first grouping the individual digits of the same place value. Then, sort the elements according to their increasing/decreasing order.

Suppose, we have an array of 8 elements. First, we will sort elements based on the value of the unit place. Then, we will sort elements based on the value of the tenth place. This process goes on until the last significant place.

Let the initial array be [121, 432, 564, 23, 1, 45, 788]. It is sorted according to radix sort as shown in the figure below.

Working of Radix Sort:
Find the largest element in the array, i.e. max. Let X be the number of digits in max. X is calculated because we have to go through all the significant places of all elements.

In this array [121, 432, 564, 23, 1, 45, 788], we have the largest number 788. It has 3 digits. Therefore, the loop should go up to hundreds place (3 times). Now, go through each significant place one by one.

Use any stable sorting technique to sort the digits at each significant place. We have used counting sort for this.

Sort the elements based on the unit place digits.

arr[] =       [1,  2,  4,  3,  1,  5,  8]

Indexes:       0   1   2   3   4   5   6   7   8
count[] =     [0,  2,  3,  4,  5,  6,  6,  6,  7]

output[] =    [1,  1,  2,  3,  4,  5,  8]
Indexes:       0   1   2   3   4   5   6

arr[] =       [121,  001,  432,  23,  564,  045,  788]

Now, sort the elements based on digits at tens place.

arr[] =       [001, 121, 023, 432, 045, 564, 788]

Finally, sort the elements based on the digits at hundreds place

arr[] =       [001, 023, 045, 121, 432, 564, 788]


PseudoCode:

radixSort(array)
  d <- maximum number of digits in the largest element
  create d arrays of size n of the array

  for i <- 0 to d
    Using counting to Sortsort the elements according to ith place digits

countingSort(array, size)
  max <- find largest element in array
  initialize count array of (max + 1) size with all zeros

  for i <- 0 to max
    find the total count of each unique element and 
    store the count at jth index in count array
  
  for j <- 0 to max
    find the cumulative sum and store it in count array itself
  
  for j <- size down to 0
    decrease count of each element by 1
    and place them in the output array


Time and Space Complexity:
Since radix sort is a non-comparative algorithm, it has advantages over comparative sorting algorithms.
For the radix sort that uses counting sort as an intermediate stable sort, the time complexity is O(d(n+k)).
Here, d is the number cycle and O(n+k) is the time complexity of counting sort.
Thus, radix sort has linear time complexity which is better than O(nlog n) of comparative sorting algorithms.
If we take very large digit numbers or the number of other bases like 32-bit and 64-bit numbers then it can perform in linear time however the intermediate sort takes large space.
This makes radix sort space inefficient. This is the reason why this sort is not used in software libraries.

Best	O(n+k)
Worst	O(n+k)
Average	O(n+k)
Space Complexity	O(max)
*/


// Radix Sort in C++ Programming
#include <iostream>
using namespace std;

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting to Sortsort the elements according to the place digits
void countingSort(int array[], int size, int place) {
  const int max = 9;
  int output[size];
  int count[max + 1];

  for (int i = 0; i < max + 1; i++)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max + 1; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    count[(array[i] / place) % 10]--;
    output[count[(array[i] / place) % 10]] = array[i];
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

// Print an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int array[] = {121, 432, 564, 23, 1, 45, 788};
  int n = sizeof(array) / sizeof(array[0]);
  radixsort(array, n);
  printArray(array, n);
}
