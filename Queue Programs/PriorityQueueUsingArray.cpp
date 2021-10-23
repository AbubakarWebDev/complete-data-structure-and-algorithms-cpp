/******************************************************************
A priority queue is a special type of queue in which each element is associated with a priority and is served according to its priority. If elements with the same priority occur, they are served according to their order in the queue.

Generally, the value of the element itself is considered for assigning the priority.

For example, The element with the highest value is considered as the highest priority element. However, in other cases, we can assume the element with the lowest value as the highest priority element. In other cases, we can set custom priorities according to our needs.

Implementation of Priority Queue:
Priority queue can be implemented using an array, a linked list, a heap data structure, or a binary search tree. Among these data structures, heap data structure provides an efficient implementation of priority queues. Priority Queue implementation using array is the one of the basic method to implement Queue.In Priority Queue data who has highest priority remove from the Queue first and second highest priority element after it and so on.In priority Queue each element has its own priority.If priority is same for two elements then data remove on the basis of first come first serve.

Insertion:
1) Ask the data and its priority from the user.
2) If front is equal to 0 and rear is equal to n-1 then Queue is full.
3) Else if front is equal to the -1 them queue is empty so we have initialize front and rear with 0.
4) Insert the data entered by user in Queue using rear.
5) If rear is equal to n-1 and front is not equal to 0 then there is empty space in queue before the front for using that space we will shift the elements of the queue with the help of front and rear.
6) Insert the data in the queue before at the position where given priority is greater then priority of the element in queue.

Deletion:
1) Remove the element and the priority from the front of the queue.
2) Increase front with 1.

Print:
1) Using loop take the starting point from the front of the queue and ending point from the rear of the queue and print the data
*******************************************************************/ 

#include <iostream>
using namespace std;

class PriorityQueueUsingArray
{
    int size;
    int rear;
    int front;
    int *dataArr;
    int *priorityArr;

public:
    PriorityQueueUsingArray(int size = 5)
    {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->dataArr = new int[this->size];
        this->priorityArr = new int[this->size];

        for (int i = 0; i < this->size; i++)
        {
            dataArr[i] = 0;
            priorityArr[i] = 0;
        }
    }

    ~PriorityQueueUsingArray()
    {
        delete[] dataArr;
        delete[] priorityArr;
    }

    bool isEmpty()
    {
        return (rear == -1 && front == -1);
    }

    bool isFull()
    {
        return (front == 0 && (rear == size - 1));
    }

    bool enque(int priority, int value)
    {
        if (isFull())
        {
            cout << "\nQueue is Full. So Value is Not Able to Enqued in Queue\n";
            return false;
        }
        else if (isEmpty())
        {
            rear = front = 0;
            dataArr[rear] = value;
            priorityArr[rear] = priority;
        }
        else if (rear == size - 1)
        {
            for (int i = front; i <= rear; i++)
            {
                dataArr[i - front] = dataArr[i];
                priorityArr[i - front] = priorityArr[i];
            }

            rear = rear - front;
            front = 0;

            int i = 0;
            for (i = rear; i >= front; i--)
            {
                if (priority > priorityArr[i])
                {
                    dataArr[i + 1] = dataArr[i];
                    priorityArr[i + 1] = priorityArr[i];
                }
                else
                {
                    break;
                }
            }

            dataArr[i + 1] = value;
            priorityArr[i + 1] = priority;
            rear++;
        }
        else
        {
            int i = 0;
            for (i = rear; i >= front; i--)
            {
                if (priority > priorityArr[i])
                {
                    dataArr[i + 1] = dataArr[i];
                    priorityArr[i + 1] = priorityArr[i];
                }
                else
                {
                    break;
                }
            }

            dataArr[i + 1] = value;
            priorityArr[i + 1] = priority;
            rear++;
        }
        
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
            x = dataArr[front];
            dataArr[front] = 0;
            priorityArr[front] = 0;
            rear = front = -1;
        }
        else
        {
            x = dataArr[front];
            dataArr[front] = 0;
            priorityArr[front] = 0;
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
                cout << "\nYour Search Values is: " << dataArr[position] << "\n";
                return true;
            }
        }
        else
        {
            if (position >= front && position <= rear)
            {
                cout << "\nYour Search Values is: " << dataArr[position] << "\n";
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
                dataArr[position] = value;
                return true;
            }
        }
        else
        {
            if (position >= front && position <= rear)
            {
                dataArr[position] = value;
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
            cout << dataArr[i] << "  ";
        }
    }
};

int main()
{
    int size;
    cout << "\nPlease First Enter The Size of Queue That You Want to Create: ";
    cin >> size;

    PriorityQueueUsingArray que(size);
    int position, priority, value;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= PRIORITY QUEUE USING ARRAY =============|\n"
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
            cout << "Enter Priority For Enqeueing in a Queue: ";
            cin >> priority;

            if (que.enque(priority, value))
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