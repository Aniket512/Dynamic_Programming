#include <bits/stdc++.h>
using namespace std;

/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
Note that we have only one quantity of each item.

Input
2 3
1 1
2 1

Output
4
*/

vector<vector<int>> dp;
int solve(int i, int W, vector<int> val, vector<int> wt)
{
    if (i < 0)
        return 0;

    if (dp[i][W] != -1)
        return dp[i][W];

    int take = 0;
    if (wt[i] <= W)
        take = val[i] + solve(i, W - wt[i], val, wt);

    return dp[i][W] = max(take, solve(i - 1, W, val, wt));
}
int knapSack(int W, vector<int> val, vector<int> wt, int N)
{
    dp.resize(N, vector<int>(W + 1, -1));
    return solve(N - 1, W, val, wt);
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << knapSack(w, val, wt, n);
    return 0;
}
