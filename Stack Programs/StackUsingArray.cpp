/******************************************************************
A stack is a linear data structure in which the insertion and deletion operations can be performed at one end called top of the stack. A stack is also called a Last In First Out (LIFO) data structure. Remember Array and Linked list where we can add or remove the data from both the end (front or back). Unlike these data structures, stack allows the user to access only one end.

The bottom is closed. Top of the stack is the only place where we have access to. We can only access item 5 which is at the top of the stack. In order to get to the item 4, we need to remove 5, to get to item 3, we need to remove 4 and 5 and so on. In all the operations we do in the stack, we manipulate the top of the stack in some way. Based on how we use the top, there are three operations we can do on the stack.

1) Push: We insert a new item at the top of the stack.
2) Pop: We remove the item from the top of the stack.
3) Top: We read the value of the item at the top of the stack.

Operations on stack:
Push: A new item can be pushed into a stack using the following steps.
Check if the stack is full. If it is, then you can not insert the item. Raise “Stack Overflow” error.
If the stack is not full, insert the item at the top of the stack.
Make this item a new top of the stack.

Pop: An item on the top of the stack can be removed (popped) using following steps.
Check if the stack is empty. If it is, then you can not remove the item. Raise “Stack Underflow” error.
If the stack is not empty, remove the item at the top of the stack.
Update the top of the stack.

Top (or peek): The top operation returns the item at the top of the stack. Don’t be confused this operation with the pop operation. The pop operation removes the top item whereas the top operation only reads the value of the top item. As in the pop operation, we need to check if the stack is empty before reading the value.
*******************************************************************/ 

#include <iostream>
using namespace std;

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
            for (int i = size - 1; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
            return true;
        }
        return false;
    }
};

int main()
{
    system("cls");
    int size;
    
    cout << "\nPlease First Enter The Size of Stack That You Want to Create: ";
    cin >> size;

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
    return 0;
}