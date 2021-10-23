/******************************************************************
Deque or Double Ended Queue is a type of queue in which insertion and removal of elements can be performed from the both Ends, i.e. front or rear. Thus, it does not follow FIFO rule (First In First Out).

Implementation of Double ended Queue:
Below is the circular array implementation of deque. In a circular array, if the array is full, we start from the beginning. But in a linear array implementation, if the array is full, no more elements can be inserted. In each of the operations below, if the array is full, "overflow message" is thrown. Here we will implement a double ended queue using a circular array. It will have the following methods:

1) push_front: inserts element at front
2) push_back: inserts element at back
3) pop_front: removes first element
4) pop_back: removes last element
5) get_front: returns first element
6) get_back: returns last element
7) full: returns true if queue is full
8) empty: returns true if queue is empty


1) push_front: inserts element at front
First we check if the queue is full. If its not full we insert an element at front end by following the given conditions:
a) If the queue is empty then intialize front and rear to 0. Both will points to the first element.
b) Else we decrement front and insert the element. Since we are using circular array, we have to keep in mind that if front is equal to 0 then instead of decreasing it by 1 we make it equal to SIZE-1.

void Dequeue::push_front(int key)
{
    if(full())
    {
        cout << "OVERFLOW\n";
    }
    else
    {
    	//If queue is empty
    	if (front == -1)
    		front = rear = 0;

    	//If front points to the first position element 
        else if (front == 0)
            front = SIZE-1;
        
        else
        	--front;
        
        arr[front] = key;
    }
}

2) push_back: inserts element at back
Again we check if the queue is full. If its not full we insert an element at back by following the given conditions:
a) If the queue is empty then intialize front and rear to 0. Both will point to the first element.
b) Else we increment rear and insert the element. Since we are using circular array, we have to keep in mind that if rear is equal to SIZE-1 then instead of increasing it by 1 we make it equal to 0.

void Dequeue::push_back(int key)
{
    if(full())
    {
        cout << "OVERFLOW\n";
    }
    else
    {
        //If queue is empty
    	   if(front == -1)
    		  front = rear = 0;

    	   //If rear points to the last element
        else if(rear == SIZE-1)
            rear = 0;
        
        else
        	++rear;
        
        arr[rear] = key;
    }    
}

3) pop_front: removes first element
In order to do this, we first check if the queue is empty. If its not then delete the front element by following the given conditions:
a) If only one element is present we once again make front and rear equal to -1.
b) Else we increment front. But we have to keep in mind that if front is equal to SIZE-1 then instead of increasing it by 1 we make it equal to 0.

void Dequeue :: pop_front()
{
    if(empty())
    {
        cout << "UNDERFLOW\n";
    }
    else
    {
    	//If only one element is present
        if(front == rear)
        	front = rear = -1;

        //If front points to the last element 
        else if(front == SIZE-1)
        	front = 0;

        else
        	++front;		
    }
}

4) pop_back: removes last element
Inorder to do this, we again first check if the queue is empty. If its not then we delete the last element by following the given conditions:
a) If only one element is present we make front and rear equal to -1.
b) Else we decrement rear. But we have to keep in mind that if rear is equal to 0 then instead of decreasing it by 1 we make it equal to SIZE-1.

void Dequeue :: pop_back()
{
    if(empty())
    {
        cout << "UNDERFLOW\n";
    }
    else
    {
    	//If only one element is present
        if(front == rear)
        	front = rear = -1;

        //If rear points to the first position element 
        else if(rear == 0)
        	rear = SIZE-1;

        else
        	--rear;		
    }
}

5) get_front: returns first element
If the queue is not empty then we simply return the value stored in the position which front points.

int Dequeue :: get_front()
{
    if(empty())
    {	cout << "f=" <<front << endl;
        cout << "UNDERFLOW\n";
        return -1;
    }
    else
    {
        return arr[front];
    }
}

6) get_back: returns last element
If the queue is not empty then we simply return the value stored in the position which rear points.

int Dequeue :: get_back()
{
    if(empty())
    {
        cout << "UNDERFLOW\n";
        return -1;
    }
    else
    {
        return arr[rear];
    }
}

7) full: returns true if queue is full
Since we are using circular array, we check for following conditions as shown in code to check if queue is full.

bool Dequeue :: full()
{
    if((front == 0 && rear == SIZE-1)  ||
    	(front == rear + 1))
        return true;
    else
        return false;
}

8) empty: returns true if queue is empty
It can be simply checked by looking where front points to. If front is still intialized with -1, the queue is empty.

bool Dequeue :: empty()
{
    if(front == -1)
    	return true;
    else
    	return false;
}

*******************************************************************/

