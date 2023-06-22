#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

Input
rabbbit
rabbit

Output
3
*/

int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (j < 0)
    {
        return 1;
    }
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
    return dp[i][j] = solve(i - 1, j, s, t, dp);
}
int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n - 1, m - 1, s, t, dp);
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    cout << numDistinct(word1, word2);
    return 0;
}
