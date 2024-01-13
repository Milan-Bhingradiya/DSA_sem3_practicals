#include <iostream>
#include <vector>
#include <queue>
#include <stack>

// TODO: ek sathe badha function vaprva nahi keme me ek class ma badha common use karela chhe....
using namespace std;
class graph
{
public:
    // liti in graph..
    vector<bool> visitedListdfs;
    vector<vector<int>> adj;

    vector<bool> visited;
    vector<bool> parent;

    // dfs..
    int vertices;

    // for func isCyclicGraph_DirectedGraph_DFS
    vector<bool> DFS_func_active;

    // TODO: constructor ne class ni bhar lakhine batav like bfs dfs laykha..
    graph(int size)
    {
        // must assign size ..
        adj.resize(size);
        visitedListdfs.resize(size);
        DFS_func_active.resize(size, false);
        visited.resize(size);
        parent.resize(size);
        vertices = size;
    }

    int BFS(int x);
    int DFS(int x);
    int isCyclicGraph_using_BFS(int x);
    int isCyclicGraphDFS(int x);
    int isCyclicGraph_DirectedGraph_DFS(int x);

    int shortestPath(int src, int dest);
    void addedge(int a, int b);
};

void graph::addedge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int graph::BFS(int x)
{
    vector<bool> visitedList;
    visitedList.resize(vertices, false);
    queue<int> queue;
    // get queue front and then push thier sub child in queue untill queue is not empty..
    queue.push(x);
    visitedList[x] = true;

    while (queue.size() > 0)
    {
        int x = queue.front();
        cout << x << " ";
        queue.pop();

        for (auto node : adj[x])
        {
            if (visitedList[node] == false)
            {
                visitedList[node] = true;
                queue.push(node);
            }
        }
    }
    cout << endl;
}

int graph::DFS(int x)
{
    visitedListdfs[x] = true;
    cout << x << " ";

    for (auto i : adj[x])
    {

        if (!visitedListdfs[i])
        {
            DFS(i);
        }
    }
}

int graph ::isCyclicGraph_using_BFS(int x)
{

    vector<bool> visited;
    visited.resize(10, false);
    queue<int> queue;
    vector<int> parent;
    parent.resize(10, -1);

    visited[x] = true;
    queue.push(x);

    while (queue.size() > 0)
    {
        int x = queue.front();
        queue.pop();

        for (auto node : adj[x])
        {
            cout << node << endl;

            if (visited[node] == false)
            {
                queue.push(node);
                visited[node] = true;
                // index etle node and value in that index is parent node of that node.
                // x na sub child ne parent x assign....
                parent[node] = x;
            }

            // if next node is visted then father of that node should be x , if cyclic graph then two father will found and then graph cylic found...
            else if (visited[node] == true && parent[node] != x)
            {

                cout << "this graph is culcic" << endl;
                break;
            }
        }
    }
}

int graph::isCyclicGraphDFS(int x)
{

    visited[x] = true;

    for (auto node : adj[x])
    {

        // node visited hoy and parent alag hoy x karta to...
        if (visited[node] && parent[node] != x)
        {
            cout << "Graph is cyclic using dfs" << endl;
            break;
        }
        else if (!visited[node])
        {
            visited[node] = true;
            parent[node] = x;
            isCyclicGraphDFS(node);
        }
    }
}

int graph::isCyclicGraph_DirectedGraph_DFS(int x)
{
    // TODO: complex
    //  this DFS_func_active is use for function is ended or not ..means recursion is ended or not..
    DFS_func_active[x] = true;
    visited[x] = true;

    for (int node : adj[x])
    {
        if (!visited[node])
        {
            // parent[node] = x;
            isCyclicGraph_DirectedGraph_DFS(node);
        }

        else if (visited[node] == true && DFS_func_active[node] == true)
        {
            cout << node;
            cout << "yes this is cyclic graph" << endl;
        }
    }

    DFS_func_active[x] = false;
}

int graph::shortestPath(int src, int dest)
{

    vector<int> visited(10);
    visited[src] = true;
    vector<int> parent(10);
    parent[src] = -1;

    queue<int> q;
    q.push(src);

    while (q.size() > 0)
    {

        int front = q.front();
        q.pop();

        for (int node : adj[front])
        {
            //  cout<<"node of "<<front<<" :: " <<node<<endl;

            if (!visited[node])
            {

                visited[node] = true;
                parent[node] = front;
                q.push(node);
            }
        }
    }

    stack<int> stack;
    int current = dest;

    stack.push(current);

    // IMPORTANT main thing of this code
    while (current != src)
    {
        current = parent[current];
        stack.push(current);
    }

    // for just print output...
    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }
}
int main()
{
    graph obj(10);

    // obj.addedge(0, 1);
    // obj.addedge(0, 2);
    // obj.addedge(1, 3);
    // obj.addedge(1, 4);
    // obj.addedge(2, 5);
    // obj.addedge(2, 6);

    // in this directed graph no cycle still showing has cyclic garpah thats why have to need build new logic for directed graph...
    // obj.addedge(0, 1);
    // obj.addedge(1, 2);
    // obj.addedge(3, 1);
    // obj.addedge(2, 3);



    // for shorttest path...
    obj.addedge(1, 2);
    obj.addedge(1, 3);
    obj.addedge(1, 4);
    obj.addedge(2, 5);
    obj.addedge(5, 8);
    obj.addedge(3, 8);
    obj.addedge(4, 6);
    obj.addedge(6, 7);
    obj.addedge(7, 8);

    // cout << "----------BFS-----------" << endl;
    // obj.BFS(0);
    // cout << "-----------DFS--------" << endl;
    // obj.DFS(0);
    // cout << "-----------IScyclcic--------" << endl;
    // obj.isCyclicGraph_DirectedGraph_DFS(0);

    obj.shortestPath(1, 8);
}