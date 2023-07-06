#include <bits/stdc++.h>
using namespace std;

/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v.
The graph has the following properties:
There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.


Input
[[1,2,3],[0,2],[0,1,3],[0,2]]

Output
0
*/

bool bfs(int i, vector<int> &color, vector<vector<int>> &graph)
{
    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto x : graph[t])
        {
            if (color[x] == 0)
            {
                color[x] = !color[t];
                q.push(x);
            }
            else if (color[x] == color[t])
                return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!bfs(i, color, graph))
            return false;
    }
    return true;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << isBipartite(grid) << endl;
    return 0;
}
