#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

Input
[2,3,-2,4]

Output
6
*/

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;

        pre *= nums[i];
        suff *= nums[n - i - 1];

        ans = max(ans, max(pre, suff));
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
        cin>>nums[i];
    }
    cout << maxProduct(nums);
    return 0;
}
