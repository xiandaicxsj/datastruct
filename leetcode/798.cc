/*
 * Given an array A, we may rotate it by a non-negative integer K so that the array becomes A[K], A[K+1], A{K+2], ... A[A.length - 1], A[0], A[1], ..., A[K-1].  Afterward, any entries that are less than or equal to their index are worth 1 point. 
 *
 * For example, if we have [2, 4, 1, 3, 0], and we rotate by K = 2, it becomes [1, 3, 0, 2, 4].  This is worth 3 points because 1 > 0 [no points], 3 > 1 [no points], 0 <= 2 [one point], 2 <= 3 [one point], 4 <= 4 [one point].
 *
 * Over all possible rotations, return the rotation index K that corresponds to the highest score we could receive.  If there are multiple answers, return the smallest such index K.
 *
 * Example 1:
 * Input: [2, 3, 1, 4, 0]
 * Output: 3
 * Explanation:  
 * Scores for each K are listed below: 
 * K = 0,  A = [2,3,1,4,0],    score 2
 * K = 1,  A = [3,1,4,0,2],    score 3
 * K = 2,  A = [1,4,0,2,3],    score 3
 * K = 3,  A = [4,0,2,3,1],    score 4
 * K = 4,  A = [0,2,3,1,4],    score 3
 * So we should choose K = 3, which has the highest score.
 *
 *  
 *
 *  Example 2:
 *  Input: [1, 3, 0, 2, 4]
 *  Output: 0
 *  Explanation:  A will always have 3 points no matter how it shifts.
 *  So we will choose the smallest K, which is 0.
 *  Note:
 *
 *  A will have length at most 20000.
 *  A[i] will be in the range [0, A.length].
 */
/* use seg tree can reduce to nlogn */
/* A=[2, 3 ,1 ,4 0]
 * score = [2, 1, -1, 1, -4] (A[i] - i)
 * K = 0;
 * while(K < A.leng) {
 * so each rotate can be split into 3 phrase:
 * 1. let  score[0] -1
 * 2. let  score[1 - A.leng]  +1
 * 3. caculate the cores
 * K++
 * }
 */





























#include<stdio.h>

int accu_point(int *point, int a, int idx, int size)
{
	int _idx = idx;
	int dec = 0;
	do { 
		if (a < _idx)
			point[dec] ++;

		if (_idx == 0)
			_idx = size - 1;
		else
			_idx --;
		dec ++;
		
	} while(_idx != idx)
}

int accu_point(int *point, int a, int idx, int size)
{
	int e = 0;
	int b = 0;

	if (a <= idx) {
		b = idx; e = size 
		b = 0, e = idx - a;
	}

	if (a > idx) {
		/* for max of a < size */
		if (a - idx > 0) {
			b = a - idx;
			e = idx + size - a;
		} else	{
			b = idx;
			e = idx + size - a;
		}
	}
}

int bestRotation(int* A, int ASize)
{
	int i;
	int *point = malloc(sizeof(int) * ASize);
	int max_v = 0;
	int min_r = 0;

	memset(point, 0 , sizeof(point);
	for (i = 0; i < ASize; i++)
		accu_point(point, A[i], i, ASize);

	max_v = point[0];
	for (i = 1; i < ASize; i++) {
		if (point[i] > max_v)
			min_r = i;
	}
	return min_r;
}

int main()
{

	return 0;
}
