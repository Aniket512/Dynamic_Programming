#include <bits/stdc++.h>
using namespace std;

/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.

Input
[[1,2,3],[],[4],[],[]]

Output
0 1 2 3 4
*/

vector<int> bfs(int V, vector<int> adj[])
{
    queue<int> q;
    q.push(0);
    vector<int> ans;
    vector<bool> vis(V, 0);
    vis[0] = 1;
    while (!q.empty())
    {

        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (auto x : adj[t])
        {
            if (!vis[x])
            {
                vis[x] = 1;
                q.push(x);
            }
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
    vector<int> ans = bfs(V, adj);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}
