#include<stdio.h>
#include<stdlib.h>
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
	    int e;
	    deque<int> d;
	    int i=0;



	    d.push_back(max);

	    while(e <= num.size())
	    {
		if (nums[e] > nums[d.font()]) {
			d.clear();
			d.push_back(e);
		} else {
			while(nums[d.back()] <= nums[e])
				d.pop_back();
			d.push_back(e);
		}

		s++;
		e++;
		if(s > d.front())
			d.pop_front();
	    }
    }
};
int nums[20];
int main()
{
	int n;
	int k;
	int *s;
	int i;
	scanf("%d", &n);
	for (i=0; i< n;i++)
		scanf("%d", &nums[i]);
	scanf("%d",&k);
	s = (int *)maxSlidingWindow(nums, n, k, NULL);
	for (i = 0; i< n;i++)
		printf("%d\n", s[i]);
}
