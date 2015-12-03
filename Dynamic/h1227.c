/*
 * wrong answer
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
