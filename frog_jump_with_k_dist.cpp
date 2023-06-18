#include <bits/stdc++.h>
using namespace std;
/*
There are N stones, numbered 1, 2, ..., N. Each stone has a height hi.
A frog is initially on Stone 1 and needs to reach Stone N.
The frog can jump from its current stone i to any of the next K stones (i+1, i+2, ..., i+K), incurring a cost of |hi - hj|, where hj is the height of the stone it lands on.
Find the minimum possible total cost incurred by the frog before reaching Stone N.

Input
5 3
10 30 40 50 20

Output
30
*/

int frogJumpWithK(int n, int k, vector<int> &heights)
{
    vector<int> dp(n, INT_MAX);
    if (n == 0)
        return 0;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= max(0, i - k); j--)
            dp[i] = min(dp[j] + abs(heights[i] - heights[j]), dp[i]);
    }
    return dp[n - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << frogJumpWithK(n, k, heights);
    return 0;
}
