#include <iostream>
#include <queue>
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

Node *insertNode(Node *root, int value)
{
    if (root == NULL)
    {
        root = new Node(value);
        return root;
    }

    Node *temp = root;
    while (true)
    {
        if (value > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = new Node(value);
                break;
            }
            temp = temp->right;
        }
        else
        {
            // for value<root->data
            if (temp->left == NULL)
            {
                temp->left = new Node(value);
                break;
            }
            temp = temp->left;
        }
    }
    return root;
}
void displayPreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ",";
    displayPreorder(root->left);
    displayPreorder(root->right);
}
void displayInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    displayInorder(root->left);
    cout << root->data << ",";
    displayInorder(root->right);
}
void displayPostorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    displayPostorder(root->left);
    displayPostorder(root->right);
    cout << root->data << ",";
}

vector<vector<int>> levelorder(Node *&root)
{
    cout << endl;
    vector<int> level;
    vector<vector<int>> ans;
    queue<Node *> q;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);

            cout << temp->data << " ";
        }
    }

    return ans;
}
int main()
{
    Node *root = NULL;
    root = insertNode(root, 100);
    root = insertNode(root, 20);
    root = insertNode(root, 200);
    root = insertNode(root, 10);
    root = insertNode(root, 30);
    root = insertNode(root, 150);
    root = insertNode(root, 300);

    cout << "Preorder : ";
    displayPreorder(root);
    cout << endl;

    cout << "inorder : ";
    displayInorder(root);
    cout << endl;
    cout << "Postorder : ";
    displayPostorder(root);

    cout << endl<< endl;
    cout << "------------------level order traversel-------------------";
    vector<vector<int>> x = levelorder(root);
    return 0;
}