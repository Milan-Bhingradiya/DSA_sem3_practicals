#include <iostream>
using namespace std;

int main()
{

    // n =node
    // m= vertex,edge,liti..

    int n, m = 0;
    cout << "Enter size of n : " << endl;
    cin >> n;
    cout << "Enter size of m : " << endl;
    cin >> m;

    int graph[n + 1][m + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int x, y;
        // this is simply row and column x,y but looking at graph then it is node to node name...
        cout << "src node  : " ;
        cin >> x;
        cout << "des node  : " ;
        cin >> y;

        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }
}
