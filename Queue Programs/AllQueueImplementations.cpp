/******************************************************************
Queue Data Structure:
Queue is a linear data structure which operates in a First IN First OUT or Last IN Last OUT.
It is named queue as it behaves like a real-world queue, for example: queue(line) of cars in a single lane, queue of people waiting at food counter etc.
Queue is an abstract data type with a bounded (predefined) capacity.
It is a simple data structure that allows adding and removing elements in a particular order.
The order is FIFO(First IN First OUT) or LILO(Last In Last Out).

Standard Queue Operations: 
Enqueue(): Add item to the queue from the REAR.
Dequeue(): Remove item from the queue from the FRONT.
isFull(): Check if queue is full or not.
isEmpty(): Check if queue empty or not.
count(): Get number of items in the queue.

Some types of Queue (We will discuss them in detail in other articles):
1) Simple Queue (Implementation using array and linkedlist)
2) Circular Queue (Implementation using array and linkedlist)
3) Priority Queue (Implementation using array and linkedlist)

Some Applications of Queue Data Structure:
Queue is used when things but have to be processed in First In First Out order. Like:
1) CPU scheduling, Disk Scheduling.
2) Handling of interrupts in real-time systems. The interrupts are handled in the same order as they arrive, First come first served.
3) In real life, Call Center phone systems will use Queues, to hold people calling them in an order, until a service representative is free.
4) When data is transferred asynchronously between two processes. Queue is used for synchronization.
*******************************************************************/ 

#include <iostream>
#include <stack>
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

class QueueUsingStack
{
    stack<int> stk1, stk2;

    void displayStack(stack<int> stk)
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

class QueueUsingArray
{
    int size;
    int *arr;
    int front;
    int rear;

public:
    QueueUsingArray(int size = 5)
    {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->arr = new int[this->size];

        for (int i = 0; i < this->size; i++)
        {
            arr[i] = 0;
        }
    }

    ~QueueUsingArray()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return (rear == -1 && front == -1);
    }

    bool isFull()
    {
        return (front == 0 && (rear == size - 1));
    }

    bool enque(int value)
    {
        if (isFull())
        {
            cout << "\nQueue is Full. So Value is Not Able to Enqued in Queue\n";
            return false;
        }
        else if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            if (rear == size - 1)
            {
                for (int i = front; i <= rear; i++)
                {
                    arr[i - front] = arr[i];
                }

                rear = rear - front;
                front = 0;
            }
            rear++;
        }

