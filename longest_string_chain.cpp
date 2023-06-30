#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on.
A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Input
["a","b","ba","bca","bda","bdca"]

Output
4

*/

static bool comp(string a, string b)
{
    return a.size() < b.size();
}
bool compare(string a, string b)
{
    if (a.size() != b.size() + 1)
        return false;
    int i = 0, j = 0;
    while (i < a.length())
    {
        if (j < b.length() && a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return (i == a.length() && j == b.length());
}
int longestStrChain(vector<string> &words)
{
    int n = words.size();
    sort(words.begin(), words.end(), comp);
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (compare(words[i], words[j]) && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    cout<< longestStrChain(words);
    return 0;
}