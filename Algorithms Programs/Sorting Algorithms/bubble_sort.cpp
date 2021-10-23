#include <iostream>
#include <algorithm>
using namespace std;

/*

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

In the bubble sort technique, each of the elements in the list is compared to its adjacent element. Thus if there are n elements in list A, then A[0] is compared to A[1], A[1] is compared to A[2] and so on.

After comparing if the first element is greater than the second, the two elements are swapped then.

Using the bubble sort technique, sorting is done in passes or iteration. Thus at the end of each iteration, the heaviest element is placed at its proper place in the list. In other words, the largest element in the list bubbles up.

Example: arr[] = {10,5,15,0,12}

Pass	    Unsorted list	        comparison	            Sorted list
1	        {10,5,15,0,12}	        {10,5}	                {5,10,15,0,12}
            {5,10,15,0,12}          {10,15}                 {5,10,15,0,12}
            {5,10,15,0,12}          {15,0}                  {5,10,0,15,12}
            {5,10,0,15,12}      	{15,12}             	{5,10,0,12,15}

2	        {5,10,0,12,15}	        {5,10}	                {5,10,0,12,15}
            {5,10,0,12,15}	        {10,0}	                {5,0,10,12,15}
            {5,0,10,12,15}	        {10,12}	                {5,0,10,12,15}

3	        {5,0,10,12,15}	        {5,0}	                {0,5,10,12,15}
            {0,5,10,12,15}	        {5,10}	                {0,5,10,12,15}

4           {0,5,10,12,15}	        {0,5}	                {0,5,10,12,15}


As shown in the illustration, with every pass, the largest element bubbles up to the last thereby sorting the list with every pass. As mentioned in the introduction, each element is compared to its adjacent element and swapped with one another if they are not in order.

Thus as shown in the illustration above, at the end of the first pass, if the array is to be sorted in ascending order, the largest element is placed at the end of the list. For the second pass, the second largest element is placed at the second last position in the list and so on.

When we reach N-1 (where N is a total number of elements in the list) passes, we will have the entire list sorted.

In Above illustration Passess Represent Outer Loop and Comparisons present inside each passess represent inner Loop. 

General Algorithm:-
Step 1: For i = 0 to N-1 repeat Step 2
Step 2: For j = 0 to N-1-i repeat
        Step 3: if A[j] > A[j+1]
            Swap A[j] and A[j+1]
[End of Inner for loop]
[End of Outer for loop]
Step 4: Exit

Optimized Bubble Sort Algorithm:
In the default bubble sort algorithm, all the comparisons are made even if the array is already sorted. This increases the execution time.

To solve this, we can introduce an extra variable swapped. The value of swapped is set true if there  occurs swapping of elements.Otherwise, it is set false.

After an iteration, if there is no swapping, the value of swapped will be false. This means elements are already sorted and there is no need to perform further iterations. This will reduce the execution time and helps to optimize the bubble sort.

Time Complexities:
Hence, the number of comparisons is: (n-1) + (n-2) + (n-3) +.....+ 1 = n(n-1)/2
nearly equals to n^2. Hence, Complexity: O(n^2). Also, if we observe the code, bubble sort requires two loops. Hence, the complexity is n*n = n^2

1) Worst Case Complexity O(n^2): If we want to sort in ascending order and the array is in descending order then the worst case occurs.

2) Best Case Complexity O(n): If the array is already sorted, then there is no need for sorting.

3) Average Case Complexity O(n^2): It occurs when the elements of the array are in jumbled order (neither ascending nor descending).

Space Complexity: Space complexity is O(1) because a constant space is requred for running a selection sort algorithm.

Stable Sorting Algorithm: A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input unsorted array.

In-Place Sorting Algorithm: A sorting algorithm is said to be In-Place if it directly modifies the list that is received as input instead of creating a new list that is then modified. In-Place, Sorting Algorithm updates input only through replacement or swapping of elements.

Bubble sort is in-place sorting algorithm as well as Stable Sorting Algorithm.
*/

// Implementaion of bubble Sort:-

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubble_sort_optimized(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
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

    bubble_sort(arr, size);

    cout << "\nSorted array is \n";
    printArray(arr, size);

    return 0;
}