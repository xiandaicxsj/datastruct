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
#ifdef RITH
	struct node *root;

	struct node *alloc_node(int v) {
		struct node *ret = new(node);
		ret->l = ret->r = NULL;
		ret->v = v;
		return ret;
	}
	int lower_bound(int v) {

	}
	/* sort nums */
	/* Questions:
	 * 1. we need to keep k values sorted windows 
	 * 2. we need to know the idx of the value
	 * 3. 
	 * keep k values windows.
	 */
	/* balance tree */
	void insert(int v) {
		struct node *new_node = alloc_node(v); 
		struct node *node = root;
		struct node *parent = root;
		if (!root) {
			root = new_node; 
			return;
		}

		while(node) {
			parent = node;
			if (v > node->v)
				node = node->r;
			else
				node = node->l;
		}

		if (v > parent->v)
			parent->r = new_node;
		else
			parent->l = new_node;
	}

	struct node *search(int v) {
		struct node *node = root;

		if (!node)
			return NULL;

		while(node) {
			if (v > node->v)
				node = node->r;
			if (v == node->v)
				return node;
			if (v < node->v)
				node = node->l;
		}

		return NULL;
	}

	struct node *remove(struct node *node, int v) {
		struct node *ret;
		struct node *left;
		struct node *right;
		if (!node)
			return NULL;
		if (v > node->v)
			node->r = remove(node->r, v);
		if (v < node->v)
			node->l = remove(node->l, v);

		if (v == nodev->v) {

			if (!node->l && !node->r) {
				ret = NULL;
				goto free;
			}

			/* left is NULL */
			if (!node->l) {
				ret = node->r;
				goto free;
			}

			if (!node->r) {
				ret = node->l;
				goto free;
			}

			if (node->l && node->r) {
				struct node *tmp;
				left = node->l;
				right = left->right;
				left->right  = node->r;
				tmp = left->right;

				while(tmp->left) {
					tmp = tmp->left;
				}
				tmp->left = right;

				ret = node->l
				goto free;
			}
		}
		
		free:
			delete(node);
			return ret;
	}

	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int i = 0;
		int l,h;
		int j = 0;
		int b = 0;
		int e = b + k;
		int windows  = 0;
		for (i = 0; i<nums.size(); i++) {
			/* check a
			 * nums[i] - t
			 * t - nums[i]
			 * how to get the nums of range ???
			 */
			/* how to check */
			insert(nums[i]);
			windows ++;
			if (windows > k) {
				remove(nums[i- k]);
				windows-- ;
			}

		}
	}
};



