#include<iostream>
#include<vector>
#include<deque>
using namespace std;
#if 0
int* maxSlidingWindow(int* nums, int numsSize, int k, int* p){

	int e = 0;
	int s = 0;
	int sum = 0;
	int i = 0;
	int *returnSize = (int *)malloc(sizeof(int)*numsSize);
	for (e; e < k; e++)
		sum += nums[e];
	returnSize[i] = sum;
	i++;
	while(e < numsSize){
		sum +=nums[e];
		sum -= nums[s];
		returnSize[i] = returnSize[i - 1];
		if (returnSize[i] < sum)
			returnSize[i] = sum;
		i++;
		s++;
		e++;
	}
	return returnSize;
}

#endif
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	    int e = 0;
	    int s = 0;
	    deque<int> d;
	    vector<int> r;

	    while(e < nums.size())
	    {
		if (d.empty())
			d.push_back(e);
		else {
			if (nums[e] > nums[d.front()]) {
				d.clear();
				d.push_back(e);
			} else {
				while(!d.empty() &&
					nums[d.back()] <= nums[e])
					d.pop_back();
				d.push_back(e);
			}
		}

		e++;
		if (e < k)
			continue;
		r.push_back(nums[d.front()]);
		s++;
		if(s > d.front())
			d.pop_front();
	    }
	    return r;
    }
};
int nums[20];
int main()
{
	vector<int>r;
	vector<int>nums;
	int i = 0;
	int num = 0;
	int k = 0;
	int t;
	Solution s;

	cin >> num;
	while (i < num) {
		cin  >> t;
		nums.push_back(t);
		i ++;
	}
	cin >> k;
	r = s.maxSlidingWindow( nums, k);
	i = 0;
	while(i < r.size()) {
		cout <<r[i]<<" ";
		i++;
	}
	return 0;
}
