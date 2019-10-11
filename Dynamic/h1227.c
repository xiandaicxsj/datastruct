/*
 * Fast Food
 * Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
 * Total Submission(s): 3626    Accepted Submission(s): 1560
 *
 *
 * Problem Description
 * The fastfood chain McBurger owns several restaurants along a highway. Recently, they have decided to build several depots along the highway, each one located at a restaurant and supplying several of the restaurants with the needed ingredients. Naturally, these depots should be placed so that the average distance between a restaurant and its assigned depot is minimized. You are to write a program that computes the optimal positions and assignments of the depots.
 *
 * To make this more precise, the management of McBurger has issued the following specification: You will be given the positions of n restaurants along the highway as n integers d1 < d2 < ... < dn (these are the distances measured from the company's headquarter, which happens to be at the same highway). Furthermore, a number k (k <= n) will be given, the number of depots to be built.
 *
 * The k depots will be built at the locations of k different restaurants. Each restaurant will be assigned to the closest depot, from which it will then receive its supplies. To minimize shipping costs, the total distance sum, defined as
 *
 *
 *
 *
 * must be as small as possible.
 *
 * Write a program that computes the positions of the k depots, such that the total distance sum is minimized.
 *  
 *
 *  Input
 *  The input file contains several descriptions of fastfood chains. Each description starts with a line containing the two integers n and k. n and k will satisfy 1 <= n <= 200, 1 <= k <= 30, k <= n. Following this will n lines containing one integer each, giving the positions di of the restaurants, ordered increasingly.
 *
 *  The input file will end with a case starting with n = k = 0. This case should not be processed.
 *   
 *
 *   Output
 *   For each chain, first output the number of the chain. Then output a line containing the total distance sum.
 *
 *   Output a blank line after each test case.
 *    
 *
 *    Sample Input
 *    6 3
 *    5
 *    6
 *    12
 *    19
 *    20
 *    27
 *    0 0
 *     
 *
 *     Sample Output
 *     Chain 1
 *     Total distance sum = 8
 *      
 *
 *      Source
 *      Southwestern Europe 1998
 *       
 *
 *       Recommend
 *       JGShining   |   We have carefully selected several similar problems for you:  1158 1080 1300 1224 1024 
 *        
 *
 *        Statistic | Submit | Discuss | Note
 *        Home | Top	Hangzhou Dianzi University Online Judge 3.0
 *        Copyright © 2005-2019 HD 
 *        thoughts:
 *        dp[i][j] means Min distance [1 : i] resturants has j depot.  
 *        dp[i][j]  = min(dp[k][j-1], + dis[k+1][i])  ( j - 1 < k < i )
 *        dis[i][j] means put 1 depot from  i to j, the distance is ??
 *
 *        Previous issue:
 *        开始认为 dp[i][j] 代表的是选中j为仓库的情况下的最小值，这样认为的原因是没有选对
 *        
 */
#if 0
#include<stdio.h>
#define MAX 100000
#define ABS(value) (value > 0 ? value : -value)
#define MINA(a,b) (a > b ? b: a)
int dp[200][30] = {0};// dp[m][n] 
int pos[200];
int belong[200];
int cal(int sum, int i, int j, int n)
{
	int k=i+1;
printf("sum is %d begin\n", sum);
	for(;k<j;k++)
	{
		if (pos[k] - pos[i] > pos[j] - pos[k])  
		{
			int tmp = 2*pos[k] -pos[i] -pos[j];
	 		sum -= tmp;
		}
	}
	for(; k<n; k++)
	 		sum -= (pos[j]-pos[i]);
	printf("pos i %d pos j %d sum is %d\n", i, j, sum);
	return sum;
}
int cal1(int k, int n)
{
	 int sum=0;
	 int i=0;
	 for (;i<n; i++)
		{
			int tmp = pos[i] - pos[k];
			if (tmp >0)
				sum += tmp;
			else
				sum -=tmp;
		}
		return sum;
}

#endif
#include<stdio.h>

#define MAX_V 1000000
#define min(a, b) ((a) > (b) ? (b) : (a))
/* caculate if we place on deposit between b and e */
int dis(int b, int e)
{
	int sum = 0;
	int i = b;
	int j = e;
	if (b == e)
		return 0;

	for(i = b; i <= j; i++)
		sum += (pos[i] - pos[e]);
	r = sum;

	for(i = b + 1; i <= j; i++) {
		sum = sum + (i - b) * (pos[i] - pos[i - 1])
			- (e - i + 1)  * (pos[i] - pos[i - 1]);
		r = min(r, sum);
	}

	return r;
}

int cal_min(int n, int k)
{
	int i = 0;
	int k1 = 0;
	int j = 0;

	for (k1 = 0; k1 <= k; k1++)
		for (i = 1; i <= n; i++) {
			if (k1 >= i)
				dp[i][k] = 0;
			else
				dp[i][k] = MAX_V;
		}

	for (k1 = 1; k1 <= k; k1++) {
		for (i = 1; i <= n; i++)  {
			if (i <= k1)
				continue;
			for (j = k1 - 1; j < i; j++)
				dp[i][k1] = min(dp[i][k1], dp[j][k1 - 1] + dis(j + 1, i));
		}
	}
}

int main()
{
	int n;
	int k;

	while ( scanf("%d %d", &n, &k) && n && k) {
		int i = 1;

		while (i < n) {
			scanf("%d", &pos[i]);
			i ++;
		}
		cal_min(n, k);
	}
	return 0;
}
