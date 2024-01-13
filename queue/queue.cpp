#include <iostream>
using namespace std;

void insert(int queue[], int data, int size, int *front, int *rear)
{
    if (*rear == size - 1)
    {
        cout << "queue is overflow " << endl
             << endl;
        return;
    }

    ++(*rear);
    queue[*rear] = data;

    if (*front == -1)
    {
        *front = 0;
    }
}

void dequeue(int queue[], int size, int *front, int *rear)
{
    if (*front == -1)
    {
        cout << "Queue is Underflow!" << endl
             << endl;
        return;
    }

    if (*front == *rear)
    {
        int temp = queue[(*front)];
        *front = -1;
        *rear = -1;
        cout << temp << " succesfully deletedd" << endl<< endl;
        return;
    }
    // return deleted element and then incremented..
    int temp = queue[(*front)];
    ++(*front);
    cout << temp << " succesfully deleted" << endl
         << endl;
}

void display(int queue[], int *front, int *rear)
{
    if (*rear == -1)
    {
        cout << "NUll queue" << endl
             << endl;
        return;
    }

cout<<"data inside queue : ";
    for (int i = *front; i <= *rear; i++)
    {
        cout << queue[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int queue[10] = {};
    int front = -1;
    int rear = -1;
    int size = sizeof(queue) / sizeof(queue[0]);

    int choice, data;
    cout << "------------------------------------------- " << endl;
    cout << "1) Show Queue data " << endl;
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
            display(queue, &front, &rear);
            break;

        case 2:
            cout << "enter Data :";
            cin >> data;
            insert(queue, data, size, &front, &rear);
            break;

        case 3:
            dequeue(queue, size, &front, &rear);
            break;

        default:
            break;
        }

    } while (choice != 8);
}