/*
 *  mid= (i+j)/2; is the best value;
 *  dp[i][j] = dp[i-1][m] + len[m+1][j]  i-1<m<j
 */
#include<stdio.h>
#define MAX 100000
#define ABS(value) (value > 0 ? value : -value)
#define MINA(a,b) (a > b ? b: a)
int dp[30][200] = {0};// dp[m][n] 
int len[200][200] = {0};
int pos[200];
int main()
{
	int n;
	int k;
	int i;
	int j;
	int mid;
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
			for(j= i+1; j<n; j++)
			{
				mid = (i+j) >>1;
				for (k= i ; k<=j ;j++)
					len[i][j] += ABS(pos[k] - pos[mid]);
			}
		}	
		for (i=0; i<n; i++)
			dp[0][i] = len[0][i];
		for (i=1; i<k; i++)
		{
			for(j=i; j<n; j++)
			{
				dp[i][j] = INF;
				for (m=i; m<j; m++)
					dp[i][j] = min(dp[i][j], dp[i-1][m] + len[m+1][j]);
			}
		}
		printf("%d", min);
	}
	return 0;
}
