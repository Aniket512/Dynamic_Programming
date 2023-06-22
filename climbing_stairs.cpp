#include<bits/stdc++.h>
using namespace std;

/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input
10

Output
89
*/

int climbStairs(int n)
{
    if (n == 1 || n == 2)
        return n;
    int t1 = 1, t2 = 2, sum = 0;
    n -= 2;
    while (n--)
    {
        sum = t1 + t2;
        t1 = t2;
        t2 = sum;
    }
    return sum;
}


int main() {
    int n;
    cin>>n;
    cout<<climbStairs(n);
    return 0;
}