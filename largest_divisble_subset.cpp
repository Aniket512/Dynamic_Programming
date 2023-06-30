#include <bits/stdc++.h>
using namespace std;

/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Input
[1,2,3]

Output
[1,2]
*/

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> temp(n);

    sort(nums.begin(), nums.end());
    int maxi = 1, lastIdx = 0;
    for (int i = 0; i < n; i++)
    {
        temp[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                temp[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIdx = i;
        }
    }

    vector<int> ans;
    ans.push_back(nums[lastIdx]);
    while (temp[lastIdx] != lastIdx)
    {
        lastIdx = temp[lastIdx];
        ans.push_back(nums[lastIdx]);
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
    vector<int> ans = largestDivisibleSubset(nums);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}