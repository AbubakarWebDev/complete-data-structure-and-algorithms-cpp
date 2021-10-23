#include <iostream>
#include <algorithm>
using namespace std;

/*
Like Merge Sort, QuickSort is a Divide and Conquer algorithm. Quick sort is a highly efficient sorting algorithm in which the array is split into subarrays and these sub-arrays are recursively called to sort the elements. An array is partitioned into two sub arrays one of which holds values smaller than the specified value, say pivot, based on which the partition is made and another array holds values greater than the pivot value.

Divide And Conquer Technique:
This technique can be divided into the following three parts:
Divide: This involves dividing the problem into a number of subproblems that are smaller instances of the same original problem.
Conquer: This involves solving Sub problem by calling recursively until all sub problems are solved.
Combine: This involves Combining the solutions of the subproblems into the solution for the original problem.

There are many different versions of quickSort that pick pivot in different ways.
1) Always pick first element as pivot.
2) Always pick last element as pivot (implemented below)
3) Pick a random element as pivot.
4) Pick median as pivot.

Steps For Sorting Array using Quick Sort:
Step 1: Make the right-most index value pivot
Step 2: partition the array using pivot value
Step 3: quicksort left partition recursively
Step 4: quicksort right partition recursively


Pseudo Code for recursive QuickSort function:-

quickSort (arr[], left, right)

    IF (left < right)
        pi = partition(arr, left, right)

        quickSort(arr, left, pi - 1)
        quickSort(arr, pi + 1, right)
    END IF

END quickSort



Pseudo code for partition function:-

partition (arr[], left, right)

    pivot = arr[right]
    i = left

    FOR (j = left + 1; j <= right; j++)

        IF (arr[j] <= pivot)
            swap arr[i] and arr[j]
            i++;   
        END IF
    
    END FOR
    
    swap arr[i] and arr[right])
    return i

END partition


Illustration of Partition Function:

            left                      
             j   
             i                      right
arr[] =     {10, 80, 30, 90, 40, 50, 70}    // pivot = arr[right] = 70
Indexes:     0   1   2   3   4   5   6 



Traverse elements from j = left to right - 1
j = 0 : Since arr[j] <= pivot, do swap(arr[i], arr[j]) and i++, j++
i = 1, j = 1

                  j   
            left  i                 right
arr[] =     {10, 80, 30, 90, 40, 50, 70}    // pivot = arr[right] = 70
Indexes:     0   1   2   3   4   5   6




j = 1 : Since arr[j] > pivot, do nothing
// No change in i and arr[], increment j++ so j = 2 

            left  i   j             right
arr[] =     {10, 80, 30, 90, 40, 50, 70}    // pivot = arr[right] = 70
Indexes:     0   1   2   3   4   5   6 




j = 2 : Since arr[j] <= pivot, do swap(arr[i], arr[j]) and i++, j++
i = 2, j = 3

            left      i   j         right
arr[] =     {10, 30, 80, 90, 40, 50, 70}    // pivot = arr[right] = 70
Indexes:     0   1   2   3   4   5   6 




j = 3 : Since arr[j] > pivot, do nothing
// No change in i and arr[], increment j++ so j = 4

            left      i       j    right
arr[] =     {10, 30, 80, 90, 40, 50, 70}    // pivot = arr[right] = 70
Indexes:     0   1   2   3   4   5   6 




j = 4 : Since arr[j] <= pivot, do swap(arr[i], arr[j]) and i++, j++
i = 3, j = 5
            left          i       j  right
arr[] =     {10, 30, 40, 90, 80, 50, 70}    // pivot = arr[right] = 70
Indexes:     0   1   2   3   4   5   6 




j = 5 : Since arr[j] <= pivot, do swap(arr[i], arr[j]) and i++, j++
i = 4, j = 6
                                      j
            left              i      right
arr[] =     {10, 30, 40, 50, 80, 90, 70}    // pivot = arr[right] = 70
Indexes:     0   1   2   3   4   5   6 



We come out of loop because j is now equal to right-1.
Finally we place pivot at correct position by swapping
arr[i] and arr[right] (or pivot)
                                      j
            left              i      right
arr[] =     {10, 30, 40, 50, 70, 80, 90}    // pivot = arr[4] = 70
Indexes:     0   1   2   3   4   5   6 



Now 70 is at its correct place. All elements smaller than
70 are before it and all elements greater than 70 are after
it.


Worst Case: The worst case occurs when the partition process always picks greatest or smallest element as pivot. If we consider above partition strategy where last element is always picked as pivot, the worst case would occur when the array is already sorted in increasing or decreasing order. Following is recurrence for worst case. 

T(n) = T(n-1) + theta(n)
The solution of above recurrence is  theta(n^2).

Best Case: The best case occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case. 

T(n) = 2T(n/2) + theta(n)
The solution of above recurrence is theta (nLogn). It can be solved using case 2 of Master Theorem.

Average Case: To do average case analysis, we need to consider all possible permutation of array and calculate time taken by every permutation which doesn’t look easy.  We can get an idea of average case by considering the case when partition puts O(n/9) elements in one set and O(9n/10) elements in other set. Following is recurrence for this case.

T(n) = T(n/9) + T(9n/10) + theta(n)
Solution of above recurrence is also O(nLogn).

Stable Sorting Algorithm: A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input unsorted array.

In-Place Sorting Algorithm: A sorting algorithm is said to be In-Place if it directly modifies the list that is received as input instead of creating a new list that is then modified. In-Place, Sorting Algorithm updates input only through replacement or swapping of elements.

Quick sort is in-place sorting algorithm, but It is not Stable Sorting Algorithm.
*/

// Implementaion of Quick Sort:-

int partitionWhenPickFirst(int arr[], int left, int right)
{
    int pivot = arr[left], j = left + 1;

    for (int i = left + 1; i <= right; i++)
    {
        if (arr[i] < pivot)
        {
            if (i != j)
            {
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }

    arr[left] = arr[j - 1];
    arr[j - 1] = pivot;

    return j - 1;
}

int partitionWhenPickMiddle(int arr[], int left, int right)
{
    int mid = (left + right) / 2, pivot = arr[mid], i = left, j = right;

    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return mid;
}

int partitionWhenPickLast(int arr[], int left, int right)
{
    int pivot = arr[right]; // pivot
    int i = left;           // Index of smaller element

    for (int j = left; j < right; j++)
    {
        // If current element is smaller than and Equal to the pivot
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++; // increment index of smaller element
        }
    }

    swap(arr[i], arr[right]);
    return i;
}

void quick_sort(int arr[], int left, int right)
{
    if (left <= right)
    {
        // pi is partitioning index
        int pi = partitionWhenPickLast(arr, left, right);
        quick_sort(arr, left, pi - 1);
        quick_sort(arr, pi + 1, right);
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

    quick_sort(arr, 0, size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, size);

    return 0;
}