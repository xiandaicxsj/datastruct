
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
