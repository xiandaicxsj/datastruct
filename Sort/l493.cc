/*
 * 493. Reverse Pairs
 * Hard
 *
 * 650
 *
 * 98
 *
 * Favorite
 *
 * Share
 * Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
 *
 * You need to return the number of important reverse pairs in the given array.
 *
 * Example1:
 *
 * Input: [1,3,2,3,1]
 * Output: 2
 * Example2:
 *
 * Input: [2,4,3,5,1]
 * Output: 3
 * Note:
 * The length of the given array will not exceed 50,000.
 * All the numbers in the input array are in the range of 32-bit integer.
 * Accepted
 * 30,419
 * Submissions
 * 126,359
 */

/* O(n2) */

/*
int reversePairs(int* nums, int numsSize){

pre[] have the the 

}


thought

choose from tail
then
for i+1 ...j:
	choose max idx that a[max_idx] < a[i] but the most adhere to a[i]/2

a[i] = a[max_idx] + a[i] > 2*a[max_idx] ? 1: 0;

but for 

3 1 2 1

when at 1, pairs num is 0 v[1] = 0
when at 2, pairs num is 0 v[2] = 0
when at 1, pairs num is 0, but we need to update ??? v[1] = 1 ? should we update v[2] ???
it seem that seg tree is a good ting ??

or
nlog(n) sort, then 
3 1 2 1
1 1 2 3
*/

#if 0
public int reversePairs(int[] nums) {
	    int res = 0;
	        int[] copy = Arrays.copyOf(nums, nums.length);
		    int[] bit = new int[copy.length + 1];
		        
		        Arrays.sort(copy);
			    
			    for (int ele : nums) {
				            res += search(bit, index(copy, 2L * ele + 1));
					            insert(bit, index(copy, ele));
						        }
			        
			        return res;
}

private int index(int[] arr, long val) {
	    int l = 0, r = arr.length - 1, m = 0;
	        	
	        while (l <= r) {
		    	m = l + ((r - l) >> 1);
	    		
		    	if (arr[m] >= val) {
		    	    r = m - 1;
	        	} else {
		    	    l = m + 1;
	        	}
	       }
		    
		return l + 1;
}
#endif
#undef C
#ifdef C
int reversePairs(int* nums, int numsSize){

}

int main()
{
}
#endif

#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:


	void bsi_insert(int idx) {
		while (idx <= size) {
			bsi[idx] ++;
			idx += (idx & -idx); 
		}
	}

	int bsi_sum(int idx) {
		int sum = 0;
		idx = idx > size ? size : idx;
		while (idx > 0) {
			cout<<"idx:"<<idx<<endl;
			sum += bsi[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}

	int *bsi;
	int size;

	int INDEX(vector<int>& nums, long v) {
		int l = 0;
		int r = nums.size() - 1;
		int m;
		int last;
		while (l <= r) {
			m = l + ((r - l) >> 1);
			if (v < (long )nums[m]) {
				l = m + 1;
				last = l;
			} else{ 
				if ((long)v > (long) nums[m]) {
					r = m -1;
					last = r;
				} else {
					last = m;
					break;
				}

			}

		}
		return last + 1;
	}

	int reversePairs(vector<int>& nums) {
		vector<int> nc = nums;
		int i = 0;
		int res = 0;
		int idx;

		sort(nc.begin(), nc.end(), greater<int>());
		size = nc.size();
		bsi = (int *) malloc((size + 1)* sizeof(int));
		memset(bsi, 0, sizeof(int) * (size + 1));

		for (i = 0; i < size; i++) {
#if 0
			cout << "lower_bound:" <<" ";
			idx = lower_bound(nc.begin(), nc.end(), 2 * nc[i] + 1) - nc.begin();
			cout <<nc[i] <<" "<< idx << endl;
			res += (bsi_sum(size + 1) - bsi_sum(idx));
			idx = lower_bound(nc.begin(), nc.end(), nc[i]) - nc.begin();
			cout << "insert: " <<nc[i] <<"to " << idx<<endl;
			bsi_insert(lower_bound(nc.begin(), nc.end(), nc[i]) - nc.begin() + 1);
#endif
			int sum = 0;
			idx = INDEX(nc, (long) nums[i] * 2 +1);
			sum = bsi_sum(idx);
	#ifdef DEBUG
			cout<<"ai: "<<nums[i]<<" check "<< 2147483647 * 2 - 1  <<" found idx: "<<idx<<" sum is:"<<sum;

	#endif
			res += sum;
	#ifdef DEBUG
			cout<< " res:"<<res<<endl;
	#endif
			bsi_insert(INDEX(nc, nums[i]));
		}
		free(bsi);

		return res;
	}
};

/* we should sort the nums from big to small, then we can checkout bsi(idx)
 * or if we sort nums from small to big, then we should res += bsi(size) - bsi(idx)
 * */
int main()
{
	int size;
	int i = 0;
	int t;
	vector<int> nums;
	Solution s;

	cin >> size;

	while (i < size) {
		cin >> t;
		nums.push_back(t);
		i++ ;
	}
	cout << 0xffffffff;
	cout << "result " <<s.reversePairs(nums) <<endl;

}
