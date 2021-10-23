/***********************************************************
Doubly Linked list is a type of Linked List Data structure which behaves like a two way list/chain. The reason it is called a two way list or two way chain is because we can traverse this list in two directions: (1) start from the head node to the end. (2) go back in the reverse direction.

                HEAD
                 ^
NULL <- (1, "Pointer to Next") <--> (2, "Pointer to Next") <--> (3, "Pointer to Next") -> NULL

As you can see from the diagram, each node object has 1 data field & 2 pointer fields. The data field contains the actual data where as the pointer fields(next & previous pointers) points to the next node & previous node in the doubly linked list. Since the nodes are not stored in contiguous memory locations, these extra pointer fields assists in locating the next & previous nodes in memory. As we have 2 pointers: one pointing to the next node and one pointing to the previous node, we can traverse in 2 directions starting from the head node to the end and vice versa.
************************************************************/

#include <iostream>
using namespace std;

class DoubleNode
{
private:
    int key;
    int value;
    DoubleNode *next;
    DoubleNode *prev;

public:
    DoubleNode(int key = 0, int value = 0)
    {
        this->key = key;
        this->value = value;
        next = NULL;
        prev = NULL;
    }

    void setNext(DoubleNode *next)
    {
        this->next = next;
    }

    void setPrev(DoubleNode *prev)
    {
        this->prev = prev;
    }

    void setValue(int value)
    {
        this->value = value;
    }

    DoubleNode *getNext()
    {
        return this->next;
    }

