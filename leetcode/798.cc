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
#include<stdlib.h>
#include<string.h>

void accu(int * point, int b, int e)
{
	point[b] ++;
	point[e + 1]--;
}

int MIN(int a, int b)
{
	return a > b ? b: a;
}
int bestRotation(int* A, int ASize)
{
 	int *point = (int *)malloc(sizeof(int) * (ASize + 1));
	int sum = 0;
	int max_idx;
	int ri;
	int max;
	int i =0;

	memset(point, 0, sizeof(point));
	/*
	 * idx: A[i] -> ASize() can get point
	 * [0, ASize -1] 
	 */
	for (i = 0; i < ASize; i++) {

		if (A[i] > ASize -1)
			continue;

		max_idx = MIN(ASize - 1, A[i]);
		if (i < max_idx) {
				/* i + 1 */
				accu(point, i + 1, i + ASize - max_idx);
		} else {
				accu(point, 0, i - max_idx);
				accu(point, i + 1, ASize - 1);
		}
	}
	ri = 0;
	sum = point[ri]; 
	max = sum;

	for (i = 1; i< ASize; i++) {
		sum += point[i];
		if (sum > max) {
			max = sum;
			ri = i;
		}
		
	}
	return ri;
}

int A[2000];
int main()
{
	int ASize;
	int i = 0;

	scanf("%d", &ASize);
	for (i; i< ASize; i++)
		scanf("%d", &A[i]);
	printf("%d\n", bestRotation(A, ASize));
	return 0;
}
      
