#include <bits/stdc++.h>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Input
[1,2,3,0,2]

Output
3
*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            if (j == 1)
            {
                dp[i][j] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            }
            else
            {
                dp[i][j] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
            }
        }
    }
    return dp[0][1];
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
