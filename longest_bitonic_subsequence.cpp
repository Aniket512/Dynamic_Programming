#include <bits/stdc++.h>
using namespace std;

/*
Given an array of positive integers. Find the maximum length of Bitonic subsequence.
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.

Input
[1, 2, 5, 3, 2]

Output
5

*/

int LongestBitonicSequence(vector<int> nums)
{
    int n = nums.size();
    vector<int> dp1(n, 1), dp2(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] && dp1[i] < dp1[j] + 1)
            {
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] < nums[i] && dp2[i] < dp2[j] + 1)
            {
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp1[i] + dp2[i] - 1);
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
    cout << LongestBitonicSequence(nums);
    return 0;
}