#include <bits/stdc++.h>
using namespace std;

/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Input
[[0,0,0],[0,1,0],[1,1,1]]

Output
[[0,0,0],[0,1,0],[1,2,1]]

*/

vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }
    vector<vector<int>> ans(n, vector<int>(m, 0));
    ;
    while (!q.empty())
    {
        int s = q.front().first.first;
        int t = q.front().first.second;
        int d = q.front().second;
        ans[s][t] = d;
        q.pop();
        for (auto x : dir)
        {
            int p = s + x[0];
            int r = t + x[1];
            if (p < 0 || r < 0 || p >= n || r >= m)
                continue;

            if (vis[p][r] == 0 && mat[p][r] == 1)
            {
                q.push({{p, r}, d + 1});
                vis[p][r] = 1;
            }
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
    vector<vector<int>> ans = updateMatrix(grid);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}
