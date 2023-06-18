#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

Input
1,2,3,1

Output
4
*/

int rob(int n, vector<int> &nums)
{
    vector<int> dp(n);
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
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
    cout << rob(n, nums);
    return 0;
}
