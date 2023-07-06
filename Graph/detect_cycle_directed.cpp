#include <bits/stdc++.h>
using namespace std;

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Input
V = 4, E = 4
adj = {{1}, {2}, {3}, {3}}

Output
true
*/

bool dfs(int i, vector<bool> &vis, vector<bool> &path, vector<int> adj[])
{
    vis[i] = 1;
    path[i] = 1;
    for (auto x : adj[i])
    {
        if (!vis[x])
        {
            vis[x] = 1;

            if (dfs(x, vis, path, adj))
                return true;
        }
        else if (vis[x] && path[x])
            return true;
    }
    path[i] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> vis(V, 0), path(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, path, adj))
                return true;
        }
    }
    return false;
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
    }
    cout << isCyclic(V, adj);
    return 0;
}