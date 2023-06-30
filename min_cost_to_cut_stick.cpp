#include <bits/stdc++.h>
using namespace std;

/*
Given a wooden stick of length n units. The stick is labelled from 0 to n
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts.
When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut).
Return the minimum total cost of the cuts.

Input
n = 7
[1,3,4,5]

Output
16

*/

int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 1e9;
    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts, dp) + solve(k + 1, j, cuts, dp);
        if (cost < ans)
            ans = cost;
    }
    return dp[i][j] = ans;
}
int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    int c = cuts.size();
    vector<vector<int>> dp(c, vector<int>(c, -1));
    return solve(1, c - 2, cuts, dp);
}

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> nums(c);
    for (int i = 0; i < c; i++)
    {
        cin >> nums[i];
    }
    cout << minCost(n, nums);
    return 0;
}