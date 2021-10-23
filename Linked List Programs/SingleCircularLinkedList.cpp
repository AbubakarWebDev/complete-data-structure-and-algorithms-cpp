/***********************************************************
Circular linked list is a type of Linked List Data structure which behaves like a one way list/chain. The reason it is called a one way list or one way chain is because we can only traverse this list in one direction, start from the head node to the end. However unlike Singly Linked List in this type of linked list we can traverse from the last node to the first in a circular one directional pattern.

        HEAD
         ^
(1, "Pointer to Next") -> (2, "Pointer to Next") -> (3, "Pointer to Next") -> HEAD

As you can see from the diagram, each node object has 1 data field & 1 pointer field. The data field contains the actual data where as the pointer field(next pointer) points to the next node in the singly linked list. Since the nodes are not stored in contiguous memory locations, this extra pointer field assists in locating the next node in memory. As we have only one pointer pointing to the next node, we can only traverse in one direction starting from the head node to the end. However unlike singly linked list, the last node in this circular linked list is storing address of the first head node. Thus you can traverse back from the last node to the first node.
************************************************************/

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

class SingleCircularLinkedList
{
private:
    SingleNode *Head;

public:
    SingleCircularLinkedList()
    {
        Head = NULL;
    }

    ~SingleCircularLinkedList()
    {
        SingleNode *n = Head;
        SingleNode *temp = NULL;

        do
        {
            temp = n;
            n = n->getNext();
            delete temp;
        } while (n != Head);

        Head = NULL;
    }

    bool isEmpty()
    {
        return Head == NULL;
    }

    SingleNode *nodeExist(int key)
    {
        SingleNode *temp = NULL;
        SingleNode *ptr = Head;

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
            } while (ptr != Head);
        }

        return temp;
    }

    bool appendNode(int key, int value)
    {
        SingleNode *n = new SingleNode(key, value);

        if (nodeExist(n->getKey()) != NULL)
        {
            cout << "\nNode Already exists with key value : " << n->getKey() << ". Append another node with different Key value" << endl;
        }
        else
        {
            if (isEmpty())
            {
                Head = n;
                n->setNext(Head);
                return true;
            }
            else
            {
                SingleNode *ptr = Head;
                while (ptr->getNext() != Head)
                {
                    ptr = ptr->getNext();
                }
                ptr->setNext(n);
                n->setNext(Head);
                return true;
            }
        }
        return false;
    }

    bool prependNode(int key, int value)
    {
        SingleNode *n = new SingleNode(key, value);

        if (nodeExist(n->getKey()) != NULL)
        {
            cout << "\nNode Already exists with key value : " << n->getKey() << ". Append another node with different Key value" << endl;
        }
        else
        {
            if (isEmpty())
            {
                Head = n;
                n->setNext(Head);
                return true;
            }
            else
            {
                SingleNode *ptr = Head;

                while (ptr->getNext() != Head)
                {
                    ptr = ptr->getNext();
                }

                ptr->setNext(n);
                n->setNext(Head);
                Head = n;
                return true;
            }
        }
        return false;
    }

    bool insertNodeAfter(int key, int value, int findKey)
    {
        SingleNode *n = new SingleNode(key, value);
        SingleNode *ptr = nodeExist(findKey);

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
                n->setNext(ptr->getNext());
                ptr->setNext(n);
                return true;
            }
        }
        return false;
    }

    bool insertNodeBefore(int key, int value, int findKey)
    {
        SingleNode *n = new SingleNode(key, value);
        SingleNode *ptr = nodeExist(findKey);

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
                    SingleNode *ptr = Head;

                    do
                    {
                        ptr = ptr->getNext();
                    } while (ptr->getNext() != Head);

                    n->setNext(Head);
                    Head = n;
                    ptr->setNext(Head);
                    return true;
                }
                else
                {
                    SingleNode *prev = Head;

                    while (prev->getNext() != ptr)
                    {
                        prev = prev->getNext();
                    }

                    prev->setNext(n);
                    n->setNext(ptr);
                    return true;
                }
            }
        }
        return false;
    }

    bool updateNode(int key, int value)
    {
        SingleNode *ptr = nodeExist(key);

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
            SingleNode *ptr = Head;

            do
            {
                updateNode(ptr->getKey(), value);
                ptr = ptr->getNext();
            } while (ptr != Head);

            return true;
        }
        return false;
    }

    bool deleteNode(int key)
    {
        SingleNode *ptr = nodeExist(key);

        if (ptr == NULL)
        {
            cout << "\nPlease Enter Valid Key For Deleting Node\n";
        }
        else
        {
            if (ptr == Head)
            {
                if (countAllNodes() == 1)
                {
                    Head = NULL;
                }
                else
                {
                    SingleNode *n = Head;
                    while (n->getNext() != Head)
                    {
                        n = n->getNext();
                    }

                    Head = Head->getNext();
                    n->setNext(Head);
                }

                delete ptr;
                return true;
            }
            else
            {
                SingleNode *n = Head;

                while (n->getNext() != ptr)
                {
                    n = n->getNext();
                }

                n->setNext(ptr->getNext());
                delete ptr;
                return true;
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
            SingleNode *n = Head;
            SingleNode *temp = NULL;

            do
            {
                temp = n;
                n = n->getNext();
                delete temp;
            } while (n != Head);

            Head = NULL;
            return true;
        }
        return false;
    }

    int countAllNodes()
    {
        SingleNode *n = Head;
        int count = 0;

        do
        {
            n = n->getNext();
            count++;
        } while (n != Head);

        return count;
    }

    bool reverseAllNodes()
    {
        if (isEmpty())
        {
            cout << "\nYour Linked List is Empty\n";
        }
        else
        {
            SingleNode *current = Head;
            SingleNode *prev = NULL, *next = NULL;

            do
            {
                next = current->getNext();
                current->setNext(prev);
                prev = current;
                current = next;
            } while (current != Head);

            Head = prev;

            SingleNode *ptr = Head;

            while (ptr->getNext() != NULL)
            {
                ptr = ptr->getNext();
            }

            ptr->setNext(Head);
            return true;
        }
        return false;
    }

    void displayList()
    {
        if (isEmpty())
        {
            cout << "\nNo Values in a Linked List\n";
        }
        else
        {
            SingleNode *ptr = Head;
            cout << "\n\nCircular Linked List Values:\n";
            do
            {
                if (ptr->getNext() == Head)
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " -> " << "HEAD\n";
                else 
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " -> ";

                ptr = ptr->getNext();   
            } while (ptr != Head);
        }
    }
};

int main()
{
    SingleCircularLinkedList list;
    SingleNode *ptr;
    int key, value, findkey;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= Single Circular Linked Lists =============|\n"
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
            if (list.reverseAllNodes())
            {
                list.displayList();
            }
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
