/**********************************************************************
An algorithm (pronounced AL-go-rith-um) is a procedure or formula for solving a problem, based on conducting a sequence of specified actions. A computer program can be viewed as an elaborate algorithm. In mathematics and computer science, an algorithm usually means a small procedure that solves a recurrent problem.

Searching Algorithms:
Searching Algorithms are designed to check for an element or retrieve an element from any data structure where it is stored. Based on the type of search operation, these algorithms are generally classified into two categories:

1) Sequential Search: In this, the list or array is traversed sequentially and every element is checked. For example: Linear Search.

2) Interval Search: These algorithms are specifically designed for searching in sorted data-structures. These type of searching algorithms are much more efficient than Linear Search as they repeatedly target the center of the search structure and divide the search space in half. For Example: Binary Search.

Sorting Algorithms:
A Sorting Algorithm is used to rearrange a given array or list elements according to a comparison operator on the elements. The comparison operator is used to decide the new order of element in the respective data structure.

Stable Sorting Algorithms: A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input unsorted array. Stability is mainly important when we have key value pairs with duplicate keys possible (like people names as keys and their details as values). And we wish to sort these objects by keys.

For Example:

Input : 4A 5 3 2 4B 1
Output : 1 2 3 4B 4A 5

Stable Sorting algorithm would have produced
Output : 1 2 3 4A 4B 5

Several common sorting algorithms are stable by nature, such as Merge Sort, Counting Sort, Radix Sort, Bucket Sort, Insertion Sort, and Bubble Sort. Others such as Quicksort, Heapsort and Selection Sort are unstable.

Do we care for simple arrays like array of integers?
When equal elements are indistinguishable, such as with integers, or more generally, any data where the entire element is the key, stability is not an issue. Stability is also not an issue if all keys are different.

Can we make any sorting algorithm stable?
Any given sorting algo which is not stable can be modified to be stable. There can be sorting algo specific ways to make it stable, but in general, any comparison based sorting algorithm which is not stable by nature can be modified to be stable by changing the key comparison operation so that the comparison of two keys considers position as a factor for objects with equal keys.


In-Place Sorting Algorithm: A sorting algorithm is said to be In-Place if it directly modifies the list that is received as input instead of creating a new list that is then modified. In-Place, Sorting Algorithm updates input only through replacement or swapping of elements.

There are many sorting algorithms that are using in-place approach. Some of them are insertion sort, selection sort, bubble sort, heap sort, Quick sort. Others are Merge Sort, Counting Sort, Radix Sort, Bucket Sort.

Those Algorithms that are stable as well as in-place: Insertion Sort, Bubble Sort.

Below is the list of the Time and space Complexity of All Sorting Algorithms:
---------------------------------------------------------------------------------------------------------
Algorithm Name              Best          Average        Worst          Space       Stable      In-place
Selection Sort              O(n^2)        O(n^2)         O(n^2)         O(1)         No           yes
Bubble Sort                 O(n)          O(n^2)         O(n^2)         O(1)         Yes          yes   
Insertion Sort              O(n)          O(n^2)         O(n^2)         O(1)         yes          yes
Heap Sort                   O(nlogn)      O(nlogn)       O(nlogn)       O(1)         No           yes
Merge Sort                  O(nlogn)      O(nlogn)       O(nlogn)       O(n)         yes          No
Quick Sort                  O(nlogn)      O(nlogn)       O(n^2)         O(n)         No           yes
Counting Sort               O(n+k)        O(n+k)         O(n+k)         O(max)       yes          no
Radix Sort                  O(n+k)        O(n+k)         O(n+k)         O(max)       yes          no
Bucket Sort                 O(n+k)        O(n)           O(n^2)         O(n+k)       yes          no
---------------------------------------------------------------------------------------------------------

Asymptotic notation:
Asymptotic Notations are the expressions that are used to represent the complexity of an algorithm. It describes the algorithm efficiency and performance in a meaningful way. It describes the behaviour of time or space complexity for large instance characteristics. 
The main idea of asymptotic analysis is to have a measure of the efficiency of algorithms that don’t depend on machine-specific constants and doesn’t require algorithms to be implemented and time taken by programs to be compared. 
Asymptotic notations are mathematical tools to represent the time or space complexity of algorithms for asymptotic analysis. There are three types of analysis that we perform on a particular algorithm.

Best Case: In which we analyse the performance of an algorithm for the input, for which the algorithm takes less time or space.

Worst Case: In which we analyse the performance of an algorithm for the input, for which the algorithm takes long time or space.

Average Case: In which we analyse the performance of an algorithm for the input, for which the algorithm takes time or space that lies between best and worst case.

Types of Asymptotic Notation
1) Big-O Notation (Ο): Big O notation specifically describes worst case scenario.
2) Omega Notation (Ω): Omega(Ω) notation specifically describes best case scenario.
3) Theta Notation (θ): This notation represents the average complexity of an algorithm.

1) Big Oh notation(O): Big O notation specifically describes worst case scenario. It represents the upper bound running time complexity of an algorithm (Asymptotic Upper bound). So if we represent a complexity of an algorithm in Big Oh notation, it means that the algorithm cannot be completed in more time than this. it would at-most take the time represented by Big Oh notation or it can take less (when not in worst case scenario). The function f(n) = O(g(n)), if and only if there exist a positive constant C and K such that f(n) ≤ C * g(n) for all n, n ≥ K.

2) Omega notation specifically describes best case scenario. It represents the lower bound running time complexity of an algorithm (Asymptotic Lower bound). So if we represent a complexity of an algorithm in Omega notation, it means that the algorithm cannot be completed in less time than this, it would at-least take the time represented by Omega notation or it can take more (when not in best case scenario).
The function f(n) = Ω(g(n)), if and only if there exist a positive constant C and K such that f(n) ≥ C * g(n) for all n, n ≥ K.

3) Theta Notation (θ): This notation describes both upper bound and lower bound of an algorithm so we can say that it defines exact asymptotic behaviour (Asymptotic Tight bound). In the real case scenario the algorithm not always run on best and worst cases, the average running time lies between best and worst and can be represented by the theta notation. The function f(n) = θ(g(n)), if and only if there exist a positive constant C1, C2 and K such that C1 * g(n) ≤ f(n) ≤ C2 * g(n) for all n, n ≥ K.

There are two more notations called little o and little omega. Little o provides strict upper bound (equality condition is removed from Big O) and little omega provides strict lower bound (equality condition removed from big omega)

Common Asymptotic Functions: Following is a list of some common asymptotic functions
function name                      notation
constant                           O(1)
logarithmic                        Ο(log n)
n times logarithmic                Ο(n log(n))
quadratic                          Ο(n^2)
cubic                              Ο(n^3)
exponential                        O(2^n)
factorial                          O(n!) = O(n^n)

Examples of asymptotic Analysis:
The simplest example is a function ƒ (n) = n^2+3n, the term 3n becomes insignificant compared to n^2 when n is very large. The function ƒ (n) is said to be asymptotically equivalent to n^2 as n → ∞", and here is written symbolically as ƒ (n) ~ n^2.

1) f(n) = 3n + 2 = O(n) as 3n + 2 ≤ 4n for all n ≥ 2  
2) f(n) = 3n + 3 = O(n) as 3n + 3 ≤ 4n for all n ≥ 3
Hence, the complexity of f(n) can be represented as O(g(n))

1) f(n) = 8n^2 + 2n - 3 as 8n^2 + 2n - 3 ≥ 8n^2 - 3 for all n ≥ 1
2) f(n) = 7n^2 + n^2 - 3 as 7n^2 + n^2 - 3 ≥ 7n^2 - 3 for all n ≥ 1
Hence, the complexity of f (n) can be represented as Ω (g (n))

1) f(n) = 3n + 2 = θ(n) as 3n + 2 ≥ 3n and 3n + 2 ≤ 4n, for n, k1 = 3, k2 = 4, for all n ≥ 2
Hence, the complexity of f (n) can be represented as θ (g(n)).

Properties of Asymptotic Notations:
As we have gone through the definition of this three notations let’s now discuss some important properties of those notations.

1) General Properties: 
If f(n) is O(g(n)) then a * f(n) is also O(g(n)) ;where a is a constant. 
Example: f(n) = 2n²+5 is O(n²) 
then 7 * f(n) = 7(2n²+5) = 14n²+35 is also O(n²) .
Similarly this property satisfies for both Θ and Ω notation. 
We can say 
If f(n) is Θ(g(n)) then a*f(n) is also Θ(g(n)) ; where a is a constant. 
If f(n) is Ω (g(n)) then a*f(n) is also Ω (g(n)) ; where a is a constant.

2) Transitive Properties:
If f(n) is O(g(n)) and g(n) is O(h(n)) then f(n) = O(h(n)).
Example: if f(n) = n, g(n) = n² and h(n) = n³
n is O(n²) and n² is O(n³)
then n is O(n³)
Similarly this property satisfies for both Θ and Ω notation.
We can say
If f(n) is Θ(g(n)) and g(n) is Θ(h(n)) then f(n) = Θ(h(n)) .
If f(n) is Ω (g(n)) and g(n) is Ω (h(n)) then f(n) = Ω (h(n))

3) Reflexive Properties:
Reflexive properties are always easy to understand after transitive.
If f(n) is given then f(n) is O(f(n)). Since MAXIMUM VALUE OF f(n) will be f(n) ITSELF !
Hence x = f(n) and y = O(f(n) tie themselves in reflexive relation always.
Example: f(n) = n² ; O(n²) i.e O(f(n))
Similarly this property satisfies for both Θ and Ω notation.
We can say that:
If f(n) is given then f(n) is Θ(f(n)).
If f(n) is given then f(n) is Ω (f(n)).

4) Symmetric Properties:
If f(n) is Θ(g(n)) then g(n) is Θ(f(n)).
Example: f(n) = n² and g(n) = n² 
then f(n) = Θ(n²) and g(n) = Θ(n²)
This property only satisfies for Θ notation.

5) Transpose Symmetric Properties: 
If f(n) is O(g(n)) then g(n) is Ω(f(n))
Example: f(n) = n , g(n) = n²
then n is O(n²) and n² is Ω (n)
This property only satisfies for O and Ω notations.

6) Some More Properties:
     1) If f(n) = O(g(n)) and f(n) = Ω(g(n)) then f(n) = Θ(g(n))

     2) If f(n) = O(g(n)) and d(n) = O(e(n)) 
          then f(n) + d(n) = O(max( g(n), e(n) ))
          Example: f(n) = n i.e O(n) 
                   d(n) = n² i.e O(n²) 
              then f(n) + d(n) = n + n² i.e O(n²)

      3) If f(n) = O(g(n)) and d(n) = O(e(n)) 
          then f(n) * d(n) = O( g(n) * e(n) ) 
          Example: f(n) = n i.e O(n) 
                   d(n) = n² i.e O(n²) 
              then f(n) * d(n) = n * n² = n³ i.e O(n³)

--------------------------------------------------------------------------

Master Theorem: 
The master method is a formula for solving recurrence relations of the decreasing and dividing Functions. It solves recurrence relations and give them a time complexity in a simple and quick way.

Recurrence Relations For Decreasing Functions: T(n) = aT(n - b) + f(n),
where,
n = size of input
a = number of subproblems in the recursion
n-b = size of each subproblem. All subproblems are assumed 
     to have the same size.
f(n) = cost of the work done outside the recursive call, 
      which includes the cost of dividing the problem and
      cost of merging the solutions

Here, a > 0 and b > 0 are constants, and f(n) is anasymptotically positive function . So, f(n) = O(n^k) where k ≥ 0. An asymptotically positive function means that for a sufficiently large value of n, we have f(n) > 0. 

Master thoerem makes three cases which will tell us what kind of bound we can apply on the function. In simple words, From the given two cases we simply find the time complexity of recurence relation.

If a > 1 then T(n) = O(a^(n/b) * n^k) or simply O(a^(n/b) * f(n)).
If a = 1 then T(n) = O(n^(k+1)) or simply T(n) = O(n * f(n)).

Examples: We have some recurrence relation of decreasing function use above master theorem to solve it:
1) T(n) = T(n - 1) + 1        ;Here a = 1, b = 1, k = 0, f(n) = 1 So, the time complexity is: O(n)
2) T(n) = T(n - 2) + 1        ;Here a = 1, b = 2, k = 0, f(n) = 1 So, the time complexity is: O(n)
3) T(n) = T(n - 1) + n        ;Here a = 1, b = 1, k = 1, f(n) = n So, the time complexity is: O(n^2)
4) T(n) = T(n - 1) + log(n)   ;Here a = 1, b = 1, k = 0, f(n) = log(n) So, the time complexity is: O(n log(n))
5) T(n) = 2T(n - 1) + 1       ;Here a = 2, b = 1, k = 0, f(n) = 1 So, the time complexity is: O(2^n)
6) T(n) = 3T(n - 1) + 1       ;Here a = 3, b = 1, k = 0, f(n) = 1 So, the time complexity is: O(3^n)
7) T(n) = 3T(n - 2) + 1       ;Here a = 3, b = 2, k = 0, f(n) = 1 So, the time complexity is: O(3^(n/2))
8) T(n) = 2T(n - 2) + 1       ;Here a = 2, b = 2, k = 0, f(n) = 1 So, the time complexity is: O(2^(n/2))
9) T(n) = 2T(n - 1) + n       ;Here a = 2, b = 1, k = 1, f(n) = n So, the time complexity is: O(n 2^n)


Recurrence Relations For Dividing Functions: T(n) = aT(n/b) + f(n),
where,
n = size of input
a = number of subproblems in the recursion
n/b = size of each subproblem. All subproblems are assumed to have the same size.
f(n) = cost of the work done outside the recursive call,
      which includes the cost of dividing the problem and
      cost of merging the solutions

Here, a ≥ 1 and b > 1 are constants, and f(n) is anasymptotically positive function. So, f(n) can be expressed as O(n^k * (logn)^p). where k ≥ 0 and p ≥ 0. An asymptotically positive function means that for a sufficiently large value of n, we have f(n) > 0.

Master thoerem makes three cases which will tell us what kind of bound we can apply on the function. In simple words, From the given three cases we simply find the time complexity of recurence relation.

if k > (log(a) base b) then some cases comes here that are given below:
          if p >= 0 then O(n^K * (log(n))^p)
          if p < 0 then O(n^K) 
If k = (log(a) base b) then some cases comes here that are given below:
          if p > -1 then T(n) = O(n^K * (log(n))^(p+1))
          if p = -1 then T(n) = O(n^K * log(log(n)))
          if p < -1 then T(n) = O(n^K)
If k < (log(a) base b) then T(n) = O(n^(log(a) base b))

Examples: We have some recurrence relation of Dividing function use above master theorem to solve it:
1) T(n) = T(n/2) + 1         ;Here a = 1, b = 2, k = 0, p = 0, f(n) = 1 So, T(n) = O(log(n))
2) T(n) = 2T(n/2) + 1        ;Here a = 2, b = 2, k = 0, p = 0, f(n) = 1 So, T(n) = O(n)
3) T(n) = 4T(n/2) + n        ;Here a = 4, b = 2, k = 1, p = 0, f(n) = n So, T(n) = O(n^2)
3) T(n) = 4T(n/2) + n*log(n) ;Here a = 4, b = 2, k = 2, p = 1, f(n) = n*log(n) So, T(n) = O(n^2)
3) T(n) = 4T(n/2) + n^2      ;Here a = 4, b = 2, k = 2, p = 0, f(n) = n^2 So, T(n) = O(n^2 log(n))
4) T(n) = 8T(n/2) + n        ;Here a = 8, b = 2, k = 1, p = 0, f(n) = n So, T(n) = O(n^3)
5) T(n) = 8T(n/2) + n^2      ;Here a = 8, b = 2, k = 2, p = 0, f(n) = n^2 So, T(n) = O(n^3)
6) T(n) = 8T(n/2) + n*log(n) ;Here a = 8, b = 2, k = 1, p = 1, f(n) = n*log(n) So, T(n) = O(n^3)
6) T(n) = 8T(n/2) + n^3      ;Here a = 8, b = 2, k = 3, p = 0, f(n) = n^3 So, T(n) = O(n^3 log(n))

In this pretty simple way, Master Theorem works to find the complexity of decreasing and dividing functions.
We can use either Theta (Θ) Notation or Omega (Ω) Notation instead of Big O Notation. Using Θ notation will be more appropriate fo the master theorem.

There are some limitations of this theorem. That is for some kind of relations it is unable to give the complexity. The master theorem cannot be used if:
1) T(n) is not monotone. eg. T(n) = sin n
2) f(n) is not a polynomial. eg. f(n) = 2^n
3) a is not a constant. eg. a = 2n
4) a < 1

For the below examples, the Master theorem cannot be used.
1) T(n) = 2^n * T(n/2) + n         ;Here a is not constant; the number of subproblems should be fixed.
2) T(n) = 0.5 * T(n/2) + n         ;Here a < 1; can't have less than one sub problem.
3) T(n) = 16 * T(n/2) - n^2        ;Here f(n) which is the time function. So, it is not negative.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

class Algorithms
{
private:
     int size;
     int *arr;

     int partition(int left, int right) 
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

     void merge(int left, int mid, int right)
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

public:
     Algorithms(int size)
     {
          this->size = size;
          this->arr = new int[this->size];

          for (int i = 0; i < this->size; i++)
          {
               arr[i] = 0;
          }
     }

     ~Algorithms()
     {
          delete[] arr;
     }

     void inputArray()
     {
          cout << "\nPlease Enter Your Array Value:\n";
          for (int i = 0; i < size; i++)
          {
               cout << "Enter Value of Array At Index " << i << " is: ";
               cin >> arr[i];
          }
     }

     void printArray()
     {
          cout << "\nArray Values are: ";
          for (int i = 0; i < size; i++)
               cout << arr[i] << " ";
          cout << "\n";
     }

     void quick_sort(int left, int right)
     {
          if (left >= right)
               return;

          int pi = partition(left, right);
          quick_sort(left, pi - 1);
          quick_sort(pi + 1, right);
     }

     void merge_sort(int left, int right)
     {
          if (left >= right)
               return;

          int mid = (left + right) / 2;
          merge_sort(left, mid);
          merge_sort(mid + 1, right);
          merge(left, mid, right);
     }

     void selection_sort()
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

     void bubble_sort()
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

     void insertion_sort()
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

     int linear_search(int x)
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

     int binary_search_iterative(int x, int left, int right)
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

     int binary_search_recursive(int x, int left, int right)
     {
          if (right >= left)
          {
               int mid = (left + right) / 2;

               // If found at mid, then return it
               if (arr[mid] == x)
                    return mid;

               // Search the left half
               else if (arr[mid] > x)
                    return binary_search_recursive(x, left, mid - 1);

               // Search the right half
               else
                    return binary_search_recursive(x, mid + 1, right);
          }

          return -1;
     }

     void shuffle_array()
     {
          // To obtain a time-based seed
          unsigned seed = 0;

          // Shuffling our array
          shuffle(arr, arr + size, default_random_engine(seed));
     }
};

int main()
{
     int size, value;
     bool check = true;

     cout << "Please Enter Array Size: ";
     cin >> size;

     Algorithms algo(size);
     algo.inputArray();

     while (check)
     {
          system("cls");
          int choice;
          cout << "\n\n|============= Searching & Sorting Algorithms =============|\n"
               << "Please Select the Operation that you want to perform With the Given Options: \n"
               << "1 : Sort Array values using Selection Sort\n"
               << "2 : Sort Array values using Bubble Sort\n"
               << "3 : Sort Array values using Insertion Sort\n"
               << "4 : Sort Array values using Merge Sort\n"
               << "5 : Sort Array values using Quick Sort\n"
               << "6 : Search a value from Array using Linear Search\n"
               << "7 : Search a value from Array using Binary Search (Iterative Approach)\n"
               << "8 : Search a value from Array using Binary Search (Recursive Approach)\n"
               << "9 : Input All Array Values\n"
               << "10 : Print All Array Values\n"
               << "11 : Unsort (Randomly Shuffle) Array Values\n"
               << "12 : Exit This Application\n"
               << "Enter Your Choice : ";
          cin >> choice;

          switch (choice)
          {
          case 1:
               algo.selection_sort();
               algo.printArray();
               break;

          case 2:
               algo.bubble_sort();
               algo.printArray();
               break;

          case 3:
               algo.insertion_sort();
               algo.printArray();
               break;

          case 4:
               algo.merge_sort(0, size - 1);
               algo.printArray();
               break;

          case 5:
               algo.quick_sort(0, size - 1);
               algo.printArray();
               break;

          case 6:
               cout << "Enter Value that You want to search in Array: ";
               cin >> value;

               if (algo.linear_search(value) == -1)
                    cout << "Your Searched Value is Not Present On Array\n";
               else
                    cout << "Searched Value is Present at Index: " << algo.linear_search(value);
               break;

          case 7:
               algo.quick_sort(0, size - 1);
               algo.printArray();
               cout << "Enter Value that You want to search in Array: ";
               cin >> value;

               if (algo.binary_search_iterative(value, 0, size - 1) == -1)
                    cout << "Your Searched Value is Not Present On Array\n";
               else
                    cout << "Searched Value is Present at Index: " << algo.binary_search_iterative(value, 0, size - 1);
               break;

          case 8:
               algo.quick_sort(0, size - 1);
               algo.printArray();
               cout << "Enter Value that You want to search in Array: ";
               cin >> value;

               if (algo.binary_search_recursive(value, 0, size - 1) == -1)
                    cout << "Your Searched Value is Not Present On Array\n";
               else
                    cout << "Searched Value is Present at Index: " << algo.binary_search_recursive(value, 0, size - 1);
               break;

          case 9:
               algo.inputArray();
               break;

          case 10:
               algo.printArray();
               break;

          case 11:
               algo.shuffle_array();
               algo.printArray();
               break;

          case 12:
               cout << "Thanks For Using this Application";
               check = false;
               break;

          default:
               cout << "Error : Invalid Value Detected!\n";
               break;
          }

          cout << "\n";
          system("pause");
     }
}