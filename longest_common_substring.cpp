#include <bits/stdc++.h>
using namespace std;

/*
Given two strings. The task is to find the length of the longest common substring.

Input
acbde
ace

Output
2
*/

int longestCommonSubstr(string S1, string S2)
{
    int n = S1.length(), m = S2.length();
    int dp[n + 1][m + 1];
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}
int main()
{
    string text1, text2;
    cin >> text1 >> text2;
    cout << longestCommonSubstr(text1, text2);
    return 0;
}
