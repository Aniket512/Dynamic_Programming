#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.

Input
2,3,2

Output
3
*/

int rob(int n, vector<int> &nums)
{
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    vector<int> dp1(n), dp2(n);

    dp1[0] = nums[0];
    dp1[1] = max(nums[0], nums[1]);
    dp2[0] = 0;
    dp2[1] = nums[1];

    for (int i = 2; i < n - 1; i++)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
    }
    for (int i = 2; i < n; i++)
    {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
    }
    return max(dp1[n - 2], dp2[n - 1]);
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
