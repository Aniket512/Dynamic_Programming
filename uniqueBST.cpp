#include <bits/stdc++.h>
using namespace std;

/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Input
3

Output
5
*/

int numTrees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n ;
    cout << numTrees(n);
    return 0;
}
