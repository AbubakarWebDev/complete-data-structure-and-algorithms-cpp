#include <iostream>
using namespace std;

/*

Linear search is the simplest searching algorithm that searches for an element in a list in sequential order. We start at one end and check every element until the desired element is not found.

Examples:
Input:  arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170}
        x = 110;

Output: 6
Element x is present at index 6



Input:  arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170}
        x = 175;

Output: -1
Element x is not present in arr[].



Linear Search Algorithm:-
LinearSearch(array, key)
  for each item in the array
    if item == value
      return its index


Time Complexities:
1) Worst Case Complexity O(n) : The element being searched may be present at the last position or not present in the array at all.

2) Best Case Complexity O(1) : The element being searched may be found at the first position.
In this case, the search terminates in success with just one comparison. Thus in best case, linear search algorithm takes O(1) operations.

3) Average Case Complexity O(n) : It occurs when the elements to be searched present at the middle or averaged locations of the array.

Space Complexity: Space complexity is O(1) because a constant space is requred for running a Linear search algorithm.

*/

// Implementaion of Linear Search:-
int linear_search(int arr[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
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

    cout << "\nEnter Value that You want to Searched in Array : ";
    cin >> value;

    if (linear_search(arr, size, value) == -1)
        cout << "Your Searched Value is Not Present in Array\n";
    else
        cout << "\nYour Searched Value is Present at Index: " << linear_search(arr, size, value);

    return 0;
}