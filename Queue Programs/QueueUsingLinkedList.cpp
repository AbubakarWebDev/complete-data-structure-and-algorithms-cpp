/******************************************************************
A queue is an ordered collection of items where the addition of new items happens at one end, called the “rear,” and the removal of existing items occurs at the other end, commonly called the “front.” The first element to be inserted is the first one to be deleted. Hence, it is called First in First out (FIFO) or Last in Last out (LILO) list. Real life example of queues are people standing in queue to buying tickets, ants walking in queue.

Why we want to implement Queue using linked list?
The major problem with the queue implemented using array is, It will work for only fixed number of data values. That means, the amount of data must be specified in the beginning itself.

Queue using array is not suitable when we do not know the size of data which we are going to use.

A queue data structure can be implemented using linked list data structure. The queue which is implemented using linked list can work for unlimited number of values.

That means, queue using linked list can work for variable size of data (No need to fix the size at beginning of the implementation). The Queue implemented using linked list can organize as many data values as we want.

We will implement Queue using linked list. Queues maintain two data pointers:

FRONT to know first inserted element
REAR to know last inserted element.
Queue is very simple data structure, you only have to manipulate FRONT and REAR to get Queue property.

Basic Operation:
Following are basic operations of Queue:

Main Queue Operations:
1)EnQueue(): Inserts an element at the rear of the Queue.
2)DeQueue(): Remove and return the front element of the Queue.

Auxiliary Queue operation:

1) Front(): Display the data front of the Queue.
2) QueueSize(): Returns the number of elements stored in the Queue.
3) display(): Display elements of queue.


*******************************************************************/ 

#include <iostream>
using namespace std;

class SingleNode
{
private:
    int key;
    int value;
    SingleNode *next = NULL;

public:
    SingleNode(int key = 0, int value = 0)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    void setNext(SingleNode *next)
    {
        this->next = next;
    }

    void setValue(int value)
    {
        this->value = value;
    }

    SingleNode *getNext()
    {
        return this->next;
    }

    int getKey()
    {
        return key;
    }

    int getValue()
    {
        return value;
    }
};

class QueueUsingLinkedList
{
    SingleNode *front;
    SingleNode *rear;

public:
    QueueUsingLinkedList()
    {
        front = NULL;
        rear = NULL;
    }

    ~QueueUsingLinkedList()
    {
        SingleNode *node = front;
        SingleNode *temp = NULL;

        while (node != NULL)
        {
            temp = node;
            node = node->getNext();
            delete temp;
        }

        front = NULL;
    }

    bool isEmpty()
    {
        return (rear == NULL && front == NULL);
    }

    SingleNode *nodeExist(int key)
    {
        SingleNode *temp = NULL;
        SingleNode *ptr = front;

        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            while (ptr != NULL)
            {
                if (ptr->getKey() == key)
                {
                    temp = ptr;
                    break;
                }
                ptr = ptr->getNext();
            }
        }

        return temp;
    }

    bool enque(int key, int value)
    {
        SingleNode *node = new SingleNode(key, value);

        if (nodeExist(node->getKey()) != NULL)
        {
            cout << "\nNode Already exists with key value : " << node->getKey() << ". Append another node with different Key value" << endl;
            return false;
        }
        else if (isEmpty())
        {
            rear = front = node;
        }
        else
        {
            rear->setNext(node);
            rear = node;
        }
        return true;
    }

    SingleNode *deque()
    {
        SingleNode *temp = NULL;

        if (isEmpty())
        {
            cout << "\nQueue is Empty. So Value is Not Able to Dequed from Queue\n";
        }
        else if (front == rear)
        {
            temp = front;
            rear = front = NULL;
        }
        else
        {
            temp = front;
            front = front->getNext();
        }
        return temp;
    }

    bool update(int key, int value)
    {
        if (isEmpty())
        {
            cout << "\nNo Value is Present on Queue.\n";
        }
        else
        {
            SingleNode *node = nodeExist(key);

            if (node != NULL)
            {
                node->setValue(value);
                return true;
            }
        }
        return false;
    }

    int count()
    {
        SingleNode *n = front;
        int count = 0;

        while (n != NULL)
        {
            n = n->getNext();
            count++;
        }

        return count;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nNo Values is Present On Queue\n";
        }
        else
        {
            SingleNode *ptr = front;

            cout << "\nYour Queue Values is Given below:\n";
            while (ptr != NULL)
            {
                if (ptr->getNext() == NULL)
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")"
                         << " -> "
                         << "NULL\n";
                else
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")"
                         << " -> ";

                ptr = ptr->getNext();
            }
        }
    }
};

int main()
{
    QueueUsingLinkedList que;
    int key, value;
    SingleNode *node;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= Queue USING Linked List =============|\n"
             << "Please Select the Operation that you want to perform With the Given Options: \n"
             << "1 : Enqeue a Value in a Queue\n"
             << "2 : Deqeue a Value from a Queue\n"
             << "3 : Check Whether a Queue is Empty or Not\n"
             << "4 : Get a Value from a Specific key of Queue\n"
             << "5 : Update Value to a Specific key of Queue\n"
             << "6 : Count All Enteries of a Queue\n"
             << "7 : Print All Enteries of a Queue\n"
             << "8 : Exit this Application\n"
             << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Unique Key For Enqeueing in a Queue: ";
            cin >> key;
            cout << "Enter Value For Enqeueing in a Queue: ";
            cin >> value;

            if (que.enque(key, value))
                cout << "Value is successfully Enqeued in Queue\n";
            break;

        case 2:
            node = que.deque();

            if (node != NULL)
            {
                cout << "\nValue is successfully deqeued From Queue\nYour deqeued Key Value Pair is: (" << node->getKey() << ", " << node->getValue() << ")\n";
                delete node;
            }
            break;

        case 3:
            if (que.isEmpty())
                cout << "Queue is Empty.\n";
            else
                cout << "Queue is Not Empty.\n";
            break;

        case 4:
            cout << "Enter key that you want to search in a Queue: ";
            cin >> key;

            node = que.nodeExist(key);

            if (node == NULL)
                cout << "The key that you entered does not exist in Queue.\n";
            else
                cout << "Your Searched Key Value Pair is: (" << node->getKey() << ", " << node->getValue() << ")";

            break;

        case 5:
            cout << "Enter key that you want to update in a Queue: ";
            cin >> key;
            cout << "Enter value that you want to update in a inputted key in a Queue: ";
            cin >> value;

            if (que.update(key, value))
                cout << "Value is successfully Updated in a Queue\n";
            else
                cout << "The key that you entered does not exist in Queue.\n";
            break;

        case 6:
            cout << "Count Total Enteries in a Queue: " << que.count();
            break;

        case 7:
            que.display();
            break;

        case 8:
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