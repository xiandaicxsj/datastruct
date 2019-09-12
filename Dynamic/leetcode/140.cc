/* Word break II
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * add spaces in s to construct a sentence where each word is a valid dictionary word. Return
 * all such possible sentences.
 *
 * Note:
 *
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * Example 1:
 *
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 *   "cats and dog",
 *   "cat sand dog"
 * ]
 * Example 2:
 *
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 *     "pine apple pen apple",
 *     "pineapple pen apple",
 *     "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * Example 3:
 *
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * Status
 * 
 * dp[i][j] means match or not ? 
 * match[i][j] means match what ?
 * dp[i][j] = dp[i][k] + dp[k][j] ?
 * qeuestion is how to quickly decide work is match or not ?
 * we need to algorithm to search quickly on something ?
 *
 */

using map[] ?
class Solution {
	public:
	bool is_word_in_dict(string s) {

	}
	/* check i - j and j + 1 - e */
	bool check_word(int i, int j) {
		if (dp[i][j])
			return true;
		if (dp[i][j])
			return true;
		return true;
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		int s = 0;
		int i = 0;
		int j = 0;
		int len = s.size();

		/* n^3 * how to search a work whe  */
		for (s = 1; s < len; s++) {
			/* max is len - s - 1 */
			for (i = 0; i < len - s; i++) {
				/* max is i + s -1 */
				for (j = i + 1; j < i + s; j++) {
					/* we just record the status, not the strig 
					 */
					dp[i][i + s] = check_word(i, j , s);
				}
			}
		}
	}
};
