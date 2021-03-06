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
 * think:
 * get sums[i] copy to sums_back and sort sums_back
 * for each s in sums[i] get lower_bound and upper_bound base on sums[i]
 * get lower_idx and upper_idx in sums_back 
 * bsi[upper_idx] - bsi[lower_idx]
 * insert sums[i] idx into bsi
 *
 *
 * Status:
 * AC
 */
#include<vector>
#include<algorithm>
#include<iostream>
#define BIT
#define DEBUG
using namespace std;
class Solution {
	public:
	void bsi_insert(int idx) {
		idx ++;
	#ifdef DEBUG
		cout<<__func__<<" idx:"<<idx<<endl;
	#endif
		while (idx < size) {
			cout<<idx<<endl;
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
	#ifdef DEBUG
		cout<<__func__<<" idx:"<<t_idx<<" sum:"<<sum<<endl;
	#endif
		return sum;
	}

	int *bsi;
	int size;
	int countRangeSum(vector<int>& nums, int lower, int upper) {
			vector<long> sums;
			vector<long> sums_sort;
			int i = 0;
			long t_sum = 0;
			long l,r;
			int rp,lp,ret = 0;
			int tr = 0; 
			int tl = 0;

			size = nums.size() + 1;

			for(i = 0; i < nums.size(); i++) {
				t_sum += nums[i];
				sums.push_back(t_sum);
				sums_sort.push_back(t_sum);
			}

			bsi = (int *) malloc(sizeof(int) * size);
			memset((void *)bsi, 0, sizeof(int) * size);

			sort(sums_sort.begin(), sums_sort.end());
			/* question:
			 * 1. when to insert sum[i] ?
			 * 2. if insert sum[i] at the ending,  how to get lower << sum[i] < upper
			 *    also should deal with duplicate value ?
			 */
			for (i = 0; i < sums.size(); i++) {
				/* this part '-' change to '+' */
				r = sums[i] - lower;
				l = sums[i] - upper;

				/* we need to check if sum[i] is already in */
				if (sums[i] >= lower && sums[i] <= upper) {
			#if 0
					si = bsi[(lower_bound(sums_sort.begin(), sums_sort.end(), sums[i]) - sums_sort.begin())];
					if (ain[si] == 0) {
						ain[si] ++;
						ret ++;
					}
			#endif
					ret ++;
				}

				/* 
				rp = (lower_bound(sums_sort.begin(), sums_sort.end(), r) - sums_sort.begin());
				lp = (lower_bound(sums_sort.begin(), sums_sort.end(), l) - sums_sort.begin());
				*/
				rp = (upper_bound(sums_sort.begin(), sums_sort.end(), r) - sums_sort.begin());
				lp = (lower_bound(sums_sort.begin(), sums_sort.end(), l) - sums_sort.begin());

				/* rp = (upper_bound) -1 + 1  
				 * upper_bound get idx sums_sort[idx] > v, but we need to get v's idx, so idx --,
				 * idx is the array idx. idx + 1 is used for bsi_sum(). 
				 *
				 * lp = (lower_bound) -1 + 1
				 * lower_bound get idx sums_osrt[idx] >= v, so for == v, we need to idx --, because we need to
				 * cover ==v case. for >v , idx--, means we need to get sums_sort[idx] < v. so idx --.
				 */

				tr = bsi_sum(rp);
				tl = bsi_sum(lp);
				ret += tr - tl;
				#ifdef DEBUG
				cout << "sum["<<i<<"]:"<< sums[i]<<" max-min:["<<r<<"-"<<l<<"] ";
				cout << "idx:"<<"["<<rp<<"-"<<lp<<"] ";

				cout << "bsi_sum:"<<"["<< tr<<"-"<<tl<<"] "<<"ret:"<<ret <<endl;
				#endif
				bsi_insert(lower_bound(sums_sort.begin(), sums_sort.end(), sums[i]) - sums_sort.begin());
			}
			free(bsi);

			return ret;

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
	cout <<"res:"<< s.countRangeSum(nums, lower, upper)<<endl;

	return 0;
}
