#include <bits/stdc++.h>
using namespace std;

/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
Note that we have only one quantity of each item.

Input
3 4
{1,2,3}
{4,5,1}

Output
3
*/

vector<vector<int>> dp;
int solve(int i, int W, vector<int> wt, vector<int> val)
{
    if (i < 0)
    {
        return 0;
    }
    if (W == 0)
    {
        return 0;
    }
    if (dp[i][W] != -1)
        return dp[i][W];
    int take = 0;
    if (wt[i] <= W)
    {
        take = val[i] + solve(i - 1, W - wt[i], wt, val);
    }
    int notTake = solve(i - 1, W, wt, val);
    return dp[i][W] = max(take, notTake);
}
int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    dp.resize(n, vector<int>(W + 1, -1));
    return solve(n - 1, W, wt, val);
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cout << knapSack(w, wt, val, n);
    return 0;
}
