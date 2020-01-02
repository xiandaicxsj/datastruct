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
//#define BIT
//#define DEBUG
#define MERGE_SORT
using namespace std;
class Solution {
	public:

#ifdef BIT
	void bsi_insert(int idx) {
		idx ++;
	#ifdef DEBUG
		cout<<__func__<<" idx:"<<idx<<endl;
	#endif
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
	#ifdef DEBUG
		cout<<__func__<<" idx:"<<t_idx<<" sum:"<<sum<<endl;
	#endif
		return sum;
	}

	int *bsi;
	int size;
#endif
#define DEBUG
#ifdef MERGE_SORT
	int ret;
	/* how to deal with 2 problem
	 * 1. sum[i] may be chosen too.
	 * 2. sum[i] may be duplicate with sum[j], then how to deal with this.
	 */
	void merge_sort(vector<int> &sums, int l, int r, int low, int upp) {
		int m = (l + r) >> 1;
		int sr = 0;
		int lv = 0;
		int rv = 0;
		int i = l;
		int lp = 0;
		int rp = 0;

		if (l >= r) {
			if (sums[r] >= low && sums[r] <= upp) {
				ret++;
			}
		#ifdef DEBUG
			cout <<"dsdfsdf"<<"l:r"<< l<<":" << r << ":"<<m<<endl;
		#endif
			return;
		}
		cout<<l<<"---->"<<m<<"---->"<<r<<endl;
		merge_sort(sums, l, m, low, upp);
		merge_sort(sums, m + 1, r, low, upp);
	#ifdef DEBUG
		cout<<l<<"------->"<<r<<endl;
		cout <<"left: "<<l<<"->" <<m<< ":"<<m<<endl;
		int t_l,t_r; 
		t_l = l;
		t_r = r;
		while(t_l <= m) {
			cout<<"sums["<<t_l<<"]:"<<sums[t_l]<<endl;
			t_l ++;
		}

		cout <<"right: "<<m+1<<"->" <<r<< ":"<<m<<endl;
		while(t_l <= r) {
			cout<<"sums["<<t_l<<"]:"<<sums[t_l]<<endl;
			t_l ++;
		}
	#endif
	
		for (sr = m + 1; sr <= r; sr++) {
			/* upp>= sr - lr >= low 
			 * lr >= sr - upp && lr <= sr- low 
			 */
			lv = sums[sr] - upp;
			rv = sums[sr] - low;

			rp = upper_bound(sums.begin() + l, m >= sums.size() - 1 ? sums.end() : sums.begin() + m + 1, rv) - sums.begin(); /* sr-low */
			lp = lower_bound(sums.begin() + l, m >= sums.size() - 1 ? sums.end() : sums.begin() + m + 1, lv) - sums.begin(); /* sr-upp */

		#ifdef DEBUG
			cout <<"sr: "<<sr;
			cout <<" lv:"<<lv;
			cout <<" rv:"<<rv;
			cout <<" lp:"<<lp;
			cout <<" rp:"<<rp;
			cout <<endl;
		#endif
			ret += (rp - lp);
		#ifdef DEBUG
			cout<<"ret:"<<ret<<endl;
		#endif
		}

		inplace_merge(sums.begin() + l, sums.begin() + m, sums.begin() + r);
	#ifdef DEBUG
		t_l = l; 
		t_r = r;
		cout<<"after merge:"<<endl;
		while(t_l <= t_r) {
			cout<<"sums["<<t_l<<"]:"<<sums[t_l]<<endl;
			t_l ++;
		}

	#endif
		/* merge func */
		/* merge res[l-m] res[m+1, r] */
	}
#endif
	int countRangeSum(vector<int>& nums, int lower, int upper) {
#ifdef MERGE_SORT
		/* as merge sort itself have log(n) depth */
		int size = nums.size();
		vector<int>sums;
		int i = 0;
		int t = 0;
		for(i = 0; i < size; i++) {
			t += nums[i];
			sums.push_back(t);
		}

		ret = 0;
		merge_sort(sums, 0, size - 1, lower, upper);
		return ret;
#endif
#ifdef BST
#endif
#ifdef BIT
			vector<int> sums;
			vector<int> sums_sort;
			int i = 0;
			int t_sum = 0;
			int l,r,rp,lp,ret = 0;
			int tr = 0; 
			int tl = 0;
			int si = 0;
			size = nums.size() + 2;
			int *ain;

			for(i = 0; i < nums.size(); i++) {
				t_sum += nums[i];
				sums.push_back(t_sum);
				sums_sort.push_back(t_sum);
			}

			bsi = (int *) malloc(sizeof(int) * size);
			memset(bsi, 0, sizeof(int) * size);

			ain = (int *) malloc(sizeof(int) * size);
			memset(ain, 0, sizeof(int) * size);


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
					si = bsi[(lower_bound(sums_sort.begin(), sums_sort.end(), sums[i]) - sums_sort.begin())];
					if (ain[si] == 0) {
						ain[si] ++;
						ret ++;
					}
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
				//bsi_insert(lower_bound(sums_sort.begin(), sums_sort.end(), sums[i]) - sums_sort.begin());
			}
			free(bsi);
			free(ain);

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
	cout <<"res:"<< s.countRangeSum(nums, lower, upper)<<endl;

	return 0;
}
