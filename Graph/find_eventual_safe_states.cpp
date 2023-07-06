#include <bits/stdc++.h>
using namespace std;

/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1.
The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Input
[[1,2],[2,3],[5],[0],[5],[],[]]

Output
[2,4,5,6]

*/

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> indegree(n, 0);
    vector<vector<int>> revGraph(n);
    for (int i = 0; i < n; i++)
    {
        for (auto x : graph[i])
        {
            indegree[i]++;
            revGraph[x].push_back(i);
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
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
        for (auto x : revGraph[t])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        grid[u].push_back(v);
    }
    vector<int> ans = eventualSafeNodes(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
