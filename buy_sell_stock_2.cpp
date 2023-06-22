#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Input
[7,1,5,3,6,4]

Output
7
*/

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
        if (prices[i] > prices[i - 1])
            profit += (prices[i] - prices[i - 1]);
    return profit;
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
