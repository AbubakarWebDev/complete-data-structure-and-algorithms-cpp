#include <iostream>
#include <algorithm>
using namespace std;

/*

Insertion sort works similarly as we sort cards in our hand in a card game.

We assume that the first card is already sorted then, we select an unsorted card. If the unsorted card is greater than the card in hand, it is placed on the right otherwise, to the left. In the same way, other unsorted cards are taken and put at their right place.

A similar approach is used by insertion sort.

Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

How Insertion Sort Works?
Suppose we need to sort the following array.

arr[] = {9, 5, 1, 4, 3}

1) The first element in the array is assumed to be sorted. Take the second element and store it separately in key. Compare key with the first element. If the first element is greater than key, then key is placed in front of the first element.

arr[] = {5, 9, 1, 4, 3}

2) Now, the first two elements are sorted. Take the third element and compare it with the elements on the left of it. Placed it just behind the element smaller than it. If there is no element smaller than it, then place it at the beginning of the array.

arr[] = {1, 5, 9, 4, 3}

3) Now, the first three elements are sorted. repeat step 2 until the 

arr[] = {1, 4, 5, 9, 3}

4) Now, the first four elements are sorted. Take the fourth element and compare it with the elements on the left of it. Placed it just behind the element smaller than it. If there is no element smaller than it, then place it at the beginning of the array.

arr[] = {1, 3, 4, 5, 9}


Time Complexities:
1) Worst Case Complexity O(n^2): Suppose, an array is in ascending order, and you want to sort it in descending order. In this case, worst case complexity occurs. Each element has to be compared with each of the other elements so, for every nth element, (n-1) number of comparisons are made.
Thus, the total number of comparisons = n*(n-1) = n^2

2) Best Case Complexity O(n): When the array is already sorted, the outer loop runs for n number of times whereas the inner loop does not run at all. So, there are only n number of comparisons. Thus, complexity is linear.

3) Average Case Complexity O(n^2): It occurs when the elements of an array are in jumbled order (neither ascending nor descending).

Space Complexity: Space complexity is O(1) because a constant space is requred for running a selection sort algorithm.

Insertion sort is in-place sorting algorithm as well as Stable Sorting Algorithm.
*/

// Implementaion of Insertion Sort:-  

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i;

        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = key;
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

    insertion_sort(arr, size);

    cout << "\nSorted array is \n";
    printArray(arr, size);

    return 0;
}