#include <bits/stdc++.h>
using namespace std;

/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Input
[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output
[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
*/

vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &board)
{
    vis[i][j] = 1;
    for (auto x : dir)
    {
        int p = i + x[0];
        int q = j + x[1];
        if (p < 0 || q < 0 || p >= board.size() || q >= board[0].size())
            continue;
        if (board[p][q] == 'O' && !vis[p][q])
            dfs(p, q, vis, board);
    }
}
void solve(vector<vector<char>> &board)
{
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int j = 0; j < m; j++)
    {

        if (board[0][j] == 'O' && !vis[0][j])
        {
            dfs(0, j, vis, board);
        }
        if (board[n - 1][j] == 'O' && !vis[n - 1][j])
        {
            dfs(n - 1, j, vis, board);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && board[i][0] == 'O')
        {
            dfs(i, 0, vis, board);
        }

        if (!vis[i][m - 1] && board[i][m - 1] == 'O')
        {
            dfs(i, m - 1, vis, board);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    solve(board);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
