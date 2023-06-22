#include <bits/stdc++.h>
using namespace std;

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Input
aa
a?

Output
true
*/

bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
    {
        return true;
    }
    if (i < 0)
    {
        while (j >= 0)
        {
            if (p[j] != '*')
                return false;
            j--;
        }
        return true;
    }
    if (j < 0)
        return false;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == p[j] || p[j] == '?')
        return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

    if (p[j] == '*')
        return dp[i][j] = solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp);

    return dp[i][j] = false;
}
bool isMatch(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, s, p, dp);
}

int main()
{
    string s, p;
    cin >> s >> p;
    cout << isMatch(s, p);
    return 0;
}
