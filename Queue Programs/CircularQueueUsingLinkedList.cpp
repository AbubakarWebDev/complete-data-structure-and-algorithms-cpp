/***********************************************************************
Using Circular Queue is better than normal queue because there is no memory wastage. Linked list provide the facility of dynamic memory allocation so it is easy to create. When we implement circular Queue using linked list it is similar to circular linked list except there is two pointer front and rear in circular Queue where as circular linked list has only one pointer head. Lets see how to implement Circular Queue using Linked list in C++ Programming.

enqueue(data)
Create a struct node type node.
Insert the given data in the new node data section and NULL in address section.
If Queue is empty then initialize front and rear from new node.
Queue is not empty then initialize rear next and rear from new node.
New node next initialize from front

dequeue()
Check if queue is empty or not.
If queue is empty then dequeue is not possible.
Else Initialize temp from front.
If front is equal to the rear then initialize front and rear from null.
Print data of temp and free temp memory.
If there is more than one node in Queue then make front next to front then initialize rear next from front.
Print temp and free temp.

print()
Check if there is some data in the queue or not.
If the queue is empty print “No data in the queue.”
Else define a node pointer and initialize it with front.
Print data of node pointer until the next of node pointer becomes NULL.
******************************************************************************/ 

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

class CircularQueueUsingLinkedList
{
    SingleNode *front;
    SingleNode *rear;

public:
    CircularQueueUsingLinkedList()
    {
        front = NULL;
        rear = NULL;
    }

    ~CircularQueueUsingLinkedList()
    {
        SingleNode *n = front;
        SingleNode *temp = NULL;

        do
        {
            temp = n;
            n = n->getNext();
            delete temp;
        } while (n != front);

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
            do
            {
                if (ptr->getKey() == key)
                {
                    temp = ptr;
                    break;
                }
                ptr = ptr->getNext();
            } while (ptr != front);
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
            node->setNext(front);
        }
        else
        {
            rear->setNext(node);
            rear = node;
            node->setNext(front);
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
            rear->setNext(front);
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

        do
        {
            n = n->getNext();
            count++;
        } while (n != front);

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
            do
            {
                if (ptr->getNext() == front)
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")"
                         << " -> "
                         << "FRONT\n";
                else
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")"
                         << " -> ";

                ptr = ptr->getNext();
            } while (ptr != front);
        }
    }
};

int main()
{
    CircularQueueUsingLinkedList que;
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