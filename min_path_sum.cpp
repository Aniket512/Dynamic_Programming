#include <bits/stdc++.h>
using namespace std;

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Input
[[1,3,1],[1,5,1],[4,2,1]]

Output
7
*/


int minPathSum(int m, int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp = grid;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i > 0 && j>0)
            dp[i][j] += min(dp[i][j-1], dp[i-1][j]);
            else if(i > 0)
            dp[i][j] += dp[i-1][j];
            else if(j > 0)
            dp[i][j] += dp[i][j-1];
        }
    }
    return dp[m - 1][n - 1];
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
    cout << minPathSum(m, n, grid);
    return 0;
}
