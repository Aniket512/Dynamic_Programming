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

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> s(wordList.begin(), wordList.end());

    if (s.find(endWord) == s.end())
        return {};

    vector<vector<string>> ans;
    int n = beginWord.length();
    queue<vector<string>> q;
    q.push({beginWord});

    vector<string> used;
    used.push_back(beginWord);
    int level = 0;
    while (!q.empty())
    {
        vector<string> v = q.front();
        q.pop();

        if (v.size() > level)
        {
            for (auto x : used)
            {
                s.erase(x);
            }
            level++;
            used.clear();
        }
        string word = v.back();

        if (word == endWord)
        {
            ans.push_back(v);
        }

        for (int i = 0; i < n; i++)
        {
            char temp = word[i];
            for (char j = 'a'; j <= 'z'; j++)
            {
                word[i] = j;

                if (s.find(word) != s.end())
                {
                    v.push_back(word);
                    q.push(v);
                    used.push_back(word);
                    v.pop_back();
                }
            }
            word[i] = temp;
        }
    }
    return ans;
}

int main()
{
    int n;
    string sw, ew;
    cin >> n >> sw >> ew;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wordList[i];
    }
    vector<vector<string>> ans = findLadders(sw, ew, wordList);
    for(auto x: ans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}