/*
 * 209. Minimum Size Subarray Sum
 *
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 *
 * Example: 
 *
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem constraint.
 * Follow up:
 * If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
 * Accepted
 * 219,445
 * Submissions
 * 602,956
 * 
 * AC
 * thinking:
 * as array sum is in increase order, make use of this we can use binary search to get nlog(n).
 * below is o(n). because each elem is push and pop 2 times. the sercret is when sum[i] - sum[d.front()] >= k,
 * then it means sum[j] (j > i) also satisfy the condition sum[j] - sum[d.front()] >= k, but j is bigger than
 * i, so we will not choose j. So just pop_front is ok.
 */
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

#define MIN(a, b) ((a) > (b) ? (b) : (a));
class Solution {
	public:
	int minSubArrayLen(int s, vector<int>& nums) {
		deque<int> d;
		vector<long> sum;
		int t = 0;
		int i = 0;
		int res = -1;

		if (!nums.size()) 
			return 0;

		sum.push_back(nums[0]);

		for(i = 1; i < nums.size(); i++)
			sum.push_back(sum[i-1] + nums[i]);
		if (sum[i - 1] >= s)
			res = i;
		else
			return 0;

		for (i = 0; i< sum.size(); i++) {
			if (sum[i] >= s && res > i + 1)
				res = i + 1;
				
			while(!d.empty() && (sum[i] - sum[d.front()] >= s)) {
					if (res > i - d.front())
						res = i - d.front();
				d.pop_front();
			}
			while(!d.empty() && sum[i] < sum[d.back()])
				d.pop_back();

			d.push_back(i);
		}

		return res;
        }
};

int main()
{
	int s;
	int i;
	int t;
	int n;
	vector<int>nums;
	Solution S;

	cin>>s;
	cin>>n;
	for (i = 0; i < n; i++) {
		cin>>t;
		nums.push_back(t);
	}

	cout << S.minSubArrayLen(s, nums);

}
