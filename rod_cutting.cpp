#include <bits/stdc++.h>
using namespace std;

/*
Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input
8
1 5 8 9 10 17 17 20
Output
22
*/

int solve(int i, int j, vector<int> &price, vector<vector<int>> dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int take = 0;
    if (i + 1 <= j)
        take = price[i] + solve(i, j - i - 1, price, dp);

    return dp[i][j] = max(take, solve(i - 1, j, price, dp));
}

int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(n - 1, n, price, dp);

    // Tabulation
    // for (int i = 1; i <= n; i++)
    // {
    //     dp[0][i] = i * price[0];
    // }
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         int take = 0;
    //         if (i + 1 <= j)
    //             take = price[i] + dp[i][j - i - 1];

    //         dp[i][j] = max(take, dp[i - 1][j]);
    //     }
    // }
    // return dp[n - 1][n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    cout << cutRod(price);
    return 0;
}
