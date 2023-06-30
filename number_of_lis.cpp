#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the number of longest increasing subsequences.

Input
[1,3,5,4,7]

Output
2

*/

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxi = 1;
    vector<int> count(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    count[i] = 0;
                }
                if (dp[i] == dp[j] + 1)
                {
                    count[i] += count[j];
                }
            }
        }
        maxi = max(maxi, dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxi == dp[i])
            ans += count[i];
    }
    return ans;
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
    cout << findNumberOfLIS(nums);
    return 0;
}