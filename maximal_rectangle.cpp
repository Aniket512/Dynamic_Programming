#include <bits/stdc++.h>
using namespace std;

/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Input
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]

Output
6
*/

int largestArea(vector<int> &arr)
{
    int n = arr.size();
    stack<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            int t = s.top();
            s.pop();
            ans = max(ans, arr[t] * (s.empty() ? i : i - s.top() - 1));
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        ans = max(ans, arr[t] * (s.empty() ? n : n - s.top() - 1));
    }
    return ans;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> temp(n, vector<int>(m));
    for (int i = 0; i < m; i++)
    {
        temp[0][i] = matrix[0][i] - '0';
    }
    int ans = largestArea(temp[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[i][j] = (matrix[i][j] == '0') ? 0 : (matrix[i][j] - '0') + temp[i - 1][j];
        }
        ans = max(ans, largestArea(temp[i]));
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << maximalRectangle(matrix);
    return 0;
}
