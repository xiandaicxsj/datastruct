//dp[i][j] = max( dp[i-1][j] +100 , dp[i][j-1]+100, if (cross[i-1][j-1] ) dp[i-1][j-1] + 141)
#include<stdio.h>
#define MAX 100
int map[MAX][MAX];
int dp[MAX][MAX];
int max(int a, int b ,int c)
{
		int m1 = a;
		if (b <m1)
			m1 = b;
		if (c <m1)
			m1 = c;
		return m1;
}
int main() {
	int m;
	int n;
	int i = 0;
	int j = 0;
	int k;
	int x,y;
	scanf("%d%d", &n, &m);
	scanf("%d", &k);
	for (i=0; i<k; i++)
	{
		scanf("%d%d", &x,&y);
		map[y-1][x-1] = 1;
	}
	for(i=0; i<=n; i++)
	{
		dp[0][i] = i*100;
	}
	for(i=0; i<=m; i++)
	{
		dp[i][0] = i*100;
	}
	for(i=1; i<=m; i++)
		for(j=1; j<=n; j++)
		{
				dp[i][j] = max(dp[i-1][j] + 100, dp[i][j-1] +100, map[i-1][j-1] ? dp[i-1][j-1] +144:10000);
		}
	printf("%d\n",dp[m][n]);
	return 0;
}
