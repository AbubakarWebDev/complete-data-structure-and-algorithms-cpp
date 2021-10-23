/******************************************************************
Implement a stack using single linked list concept. all the single linked list operations perform based on Stack operations LIFO(last in first out) and with the help of that knowledge we are going to implement a stack using single linked list. using single linked lists so how to implement here it is linked list means what we are storing the information in the form of nodes and we need to follow the stack rules and we need to implement using single linked list nodes so what are the rules we need to follow in the implementation of a stack a simple rule that is last in first out and all the operations we should perform so with the help of a top variable.

A stack can be easily implemented through the linked list. In stack Implementation, a stack contains a top pointer. which is “head” of the stack where pushing and popping items happens at the head of the list. first node have null in link field and second node link have first node address in link field and so on and last node address in “top” pointer.

The main advantage of using linked list over an arrays is that it is possible to implements a stack that can shrink or grow as much as needed. In using array will put a restriction to the maximum capacity of the array which can lead to stack overflow. Here each new node will be dynamically allocate. so overflow is not possible.

Stack Operations:
push() : Insert the element into linked list nothing but which is the top node of Stack.
pop() : Return top element from the Stack and move the top pointer to the second node of linked list or Stack.
peek(): Return the top element.
display(): Print all element of Stack.
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

class StackUsingLinkedList
{
private:
    SingleNode *top;

public:
    StackUsingLinkedList()
    {
        top = NULL;
    }

    ~StackUsingLinkedList()
    {
        SingleNode *node = top;
        SingleNode *temp = NULL;

        while (node != NULL)
        {
            temp = node;
            node = node->getNext();
            delete temp;
        }

        top = NULL;
    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    SingleNode *nodeExist(int key)
    {
        SingleNode *temp = NULL;
        SingleNode *ptr = top;

        if (ptr != NULL)
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

    bool push(int key, int value)
    {
        SingleNode *new_node = new SingleNode(key, value);

        if (nodeExist(new_node->getKey()) != NULL)
        {
            cout << "\nNode Already exists with this key: " << new_node->getKey() << ". Push node with different Key" << endl;
        }
        else
        {
            if (isEmpty())
            {
                top = new_node;
                return true;
            }
            else
            {
                new_node->setNext(top);
                top = new_node;
                return true;
            }
        }
        return false;
    }

    SingleNode *pop()
    {
        SingleNode *temp = NULL;

        if (isEmpty())
        {
            cout << "\nError: Stack Underflow. Stack is Empty\n";
        }
        else
        {
            temp = top;
            top = top->getNext();
        }
        return temp;
    }

    SingleNode *peek()
    {
        if (isEmpty())
        {
            cout << "\nError: Stack Underflow. Stack is Empty\n";
        }
        else
        {
            return top;
        }
        return NULL;
    }

    bool update(int key, int value)
    {
        SingleNode *node = nodeExist(key);

        if (isEmpty())
        {
            cout << "\nStack is Empty. No Value is Present on Stack\n";
        }
        else
        {
            if (node == NULL)
            {
                cout << "\nNode With this Key Does Not Exist in Stack\n";
            }
            else
            {
                node->setValue(value);
                return true;
            }
        }
        return false;
    }

    int count()
    {
        int count = 0;
        SingleNode *temp = top;

        while (temp != NULL)
        {
            count++;
            temp = temp->getNext();
        }

        return count;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty. No Value in present in stack";
        }
        else
        {
            SingleNode *temp = top;
            cout << "All values in the Stack are :" << endl;
            while (temp != NULL)
            {
                cout << "Key: " << temp->getKey() << " Value: " << temp->getValue() << "\n";
                temp = temp->getNext();
            }
            cout << endl;
        }
    }
};

int main()
{
    StackUsingLinkedList stk;
    SingleNode *node;
    int key, value;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= STACK USING LINKED LIST =============|\n"
             << "Please Select the Operation that you want to perform With the Given Options: \n"
             << "1 : Push a Value in a Stack\n"
             << "2 : Pop a Value from a Stack\n"
             << "3 : Peek Value from a Stack\n"
             << "4 : Check Whether a Stack is Empty or Not\n"
             << "5 : Get a Value from a Specific Position in Stack\n"
             << "6 : Update a Value to a Specific Position in Stack\n"
             << "7 : Count All Enteries of a Stack\n"
             << "8 : Print All Enteries of a Stack\n"
             << "9 : Exit This Application\n"
             << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Key For Push Node in a stack: ";
            cin >> key;
            cout << "Enter Value For Push Node in a stack: ";
            cin >> value;

            if (stk.push(key, value))
                cout << "\nYour Key Value pair is successfully Pushed in Stack\n";
            break;

        case 2:
            node = stk.pop();

            if (node != NULL)
            {
                cout << "\nValue is Successfully Poped From Stack.\n";
                cout << "Your Poped Key Value Pair is: (" << node->getKey() << ", " << node->getValue() << ")\n";
                delete node;
            }
            break;

        case 3:
            node = stk.peek();

            if (node != NULL)
            {
                cout << "\nValue is Successfully Peeked From Stack.\n";
                cout << "Your Peek Key Value Pair is: "
                     << "(" << node->getKey() << ", " << node->getValue() << ")\n";
            }

            break;

        case 4:
            if (stk.isEmpty())
                cout << "Stack is Empty.\n";
            else
                cout << "Stack is Not Empty.\n";
            break;

        case 5:

            cout << "\nEnter Key For a Node that you want to searches in a stack: ";
            cin >> key;

            node = stk.nodeExist(key);

            if (node != NULL)
            {
                cout << "\nValue is Successfully find in Stack.\n";
                cout << "Your Searched Key Value Pair is: "
                     << "(" << node->getKey() << ", " << node->getValue() << ")\n";
            }
            else
                cout << "\nPlease Enter Valid Key. Node with this Key Does Not Exist in Stack.\n";
            break;

        case 6:
            cout << "\nEnter Key For Push Node in a stack: ";
            cin >> key;
            cout << "\nEnter Value For Push Node in a stack: ";
            cin >> value;

            if (stk.update(key, value))
            {
                cout << "Your Value is Successfully Updated in Stack.\n";
            }
            break;

        case 7:
            cout << "\nCount Total Enteries in a Stack are: " << stk.count() << "\n";
            break;

        case 8:
            stk.display();
            break;

        case 9:
            cout << "\nThanks For Using this Application\n";
            check = false;
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