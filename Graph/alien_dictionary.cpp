#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary.
Find the order of characters in the alien language.

Input
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}

Output
bdac
*/

string findOrder(string dict[], int N, int K)
{
    // code here
    vector<vector<int>> temp(K);
    for (int i = 1; i < N; i++)
    {
        string a = dict[i - 1], b = dict[i];

        for (int j = 0; j < min(a.length(), b.length()); j++)
        {
            if (a[j] != b[j])
            {
                temp[a[j] - 'a'].push_back(b[j] - 'a');
                break;
            }
        }
    }
    vector<int> indegree(K, 0);

    string ans = "";
    for (auto x : temp)
    {
        for (auto y : x)
        {
            indegree[y]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < K; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        ans += (t + 'a');

        for (auto x : temp[t])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string dict[n];
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    cout << findOrder(dict, n, k);
    return 0;
}