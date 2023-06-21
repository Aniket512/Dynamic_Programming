#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Input
3 11
1 2 5
Output
3
*/


int solve(int i, int W, vector<int> &coins, vector<vector<int>> &dp)
{
    if (W == 0)
    {
        return 0;
    }
    if (i < 0 || W < 0)
    {
        return 1e9;
    }

    if (dp[i][W] != -1)
        return dp[i][W];
    int take = 1e9;
    if (coins[i] <= W)
    {
        take = solve(i, W - coins[i], coins, dp);
    }
    int notTake = solve(i - 1, W, coins, dp);
    return dp[i][W] = min(take + 1, notTake);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = solve(n - 1, amount, coins, dp);
    return (ans >= 1e9) ? -1 : ans;
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << coinChange(coins, w);
    return 0;
}
