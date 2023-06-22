#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Input
k = 2
[2,4,1]
Output

2
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

int maxProfit(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    return solve(0, prices, 1, k, dp);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(prices, k);
    return 0;
}
