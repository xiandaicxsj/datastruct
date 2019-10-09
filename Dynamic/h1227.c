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
 */
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
int main()
{
	int n;
	int k;
	int i;
	int j;
	while ( scanf("%d %d", &n, &k) && n && k)
	{
		i = 0;
		j = 0;
		for (; i<n; i++)
		{
				scanf("%d", &(pos[i]));
		}
		int m;
		int min= MAX;
		for(i=0; i<n; i++)
		{
				for (j = 0; j<k; j++)
				{
						if( j>i )
							continue;

						if( j==0)
						{
							dp[i][j] =cal1(i,n);
							continue;
						}
						for (m=0; m< i; m++)
						{
								if ( j-1 <= m)
								{
									printf("%d times\n", j);
									dp[i][j] =cal(dp[m][j-1],m, i, n);
								}
						}
						if (j == k-1)
							min= MINA(dp[i][j], min);
				}
		}	
		printf("%d", min);
	}
	return 0;
}
