/**********************************************************
Link List Data Structure:
A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers(entity that point to the next element)
In simple words, a linked list consists of nodes where each node contains a data field and a reference(link) to the next node in the list.

Link: Each link of a linked list can store a data called an element.
Next: Each link of a linked list contains a link to the next link called Next.
LinkedList: A Linked List contains the connection link to the first link called Head.

Basic Operations:
Following are the basic operations supported by a list.
a) Insertion: Adds a new node to a specific position on the list
b) Deletion: Remove/Delink a node from a specific position on the list
c) Appending: Adds an element at the last of the list.
d) Preppending: Adds an element at the beginning of the list.
e) Displaying: Displays the complete Linked list.
f) Counting: Displays the Size (Total Number of Nodes) of Linked list.

Some Applications of Linked List DS :–
Linked Lists can be used to implement Stacks , Queues.
Linked Lists can also be used to implement Graphs. (Adjacency list representation of Graph).
Implementing Hash Tables :- Each Bucket of the hash table can itself be a linked list. (Open chain hashing).
Undo functionality in Photoshop or Word . Linked list of states.

Types of Linked List:
Following are the various types of linked list:-
1) Single Linked List: Item navigation is forward only.
2) Doubly Linked List: Items can be navigated forward and backward.
3) Single Circular Linked List: Last item contains link of the first element as next and the first element has a link to the last element as previous and Item navigation is forward only.
4) Double Circular Linked List: Items can be navigated forward and backward as well as Last item contains link of the first element as next and the first element has a link to the last element as previous.

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

class SinglyLinkedList
{
private:
    SingleNode *Head;

public:
    SinglyLinkedList()
    {
        Head = NULL;
    }

    ~SinglyLinkedList()
    {
        SingleNode *n = Head;
        SingleNode *temp = NULL;

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
                return true;
            }
            else
            {
                SingleNode *ptr = Head;
                while (ptr->getNext() != NULL)
                {
                    ptr = ptr->getNext();
                }
                ptr->setNext(n);
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
                return true;
            }
            else
            {
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
                    n->setNext(Head);
                    Head = n;
                    return true;
                }
                else
                {
                    SingleNode *prev = Head;
                    while (prev->getNext() != ptr)
                    {
                        prev = prev->getNext();
                    }

                    n->setNext(ptr);
                    prev->setNext(n);
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
        SingleNode *ptr = nodeExist(key);

        if (ptr == NULL)
        {
            cout << "\nPlease Enter Valid Key For Deleting Node\n";
        }
        else
        {
            if (ptr == Head)
            {
                Head = Head->getNext();
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
        SingleNode *n = Head;
        int count = 0;

        while (n != NULL)
        {
            n = n->getNext();
            count++;
        }

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

            while (current != NULL)
            {
                next = current->getNext();
                current->setNext(prev);
                prev = current;
                current = next;
            }

            Head = prev;
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
            cout << "\n\nSingly Linked List Values:\n";
            while (ptr != NULL)
            {
                if (ptr->getNext() == NULL)
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " -> " << "NULL\n";
                else 
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " -> ";

                ptr = ptr->getNext();   
            }
        }
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

class DoubleCircularLinkedList
{
private:
    DoubleNode *Head;

public:
    DoubleCircularLinkedList()
    {
        Head = NULL;
    }

    ~DoubleCircularLinkedList()
    {
        DoubleNode *n = Head;
        DoubleNode *temp = NULL;

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
                n->setNext(Head);
                n->setPrev(Head);
                return true;
            }
            else
            {
                DoubleNode *ptr = Head;

                do
                {
                    ptr = ptr->getNext();
                } while (ptr->getNext() != Head);

                ptr->setNext(n);
                n->setPrev(ptr);
                n->setNext(Head);
                Head->setPrev(n);
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
                n->setNext(Head);
                n->setPrev(Head);
                return true;
            }
            else
            {
                DoubleNode *ptr = Head;
                n->setNext(Head);
                Head->setPrev(n);

                do
                {
                    ptr = ptr->getNext();
                } while (ptr->getNext() != Head);

                Head = n;
                ptr->setNext(Head);
                Head->setPrev(ptr);
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
                if (ptr->getNext() == Head)
                {
                    ptr->setNext(n);
                    n->setPrev(ptr);
                    n->setNext(Head);
                    Head->setPrev(n);
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
                    DoubleNode *ptr = Head;
                    n->setNext(Head);
                    Head->setPrev(n);

                    do
                    {
                        ptr = ptr->getNext();
                    } while (ptr->getNext() != Head);

                    Head = n;
                    ptr->setNext(Head);
                    Head->setPrev(ptr);

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
        DoubleNode *ptr = nodeExist(key);

        if (ptr == NULL)
        {
            cout << "\nPlease Enter Valid Key For Deleting Node\n";
        }
        else
        {
            if (ptr == Head) // For First Node
            {
                if (countAllNodes() == 1)
                {
                    Head = NULL;
                }
                else
                {
                    DoubleNode *temp = Head;

                    while (temp->getNext() != Head)
                    {
                        temp = temp->getNext();
                    }

                    Head = Head->getNext();
                    Head->setPrev(temp);
                    temp->setNext(Head);
                }

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

                if (ptr->getNext() == Head) // For Last Node
                {
                    n->setNext(Head);
                    Head->setPrev(n);
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
        DoubleNode *n = Head;
        int count = 0;

        do
        {
            n = n->getNext();
            count++;
        } while (n != Head);

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

            while (ptr->getNext() != Head)
            {
                ptr = ptr->getNext();
            }

            DoubleNode *temp = ptr;

            cout << "\n\nDouble Circular Linked List Reversed Values:\n";

            do
            {
                if (ptr->getPrev() == temp)
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " -> " << "TAIL\n";
                else if (ptr == temp)
                    cout << "HEAD <- (" << ptr->getKey() << "," << ptr->getValue() << ")" << " <--> ";
                else 
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " <--> ";

                ptr = ptr->getPrev(); 
            } while (ptr != temp);
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
            cout << "\n\nDouble Circular Linked List Values:\n";
            do
            {
                if (ptr->getNext() == Head)
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " -> " << "HEAD\n";
                else if (ptr == Head)
                    cout << "TAIL <- (" << ptr->getKey() << "," << ptr->getValue() << ")" << " <--> ";
                else 
                    cout << "(" << ptr->getKey() << "," << ptr->getValue() << ")" << " <--> ";

                ptr = ptr->getNext();   

            } while (ptr != Head);
        }
    }
};

class AllLinkedList
{
private:
    void singlyLinkedListMenu()
    {
        SinglyLinkedList list;
        SingleNode *ptr;
        int key, value, findkey;
        bool check = true;

        while (check)
        {
            system("cls");
            int choice;
            cout << "\n\n|============= Singly Linked Lists =============|\n"
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
    }

    void doublyLinkedListMenu()
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
    }

    void singleCircularLinkedListMenu()
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
    }

    void doubleCircularLinkedListMenu()
    {
        DoubleCircularLinkedList list;
        DoubleNode *ptr;
        int key, value, findkey;
        bool check = true;

        while (check)
        {
            system("cls");
            int choice;
            cout << "\n\n|============= Double Circular Linked Lists =============|\n"
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
    }

public:
    void mainMenu()
    {
        bool check = true;
        while (check)
        {
            system("cls");
            int choice;
            cout << "\n\n|============= ALL Linked Lists =============|\n"
                 << "Please Select Your Linked Linked With the Given Options: \n"
                 << "1 : Singly Linked List\n"
                 << "2 : Doubly Linked List\n"
                 << "3 : Single Circular Linked List\n"
                 << "4 : Double Circular Linked List\n"
                 << "5 : Exit Application\n"
                 << "Enter Your Choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                singlyLinkedListMenu();
                return;
                break;

            case 2:
                doublyLinkedListMenu();
                return;
                break;

            case 3:
                singleCircularLinkedListMenu();
                return;
                break;

            case 4:
                doubleCircularLinkedListMenu();
                return;
                break;

            case 5:
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
    }
};

int main()
{
    AllLinkedList list;
    list.mainMenu();
    return 0;
}