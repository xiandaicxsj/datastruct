/*
 * 969. Pancake Sorting
 * Medium
 *
 * 222
 *
 * 269
 *
 * Favorite
 *
 * Share
 * Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.
 *
 * Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.
 *
 *  
 *
 *  Example 1:
 *
 *  Input: [3,2,4,1]
 *  Output: [4,2,4,3]
 *  Explanation: 
 *  We perform 4 pancake flips, with k values 4, 2, 4, and 3.
 *  Starting state: A = [3, 2, 4, 1]
 *  After 1st flip (k=4): A = [1, 4, 2, 3]
 *  After 2nd flip (k=2): A = [4, 1, 2, 3]
 *  After 3rd flip (k=4): A = [3, 2, 1, 4]
 *  After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 
 *  Example 2:
 *
 *  Input: [1,2,3]
 *  Output: []
 *  Explanation: The input is already sorted, so there is no need to flip anything.
 *  Note that other answers, such as [3, 3], would also be accepted.
 *   
 *
 *   Note:
 *
 *   1 <= A.length <= 100
 *   A[i] is a permutation of [1, 2, ..., A.length]
 *   Accepted
 *   17,053
 *   Submissions
 *   27,116
 */

#if 0
class Solution {
	public:
	vector<int> pancakeSort(vector<int>& A) {
		            
	}
};
#endif

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
/* return index of max value of A */
#include<stdio.h>
#include<stdlib.h>
int find_max(int * A, int b, int e)
{
	int max_idx = b;
	int max = A[b];
	int i = b;

	while(i <= e) {
		if (A[i] > max) {
			max = A[i];
			max_idx = i;
		}

		i++;
	}
	return max_idx;

}

int filp(int *A, int b, int e)
{
	int tmp;
	while(b <= e) {
		tmp = A[b];
		A[b] = A[e];
		A[e] = tmp;
		e--;
		b++;
	}
}

int* pancakeSort(int* A, int ASize, int* returnSize){
	int i = 0;
	int r_i = 0;
	int *tmp_array =  (int *)malloc(10 * sizeof(int) * ASize);
	int *r_array;
	int max;

	i = ASize - 1;
	while (i >= 1) {
		max = find_max(A, 0, i);
		filp(A, 0, max);
		tmp_array[r_i] = max + 1;
		r_i ++;
		filp(A, 0, i);
		tmp_array[r_i] =  i + 1;
		r_i ++;

		i--;
	}

	/* check r_i == 0; */
	r_array = (int *)malloc(sizeof(int) * r_i);
	for (i = 0; i < r_i; i++)
		r_array[i] = tmp_array[i];

	free(tmp_array);
	*returnSize = r_i;

	return r_array;
	
}

int array[1000];
int main()
{
	int size;
	int r;
	int *ra;
	scanf("%d",  &size);
	for (int i = 0; i < size; i++)
		scanf("%d", &array[i]);
	ra = pancakeSort(array, size, &r);
	for (int i = 0; i < r; i++)
		printf("%d ", ra[i]);
	printf("\n");

	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
}

