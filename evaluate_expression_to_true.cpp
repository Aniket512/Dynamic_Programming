#include <bits/stdc++.h>
using namespace std;

/*
You are given an expression ‘EXP’ in the form of a string where operands will be : (TRUE and FALSE) and operators will be : (AND, OR, XOR). 
Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.
Input
F|T^F

Output
2
*/

const long long mod = 1000000007;
long long f(int i, int j, int isTrue, string &S,
            vector<vector<vector<long long>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return S[i] == 'T';
        else
            return S[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    long long ways = 0;
    for (int ind = i + 1; ind < j; ind = ind + 2)
    {
        long long lt = f(i, ind - 1, 1, S, dp);
        long long lf = f(i, ind - 1, 0, S, dp);
        long long rt = f(ind + 1, j, 1, S, dp);
        long long rf = f(ind + 1, j, 0, S, dp);

        if (S[ind] == '&')
        {
            if (isTrue)
                ways = (ways + (lt * rt) % mod) % mod;
            else
                ways =
                    (ways + (lf * rt) % mod + (lt * rf) % mod + (lf * rf) % mod) % mod;
        }
        else if (S[ind] == '|')
        {
            if (isTrue)
                ways =
                    (ways + (lt * rt) % mod + (lt * rf) % mod + (rt * lf) % mod) % mod;
            else
                ways = (ways + (lf * rf) % mod) % mod;
        }
        else
        {
            if (isTrue)
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
            else
                ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string &exp)
{
    int N = exp.size();
    vector<vector<vector<long long>>> dp(
        N, vector<vector<long long>>(N, vector<long long>(2, -1)));
    return f(0, N - 1, 1, exp, dp) % mod;
}

int main()
{
    string exp;
    cin >> exp;
    cout << evaluateExp(exp);
    return 0;
}
