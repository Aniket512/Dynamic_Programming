#include <bits/stdc++.h>
using namespace std;

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Input
numCourses = 2, prerequisites = [[1,0]]

Output
[0,1]
*/

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto x : prerequisites)
    {
        adj[x[1]].push_back(x[0]);
        indegree[x[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (auto x : adj[t])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }

    if (ans.size() == numCourses)
        return ans;
    return {};
}

int main()
{
    int numCourses, n;
    cin >> numCourses >> n;
    vector<vector<int>> pre(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> pre[i][j];
        }
    }
    vector<int> ans = findOrder(numCourses, pre);
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}
