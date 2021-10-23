#include <iostream>
#include <algorithm>
using namespace std;

/*

Binary Search is a searching algorithm for finding an element's position in a sorted array.
In this approach, the element is always searched in the middle of a portion of an array.
Binary search can be implemented only on a sorted list of items. If the elements are not sorted already, we need to sort them first.

Binary search looks for a particular item by comparing the middle most item of the collection. If a match occurs, then the index of item is returned. If the middle item is greater than the item, then the item is searched in the sub-array to the left of the middle item. Otherwise, the item is searched for in the sub-array to the right of the middle item. This process continues on the sub-array as well until the size of the subarray reduces to zero.

Binary Search Working:-
Binary Search Algorithm can be implemented in two ways which are discussed below.
1) Iterative Method
2) Recursive Method

The general steps for both methods are discussed below:-

1) The array in which searching is to be performed is:

    arr[] = {3, 4, 5, 6, 7, 8, 9}

2) Let x = 4 be the element to be searched. Set two variables at the lowest and the highest positions of the array respectively.

    Array:      3  4  5  6  7  8  9

    Index:      0  1  2  3  4  5  6
                ^                 ^
               low               High


3) Find the middle element mid of the array ie. (low + high) / 2 = 3.

    Array:      3  4  5  6  7  8  9

    Index:      0  1  2  3  4  5  6
                ^        ^        ^
               low      Mid      High


4) If x == arr[mid], then return mid.
        
5) Else If Searched element x is greater than arr[mid], then it can only be present in Right side of the Mid (Right Subarray). This is done by setting low to low = mid + 1.

6) Else, the element can only be present on the left side of mid (Left Subarray). This is done by setting high to high = mid - 1.

    Array:      3  4  5  6  7  8  9

    Index:      0  1  2  3  4  5  6
                ^     ^        
               low   High      


7) Repeat steps 3 to 6 until value of low meets the value of high.

    Array:      3           4           5

    Index:      0           1           2
                ^           ^           ^        
               low         Mid         High

8) x = 4 is found (arr[Mid]).

    Array:      3           4           5

    Index:      0           1           2
                            ^                   
                         arr[Mid] 


Time Complexities:
1) Worst Case Complexity O(logn) : The element being searched may be present at the last position or not present in the array at all. So the algorithm do (logn) number of comparisons.

2) Best Case Complexity O(1) : The element being searched may be found at the first position.
In this case, the search terminates in success with just one comparison. Thus in best case, algorithm takes O(1) operations.

3) Average Case Complexity O(logn) : It occurs when the elements to be searched present at the averge locations of the array.

Space Complexity: Space complexity is O(1) because a constant space is requred for running an algorithm.        

*/

// Implementaion of Linear Search:-

int binary_search_iterative(int arr[], int x, int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            left = mid + 1;

        else
            right = mid - 1;
    }
    return -1;
}

int binary_search_recursive(int arr[], int x, int left, int right)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;

        // If found at mid, then return it
        if (arr[mid] == x)
            return mid;

        // Search the right half
        else if (arr[mid] < x)
            return binary_search_recursive(arr, x, mid + 1, right);

        // Search the left half
        else
            return binary_search_recursive(arr, x, left, mid - 1);
    }

    return -1;
}

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

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    system("cls");
    int size, value;

    cout << "Please Enter Array Size: ";
    cin >> size;

    int *arr = new int[size];

    cout << "\nPlease Enter Array Values\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array Value at index " << i << " is: ";
        cin >> arr[i];
    }

    bubble_sort(arr, size);
    cout << "Array Values are: ";
    printArray(arr, size);

    cout << "\nEnter Value that You want to Searched in Array : ";
    cin >> value;

    if (binary_search_recursive(arr, value, 0, size - 1) == -1)
        cout << "Your Searched Value is Not Present in Array\n";
    else
        cout << "\nYour Searched Value is Present at Index: " << binary_search_iterative(arr, value, 0, size - 1);

    return 0;
}