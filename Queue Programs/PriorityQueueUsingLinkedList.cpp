/******************************************************************
We are given with the data and the priority as an integer value and the task is to create a linked list as per the priority given and display the result.

Queue is a FIFO data structure in which the element which is inserted first is the first one to get removed. A Priority Queue is a type of queue in which elements can be inserted or deleted depending upon the priority. It can be implemented using queue, stack or linked list data structure. Priority queue is implemented by following these rules −

Data or element with the highest priority will get executed before the data or element with the lowest priority.
If two elements have the same priority than they will be executed in the sequence they are added in the list.
A node of a linked list for implementing priority queue will contain three parts −

Data − It will store the integer value.
Address − It will store the address of a next node
Priority −It will store the priority which is an integer value. It can range from 0-10 where 0 represents the highest priority and 10 represents the lowest priority.
*******************************************************************/ 

#include <iostream>
using namespace std;

class SingleNode
{
private:
    int key;
    int value;
    int priority;
    SingleNode *next = NULL;

public:
    SingleNode(int key = 0, int priority = 0, int value = 0)
    {
        this->key = key;
        this->value = value;
        this->priority = priority;
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

    void setPriority(int priority)
    {
        this->priority = priority;
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

    int getPriority()
    {
        return priority;
    }
};

class PriorityQueueUsingLinkedList
{
    SingleNode *front;
    SingleNode *rear;

public:
    PriorityQueueUsingLinkedList()
    {
        front = NULL;
        rear = NULL;
    }

    ~PriorityQueueUsingLinkedList()
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

    bool enque(int key, int priority, int value)
    {
        SingleNode *node = new SingleNode(key, priority, value);

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
            SingleNode *start = front;

            // Special Case: The front node of list has
            // lesser priority than new node. So
            // insert newnode before front node
            // and change front node.
            if (front->getPriority() < priority)
            {
                // Insert New Node before front node
                node->setNext(front);
                front = node;
            }
            else
            {
                // Traverse the list and find a
                // position to insert new node
                while (start->getNext() != NULL && start->getNext()->getPriority() > priority)
                {
                    start = start->getNext();
                }

                // Either at the ends of the list
                // or at required position
                node->setNext(start->getNext());
                start->setNext(node);
            }
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
    PriorityQueueUsingLinkedList que;
    SingleNode *node;
    int key, priority, value;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= PRIORITY QUEUE USING LINKED LIST =============|\n"
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
            cout << "Enter Priority For Enqeueing in a Queue: ";
            cin >> priority;

            if (que.enque(key, priority, value))
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