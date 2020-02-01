/*
 * 164. Maximum Gap
 * Hard
 *
 * 626
 *
 * 152
 *
 * Favorite
 *
 * Share
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * Example 1:
 *
 * Input: [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either
 *              (3,6) or (6,9) has the maximum difference 3.
 *              Example 2:
 *
 *              Input: [10]
 *              Output: 0
 *              Explanation: The array contains less than 2 elements, therefore return 0.
 *              Note:
 *
 *              You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 *              Try to solve it in linear time/space.
 *              Accepted
 *              78,237
 *              Submissions
 *              231,386
 */


#ifdef C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int maximumGap(int* nums, int numsSize){
	int i = 0;
	int e = -1;
	int max = 0;
	int ARRAY_SIZE = 0;
	int max_v;
	int min_v;
	unsigned int *pos;

	if (numsSize < 2)
		return 0;

	max_v = nums[0];
	min_v = nums[0];
	for (i = 1; i < numsSize; i++)  {
		if (nums[i] > max_v)
			max_v = nums[i];
		if (nums[i] < min_v)
			min_v = nums[i];
	}
	if (numsSize == 2)
		return max_v - min_v;


	ARRAY_SIZE = (max_v - min_v) + 1;
	ARRAY_SIZE = ARRAY_SIZE / sizeof(unsigned int) + 1;

	pos = (unsigned int *)malloc(sizeof(unsigned int) * (ARRAY_SIZE));
	for (i = 0; i < ARRAY_SIZE; i++)
		pos[0] = 0;

	for (i = 0; i< numsSize; i++) 
		pos[(nums[i] - min_v) / (sizeof(unsigned int))] |= 1 << ((nums[i] - min_v) % (sizeof(unsigned int)));

	for (i = 0; i < ARRAY_SIZE * sizeof(unsigned int); i++) {
		if (pos[i / sizeof(unsigned int)] & ( 1 <<( i % sizeof(unsigned int)))) {
			if (e != -1) {
				if (i - e > max)
					max = i  - e;
			} else
				max = 0;
			e = i;
		}
	}	

	free(pos);

	return max;
}

int num_array[1000];
int main()
{
	int nums;
	int i = 0;
	scanf("%d", &nums);
	while (i < nums) {
		scanf("%d", &num_array[i]);
		i++;
	}

	printf("%d\n", maximumGap(num_array, nums));

}

#endif

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#if 0
class Solution {
public:
    int* pos;
    int p_size;
    int min;

    int get_ai(int i) {
	 return (i - min) / (sizeof(int) * 8);
    }

    int get_ni(int i) {
	    return (i - min) % (sizeof(int) * 8);
    }

    int maximumGap(vector<int>& nums) {
	    int size = nums.size();
	    int max;
	    int i = 0;
	    int p_size;
	    int max_gap = 0;
	    int e;
	    int a_i;
            int n_i;

	    if (!size)
		    return 0;
	    min = nums[0];

	    max = min;
	    for(i = 1; i < size; i++) {
		    if (nums[i] < min)
			    min = nums[i];
		    if (nums[i] > max)
			    max = nums[i];
	    }

	    p_size = (max - min + 1) / sizeof(int) + 1;
	    pos = (int *)malloc(p_size * sizeof(int));
	    memset(pos, 0, sizeof(int) * p_size);

	    for(i = 0; i < size; i++) {
		    a_i = get_ai(nums[i]);
		    n_i = get_ni(nums[i]);
		    pos[a_i] |= 1 << n_i;
            }

	    e = min;
	    for(i = min; i <= max; i++) {
		    a_i = get_ai(i);
		    n_i = get_ni(i);
		    if (pos[a_i] & (1 << n_i)) {
			    max_gap = max_gap > i - e ? max_gap : i -e;
			    e = i;
		    }
	    }
	    free(pos);

	    return max_gap;
    }
};
#endif

#include<limits>
#include<algorithm>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
class bucket {
public:
    bool used = false;
    int min_v = std::numeric_limits<int>::max();        // same as INT_MAX
    int max_v = std::numeric_limits<int>::min();
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
	    int min, max;
	    int bucket_idx;
	    int bucket_size;
	    if (nums.size() < 2)
		    return 0;
	    min = *min_element(nums.begin(), nums.end());
	    max = *max_element(nums.begin(), nums.end());
	    /* here bucket_size = (max - min) / (nums.size() - 1)
	     * Hence by setting bucket size bb to be 1 < b \leq (max - min)/(n-1)1<b≤(max−min)/(n−1),
	     * we can ensure that at least one of the gaps between adjacent buckets would serve as the maximal gap.
	     */

	    bucket_size = MAX(1, ((max - min) / (nums.size() - 1)));
	    vector<bucket> buckets((max - min + 1) / bucket_size + 1);

	    for(auto &&num :nums) {
		    bucket_idx = (num - min) / bucket_size;
		    buckets[bucket_idx].min_v = MIN(num, buckets[bucket_idx].min_v);
		    buckets[bucket_idx].max_v = MAX(num, buckets[bucket_idx].max_v);
		    buckets[bucket_idx].used = true;
	    }

	    int pre_bucket_max = min;
	    int max_gap = 0;

	    for (auto &&bucket :buckets) {
		    if (!bucket.used)
			    continue;
		    max_gap = MAX(max_gap, bucket.min_v - pre_bucket_max);
		    pre_bucket_max = bucket.max_v;
	    }

	    return max_gap;
    }
};

int main()
{
	int size;
	Solution s;
	int i = 0;
	vector<int> nums;
	int tmp;

	cin >> size;
	while(i < size) {
		cin >> tmp;
		nums.push_back(tmp);
		i++;
	}

	cout<<s.maximumGap(nums)<<endl;
}

