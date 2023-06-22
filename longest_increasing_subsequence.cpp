#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence

Input
[10,9,2,5,3,7,101,18]

Output
4
*/

int ceilIndex(int tail[], int l, int r, int x)
{
    while (r > l)
    {
        int mid = l + (r - l) / 2;
        if (tail[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int tail[n] = {0};
    tail[0] = nums[0];
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > tail[len - 1])
        {
            tail[len] = nums[i];
            len++;
        }
        else
        {
            int c = ceilIndex(tail, 0, len - 1, nums[i]);
            tail[c] = nums[i];
        }
    }
    return len;
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
    cout << lengthOfLIS(nums);
    return 0;
}