/*
 * i-j : hose i to hose j
 * k: i-j put in to k stables
 * dp[i][j][k] = min(dp[i][x][s] + dp[x+1][j][k-s]) (1 < s < k,  i< x < j)
 *
 *
#include<stdio.h>

#define N 100;
int stable[N];
int main()
{
	int i;
	int j;
	int n;
	for(int k = 0; k< ; k++)
	for(n = 1; n< length; n++)  
	{
		for(i=0; i<length-n;i++)
		{
			if (k == 1)
			{
			}
			else
			for(j=i; j<i+n; j++)
			{
				for(s = 1; s< k; s++)
				{
				}
			}
		}
	}
	return 0;
}
*/

/* new thought */
/* dp[i][j]  min value of j horse put into i stable */
/* dp[i][j] = min(dp[i-1][k], cacule(k <-> j)); */
#include<stdio.h>
#define MAX 500
#define MAX_V 65535
int dp[MAX][MAX] = {MAX_V};
int horse[MAX];

int min(int a, int b)
{
	return a>b ? b:a;
}
int caculate(int b, int e)
{
	int wc = 0;
	int bb = b;
	while(bb <= e)
	{
		if (horse[bb]==1)
			wc ++;
		bb ++;
	}
	return wc * (e - b + 1 - wc);
}

int main()
{
	int horse_num = 0;
	int stable_num = 0;
	int hidx = 1;
	int sidx = 1;
	
	int m;
	int i;
	int j;

	while(scanf("%d %d", &horse_num, &stable_num) !=EOF)
	{	

		hidx = 1;
		while(hidx <= horse_num)
		{
			scanf("%d", &horse[hidx]);
			hidx ++;
		}
		hidx = 1;

		if (horse_num <= stable_num)
		{
			printf("0\n");
			continue;
		}

		for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
				dp[i][j] = MAX_V;

	for(sidx = 1; sidx <=  stable_num; sidx ++)
	{
		for(hidx = 1; hidx <= horse_num; hidx ++)
		{
			if (sidx == 1)
				dp[sidx][hidx] = caculate(1, hidx);
			else
			{
				for (m = 1; m < hidx; m++)
			     		dp[sidx][hidx] = min(dp[sidx][hidx], dp[sidx-1][m] + caculate(m+1, hidx));
			}
		}
	}
	printf("%d\n", dp[stable_num][horse_num]);
	}
	return 0;
}
