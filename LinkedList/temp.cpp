#include <iostream>
using namespace std;

class Node
{
private:
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    };
};


void milan(Node* &head){
head->data=999900;
    cout<<"address in milan :"<<head<<endl;

   Node* newnode=new Node(100);
    head=newnode;
}
int main()
{
    Node *head=new Node(100);;
    cout<<"address in main :"<<head<<endl;

    milan(head);
    milan(head);
    cout<<"main data: "<<head->data<<endl;


    return 0;
}
