#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.
Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Input
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}

Output
true
*/

bool bfs(int i, vector<bool> &vis, vector<int> adj[])
{
    queue<pair<int, int>> q;
    q.push({i, -1});
    while (!q.empty())
    {
        int t = q.front().first;
        int par = q.front().second;
        q.pop();
        vis[t] = 1;
        for (auto x : adj[t])
        {
            if (!vis[x])
            {
                q.push({x, t});
            }
            else if (x != par)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (bfs(i, vis, adj) == true)
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
        adj[v].push_back(u);
    }
    cout << isCycle(V, adj);
    return 0;
}