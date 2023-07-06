#include <bits/stdc++.h>
using namespace std;

/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
Return the modified image after performing the flood fill.

Input
image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output
[[2,2,2],[2,2,0],[2,0,1]]

*/

void fill(int i, int j, vector<vector<int>> &image, int color, int prev)
{
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size())
        return;
    if (image[i][j] != prev || image[i][j] == color)
        return;

    image[i][j] = color;
    fill(i + 1, j, image, color, prev);
    fill(i - 1, j, image, color, prev);
    fill(i, j + 1, image, color, prev);
    fill(i, j - 1, image, color, prev);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    fill(sr, sc, image, color, image[sr][sc]);
    return image;
}

int main()
{
    int m, n, sr, sc, color;
    cin >> m >> n >> sr >> sc >> color;
    vector<vector<int>> image(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> image[i][j];
        }
    }
    vector<vector<int>> ans = floodFill(image, sr, sc, color);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
