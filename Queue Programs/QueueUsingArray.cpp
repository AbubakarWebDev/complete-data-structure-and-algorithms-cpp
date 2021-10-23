/******************************************************************
Queue Using Array:
In queue, insertion and deletion happen at the opposite ends, so implementation is not as simple as stack. 
To implement a queue using array, create an array arr of size n and take two variables front and rear both of which will be initialized to 0 which means the queue is currently empty. Element rear is the index upto which the elements are stored in the array and front is the index of the first element of the array. Now, some of the implementation of queue operations are as follows:  

1) Enqueue: Addition of an element to the queue. Adding an element will be performed after checking whether the queue is full or not. If rear < n which indicates that the array is not full then store the element at arr[rear] and increment rear by 1 but if rear == n then it is said to be an Overflow condition as the array is full.

2) Dequeue: Removal of an element from the queue. An element can only be deleted when there is at least an element to delete i.e. rear > 0. Now, element at arr[front] can be deleted but all the remaining elements have to shifted to the left by one position in order for the dequeue operation to delete the second element from the left on another dequeue operation.

3) Front: Get the front element from the queue i.e. arr[front] if queue is not empty.

4) Display: Print all element of the queue. If the queue is non-empty, traverse and print all the elements from index front to rear.
*******************************************************************/ 

#include <iostream>
using namespace std;

class QueueUsingArray
{
    int size;
    int *arr;
    int front;
    int rear;

public:
    QueueUsingArray(int size = 5)
    {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->arr = new int[this->size];

        for (int i = 0; i < this->size; i++)
        {
            arr[i] = 0;
        }
    }

    ~QueueUsingArray()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return (rear == -1 && front == -1);
    }

    bool isFull()
    {
        return (front == 0 && (rear == size - 1));
    }

    bool enque(int value)
    {
        if (isFull())
        {
            cout << "\nQueue is Full. So Value is Not Able to Enqued in Queue\n";
            return false;
        }
        else if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            if (rear == size - 1)
            {
                for (int i = front; i <= rear; i++)
                {
                    arr[i - front] = arr[i];
                    arr[i] = 0;
                }

                rear = rear - front;
                front = 0;
            }
            rear++;
        }

        arr[rear] = value;
        return true;
    }

    int deque()
    {
        int x = 0;

        if (isEmpty())
        {
            cout << "\nQueue is Empty. So Value is Not Able to Dequed from Queue\n";
            return false;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            rear = front = -1;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
        }

        return x;
    }

    bool search(int position)
    {
        if (isEmpty())
        {
            cout << "\nNo Value is Present on Queue.\n";
            return false;
        }
        else if (rear == front)
        {
            if (rear == position)
            {
                cout << "\nYour Search Values is: " << arr[position] << "\n";
                return true;
            }
        }
        else
        {
            if (position >= front && position <= rear)
            {
                cout << "\nYour Search Values is: " << arr[position] << "\n";
                return true;
            }
        }
        return false;
    }

    bool update(int position, int value)
    {
        if (isEmpty())
        {
            cout << "\nNo Value is Present on Queue.\n";
            return false;
        }
        else if (rear == front)
        {
            if (rear == position)
            {
                arr[position] = value;
                return true;
            }
        }
        else
        {
            if (position >= front && position <= rear)
            {
                arr[position] = value;
                return true;
            }
        }
        return false;
    }

    int count()
    {
        if (isEmpty())
            return 0;
        else
            return (rear - front + 1);
    }

    void display()
    {
        cout << "\nYour Queue Values is Given Below\n";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "  ";
        }
    }
};

int main()
{
    system("cls");
    int size;

    cout << "\nPlease First Enter The Size of Queue That You Want to Create: ";
    cin >> size;

    QueueUsingArray que(size);
    int position, value;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= Queue USING ARRAY =============|\n"
             << "Please Select the Operation that you want to perform With the Given Options: \n"
             << "1 : Enqeue a Value in a Queue\n"
             << "2 : Deqeue a Value from a Queue\n"
             << "3 : Check Whether a Queue is Full or Not\n"
             << "4 : Check Whether a Queue is Empty or Not\n"
             << "5 : Get a Value from a Specific Position of Queue\n"
             << "6 : Update Value to a Specific Position of Queue\n"
             << "7 : Count All Enteries of a Queue\n"
             << "8 : Print All Enteries of a Queue\n"
             << "9 : Exit this Application\n"
             << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value For Enqeueing in a Queue: ";
            cin >> value;

            if (que.enque(value))
                cout << "Value is successfully Enqeued in Queue\n";
            break;

        case 2:
            value = que.deque();

            if (value)
                cout << "\nValue is successfully deqeued From Queue\nYour deqeued Value is: " << value << "\n";
            break;

        case 3:
            if (que.isFull())
                cout << "Queue is Full.\n";
            else
                cout << "Queue is Not Full.\n";
            break;

        case 4:
            if (que.isEmpty())
                cout << "Queue is Empty.\n";
            else
                cout << "Queue is Not Empty.\n";
            break;

        case 5:
            cout << "Enter Position that you want to search in a Queue: ";
            cin >> position;

            if (!que.search(position))
                cout << "\nThe Position that you entered does not exist in Queue.\n";
            break;

        case 6:
            cout << "Enter Position that you want to update in a Queue: ";
            cin >> position;
            cout << "Enter value that you want to update in a inputted position in a Queue: ";
            cin >> value;

            if (que.update(position, value))
                cout << "Value is successfully Updated in a Queue\n";
            else
                cout << "The Position that you entered does not exist in Queue.\n";
            break;

        case 7:
            cout << "Count Total Enteries in a Queue: " << que.count();
            break;

        case 8:
            que.display();
            break;

        case 9:
            check = false;
            cout << "\nThank You Very Much For Using This Application\n";
            break;

        default:
            cout << "Error : Invalid Value Detected!\n";
            break;
        }

        cout << "\n";
        system("pause");
    }
    return 0;
}