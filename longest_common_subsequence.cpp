#include <bits/stdc++.h>
using namespace std;

/*
Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.


Input
abcde
ace

Output
3
*/

int longestCommonSubsequence(string text1, string text2)
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
    return dp[n][m];
}
int main()
{
    string text1, text2;
    cin>>text1>>text2;
    cout << longestCommonSubsequence(text1, text2);
    return 0;
}