// Here is Complete Implementation of Double Ended Queue:
#include <iostream>
using namespace std;

class DoubleEndedQueue
{
    int size;
    int *arr;
    int front;
    int rear;
    int itemCount;

public:
    DoubleEndedQueue(int size = 5)
    {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->itemCount = 0;
        this->arr = new int[this->size];

        for (int i = 0; i < this->size; i++)
        {
            arr[i] = 0;
        }
    }

    ~DoubleEndedQueue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    void push_front(int key)
    {
        if (isFull())
        {
            cout << "\nQueue is Full. So Value is Not Able to Enqued in Queue\n";
        }
        else
        {
            //If queue is empty
            if (front == -1)
                front = rear = 0;

            //If front points to the first position element
            else if (front == 0)
                front = size - 1;

            else
                --front;

            arr[front] = key;
            itemCount++;
        }
    }

    void push_back(int key)
    {
        if (isFull())
        {
            cout << "\nQueue is Full. So Value is Not Able to Enqued in Queue\n";
        }
        else
        {
            //If queue is empty
            if (front == -1)
                front = rear = 0;

            //If rear points to the last element
            else if (rear == size - 1)
                rear = 0;

            else
                ++rear;

            arr[rear] = key;
            itemCount++;
        }
    }

    void pop_front()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty. So Value is Not Able to Dequed from Queue\n";
        }
        else
        {
            //If only one element is present
            if (front == rear)
                front = rear = -1;

            //If front points to the last element
            else if (front == size - 1)
                front = 0;

            else
                ++front;
        }
    }

    void pop_back()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty. So Value is Not Able to Dequed from Queue\n";
        }
        else
        {
            //If only one element is present
            if (front == rear)
                front = rear = -1;

            //If rear points to the first position element
            else if (rear == 0)
                rear = size - 1;

            else
                --rear;
        }
    }

    int get_front()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty. So Value is Not Able to Get from Queue\n";
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int get_back()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty. So Value is Not Able to Get from Queue\n";
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    int count()
    {
        if (isEmpty())
            return 0;
        else
            return (itemCount);
    }

    void display()
    {
        cout << "\nYour Queue Values is Given Below\n";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "  ";
        }
    }
};

int main()
{
    int size;
    cout << "\nPlease First Enter The Size of Queue That You Want to Create: ";
    cin >> size;

    DoubleEndedQueue que(size);
    int position, value;
    bool check = true;

    while (check)
    {
        system("cls");
        int choice;
        cout << "\n\n|============= DOUBLE ENDED QUEUE USING ARRAY =============|\n"
             << "Please Select the Operation that you want to perform With the Given Options: \n"
             << "1 : Enqeue a Value On a Front End of Queue\n"
             << "2 : Enqeue a Value On a Rear End of Queue\n"
             << "3 : Deqeue a Value from a Front End of Queue\n"
             << "4 : Deqeue a Value from a Rear End of Queue\n"
             << "5 : Check Whether a Queue is Full or Not\n"
             << "6 : Check Whether a Queue is Empty or Not\n"
             << "7 : Count All Enteries of a Queue\n"
             << "8 : Print All Enteries of a Queue\n"
             << "9 : Exit this Application\n"
             << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value For Enqeueing in a Queue: ";
            cin >> value;

            que.push_front(value);
            cout << "Value is successfully Enqeued in Queue\n";
            break;

        case 2:
            cout << "Enter Value For Enqeueing in a Queue: ";
            cin >> value;

            que.push_back(value);
            cout << "Value is successfully Enqeued in Queue\n";
            break;

        case 3:
            value = que.get_front();
            cout << "\nValue is successfully deqeued From Front End of Queue\nYour deqeued Value is: " << value << "\n";
            que.pop_front();
            break;

        case 4:
            value = que.get_back();
            cout << "\nValue is successfully deqeued From Rear End of Queue\nYour deqeued Value is: " << value << "\n";
            que.pop_back();
            break;

        case 5:
            if (que.isFull())
                cout << "Queue is Full.\n";
            else
                cout << "Queue is Not Full.\n";
            break;

        case 6:
            if (que.isEmpty())
                cout << "Queue is Empty.\n";
            else
                cout << "Queue is Not Empty.\n";
            break;

        case 7:
            cout << "Count Total Enteries in a Queue: " << que.count();
            break;

        case 8:
            que.display();
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
    return 0;
}
