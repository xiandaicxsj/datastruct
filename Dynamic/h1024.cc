/*
 * RES: Sample verified. But not AC yet. Still need thinking more.
 * 
 * MAX SUM PLUS PLUS
 * Problem Description
 * Now I think you have got an AC in Ignatius.L's "Max Sum" problem. To be a brave ACMer, we always challenge ourselves to more difficult problems. Now you are faced with a more difficult problem.
 *
 * Given a consecutive test_number sequence S1, S2, S3, S4 ... Sx, ... Sn (1 ≤ x ≤ n ≤ 1,000,000, -32768 ≤ Sx ≤ 32767). We define a function sum(i, j) = Si + ... + Sj (1 ≤ i ≤ j ≤ n).
 *
 * Now given an integer m (m > 0), your task is to find m test_pairs of i and j which make sum(i1, j1) + sum(i2, j2) + sum(i3, j3) + ... + sum(im, jm) maximal (ix ≤ iy ≤ jx or ix ≤ jy ≤ jx is not allowed).
 *
 * But I`m lazy, I don't want to write a special-judge module, so you don't have to output m test_pairs of i and j, just output the maximal summation of sum(ix, jx)(1 ≤ x ≤ m) instead. ^_^
 *  
 *
 *  Input
 *  Each test case will begin with two integers m and n, followed by n integers S1, S2, S3 ... Sn.
 *  Process to the end of file.
 *   Output
 *   Output the maximal summation described above in one line.
 *    
 *
 *    Sample Input
 *
 *    1 3 1 2 3
 *    2 6 -1 4 -2 3 -2 3
 *
 *     
 *
 *     Sample Output
 *
 *     6
 *     8
 *
 *     Hint
 *
 *     Huge input, scanf and dynamic programming is recommended.
 */

/* thinking 
 * dp[test_num][k] means the max sum value of (0 - num) have k test_pair. end with l
 * dp[test_num][k] = v[k] < 0 max(dp[j][k]) 0 < j <num -1
 * 		v[k] > 0 max(dp[j][k - 1] + cal_one(v[j], v[k]): 0 < j <test_num -1)
 *
 *
 */
 
#include<stdio.h>
typedef int var_t;
#define MAX_NUM 1000 
#define MAX_PAIR 1000 
#define MIN_DATA (-1000)
var_t v[MAX_NUM];
var_t dp[MAX_NUM][MAX_PAIR];
int test_pair;
int test_num;
#define max(a, b) (a > b ? a : b)

var_t cal_max(int start, int end)
{
	var_t ret = v[end];
	var_t value = v[end];
	end --;

	//printf(" 1 s %d e %d max %d\n", start, end, ret);
	while(end >= start)
	{
		value += v[end];
		ret = max(ret, value); 
		end--;
	}
	//printf(" 2 s %d e %d max %d\n", start, end, ret);
	return ret;
}

void dp_print(int i)
{
	int j;
	printf("idx %d :", i);
	for(j = 1; j <= test_pair; j++)
		printf(" %d", dp[i][j]);
	printf("\n");
}

void cal_dp() {

	int i = 1;
	int j = 1;
	int k = 0;
	int max_v = MIN_DATA;
	var_t tmp;

	dp[i][j] = v[1];

	for(i = 2; i <= test_num; i++) {

		for(j = 1; j <= test_pair; j++) {

			if (v[i] < 0) {

				dp[i][j] = v[i];
				//printf("v[i]:%d dp[i][j]: %d\n", v[i], dp[i][j]);
				for(k = i - 1; k > 0; k--) {
					tmp = ((dp[k][j - 1] == MIN_DATA) ? 0: dp[k][j - 1]) + v[i];
					dp[i][j] = max(dp[i][j], tmp);
				}
				//printf("v[i]:%d dp[i][j]: %d\n", v[i], dp[i][j]);
			} else {

				for(k = i - 1; k > 0; k--) {
					dp[i][j] = max(dp[i][j], (dp[k][j - 1] == MIN_DATA ? 0 : dp[k][j-1]) + cal_max(k + 1, i));
					//printf(" dp[i][j]: %d cal k: %d i: %d v %d dp[k][j-1]: %d\n", dp[i][j], k, i, cal_max(k,i), dp[k][j-1]);
				}
			}
			max_v = max(max_v, dp[i][j]);
		}
		//dp_print(i);
	}
	printf("max value %d\n", max_v);
}

int main()
{
	int idx;
	int i,j;

	scanf("%d %d", &test_pair, &test_num);
	for(idx = 1; idx <= test_num; idx ++)
		scanf("%d", &v[idx]);
	for(i = 0; i <= test_num; i++)
		for(j = 0; j <= test_pair; j++)
			dp[i][j] = MIN_DATA;
	cal_dp();
	return 0;

}	 
