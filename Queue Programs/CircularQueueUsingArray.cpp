/******************************************************************
Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called ‘Ring Buffer’. 

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Applications: 
1) Memory Management: The unused memory locations in the case of ordinary queues can be utilized in circular queues.
2) Traffic system: In computer controlled traffic system, circular queues are used to switch on the traffic lights one by one repeatedly as per the time set.
3) CPU Scheduling: Operating systems often maintain a queue of processes that are ready to execute or that are waiting for a particular event to occur.
*******************************************************************/ 

#include <iostream>
using namespace std;

class CircularQueueUsingArray
{
    int size;
    int *arr;
    int front;
    int rear;
    int itemCount;

public:
    CircularQueueUsingArray(int size = 5)
    {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->itemCount = 0;
        this->arr = new int[this->size];

        for (int i = 0; i < this->size; i++)
        {
            arr[i] = 0;
        }
    }

    ~CircularQueueUsingArray()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return (rear == -1 && front == -1);
    }

    bool isFull()
    {
        return (((rear + 1) % size) == front);
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
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        itemCount++;
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
            front = (front + 1) % size;
        }

        itemCount--;
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
            return (itemCount);
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
    int size;
    cout << "\nPlease First Enter The Size of Queue That You Want to Create: ";
    cin >> size;

    CircularQueueUsingArray que(size);
    int position, value;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= Circular Queue USING ARRAY =============|\n"
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
