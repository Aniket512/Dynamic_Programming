#include <bits/stdc++.h>
using namespace std;

/*
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.

Input
[[2,3,1] , [0], [0,4], [0], [2]]

Output
0 2 4 3 1
*/

vector<int> ans;
void dfs(int i, vector<bool> &vis, vector<int> adj[])
{
    vis[i] = 1;
    ans.push_back(i);
    for (auto x : adj[i])
    {
        if (!vis[x])
            dfs(x, vis, adj);
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<bool> vis(V, 0);
    dfs(0, vis, adj);
    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = dfsOfGraph(V, adj);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}
