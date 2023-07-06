#include <bits/stdc++.h>
using namespace std;

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Input
[
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

Output
3
*/

int n, m;
void bfs(int i, int j, vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        if (i > 0 && grid[i - 1][j] != '0')
        {
            grid[i - 1][j] = '0';
            q.push({i - 1, j});
        }
        if (j > 0 && grid[i][j - 1] != '0')
        {
            grid[i][j - 1] = '0';
            q.push({i, j - 1});
        }
        if (i < n - 1 && grid[i + 1][j] != '0')
        {
            grid[i + 1][j] = '0';
            q.push({i + 1, j});
        }
        if (j < m - 1 && grid[i][j + 1] != '0')
        {
            grid[i][j + 1] = '0';
            q.push({i, j + 1});
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    n = grid.size();
    m = grid[0].size();
    int ans = 0;
    vector<vector<char>> temp = grid;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] != '0')
            {
                bfs(i, j, temp);
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << numIslands(grid);
    return 0;
}
