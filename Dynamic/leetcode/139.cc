/*
 * 139. Word Break
 * Medium
 *
 * 2640
 *
 * 139
 *
 * Favorite
 *
 * Share
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Note:
 *
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * Example 1:
 *
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 * Example 2:
 *
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 *              Note that you are allowed to reuse a dictionary word.
 *              Example 3:
 *
 *              Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 *              Output: false
 *
 */
/* dp[10000]; dp[i] means if i is */
/* dp case */
#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
class Solution {
	public:
		bool wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
			int i, j;
			bool dp[1000];
			for (i = 0; i < s.size(); i++) {
				for (j = 0; j < i; j++)
					if (dp[j] && wordSet.count(s.substr(j + 1 , i - j)))
						dp[i] = true;
			}
		}
};

# if 0
/* search case */
class Solution {
	public:
		bool search_str(string s, int b, unordered_set<string> &wordSet) {
			int size = s.size();
			int e = b;
			/* 0 , 1 
			 * size = 2
			 * s = 0
			 * e = 2
			 */
			for (e; e <= size; e++) {
				if (wordSet.count(s.substr(b, e - b)))
					if (search_str(s, e))
						return true;
			}
			return false;
		}

		bool wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
			return search_str(s, 0, wordSet);
		}
};
#endif
int main()
{
	Solution s;
	string word;
	string tmp;
	int i = 0;
	int n = 0;
	vector<string> wordset;

	cin >> word;

	cin >> n; 
	while (i < n) {
		cin >> tmp;
		wordset.push_back(tmp);
		i++;
	}
	s.wordBreak(word, wordset);

	return 0;
}
