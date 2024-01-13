#include <iostream>
using namespace std;

int front = -1;
int rear = -1;
int queue[10];
int size = sizeof(queue) / sizeof(queue[0]);

void insert(int data)
{
    if (rear == size - 1 && front == 0 || front != 0 && rear + 1 == front)
    {
        cout << "Queue is overflow.."<<endl;
        return;
    }

    if (front != 0 && rear == size - 1)
    {
        rear = 0;
        return;
    }

    ++rear;
    queue[rear] = data;
    if (front == -1)
    {
        front = 0;
    }
}

void display()
{

    cout << "queue -> ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {

            cout << queue[i] << " | ";
        }
    }
    else
    {
    }
    cout << endl;
}

void Delete()
{
    if (rear == -1)
    {
        cout << "queue underflow" << endl;
        return;
    }
    else if (rear == 0 && front == size - 1)
    {
        cout << "queue underflow" << endl
             << endl;
    }
    if (rear != 0 && front > rear)
    {
        cout << "queue underflow 2  if " << endl
             << endl;
    }

    cout << queue[front] << "succesfully deleted" << endl;
    if (front == size - 1)
    {
        front = 0;
    }

    if (front == rear)
    {
        front = 0;
        rear = 0;
    }

    if (front < rear)
    {
        cout << "front ++ happenl";
        ++front;
    }
}

int main()
{

    int choice, data;
    cout << "------------------------------------------- " << endl;
    cout << "1) Show QUeue data " << endl;
    cout << "2) insert In queue " << endl;
    cout << "3) delete in queue " << endl;
    cout << "--------------------------------------------" << endl;

    do
    {
        cout << "enter choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            display();
            break;

        case 2:
            cout << "enter Data :";
            cin >> data;
            insert(data);
            break;

        case 3:
            Delete();
            break;

        default:
            break;
        }

    } while (choice != 8);
}