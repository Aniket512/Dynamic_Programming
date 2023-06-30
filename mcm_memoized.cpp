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


int solve(int i, int j, vector<int>&arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 1e9;

    for (int k = i; k < j; k++)
    {
        int temp = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
        if (temp < ans)
            ans = temp;
    }

    return dp[i][j] = ans;
}
int matrixMultiplication(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(1, n - 1, nums, dp);
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