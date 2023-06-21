#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

Input
3 5
1 2 5
Output
4
*/

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<int> prev(amount+1,0), curr(amount+1,0);
    for (int i = 0; i <= amount; i++)
    {
        prev[i] = (i % coins[0] == 0);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int take = 0;
            if (coins[i] <= j)
                take = curr[j - coins[i]];

            curr[j] = take + prev[j];
        }
        prev = curr;
    }
    return prev[amount];
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << change(w,coins);
    return 0;
}
