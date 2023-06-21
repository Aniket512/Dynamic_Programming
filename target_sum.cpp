#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
Return the number of different expressions that you can build, which evaluates to target.

Input
nums = [1,1,1,1,1], target = 3

Output
5

*/
vector<vector<int>> dp;
int solve(int i, vector<int> &nums, int target)
{
    if (i == 0)
    {
        if (target == 0 && nums[0] == 0)
            return 2;
        if (target == 0 || nums[0] == target)
            return 1;
        return 0;
    }

    if (dp[i][target] != -1)
        return dp[i][target];
    int take = 0;
    if (nums[i] <= target)
        take = solve(i - 1, nums, target - nums[i]);

    return dp[i][target] = take + solve(i - 1, nums, target);
}
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;
    for (auto x : nums)
    {
        (sum += x);
    }
    if ((sum - target) < 0 || (sum - target) % 2)
        return 0;
    int amount = (sum - target) / 2;
    dp.resize(n, vector<int>(amount + 1, -1));
    return solve(n - 1, nums, amount);
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << findTargetSumWays(nums, target);
    return 0;
}
