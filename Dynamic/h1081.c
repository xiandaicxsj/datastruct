/*
 * compress 2d array /passed
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
#define MAX(a,b) ( a > b ? a : b)
int array[N][N];
int tmp[N];
int dp(int n)
{
	int *dp = (int *)malloc(n*sizeof(int));
	memset(dp, 0, sizeof(int)*n);
	int max;
	int i=0;
	max = tmp[0];
	dp[0] = tmp[0];
	for (i=1; i<n; i++)
	{
		dp[i] = MAX(tmp[i] + dp[i-1] ,tmp[i]);
		max = MAX(dp[i] ,max);
	}
	return max;
}
int main()
{
	int n;
	
	while( ~scanf("%d", &n) &&n)
	{
	int i = 0;
	int j = 0;
	int k = 0;
	int max = -10000;
	for(; i<n*n; i++)
		scanf("%d", &(array[i/n][i%n]));
	for(i = 0; i<n; i++)
	{
		memset(tmp, 0, sizeof(int)*N);
		for( j = i; j<n; j++)
		{
			for( k=0; k<n; k++)
				tmp[k] += array[j][k];
			max = MAX(dp(n), max);
		}
	}
	printf("%d\n", max);
	}
	return 0;
}
