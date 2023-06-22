#include <bits/stdc++.h>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Input
[7,1,5,3,6,4]

Output
5
*/

int maxProfit(vector<int> &prices)
{
    int ans = 0, mn = INT_MAX;
    for (auto price : prices)
    {
        if (price < mn)
        {
            mn = price;
        }
        ans = max(ans, price - mn);
    }
    return ans;
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
