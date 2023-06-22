#include <bits/stdc++.h>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.

Input
[3,3,5,0,0,3,1,4]

Output
6
*/

int solve(int i, vector<int> &prices, bool buy, int cap, vector<vector<vector<int>>> &dp)
{
    if (cap == 0 || i == prices.size())
        return 0;

    if (dp[i][buy][cap] != -1)
        return dp[i][buy][cap];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[i] + solve(i + 1, prices, 0, cap, dp), solve(i + 1, prices, 1, cap, dp));
    }
    else
    {
        profit = max(prices[i] + solve(i + 1, prices, 1, cap - 1, dp), solve(i + 1, prices, 0, cap, dp));
    }
    return dp[i][buy][cap] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(0, prices, 1, 2, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(prices);
    return 0;
}
