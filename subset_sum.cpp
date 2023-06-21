#include <bits/stdc++.h>
using namespace std;

/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Input
6 7
3 34 4 12 5 2

Output
1
*/

vector<vector<int>> dp;
bool helper(int i, int sum, vector<int> arr)
{
    if (sum == 0)
        return true;

    if (i > arr.size() - 1)
        return false;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    bool take = false;
    if (arr[i] <= sum)
    {
        take = helper(i + 1, sum - arr[i], arr);
    }
    return dp[i][sum] = take || helper(i + 1, sum, arr);
}
bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    dp.resize(n + 1, vector<int>(sum + 1, -1));
    return helper(0, sum, arr);
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << isSubsetSum(arr, sum);
    return 0;
}
