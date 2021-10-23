#include <iostream>
#include <algorithm>
using namespace std;

/*

Merge Sort is a kind of Divide and Conquer algorithm in computer programming. It is one of the most popular sorting algorithms and a great way to develop confidence in building recursive algorithms. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.

Divide And Conquer Technique:
This technique can be divided into the following three parts:
Divide: This involves dividing the problem into a number of subproblems that are smaller instances of the same original problem.
Conquer: This involves solving Sub problem by calling recursively until all sub problems are solved.
Combine: This involves Combining the solutions of the subproblems into the solution for the original problem.

The MergeSort function (merge_sort()) repeatedly divides the array into two halves until we reach a stage where we try to perform MergeSort on a subarray of size 1 i.e. when left == right.

After that, the merge function (merge()) comes into play and combines the sorted arrays into larger arrays until the whole array is merged.

MergeSort(arr[], l,  r)

If l < r
    1. Find the middle point to divide the array into two halves:
             middle m = (l+r)/2
    
    2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
    
    3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
    
    4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
endif


Time Complexity: Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation: T(n) = 2T(n/2) + θ(n)

The above recurrence can be solved either using the Recurrence Tree method or the Master method. It falls in case II of Master Method and the solution of the recurrence is θ(nLogn). Time complexity of Merge Sort is  θ(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.

Best Case Complexity: O(n*log n)

Worst Case Complexity: O(n*log n)

Average Case Complexity: O(n*log n)

Space Complexity:
The space complexity of merge sort is O(n).

Stable Sorting Algorithm: A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input unsorted array.

In-Place Sorting Algorithm: A sorting algorithm is said to be In-Place if it directly modifies the list that is received as input instead of creating a new list that is then modified. In-Place, Sorting Algorithm updates input only through replacement or swapping of elements.

Merge sort is a stable algorithm but not an in-place algorithm. It requires extra array storage.

*/


// Implementaion of Merge Sort:-
void merge(int arr[], int left, int mid, int right)
{
    // Initial index of first subarray
    int i = left;

    // Initial index of second subarray
    int j = mid + 1;

    // Initial index of temporary array
    int k = 0;

    // decleare temporary array for merging first and second subarray in one array
    int temp[right + 1];

    // merging and sorting first and second subarray into temp array
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of first subarray
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of second subarray
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copies Sorted merged Temporary array in original array
    for (int index = left, itr = 0; index <= right; index++, itr++)
        arr[index] = temp[itr];
}

void merge_sort(int arr[], int left, int right)
{
    if (left <= right) 
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

    merge_sort(arr, 0, size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, size);

    return 0;
}