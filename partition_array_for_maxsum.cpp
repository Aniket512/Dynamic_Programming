#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k.
After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning.

Input
[1,15,7,9,2,5,10], k = 3

Output
84
*/

int solve(int i, vector<int> &arr, int k, int n, vector<int> &dp)
{
    if (i == n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int ans = 0, cnt = 0;
    int len = 0;
    int maxi = arr[i];
    for (int j = i; j < min(n, i + k); j++)
    {
        len++;
        maxi = max(arr[j], maxi);
        cnt = maxi * (len) + solve(j + 1, arr, k, n, dp);
        ans = max(cnt, ans);
    }
    return dp[i] = ans;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(0, arr, k, n, dp);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxSumAfterPartitioning(arr, k);
    return 0;
}
