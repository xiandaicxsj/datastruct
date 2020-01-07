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
struct node {
	int v;
	struct node *l;
	struct node *r;
};

class Solution {
	public:
	struct node *root;

	/* sort nums */
	/* Questions:
	 * 1. we need to keep k values sorted windows 
	 * 2. we need to know the idx of the value
	 * 3. 
	 * keep k values windows.
	 */
	/* balance tree */
	void insert(int v) {

	}

	struct remove(struct node *node, int v) {
		struct node *ret;
		if (!node)
			return NULL;
		if (v > node->v)
			node->r = remove(node->r, v);
		if (v < node->v)
			node->l = remove(node->l, v);
		if (v == nodev->v) {
			if (!node->l && !node->r)
				ret = NULL;
			/* left is NULL */
			if (!node->l)
				ret = node->r;

			if (!node->r)
				ret = node->l;
			if (node

		}
		
		return node;
	}

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



