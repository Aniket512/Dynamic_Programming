#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array A containing N integers.
You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.
Find and return this minimum possible absolute difference.

Input
[1, 6, 11, 5]

Output
1
*/

vector<vector<int>> dp;
int ans = 1e9;
int minDiffSubset(vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(n, vector<int>(sum + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (nums[0] <= sum)
        dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool take = false;
            if (nums[i] <= j)
                take = dp[i - 1][j - nums[i]];

            dp[i][j] = take || dp[i - 1][j];
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= sum/2; i++)
    {
        if (dp[n - 1][i] == true)
            ans = min(ans, abs(i - (sum - i)));
    }
    return ans;
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
    cout << minDiffSubset(arr);
    return 0;
}
