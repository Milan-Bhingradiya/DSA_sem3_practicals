#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		data = 0;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void insertAtStart(Node *&head)
{

	int data;
	cout << "enter Value:";
	cin >> data;

	Node *newnode = new Node(data);
	if (head == NULL)
	{
		head = newnode;
		return;
	}

	newnode->next = head;
	head = newnode;
}

void insertAtEnd(Node *&head)
{
	int data;
	cout << "enter Value";
	cin >> data;
	
	Node *newnode = new Node(data);
	if (head == NULL)
	{
		head = newnode;
		return;
	}
	Node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
};

void deleteAtStart(Node *&head)
{
	if (head == NULL)
	{
		cout << "its already empty " << endl;
		return;
	}

	Node *temp = head;
	head = head->next;
	cout<< "deleted successfully"<<endl;
	delete temp;
}

void deleteAtEnd(Node *&head)
{
	if (head == NULL)
	{
		cout << "its already empty " << endl;
		return;
	}

	Node *temp = head;
	Node *prev = NULL;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}

	prev->next = NULL;
	cout<< "deleted successfully"<<endl;
	delete temp;
}

void insertInOrder(Node *&head)
{

	bool flag_isvalue_fitted = false;
	int data;
	cout << "enter Value :";
	cin >> data;

	Node *newnode = new Node(data);
	Node *temp = head;

	if (head == NULL)
	{
		head = newnode;
		return;
	}

	while (temp->next != NULL)
	{
		// if 2,3,4,  and data is 1 then....
		if (data < head->data)
		{
			flag_isvalue_fitted = true;
			newnode->next = head;
			head = newnode;
		}
		else
		{
			// if 2,4,5,6, and data is 3....
			if (data > temp->data && data < temp->next->data)
			{
				flag_isvalue_fitted = true;
				newnode->next = temp->next;
				temp->next = newnode;
			}
		}
		temp = temp->next;
	}

	if (flag_isvalue_fitted == false)
	{
		if (temp->next == NULL)
		{
			temp->next = newnode;
		}
	}
}
void display(Node *head)
{
	if(head==NULL) return;
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Node *head = NULL;

	cout << "1) Display " << endl;
	cout << "2) insert at start " << endl;
	cout << "3) insert at end " << endl;
	cout << "4) delete at start " << endl;
	cout << "5) delete at end " << endl;
	cout << "6) insert in order (just insert)" << endl;

	int choice;

	do
	{
		cout << "enter your choice :";
		cin >> choice;

		switch (choice)
		{
		case 1:
			display(head);
			break;

		case 2:
			insertAtStart(head);
			break;

		case 3:
			insertAtEnd(head);
			break;
		case 4:
			deleteAtStart(head);
			break;
		case 5:
			deleteAtEnd(head);
			break;
		case 6:
			insertInOrder(head);
			break;
		}

	} while (choice != 10);
}
