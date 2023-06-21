#include <bits/stdc++.h>
using namespace std;

/*
Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.


Input
horse
ros

Output
3
*/

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        }
    }

    return dp[n][m];
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2);
    return 0;
}
