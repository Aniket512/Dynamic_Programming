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

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> s(wordList.begin(), wordList.end());

    if (s.find(endWord) == s.end())
        return 0;

    int n = beginWord.length();
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while (!q.empty())
    {
        string word = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (word == endWord)
            return cnt;

        for (int i = 0; i < n; i++)
        {
            char temp = word[i];
            for (char j = 'a'; j <= 'z'; j++)
            {
                word[i] = j;
                if (s.find(word) != s.end())
                {
                    s.erase(word);
                    q.push({word, cnt + 1});
                }
            }
            word[i] = temp;
        }
    }
    return 0;
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
    cout << ladderLength(sw, ew, wordList);
    return 0;
}