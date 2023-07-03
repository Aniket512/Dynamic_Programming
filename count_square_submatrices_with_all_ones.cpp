#include <bits/stdc++.h>
using namespace std;

/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Input
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]

Output
15
*/

int countSquares(vector<vector<int>> &matrix)
{
    int ans = 0;
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = matrix[i][0];
        ans += dp[i][0];
    }
    for (int i = 1; i < m; i++)
    {
        dp[0][i] = matrix[0][i];
        ans += dp[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 1)
                dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
            ans += dp[i][j];
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << countSquares(matrix);
    return 0;
}
