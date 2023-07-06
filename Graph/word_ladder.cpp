#include <bits/stdc++.h>
using namespace std;

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Input
beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]

Output
5
*/

vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid)
{
    vis[i][j] = 1;
    for (auto x : dir)
    {
        int p = i + x[0];
        int q = j + x[1];
        if (p < 0 || q < 0 || p >= grid.size() || q >= grid[0].size())
            continue;
        if (grid[p][q] == 1 && !vis[p][q])
            dfs(p, q, vis, grid);
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int j = 0; j < m; j++)
    {

        if (grid[0][j] == 1 && !vis[0][j])
        {
            dfs(0, j, vis, grid);
        }
        if (grid[n - 1][j] == 1 && !vis[n - 1][j])
        {
            dfs(n - 1, j, vis, grid);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && grid[i][0] == 1)
        {
            dfs(i, 0, vis, grid);
        }

        if (!vis[i][m - 1] && grid[i][m - 1] == 1)
        {
            dfs(i, m - 1, vis, grid);
        }
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout<<numEnclaves(grid)<<endl;
    return 0;
}

