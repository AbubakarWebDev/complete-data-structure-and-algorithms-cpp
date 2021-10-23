#include <iostream>
#include <algorithm>
using namespace std;

/*

Selection sort is a simple sorting algorithm. This sorting algorithm is an in-place comparison-based algorithm in which the list is divided into two parts, the sorted part at the left end and the unsorted part at the right end. Initially, the sorted part is empty and the unsorted part is the entire list.

The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array. This process continues moving unsorted array boundary by one element to the right.

This algorithm is not suitable for large data sets as its average and worst case complexities are of Ο(n2), where n is the number of items.

Example: arr[] = 64 25 12 22 11

Find the minimum element in arr[0...4]
and place it at beginning
11 25 12 22 64

Find the minimum element in arr[1...4]
and place it at beginning of arr[1...4]
11 12 25 22 64

Find the minimum element in arr[2...4]
and place it at beginning of arr[2...4]
11 12 22 25 64

Find the minimum element in arr[3...4]
and place it at beginning of arr[3...4]
11 12 22 25 64 



How Selection Sort Works?

1) Set the first element of Array as minimum.
    64 25 12 22 11
    ^

2) Compare minimum with the second element. If the second element is smaller than minimum, assign the second element as minimum otherwise do nothing.
    64 25 12 22 11 
       ^

3) Compare minimum with the third element. Again, if the third element is smaller, then assign minimum to the third element otherwise do nothing.
    64 25 12 22 11 
          ^

3) Compare minimum with the Fourth element. Again, if the Fourth element is smaller, then assign minimum to the Fourth element otherwise do nothing.
    64 25 12 22 11 
          ^

4) Compare minimum with the Fifth element. Again, if the Fifth element is smaller, then assign minimum to the Fifth element otherwise do nothing.
    64 25 12 22 11 
                ^

5) After each iteration, minimum is placed in the front of the unsorted list (Swap minimum with first element).
    11 25 12 22 64 

6) For each iteration, indexing starts from the first unsorted element. Step 1 to 5 are repeated until all the elements are placed at their correct positions.


Time Complexities:
Number of comparisons: (n - 1) + (n - 2) + (n - 3) + ..... + 1 = n(n - 1) / 2 nearly equals to n^2. So Complexity = O(n^2). Also, we can analyze the complexity by simply observing the number of loops. There are 2 loops so the complexity is n*n = n2.

1) Worst Case Complexity O(n^2) : If we want to sort in ascending order and the array is in descending order then, the worst case occurs.

2) Best Case Complexity O(n^2) : It occurs when the array is already sorted.

3) Average Case Complexity O(n^2) : It occurs when the elements of the array are in jumbled order (neither ascending nor descending).

The time complexity of the selection sort is the same in all cases. At every step, you have to find the minimum element and put it in the right place. The minimum element is not known until the end of the array is not reached.

Space Complexity: Space complexity is O(1) because a constant space is requred for running a selection sort algorithm.

Stable Sorting Algorithm: A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input unsorted array.

In-Place Sorting Algorithm: A sorting algorithm is said to be In-Place if it directly modifies the list that is received as input instead of creating a new list that is then modified. In-Place, Sorting Algorithm updates input only through replacement or swapping of elements.

Selection sort is in-place sorting algorithm, but It is not Stable Sorting Algorithm.

*/

// Implementaion of Selection Sort:-

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void selection_sort_stable(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        
        int key = arr[min];
        while (min > i)
        {
            arr[min] = arr[min - 1];
            min--;
        }
        arr[i] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    system("cls");
    int size;

    cout << "Please Enter Array Size: ";
    cin >> size;
    
    int *arr = new int[size];

    cout << "\nPlease Enter Array Values\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array Value at index " << i << " is: ";
        cin >> arr[i];
    }

    cout << "\nGiven array is \n";
    printArray(arr, size);

    selection_sort(arr, size);

    cout << "\nSorted array is \n";
    printArray(arr, size);

    return 0;
}