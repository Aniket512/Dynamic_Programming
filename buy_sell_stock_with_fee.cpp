#include <bits/stdc++.h>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Input
fee = 2
[1,3,2,8,4,9]

Output
8
*/

int solve(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp, int fee)
{
    if (i >= prices.size())
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];
    if (buy)
    {
        return dp[i][buy] = max(-prices[i] + solve(i + 1, 0, prices, dp, fee), solve(i + 1, 1, prices, dp, fee));
    }
    else
    {
        return dp[i][buy] = max(prices[i] - fee + solve(i + 1, 1, prices, dp, fee), solve(i + 1, 0, prices, dp, fee));
    }
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, dp, fee);
}

int main()
{
    int n, fee;
    cin >> n >> fee;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(prices, fee);
    return 0;
}
