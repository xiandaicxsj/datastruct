/*Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
TEST passed 
NOT AC 
*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {

	    int size = nums.size();

	    if (size <= 1)
		    return 0;
	    /* from big > small */
	    vector<int> a(nums.begin(), nums.begin() + size / 2); 
	    vector<int> b(nums.begin() + size / 2, nums.end()); 

	    int l = reversePairs(a);
	    int r = reversePairs(b);

	    int bi = 0;
	    int ai = 0;
	    int ni = 0;

	    r += l;
	    while(ai < a.size()) {
	    	while(a[ai] <= 2 * b[bi] && bi < b.size())
			bi ++;

		if (bi == b.size())
			break;

		/* how */
		r += (b.size() - bi);
		ai ++;
	    }

	    ai = bi = 0;

	    while(ni < size) {
		    if (a[ai] >= b[bi]) {
			    nums[ni] = a[ai];
		            ai++;
			    if (ai == a.size()) {
				    ni ++;
				    while(ni < size && bi < b.size()) {
					    nums[ni] = b[bi];
					    ni ++;
					    bi ++;
				    }
				    break;
		            }
		    } else {
			    nums[ni] = b[bi];
		            bi++;
			    if (bi == b.size()) {
				    ni ++;
				    while(ni < size && ai < a.size()) {
					    nums[ni] = a[ai];
					    ni ++;
					    ai ++;
				    }
				    break;
		            }
		    }
		    ni ++;
	    }
	    return r;
    } 
};

int main()
{
	Solution s;
	int n;
	vector<int> nums;
	int i = 0;
	int tmp;

	cin >>n;
	while(i < n)
	{
		cin >> tmp;
		nums.push_back(tmp);
		i++;
	}
	cout << s.reversePairs(nums);
	return 0;

}
