#include <bits/stdc++.h>
using namespace std;

/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together.
The efficient way is the one that involves the least number of multiplications.
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).


Input
[40, 20, 30, 10, 30]

Output
26000

*/

int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int ans = 1e9;

            for (int k = i; k < j; k++)
            {
                int temp = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if (temp < ans)
                    ans = temp;
            }
            dp[i][j] = ans;
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << matrixMultiplication(nums);
    return 0;
}