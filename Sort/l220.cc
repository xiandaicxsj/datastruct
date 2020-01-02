/*
 * 220. Contains Duplicate III
 * Medium
 *
 * 826
 *
 * 846
 *
 * Favorite
 *
 * Share
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
 *
 * Example 1:
 *
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 * Example 2:
 *
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 * Example 3:
 *
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 * Accepted
 * 106,157
 * Submissions
 * 523,023
 * Seen this que
 */

/* balance search tree */

class Solution {
	public:
	struct node *root;

	/* sort nums */
	/* then each time get upper/lower bound, check related idx 
	 * then get ...
	 * keep k values windows.
	 */
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int i = 0;
		int l,h;
		int j = 0;
		int b = 0;
		int e = b + k;
		for (i = 0; i<nums.size(); i++) {
			if (i == 0)
				continue;

		}
	}
};



