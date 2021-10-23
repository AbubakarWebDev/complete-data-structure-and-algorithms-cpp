/******************************************************************
A Queue is defined by its property of FIFO, which means First in First Out, i.e the element which is added first is taken out first. This behaviour defines a queue, whereas data is actually stored in an array or a list in the background.

What we mean here is that no matter how and where the data is getting stored, if the first element added is the first element being removed and we have implementation of the functions enqueue() and dequeue() to enable this behaviour, we can say that we have implemented a Queue data structure.

While implementing a queue data structure using stacks, we will have to consider the natural behaviour of stack too, which is First in Last Out.

For performing enqueue we require only one stack as we can directly push data onto the stack, but to perform dequeue we will require two Stacks, because we need to follow queue's FIFO property and if we directly pop any data element out of Stack, it will follow LIFO approach(Last in First Out).

The idea is to implement enqueue operation of queue in such a way that the first entered element always ends up at the top of the stack. To achieve this, we need an additional stack.

To enqueue an item in the queue, we first move all elements from the first stack to the second stack, then push item into the first stack, and finally move all elements back to the first stack. This ensures that we push new items everytime at the bottom of the stack and hence we got the property of Queue from two stacks 

To dequeue an item from the queue, we simply return the top item from the first stack.
*******************************************************************/ 

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack
{
    stack <int> stk1, stk2;

    void displayStack(stack <int> stk)
    {
        while (!stk.empty())
        {
            cout << stk.top() << "  ";
            stk.pop();
        }
        cout << '\n';
    }

public:
    bool isEmpty()
    {
        return (stk1.empty());
    }

    bool enque(int value)
    {
        while (!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }

        stk1.push(value);

        while (!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }

        return true;
    }

    int deque()
    {
        if (stk1.empty())
        {
            cout << "\nNo Value is Present on Queue.\n";
            return false;
        }

        int value = stk1.top();
        stk1.pop();

        return value;
    }

    int count()
    {
        return stk1.size();
    }

    void display()
    {
        if (stk1.empty())
        {
            cout << "\nNo Value is Present on Queue.\n";
        }
        else
        {
            cout << "\nYour Queue Values is Given Below\n";
            displayStack(stk1);
        }
    }
};

int main()
{
    QueueUsingStack que;
    int value;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= Queue USING STACK =============|\n"
             << "Please Select the Operation that you want to perform With the Given Options: \n"
             << "1 : Enqeue a Value in a Queue\n"
             << "2 : Deqeue a Value from a Queue\n"
             << "3 : Check Whether a Queue is Empty or Not\n"
             << "4 : Count All Enteries of a Queue\n"
             << "5 : Print All Enteries of a Queue\n"
             << "6 : Exit this Application\n"
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
            if (que.isEmpty())
                cout << "Queue is Empty.\n";
            else
                cout << "Queue is Not Empty.\n";
            break;

        case 4:
            cout << "Count Total Enteries in a Queue: " << que.count();
            break;

        case 5:
            que.display();
            break;

        case 6:
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