        arr[rear] = value;
        return true;
    }

    int deque()
    {
        int x = 0;

        if (isEmpty())
        {
            cout << "\nQueue is Empty. So Value is Not Able to Dequed from Queue\n";
            return false;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            rear = front = -1;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
        }

        return x;
    }

    bool search(int position)
    {
        if (isEmpty())
        {
            cout << "\nNo Value is Present on Queue.\n";
            return false;
        }
        else if (rear == front)
        {
            if (rear == position)
            {
                cout << "\nYour Search Values is: " << arr[position] << "\n";
                return true;
            }
        }
        else
        {
            if (position >= front && position <= rear)
            {
                cout << "\nYour Search Values is: " << arr[position] << "\n";
                return true;
            }
        }
        return false;
    }

    bool update(int position, int value)
    {
        if (isEmpty())
        {
            cout << "\nNo Value is Present on Queue.\n";
            return false;
        }
        else if (rear == front)
        {
            if (rear == position)
            {
                arr[position] = value;
                return true;
            }
        }
        else
        {
            if (position >= front && position <= rear)
            {
                arr[position] = value;
                return true;
            }
        }
        return false;
    }

    int count()
    {
        if (isEmpty())
            return 0;
        else
            return (rear - front + 1);
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

class QueueUsingLinkedList
{
    SingleNode *front;
    SingleNode *rear;

public:
    QueueUsingLinkedList()
    {
        front = NULL;
        rear = NULL;
    }

    ~QueueUsingLinkedList()
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
        }
        else
        {
            rear->setNext(node);
            rear = node;
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

class CircularQueueUsingArray
{
    int size;
    int *arr;
    int front;
    int rear;
    int itemCount;

public:
    CircularQueueUsingArray(int size = 5)
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

    ~CircularQueueUsingArray()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return (rear == -1 && front == -1);
    }

    bool isFull()
    {
        return (((rear + 1) % size) == front);
    }

    bool enque(int value)
    {
        if (isFull())
        {
            cout << "\nQueue is Full. So Value is Not Able to Enqued in Queue\n";
            return false;
        }
        else if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        itemCount++;
        return true;
    }

    int deque()
    {
        int x = 0;

        if (isEmpty())
        {
            cout << "\nQueue is Empty. So Value is Not Able to Dequed from Queue\n";
            return false;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            rear = front = -1;
        }
        else
        {
            x = arr[front];
            front = (front + 1) % size;
        }

        itemCount--;
        return x;
    }

    bool search(int position)
    {
        if (isEmpty())
        {
            cout << "\nNo Value is Present on Queue.\n";
            return false;
        }
        else if (rear == front)
        {
            if (rear == position)
            {
                cout << "\nYour Search Values is: " << arr[position] << "\n";
                return true;
            }
        }
        else
        {
            if (position >= front && position <= rear)
            {
                cout << "\nYour Search Values is: " << arr[position] << "\n";
                return true;
            }
        }
        return false;
    }

    bool update(int position, int value)
    {
        if (isEmpty())
        {
            cout << "\nNo Value is Present on Queue.\n";
            return false;
        }
        else if (rear == front)
        {
            if (rear == position)
            {
                arr[position] = value;
                return true;
            }
        }
        else
        {
            if (position >= front && position <= rear)
            {
                arr[position] = value;
                return true;
            }
        }
        return false;
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

class PriorityQueueUsingArray
{
    int size;
    int rear;
    int front;
    int *dataArr;
    int *priorityArr;

public:
    PriorityQueueUsingArray(int size = 5)
    {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->dataArr = new int[this->size];
        this->priorityArr = new int[this->size];

        for (int i = 0; i < this->size; i++)
        {
            dataArr[i] = 0;
            priorityArr[i] = 0;
        }
    }

    ~PriorityQueueUsingArray()
    {
        delete[] dataArr;
        delete[] priorityArr;
    }

    bool isEmpty()
    {
        return (rear == -1 && front == -1);
    }

    bool isFull()
    {
        return (front == 0 && (rear == size - 1));
    }

    bool enque(int priority, int value)
    {
        if (isFull())
        {
            cout << "\nQueue is Full. So Value is Not Able to Enqued in Queue\n";
            return false;
        }
        else if (isEmpty())
        {
            rear = front = 0;
            dataArr[rear] = value;
            priorityArr[rear] = priority;
        }
        else if (rear == size - 1)
        {
            for (int i = front; i <= rear; i++)
            {
                dataArr[i - front] = dataArr[i];
                priorityArr[i - front] = priorityArr[i];
            }

            rear = rear - front;
            front = 0;

            int i = 0;
            for (i = rear; i >= front; i--)
            {
                if (priority > priorityArr[i])
                {
                    dataArr[i + 1] = dataArr[i];
                    priorityArr[i + 1] = priorityArr[i];
                }
                else
                {
                    break;
                }
            }

            dataArr[i + 1] = value;
            priorityArr[i + 1] = priority;
            rear++;
        }
        else
        {
            int i = 0;
            for (i = rear; i >= front; i--)
            {
                if (priority > priorityArr[i])
                {
                    dataArr[i + 1] = dataArr[i];
                    priorityArr[i + 1] = priorityArr[i];
                }
                else
                {
                    break;
                }
            }

            dataArr[i + 1] = value;
            priorityArr[i + 1] = priority;
            rear++;
        }

        return true;
    }

    int deque()
    {
        int x = 0;

        if (isEmpty())
        {
            cout << "\nQueue is Empty. So Value is Not Able to Dequed from Queue\n";
            return false;
        }
        else if (front == rear)
        {
            x = dataArr[front];
            dataArr[front] = 0;
            priorityArr[front] = 0;
            rear = front = -1;
        }
        else
        {
            x = dataArr[front];
            dataArr[front] = 0;
            priorityArr[front] = 0;
            front++;
        }

        return x;
    }

    bool search(int position)
    {
        if (isEmpty())
        {
            cout << "\nNo Value is Present on Queue.\n";
            return false;
        }
        else if (rear == front)
        {
            if (rear == position)
            {
                cout << "\nYour Search Values is: " << dataArr[position] << "\n";
                return true;
            }
        }
        else
        {
            if (position >= front && position <= rear)
            {
                cout << "\nYour Search Values is: " << dataArr[position] << "\n";
                return true;
            }
        }
        return false;
    }

    bool update(int position, int value)
    {
        if (isEmpty())
        {
            cout << "\nNo Value is Present on Queue.\n";
            return false;
        }
        else if (rear == front)
        {
            if (rear == position)
            {
                dataArr[position] = value;
                return true;
            }
        }
        else
        {
            if (position >= front && position <= rear)
            {
                dataArr[position] = value;
                return true;
            }
        }
        return false;
    }

    int count()
    {
        if (isEmpty())
            return 0;
        else
            return (rear - front + 1);
    }

    void display()
    {
        cout << "\nYour Queue Values is Given Below\n";
        for (int i = 0; i < size; i++)
        {
            cout << dataArr[i] << "  ";
        }
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

class AllQueueImplementations
{
private:
    void QueueUsingStackMenu()
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
    }

    void QueueUsingArrayMenu()
    {
        int size;
        cout << "\nPlease First Enter The Size of Queue That You Want to Create: ";
        cin >> size;

        QueueUsingArray que(size);
        int position, value;
        bool check = true;

        while (check)
        {
            system("cls");
            int choice;
            cout << "\n\n|============= Queue USING ARRAY =============|\n"
                 << "Please Select the Operation that you want to perform With the Given Options: \n"
                 << "1 : Enqeue a Value in a Queue\n"
                 << "2 : Deqeue a Value from a Queue\n"
                 << "3 : Check Whether a Queue is Full or Not\n"
                 << "4 : Check Whether a Queue is Empty or Not\n"
                 << "5 : Get a Value from a Specific Position of Queue\n"
                 << "6 : Update Value to a Specific Position of Queue\n"
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

                if (que.enque(value))
                    cout << "Value is successfully Enqeued in Queue\n";
                break;

            case 2:
                value = que.deque();

                if (value)
                    cout << "\nValue is successfully deqeued From Queue\nYour deqeued Value is: " << value << "\n";
                break;

            case 3:
                if (que.isFull())
                    cout << "Queue is Full.\n";
                else
                    cout << "Queue is Not Full.\n";
                break;

            case 4:
                if (que.isEmpty())
                    cout << "Queue is Empty.\n";
                else
                    cout << "Queue is Not Empty.\n";
                break;

            case 5:
                cout << "Enter Position that you want to search in a Queue: ";
                cin >> position;

                if (!que.search(position))
                    cout << "\nThe Position that you entered does not exist in Queue.\n";
                break;

            case 6:
                cout << "Enter Position that you want to update in a Queue: ";
                cin >> position;
                cout << "Enter value that you want to update in a inputted position in a Queue: ";
                cin >> value;

                if (que.update(position, value))
                    cout << "Value is successfully Updated in a Queue\n";
                else
                    cout << "The Position that you entered does not exist in Queue.\n";
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
    }

    void QueueUsingLinkedListMenu()
    {
        QueueUsingLinkedList que;
        SingleNode *node;
        int key, value;
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
    }

    void CircularQueueUsingArrayMenu()
    {
        int size;
        cout << "\nPlease First Enter The Size of Queue That You Want to Create: ";
        cin >> size;

        CircularQueueUsingArray que(size);
        int position, value;
        bool check = true;

        while (check)
        {
            system("cls");
            int choice;
            cout << "\n\n|============= Circular Queue USING ARRAY =============|\n"
                 << "Please Select the Operation that you want to perform With the Given Options: \n"
                 << "1 : Enqeue a Value in a Queue\n"
                 << "2 : Deqeue a Value from a Queue\n"
                 << "3 : Check Whether a Queue is Full or Not\n"
                 << "4 : Check Whether a Queue is Empty or Not\n"
                 << "5 : Get a Value from a Specific Position of Queue\n"
                 << "6 : Update Value to a Specific Position of Queue\n"
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

                if (que.enque(value))
                    cout << "Value is successfully Enqeued in Queue\n";
                break;

            case 2:
                value = que.deque();

                if (value)
                    cout << "\nValue is successfully deqeued From Queue\nYour deqeued Value is: " << value << "\n";
                break;

            case 3:
                if (que.isFull())
                    cout << "Queue is Full.\n";
                else
                    cout << "Queue is Not Full.\n";
                break;

            case 4:
                if (que.isEmpty())
                    cout << "Queue is Empty.\n";
                else
                    cout << "Queue is Not Empty.\n";
                break;

            case 5:
                cout << "Enter Position that you want to search in a Queue: ";
                cin >> position;

                if (!que.search(position))
                    cout << "\nThe Position that you entered does not exist in Queue.\n";
                break;

            case 6:
                cout << "Enter Position that you want to update in a Queue: ";
                cin >> position;
                cout << "Enter value that you want to update in a inputted position in a Queue: ";
                cin >> value;

                if (que.update(position, value))
                    cout << "Value is successfully Updated in a Queue\n";
                else
                    cout << "The Position that you entered does not exist in Queue.\n";
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
    }

    void CircularQueueUsingLinkedListMenu()
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
    }

    void PriorityQueueUsingArrayMenu()
    {
        int size;
        cout << "\nPlease First Enter The Size of Queue That You Want to Create: ";
        cin >> size;

        PriorityQueueUsingArray que(size);
        int position, priority, value;
        bool check = true;

        while (check)
        {
            system("cls");
            int choice;
            cout << "\n\n|============= PRIORITY QUEUE USING ARRAY =============|\n"
                 << "Please Select the Operation that you want to perform With the Given Options: \n"
                 << "1 : Enqeue a Value in a Queue\n"
                 << "2 : Deqeue a Value from a Queue\n"
                 << "3 : Check Whether a Queue is Full or Not\n"
                 << "4 : Check Whether a Queue is Empty or Not\n"
                 << "5 : Get a Value from a Specific Position of Queue\n"
                 << "6 : Update Value to a Specific Position of Queue\n"
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
                cout << "Enter Priority For Enqeueing in a Queue: ";
                cin >> priority;

                if (que.enque(priority, value))
                    cout << "Value is successfully Enqeued in Queue\n";
                break;

            case 2:
                value = que.deque();

                if (value)
                    cout << "\nValue is successfully deqeued From Queue\nYour deqeued Value is: " << value << "\n";
                break;

            case 3:
                if (que.isFull())
                    cout << "Queue is Full.\n";
                else
                    cout << "Queue is Not Full.\n";
                break;

            case 4:
                if (que.isEmpty())
                    cout << "Queue is Empty.\n";
                else
                    cout << "Queue is Not Empty.\n";
                break;

            case 5:
                cout << "Enter Position that you want to search in a Queue: ";
                cin >> position;

                if (!que.search(position))
                    cout << "\nThe Position that you entered does not exist in Queue.\n";
                break;

            case 6:
                cout << "Enter Position that you want to update in a Queue: ";
                cin >> position;
                cout << "Enter value that you want to update in a inputted position in a Queue: ";
                cin >> value;

                if (que.update(position, value))
                    cout << "Value is successfully Updated in a Queue\n";
                else
                    cout << "The Position that you entered does not exist in Queue.\n";
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
    }

    void PriorityQueueUsingLinkedListMenu()
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
    }

public:
    void mainMenu()
    {
        bool check = true;
        while (check)
        {
            system("cls");
            int choice;
            cout << "\n\n|============= ALL QUEUE IMPLEMENTATIONS =============|\n"
                 << "Please Select Your QUEUE With the Given Options: \n"
                 << "1 : Queue Using Stack\n"
                 << "2 : Queue Using Array\n"
                 << "3 : Queue Using Linked List\n"
                 << "4 : Circular Queue Using Array\n"
                 << "5 : Circular Queue Using Linked List\n"
                 << "6 : Priority Queue Using Array\n"
                 << "7 : Priority Queue Using Linked List\n"
                 << "8 : Exit Application\n"
                 << "Enter Your Choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                QueueUsingStackMenu();
                return;
                break;

            case 2:
                QueueUsingArrayMenu();
                return;
                break;

            case 3:
                QueueUsingLinkedListMenu();
                return;
                break;

            case 4:
                CircularQueueUsingArray();
                return;
                break;

            case 5:
                CircularQueueUsingLinkedList();
                return;
                break;

            case 6:
                PriorityQueueUsingArray();
                return;
                break;

            case 7:
                PriorityQueueUsingLinkedList();
                return;
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
    }
};

int main()
{
    AllQueueImplementations Que;
    Que.mainMenu();
    return 0;
}
