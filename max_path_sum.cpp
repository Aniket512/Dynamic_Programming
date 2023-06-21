#include <bits/stdc++.h>
using namespace std;

/*
You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.
Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)

Input
4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1

Output
105
*/

vector<vector<int>> dp;
int helper(int i, int j, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (j < 0 || j >= m)
        return -1e8;

    if (i == n - 1)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = matrix[i][j] + helper(i + 1, j, matrix);
    int down_left = matrix[i][j] + helper(i + 1, j - 1, matrix);
    int down_right = matrix[i][j] + helper(i + 1, j + 1, matrix);

    return dp[i][j] = max({down, down_left, down_right});
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    dp.resize(n, vector<int>(m, -1));
    int ans = -1e8;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, helper(0, i, matrix));
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
    cout << getMaxPathSum(grid);
    return 0;
}
