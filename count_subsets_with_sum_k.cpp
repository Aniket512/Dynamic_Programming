#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.

Input
4 3
{5, 2, 6, 4}

Output
1
*/

#define MOD 1000000007

vector<vector<int>> dp;
int solve(vector<int> &nums, int i, int sum)
{
    if (i == 0)
    {
        if (sum == 0 && nums[0] == 0)
            return 2;
        if (sum == 0 || sum == nums[0])
            return 1;
        return 0;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int take = 0;
    if (nums[i] <= sum)
        take = solve(nums, i - 1, sum - nums[i]) % MOD;

    return dp[i][sum] = (take + solve(nums, i - 1, sum)) % MOD;
}

int countPartitions( int d, vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (auto x : arr)
    {
        (sum += x) % MOD;
    }
    if ((sum - d) < 0 || (sum - d) % 2)
        return 0;
    int target = (sum - d) / 2;
    dp.resize(n, vector<int>(target + 1, -1));
    return solve(arr, n - 1, target);
}

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << countPartitions(d, arr);
    return 0;
}
