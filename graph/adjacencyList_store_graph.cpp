#include <iostream>
#include <vector>
using namespace std;

int main()
{ int n,m;
    cout << "enter num of node : " << endl;
    cin >> n;
    cout << "enter num of Edge/vertex : " << endl;
    cin >> m;

    vector<int> adj[n + 1];
//  for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j <= 1; j++)
//         {
//             adj[i][j]=0;
//         }
//         cout << endl;
//     }


    for (int i = 0; i < m; i++)
    {
            // cout<<"enter node "<<i<<" go to where : "<<endl;
            int src ,dest;
            cout << "enter :" << endl;
            cin >> src;
            cin >> dest;
            adj[src].push_back(dest);
            adj[dest].push_back(src);        
    }


}