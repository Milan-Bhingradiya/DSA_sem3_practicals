
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int value)
    {
        data = value;
        right = NULL;
        left = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;

    cout << "Enter data for node : " << endl;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Insert Node leftside of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Insert Node rightside of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    root = (buildTree(root));
    return 0;
}
