#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <utility>
#include <unordered_map>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int node, int edge, vector<pair<pair<int, int>, int>> &g)
{

    // create adj list

    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        // u means src ,v means dest,w means weight...
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(node + 1);
    vector<bool> mst(node + 1);
    vector<int> parent(node + 1);

    for (int i = 0; i <= node; i++)
    {

        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // start algorithm

    key[1] = 0;
    parent[1] = -1;

    for (int i = 0; i < node; i++)
    {
        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= node; v++)
        {

            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true;
        mst[u] = true;

        // checl its adj nodes;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {

                parent[v] = u;
                key[v] = w;
            }
        }

        // make ans
        
    }

    vector<pair<pair<int, int>, int>> result;
        for (int i = 2; i <= node; i++)
        {
            result.push_back({{parent[i], i}, key[i]});
        }

        return result;
}
int main(int argc, char const *argv[])
{

    vector<pair<pair<int, int>, int>> inputdata;
    vector<pair<pair<int, int>, int>> result;
    inputdata.push_back({{0, 1}, 2});
    inputdata.push_back({{0, 3}, 6});
    inputdata.push_back({{1, 3}, 8});
    inputdata.push_back({{1, 4}, 5});
    inputdata.push_back({{1, 2}, 3});
    inputdata.push_back({{2, 4}, 7});
    
    result = calculatePrimsMST(5, 6, inputdata);
    for ( auto &edge : result)
    {
        cout << "Node " << edge.first.first << " to Node " << edge.first.second << ", Weight: " << edge.second << endl;
    }
}