    DoubleNode *getPrev()
    {
        return this->prev;
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

class DoublyLinkedList
{
private:
    DoubleNode *Head;

public:
    DoublyLinkedList()
    {
        Head = NULL;
    }

    ~DoublyLinkedList()
    {
        DoubleNode *n = Head;
        DoubleNode *temp = NULL;

        while (n != NULL)
        {
            temp = n;
            n = n->getNext();
            delete temp;
        }

        Head = NULL;
    }

    bool isEmpty()
    {
        return Head == NULL;
    }

    DoubleNode *nodeExist(int key)
    {
        DoubleNode *temp = NULL;
        DoubleNode *ptr = Head;

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

    bool appendNode(int key, int value)
    {
        DoubleNode *n = new DoubleNode(key, value);

        if (nodeExist(n->getKey()) != NULL)
        {
            cout << "\nNode Already exists with key value : " << n->getKey() << ". Append another node with different Key value" << endl;
        }
        else
        {
            if (isEmpty())
            {
                Head = n;
                return true;
            }
            else
            {
                DoubleNode *ptr = Head;
                while (ptr->getNext() != NULL)
                {
                    ptr = ptr->getNext();
                }
                ptr->setNext(n);
                n->setPrev(ptr);
                return true;
            }
        }
        return false;
    }

    bool prependNode(int key, int value)
    {
        DoubleNode *n = new DoubleNode(key, value);

        if (nodeExist(n->getKey()) != NULL)
        {
            cout << "\nNode Already exists with key value : " << n->getKey() << ". Preppend another node with different Key value" << endl;
        }
        else
        {
            if (isEmpty())
            {
                Head = n;
                return true;
            }
            else
            {
                n->setNext(Head);
                Head->setPrev(n);
                Head = n;
                return true;
            }
        }
        return false;
    }

    bool insertNodeAfter(int key, int value, int findKey)
    {
        DoubleNode *n = new DoubleNode(key, value);
        DoubleNode *ptr = nodeExist(findKey);

        if (ptr == NULL)
        {
            cout << "\nPlease Enter Valid Key of Node that You want to find\n";
        }
        else
        {
            if (nodeExist(n->getKey()) != NULL)
            {
                cout << "\nNode Already exists with key value : " << key << ". Insert another node with different Key value" << endl;
            }
            else
            {
                if (ptr->getNext() == NULL)
                {
                    ptr->setNext(n);
                    n->setPrev(ptr);
                    return true;
                }
                else
                {
                    n->setNext(ptr->getNext());
                    ptr->getNext()->setPrev(n);
                    n->setPrev(ptr);
                    ptr->setNext(n);
                    return true;
                }
            }
        }
        return false;
    }

    bool insertNodeBefore(int key, int value, int findKey)
    {
        DoubleNode *n = new DoubleNode(key, value);
        DoubleNode *ptr = nodeExist(findKey);

        if (ptr == NULL)
        {
            cout << "\nPlease Enter Valid Key of Node that You want to find\n";
        }
        else
        {
            if (nodeExist(n->getKey()) != NULL)
            {
                cout << "\nNode Already exists with key value : " << key << ". Insert another node with different Key value" << endl;
            }
            else
            {
                if (ptr == Head)
                {
                    n->setNext(Head);
                    Head->setPrev(n);
                    Head = n;
                    return true;
                }
                else
                {
                    n->setNext(ptr);
                    n->setPrev(ptr->getPrev());
                    ptr->getPrev()->setNext(n);
                    ptr->setPrev(n);
                    return true;
                }
            }
        }
        return false;
    }

    bool updateNode(int key, int value)
    {
        DoubleNode *ptr = nodeExist(key);

        if (ptr == NULL)
        {
            cout << "\nPlease Enter Valid Key For Updating Node\n";
        }
        else
        {
            ptr->setValue(value);
            return true;
        }
        return false;
    }

    bool updateAllNodes(int value)
    {
        if (isEmpty())
        {
            cout << "\nYour Linked List is Empty\n";
        }
        else
        {
            DoubleNode *ptr = Head;
            while (ptr != NULL)
            {
                updateNode(ptr->getKey(), value);
                ptr = ptr->getNext();
            }
            return true;
        }
        return false;
    }

    bool deleteNode(int key)
    {
        DoubleNode *ptr = nodeExist(key);

        if (ptr == NULL)
        {
            cout << "\nPlease Enter Valid Key For Deleting Node\n";
        }
        else
        {
            if (ptr == Head)
            {
                Head = Head->getNext();
                Head->setPrev(NULL);
                delete ptr;
                return true;
            }
            else
            {
                DoubleNode *n = Head;

                while (n->getNext() != ptr)
                {
                    n = n->getNext();
                }

                if (ptr->getNext() == NULL)
                {
                    n->setNext(NULL);
                    delete ptr;
                    return true;
                }
                else
                {
                    n->setNext(ptr->getNext());
                    ptr->getNext()->setPrev(n);
                    delete ptr;
                    return true;
                }
            }
        }
        return false;
    }

    bool deleteAllNodes()
    {
        if (isEmpty())
        {
            cout << "\nYour Linked List is Empty\n";
        }
        else
        {
            DoubleNode *n = Head;
            DoubleNode *temp = NULL;

            while (n != NULL)
            {
                temp = n;
                n = n->getNext();
                delete temp;
            }

            Head = NULL;
            return true;
        }
        return false;
    }

    int countAllNodes()
    {
        DoubleNode *n = Head;
        int count = 0;

        while (n != NULL)
        {
            n = n->getNext();
            count++;
        }

        return count;
    }

    void displayListReverse()
    {
        if (isEmpty())
        {
            cout << "\nNo Values in a Linked List\n";
        }
        else
        {
            DoubleNode *ptr = Head;

            while (ptr->getNext() != NULL)
            {
                ptr = ptr->getNext();
            }

            DoubleNode *temp = ptr;

            cout << "\n\nDoubly Linked List Reversed Values:\n";
            while (ptr != NULL)
            {
                if (ptr->getPrev() == NULL)
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " -> " << "NULL\n";
                else if (ptr == temp)
                    cout << "NULL <- (" << ptr->getKey() << "," << ptr->getValue() << ")" << " <--> ";
                else 
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " <--> ";

                ptr = ptr->getPrev();
            }
        }
    }

    void displayList()
    {
        if (isEmpty())
        {
            cout << "\nNo Values in a Linked List\n";
        }
        else
        {
            DoubleNode *ptr = Head;
            cout << "\n\nDoubly Linked List Values:\n";
            while (ptr != NULL)
            {
                if (ptr->getNext() == NULL)
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " -> " << "NULL\n";
                else if (ptr == Head)
                    cout << "NULL <- (" << ptr->getKey() << "," << ptr->getValue() << ")" << " <--> ";
                else 
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " <--> ";

                ptr = ptr->getNext();   
            }
        }
    }
};

int main()
{
    DoublyLinkedList list;
    DoubleNode *ptr;
    int key, value, findkey;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= Double Linked Lists =============|\n"
             << "Please Select the Operation that you want to perform With the Given Options: \n"
             << "1 : Append Node In a Linked List\n"
             << "2 : Prepend Node In a Linked List\n"
             << "3 : Insert Node After a Specific Position\n"
             << "4 : Insert Node Before a Specific Position\n"
             << "5 : Update Node In a Linked List\n"
             << "6 : Update All Nodes In a Linked List\n"
             << "7 : Delete Node from a Linked List\n"
             << "8 : Delete All Nodes from a Linked List\n"
             << "9 : Search a Specific Nodes In a Linked List\n"
             << "10 : Count All Nodes from a Linked List\n"
             << "11 : Print Complete Linked List\n"
             << "12 : Print Complete Linked List In Reverse Order\n"
             << "13 : Exit This Application\n"
             << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Unique Key For Appending Your Node: ";
            cin >> key;
            cout << "Enter Value For Appending Your Node: ";
            cin >> value;
            if (list.appendNode(key, value))
            {
                cout << "\nYour Node is Appended Successfully\n";
            }
            break;

        case 2:
            cout << "Enter Unique Key For Prepending Your Node: ";
            cin >> key;
            cout << "Enter Value For Prepending Your Node: ";
            cin >> value;
            if (list.prependNode(key, value))
            {
                cout << "\nYour Node is Prepended Successfully\n";
            }
            break;

        case 3:
            cout << "Enter Unique Key For Inserting Your Node: ";
            cin >> key;
            cout << "Enter Value For Inserting Your Node: ";
            cin >> value;
            cout << "Enter Find Key For Inserting Node After this position : ";
            cin >> findkey;
            if (list.insertNodeAfter(key, value, findkey))
            {
                cout << "\nYour Node is Inserted Successfully\n";
            }
            break;

        case 4:
            cout << "Enter Unique Key For Inserting Your Node: ";
            cin >> key;
            cout << "Enter Value For Inserting Your Node: ";
            cin >> value;
            cout << "Enter Find Key For Inserting Node Before this position : ";
            cin >> findkey;
            if (list.insertNodeBefore(key, value, findkey))
            {
                cout << "\nYour Node is Inserted Successfully\n";
            }
            break;

        case 5:
            cout << "Enter Find Key For Node that you want to update: ";
            cin >> key;
            cout << "Enter Value For Updating the Node: ";
            cin >> value;
            if (list.updateNode(key, value))
            {
                cout << "\nYour Node is Updated Successfully\n";
            }
            break;

        case 6:
            cout << "Enter Value For Updating All the Node in Linked List: ";
            cin >> value;
            if (list.updateAllNodes(value))
            {
                cout << "\nYour All Nodes is Updated Successfully\n";
            }
            break;

        case 7:
            cout << "Enter Find Key For Node that you want to Delete: ";
            cin >> key;
            if (list.deleteNode(key))
            {
                cout << "\nYour Node is Deleted Successfully\n";
            }
            break;

        case 8:
            if (list.deleteAllNodes())
            {
                cout << "\nYour All Node is Deleted Successfully\n";
            }
            break;

        case 9:
            cout << "Enter Find Key For Node that you want to Search its value: ";
            cin >> key;

            ptr = list.nodeExist(key);

            if (ptr == NULL)
            {
                cout << "\nYour Node is Not Found in List with this key\n";
            }
            else
            {
                cout << "Your Node Value is: " << ptr->getValue();
            }
            break;

        case 10:
            cout << "Total Count of Nodes in a Linked List: " << list.countAllNodes();
            break;

        case 11:
            list.displayList();
            break;

        case 12:
            list.displayListReverse();
            break;

        case 13:
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
