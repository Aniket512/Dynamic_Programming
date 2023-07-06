#include <bits/stdc++.h>
using namespace std;

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Input
[
  [2,1,1],[1,1,0],[0,1,1]
]

Output
4
*/

vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    int n = grid.size(), m = grid[0].size();
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
                grid[i][j] = 0;
            }
            temp += (grid[i][j] == 1);
        }
    }
    if (temp == 0)
        return 0;
    int ans = -1;
    while (!q.empty())
    {
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            int s = q.front().first;
            int t = q.front().second;
            q.pop();
            for (auto x : dir)
            {
                int p = s + x[0];
                int r = t + x[1];
                if (p < 0 || p >= n || r < 0 || r >= m)
                    continue;

                if (grid[p][r] == 1)
                {
                    grid[p][r] = 0;
                    q.push({p, r});
                    temp--;
                }
            }
        }
        ans++;
    }

    return (temp == 0) ? ans : -1;
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
    cout << orangesRotting(grid);
    return 0;
}
