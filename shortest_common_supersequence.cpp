#include <bits/stdc++.h>
using namespace std;

/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.
If there are multiple valid strings, return any of them.

Input
abac
cab

Output
cabac
*/

string shortestCommonSupersequence(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = (n + m) - dp[n][m];
    string ans(len, '$');
    int i = n, j = m;
    len--;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans[len] = str1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans[len] = str1[i - 1];
            i--;
        }
        else
        {
            ans[len] = str2[j - 1];
            j--;
        }
        len--;
    }
    while (i > 0)
    {
        ans[len] = str1[i - 1];
        i--;
        len--;
    }
    while (j > 0)
    {
        ans[len] = str2[j - 1];
        j--;
        len--;
    }
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << shortestCommonSupersequence(s1, s2);
    return 0;
}
