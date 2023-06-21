#include <bits/stdc++.h>
using namespace std;

/*
Given two strings text1 and text2, return the longest common subsequence.

Input
abcde
ace

Output
ace
*/

string longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    int i = n, j = m;
    int len = dp[n][m];
    string ans(len, '$');
    len--;
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1]){
            ans[len] = text1[i - 1];
            i--;j--;
            len--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    return ans;
}
int main()
{
    string text1, text2;
    cin >> text1 >> text2;
    cout << longestCommonSubsequence(text1, text2);
    return 0;
}
