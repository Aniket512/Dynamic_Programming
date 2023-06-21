#include <bits/stdc++.h>
using namespace std;

/*
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Input
[[2],[3,4],[6,5,7],[4,1,8,3]]

Output
11
*/

int triangle(int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp = grid;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            dp[i][j] += min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n);
    int t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> t;
            grid[i].push_back(t);
        }
    }
    cout << triangle(n, grid);
    return 0;
}
