#include <bits/stdc++.h>
using namespace std;

/*
Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2.
It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Input
heap
pea

Output
3
*/

int minOperations(string str1, string str2)
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
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return (n + m) - 2 * dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << minOperations(s1, s2);
    return 0;
}
