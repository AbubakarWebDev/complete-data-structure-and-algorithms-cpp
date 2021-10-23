/************************************************
A stack is a linear data structure in which the insertion and deletion operations can be performed at one end called top of the stack. A stack is also called a Last In First Out (LIFO) data structure. Remember Array and Linked list where we can add or remove the data from both the end (front or back). Unlike these data structures, stack allows the user to access only one end.

The bottom is closed. Top of the stack is the only place where we have access to. We can only access item 5 which is at the top of the stack. In order to get to the item 4, we need to remove 5, to get to item 3, we need to remove 4 and 5 and so on. In all the operations we do in the stack, we manipulate the top of the stack in some way. Based on how we use the top, there are three operations we can do on the stack.

1) Push: We insert a new item at the top of the stack.
2) Pop: We remove the item from the top of the stack.
3) Top: We read the value of the item at the top of the stack.
******************************************************/

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

class StackUsingArray
{
    int size;
    int *arr;
    int top;

public:
    StackUsingArray(int size = 5)
    {
        this->size = size;
        this->top = -1;
        this->arr = new int[this->size];

        for (int i = 0; i < this->size; i++)
        {
            arr[i] = 0;
        }
    }

    ~StackUsingArray()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == (size - 1);
    }

    bool push(int value)
    {
        if (!isFull())
        {
            top++;
            arr[top] = value;
            return true;
        }
        return false;
    }

    int pop()
    {
        if (!isEmpty())
        {
            int popvalue = arr[top];
            arr[top] = 0;
            top--;
            return popvalue;
        }
        return false;
    }

    int peek()
    {
        if (!isEmpty())
        {
            return arr[top];
        }
        return false;
    }

    int count()
    {
        return (top + 1);
    }

    int peek(int position)
    {
        if (!isEmpty())
        {
            if (position >= 0 && position <= top)
            {
                return arr[position];
            }
        }
        return false;
    }

    bool update(int position, int value)
    {
        if (!isEmpty())
        {
            if (position >= 0 && position <= top)
            {
                arr[position] = value;
                return true;
            }
        }
        return false;
    }

    bool display()
    {
        if (!isEmpty())
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
            return true;
        }
        return false;
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

class AllStackImplementation
{
private:
    void StackUsingArrayMenu(int size)
    {
        StackUsingArray stk(size);
        int position, value;
        bool check = true;

        while (check)
        {
            system("cls");
            int choice;
            cout << "\n\n|============= STACK USING ARRAY =============|\n"
                 << "Please Select the Operation that you want to perform With the Given Options: \n"
                 << "1 : Push a Value in a Stack\n"
                 << "2 : Pop a Value from a Stack\n"
                 << "3 : Check Whether a Stack is Full or Not\n"
                 << "4 : Check Whether a Stack is Empty or Not\n"
                 << "5 : Peek a Value from Stack\n"
                 << "6 : Get a Value from a Specific Position of Stack\n"
                 << "7 : Update Value to a Specific Position of Stack\n"
                 << "8 : Count All Enteries of a Stack\n"
                 << "9 : Print All Enteries of a Stack\n"
                 << "10 : Exit this Application\n"
                 << "Enter Your Choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                if (stk.isFull())
                    cout << "Stack Overflow Error: Stack is Full.\n";
                else
                {
                    cout << "Enter Value For Push in a stack: ";
                    cin >> value;

                    if (stk.push(value))
                        cout << "Value is successfully Pushed in Stack\n";
                }
                break;

            case 2:
                if (stk.isEmpty())
                    cout << "Stack Underflow Error: Stack is Empty.\n";
                else
                {
                    int value = stk.pop();
                    cout << "Value is successfully Poped From Stack\nYour Poped Value is: " << value << "\n";
                }
                break;

            case 3:
                if (stk.isFull())
                    cout << "Stack is Full.\n";
                else
                    cout << "Stack is Not Full.\n";
                break;

            case 4:
                if (stk.isEmpty())
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is Not Empty.\n";
                break;

            case 5:
                if (!stk.peek())
                    cout << "Stack is Empty. No Value is Present in Stack\n";
                else
                    cout << "Peek Value of Stack is: " << stk.peek() << "\n";
                break;

            case 6:
                if (stk.isEmpty())
                    cout << "Error: Stack is Empty.\n";
                else
                {
                    cout << "Enter Position that you want to peek from a stack: ";
                    cin >> position;

                    if (!(position >= 0 && position <= stk.peek()))
                        cout << "This Position does not exist in stack.\n";

                    if (stk.peek(position))
                        cout << "Value is successfully Peeked from a stack\nYour Peeked Value is: " << stk.peek(position) << "\n";
                }
                break;

            case 7:
                if (stk.isEmpty())
                    cout << "Error: Stack is Empty.\n";
                else
                {
                    cout << "Enter Position that you want to update in a stack: ";
                    cin >> position;
                    cout << "Enter value that you want to update in a inputted position in a stack: ";
                    cin >> value;

                    if (!(position >= 0 && position <= stk.peek()))
                        cout << "This Position does not exist in stack.\n";

                    if (stk.update(position, value))
                        cout << "Value is successfully Updated in a stack\n";
                }
                break;

            case 8:
                cout << "Count Total Enteries in a Stack: " << stk.count();
                break;

            case 9:
                if (stk.isEmpty())
                    cout << "Stack is Empty.\n";
                else
                {
                    cout << "All values in a Stack:\n";
                    stk.display();
                }
                break;

            case 10:
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

    void StackUsingLinkedListMenu()
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
                 << "9 : Exit this Application\n"
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
            int size;
            cout << "\n\n|============= ALL STACK IMPLEMENTATION =============|\n"
                 << "Please Select Your Favourite Stack Implementation With the Given Options: \n"
                 << "1 : Stack using Array\n"
                 << "2 : Stack using Linked List\n"
                 << "3 : Exit Application\n"
                 << "Enter Your Choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                system("cls");
                cout << "\nPlease First Enter The Size of Stack That You Want to Create: ";
                cin >> size;
                StackUsingArrayMenu(size);
                return;
                break;

            case 2:
                StackUsingLinkedListMenu();
                return;
                break;

            case 3:
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
    AllStackImplementation stk;
    stk.mainMenu();
    return 0;
}