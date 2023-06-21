#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Input
[1,5,11,5]

Output
true
*/

vector<vector<int>> dp;
bool helper(int i, int sum, vector<int> &nums)
{
    if (sum == 0)
        return true;
    if (i == 0)
        return (nums[i] == sum);
    if (dp[i][sum] != -1)
        return dp[i][sum];
    bool take = false;
    if (nums[i] <= sum)
        take = helper(i - 1, sum - nums[i], nums);

    return dp[i][sum] = take || helper(i - 1, sum, nums);
}
bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1)
        return false;

    int n = nums.size();
    int target = sum / 2;
    dp.resize(n, vector<int>(target + 1, -1));
    return helper(n - 1, target, nums);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << canPartition(arr);
    return 0;
}
