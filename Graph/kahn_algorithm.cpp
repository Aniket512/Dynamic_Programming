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

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            indegree[*it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        ans.push_back(t);

        for (auto x : adj[t])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
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
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}