#include <bits/stdc++.h>
using namespace std;

/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Input
V = 4, E = 3
adj = {{},{0},{0},{0}}

Output
3 2 1 0
*/

vector<int> ans;
stack<int> s;
void dfs(int i, vector<bool> &vis, vector<int> adj[])
{
    vis[i] = 1;
    for (auto x : adj[i])
    {
        if (!vis[x])
        {
            dfs(x, vis, adj);
        }
    }
    s.push(i);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
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
    }
    vector<int> ans = topoSort(V, adj);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}