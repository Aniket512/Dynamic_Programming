#include <bits/stdc++.h>
using namespace std;

/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

Input
[[1,1,0],[1,1,0],[0,0,1]]

Output
2
*/

vector<bool> vis;
void dfs(int i, vector<vector<int>> &adj)
{
    vis[i] = true;
    for (auto x : adj[i])
    {
        if (!vis[x])
            dfs(x, adj);
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j])
                adj[i].push_back(j);
        }
    }
    vis.resize(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj);
            ans++;
        }
    }
    return ans;
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
    cout << findCircleNum(grid);
    return 0;
}
