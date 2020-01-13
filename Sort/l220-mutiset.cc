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
#include<iostream>
#include<set>
#include<vector>
using namespace std;
class Solution {
	public:

	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		multiset<long> nums_set;
		long min_v; long max_v;
		int i = 0;
		multiset<long>::iterator lower_idx;
		multiset<long>::iterator upper_idx;

		if (t < 0)
			return false;

		for (; i< nums.size(); i++) {
			min_v = (long)nums[i] - t;
			max_v = (long)nums[i] + t;
			/* |nums[i] - k[i]| <= t
			 * t > nums[i] - k[i] > -t
			 * k[i] >=  nums[i] - t 
			 * k[i] <= nums[i] + t
			 */
			/* for max_v > min_v case */
			lower_idx = nums_set.lower_bound(min_v);
			upper_idx = nums_set.upper_bound(max_v);
			if (lower_idx != upper_idx) {
				return true;
			}

			nums_set.insert((long)nums[i]);
			if (nums_set.size() > k) 
				nums_set.erase(nums_set.find(nums[i- k]));
		}

		return false;
	}
};

int main()
{
	vector<int> nums;
	Solution s;
	int num;
	int k, t;
	int tmp;

	cin>> num;
	while(num) {
		cin >> tmp;
		nums.push_back(tmp);
		num --;
	}
	cin >> k;
	cin >> t;

	if(s.containsNearbyAlmostDuplicate(nums,  k, t))
		cout<< "true"<<endl;
	else
		cout<< "false"<<endl;
}



