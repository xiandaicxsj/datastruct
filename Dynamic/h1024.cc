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

/* 
 * dp[t][k] =  max(dp[t][k - 1], dp[t-1][j] + sum[k]- sum[j])
 *
 */
/* thinking 
 * dp[test_num][k] means the max sum value of (0 - num) have k test_pair. end with l
 * dp[test_num][k] = v[k] < 0 max(dp[j][k]) 0 < j <num -1
 * 		v[k] > 0 max(dp[j][k - 1] + cal_one(v[j], v[k]): 0 < j <test_num -1)
 *
 *
 *
 *
 * dp[n][i] means from 0 - i, have n pairs, max value, last item is v[i]
 * 
 * dp[n][i] = max(dp[n][i-1] + v[i], dp[n-1][j] + v[i] { n - 1 < j < i})
 * [i - 1]  > n 
 * 
 * for sing max plus 
 * dp[i] = max(v[i], dp[i] + v[i])
 * dp[i] means last member is i's max
 * max(dp[0-n])
 * 
 * Status: T
 */
 
#if 0
#include<stdio.h>
#define MAX_NUM 1000 
#define MAX_PAIR 1000 
#define MIN_DATA (-1000)
#define __INT64_C(c)  c ## LL
#define INT64_MIN (-__INT64_C(9223372036854775807)-1)
# define INT32_MIN              (-2147483647-1)
int v[MAX_NUM];
int dp[MAX_NUM][MAX_PAIR];
int sum[MAX_NUM];
int test_pair;
int test_num;
#define MIN_INT 0xffffffffffffffff
#define max(a, b) ((a) > (b) ? (a) : (b))

#define DEBUG
#ifdef DEBUG
void dp_print(int i)
{
	int j;
	printf("idx %d :", i);
	for(j = 1; j <= test_pair; j++)
		printf(" %d", dp[i][j]);
	printf("\n");
}
#endif

#ifdef CASE2
void cal_dp1()
{
	int tp = 0;
	int tn = 0;
	int t = 0;
	int k = 0;
	int next = 0;

	for (tn = 1; tn <= test_num; tn++) {
		sum[tn] = 0;
		t += v[tn1];
		sum[tn] = t;
	}

	for (tp = 0; tp <= test_pair; tp++)
		for (tn = 0; tn <= test_num; tn++) {
		dp[tp][tn] = INT32_MIN;
	}

	dp[0][0] = INT32_MIN;

	for (tp = 1; tp <= test_pair; tp++)
		for (tn = 1; tn <= test_num; tn++) {
			if (tn < tp)
				continue;

	#ifdef DEBUG
			printf("check dp[%d][%d]\n", tp, tn);
	#endif
			dp[tp][tn] = dp[tp][tn - 1];
	#ifdef DEBUG
			printf(" dp[%d][%d] %d\n", tp, tn, dp[tp][tn]);
	#endif
			for (k = 0; k < tn; k++) {
				next = dp[tp-1][k] == INT32_MIN ? sum[tn] - sum[k] : dp[tp - 1][k] + sum[tn] - sum[k];
	#ifdef DEBUG
				printf("dp[%d][%d]:%d-next:%d: sum:%d\n", tp - 1, k, dp[tp-1][k], next, sum[tn]-sum[k]);
	#endif
				dp[tp][tn] = max(dp[tp][tn], next);
			}
	#ifdef DEBUG
			printf("dp[%d][%d]:%d\n", tp, tn, dp[tp][tn]);
	#endif
		}



	#ifdef DEBUG
	for (tp = 1; tp <= test_pair; tp++)
		for (tn = 1; tn <= test_num; tn++)
			printf("dp[%d][%d]:%d\n", tp, tn, dp[tn][tp]);
	#endif
	printf("%d\n", dp[test_pair][test_num]);

}
#endif

#if 0
void cal_dp() {


	printf("test_num: %d\n", test_num);
	dp[0][0] = v[0];
	int maxv;
	int sum = 0;
	int i = 0;
	int j = 0;

	for (i = 1; i <= test_num; i++) {
		sum += v[i];
		dp[i][i] = sum;
		dp[0][i] = INT32_MIN;
	}

	for (i = 1; i <= test_pair ; i ++) {
		maxv = dp[i][i];
		for (j = i + 1; j <= test_num; j++) {
			maxv =  max(dp[i - 1][j - 1], maxv);
			dp[i][j] = maxv + v[j];
			printf("j:%d v:%d\n", j, dp[i][j]);
		}
	}

	printf("=======\n");
	maxv = dp[test_pair][test_num];
	for (j = 1; j <= test_num; j++) {
		maxv = max(dp[test_pair][j], maxv);
	}
	int tp;
2int tn;
	for (tp = 1; tp <= test_pair; tp++)
		for (tn = 1; tn <= test_num; tn++)
			printf("dp[%d][%d]:%d\n", tp, tn, dp[tn][tp]);
	printf("%d\n", maxv);
}
#endif

#endif 
#include<stdio.h>
#define MAX_NUM 1000002
#define max(a, b) ((a) > (b) ? (a) : (b))
int v[MAX_NUM];
int pre_max[MAX_NUM];
int test_pair;
int test_num;
void cal_dp2(int test_pair, int test_num) 
{
	int i = 0;
	int j = 0;
	int k = 0;
	int tmp;
	int maxv;

	for (i = 1; i <= test_num ; i ++)
		pre_max[i] = 0;
	for (i = 1; i <= test_pair ; i ++) {
		tmp = 0;
		for (k = 1; k <= i; k++)
			tmp += v[k];
		maxv = tmp;
		for (j = i + 1; j <= test_num; j++) {
			//tmp = max(maxv, pre_max[j - 1]) + v[j];
			tmp = max(tmp, pre_max[j - 1]) + v[j];
			pre_max[j - 1] = maxv;
			maxv = max(maxv, tmp);
		}
	}

	printf("%d\n", maxv);

}

void DP(int m, int n)
{
	for(int i = 1; i <= m; ++i)
	{
		int tmp = 0;
		for(int k = 1; k <= i; ++k)
			tmp += v[k];
		pre_max[n] = tmp;
			         
	         for(int j = i+1; j <= n; ++j) {
			tmp = max(pre_max[j-1], tmp) + v[j];
			pre_max[j-1] = pre_max[n];
			pre_max[n] = max(pre_max[n], tmp);         
		 }
     }
     printf("%d\n", pre_max[n]);
}

int main()
{
	int idx;
	int i,j;

	//printf("%d\n", INT32_MIN);
	while(~scanf("%d %d", &test_pair, &test_num)) {
		for(idx = 1; idx <= test_num; idx ++)
			scanf("%d", &v[idx]);
		cal_dp2(test_pair, test_num);
		//DP(test_pair, test_num);
	}
	return 0;

}	 
