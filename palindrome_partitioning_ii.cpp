#include <bits/stdc++.h>
using namespace std;

/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Input
aab

Output
1
*/

bool isPal(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int solve(int i, string &s, int n, vector<int> &dp)
{
    if (i == n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int cnt = 1e9;
    for (int j = i; j < n; j++)
    {
        if (isPal(i, j, s))
        {
            int temp = solve(j + 1, s, n, dp) + 1;
            cnt = min(temp, cnt);
        }
    }
    return dp[i] = cnt;
}
int minCut(string s)
{
    int n = s.length();
    vector<int> dp(n, -1);
    return solve(0, s, n, dp) - 1;
}


int main()
{
    string exp;
    cin >> exp;
    cout << minCut(exp);
    return 0;
}
