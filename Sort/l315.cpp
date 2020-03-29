/*
315. Count of Smaller Numbers After Self
Hard

1706

67

Add to List

Share
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

sort array 
then use bst tree to caculte. traverse from back to begin
then ..get new nums.

STATUS:
ACs
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
class Solution {
public:

	void bsi_insert(int idx) {

		while (idx < size) {
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

		return sum;
	}
	int size;
	int* bsi;

	vector<int> countSmaller(vector<int>& nums) {
		int i = 0;
		int idx = 0;
		int count = 0;
		vector<int> ssort;
		vector<int> tmp;
		vector<int> ret;

		ssort = nums;
		sort(ssort.begin(), ssort.end());
		bsi = (int*)malloc(sizeof(int) * nums.size());
		memset(bsi, 0, sizeof(int) * nums.size());
		size = nums.size();

		i = ssort.size() - 1;
		while (i >= 0) {
			idx = lower_bound(ssort.begin(), ssort.end(), nums[i]) - ssort.begin() + 1;
			count = bsi_sum(MAX(idx - 1, 0));
			tmp.push_back(count);
			bsi_insert(idx);
			i--;
		}
		i = tmp.size() - 1;
		while (i >= 0) {
			ret.push_back(tmp[i]);
			i--;
		}

		free(bsi);
		return ret;
	}
};

int main()
{
	Solution s;
	int num;
	vector<int> nums;
	vector<int> ret;

	cin >> num;
	while (num) {
		int t;
		cin >> t;
		nums.push_back(t);
		num--;
	}
	ret = s.countSmaller(nums);
	for (auto&& t : ret) {

		cout << t << " ";
	}
	cout << endl;
}