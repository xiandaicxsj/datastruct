/*
 * 327. Count of Range Sum
 * Hard
 *
 * 526
 *
 * 70
 *
 * Add to List
 *
 * Share
 * Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
 *
 * Note:
 * A naive algorithm of O(n2) is trivial. You MUST do better than that.
 *
 * Example:
 *
 * Input: nums = [-2,5,-1], lower = -2, upper = 2,
 * Output: 3 
 * Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
 * Accepted
 * 37,181
 * Submissions
 * 109,086
 *
 */
#include<vector>
#include<algorithm>
#include<iostream>
#define BIT
using namespace std;
class Solution {
	public:

#ifdef BIT
	void bsi_insert(int idx) {
		cout<<"inseridx: "<<idx<<endl;
		idx ++;
		while (idx <= size) {
			bsi[idx] ++;
			idx += (idx & -idx); 
		}
	}

	int bsi_sum(int idx) {
		int sum = 0;
		int t_idx = idx;
		idx = idx > size ? size : idx;
		while (idx > 0) {
			sum += bsi[idx];
			idx -= (idx & -idx);
		}
		cout<<"idx:sum: "<<t_idx<<":"<<sum<<endl;
		return sum;
	}

	int *bsi;
	int size;
#endif
	int countRangeSum(vector<int>& nums, int lower, int upper) {
#ifdef MERGE_SORT
#endif
#ifdef BST
#endif
#ifdef BIT
			vector<int> sums;
			vector<int> sums_sort;
			int i = 0;
			int t_sum = 0;
			int l,r,rp,lp,ret = 0;
			size = nums.size() + 1;

			for(i = 0; i < nums.size(); i++) {
				t_sum += nums[i];
				cout<<i<<": "<<t_sum<<endl;
				sums.push_back(t_sum);
				sums_sort.push_back(t_sum);
			}

			cout << "1"<<endl;
			bsi = (int *) malloc(sizeof(int) * size);
			memset(bsi, 0, sizeof(int) * size);

			sort(sums_sort.begin(), sums_sort.end());
			cout << "sort"<<endl;
			for (i = 0; i< sums_sort.size(); i++) {
				cout<<sums_sort[i]<<endl;
			}
			cout << "after sort"<<endl;
			/*  ----  */
			for (i = 0; i < sums.size(); i++) {
				/* this part '-' change to '+' */
				cout <<"-----------"<<endl;
				r = sums[i] - lower;
				l = sums[i] - upper;

				/* 
				rp = (lower_bound(sums_sort.begin(), sums_sort.end(), r) - sums_sort.begin());
				lp = (lower_bound(sums_sort.begin(), sums_sort.end(), l) - sums_sort.begin());
				*/
				rp = (upper_bound(sums_sort.begin(), sums_sort.end(), r) - sums_sort.begin());
				lp = (upper_bound(sums_sort.begin(), sums_sort.end(), l) - sums_sort.begin());
				cout << "check "<< sums[i]<<endl;
				cout << "r:l "<<r<<":"<<l<<endl;
				cout << "rp:lp "<<rp<<":"<<lp<<endl;

				ret += bsi_sum(rp) - bsi_sum(lp);
				cout << "ret :"<<ret<<endl;
				bsi_insert(lower_bound(sums_sort.begin(), sums_sort.end(), sums[i]) - sums_sort.begin());
			}
			free(bsi);

			return ret;
#endif

# if 0
			vector<int> sums;
			vector<int> sums_sort;
			int l, r, m= 0;
			int lp, rp =0;
			int t_sum = 0;
			int i = 0;
			int ret = 0;

			for(i = 0; i< nums.size(); i++) {
				t_sum += nums[i];
				cout<<i<<": "<<t_sum<<endl;
				sums.push_back(t_sum);
			}

			sums_sort = sums;
			sort(sums_sort.begin(), sums_sort.end());
			/*  ----  */
			//sums_map is sorted
			for (i = 0; i < sums.size(); i++) {

				l = sums[i] + lower;
				r = sums[i] + upper;
				m = sums[i];

				rp = (upper_bound(sums_sort.begin(), sums_sort.end(), r) - sums_sort.begin());
				lp = (lower_bound(sums_sort.begin(), sums_sort.end(), l) - sums_sort.begin());
				ret += rp - lp;
				cout<<"sum: "<<sums[i]<< " l:"<<l<<" r:"<<r<<" lp:"<<lp<<" rp:"<<rp<<" ret:"<<ret<<endl;
				m = lower_bound(sums_sort.begin(), sums_sort.end(), m) - sums_sort.begin();
				cout << "m: "<<m<<" size:"<<endl;
				/* this may cause n */
				sums_sort.erase(sums_sort.begin() + m);
			}
			return ret;
#endif
		}
};


int main()
{
	int i = 0;
	int t;
	int lower;
	int upper;
	vector<int> nums;
	Solution s;
	int num;

	cin >> num;
	while (i < num) {
		cin >> t;
		nums.push_back(t);
		i ++;
	}
	cin >> lower;
	cin >> upper;
	cout<<"lower: "<<lower << "upper: "<<upper<<endl;
	cout << s.countRangeSum(nums, lower, upper);

	return 0;
}
