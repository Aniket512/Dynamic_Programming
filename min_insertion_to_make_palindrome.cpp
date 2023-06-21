#include <bits/stdc++.h>
using namespace std;

/*
Given a string s, find the longest palindromic subsequence's length in s.

Input
mbadm

Output
2
*/

int minInsertions(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    string r = s;
    reverse(r.begin(), r.end());
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s[i - 1] == r[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return n - dp[n][n];
}

int main()
{
    string s;
    cin >> s;
    cout << minInsertions(s);
    return 0;
}
