#include <bits/stdc++.h>
using namespace std;
/*
There is a frog on the '1st' step of an 'N' stairs long staircase.
The frog wants to reach the 'Nth' stair.'HEIGHT[i]' is the height of the '(i+1)th' stair.
If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of(HEIGHT[i - 1] - HEIGHT[j - 1]).
If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair.
Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

Input
4
10 20 30 10

Output
20
*/

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n);
    if (n == 1)
        return 0;
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]), dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << frogJump(n, heights);
    return 0;
}
