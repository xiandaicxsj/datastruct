/* the debult alum */
/* 
 * can reduce memory space
 *dp[i][a] = max(dp[i-1][a-1] + 1, dp[i-1][a])
 */
/*
#define MAX 200 
long long dp[MAX][MAX];
#include<stdio.h> 
int main()
{
	int n,a,b;
	int _a;
	int i = 0;
	int t = 0;
	int ret = 0;
	while(scanf("%d %d %d", &n, &a, &b)!=EOF)
	{
		dp[1][1] = 1;
		for(i = 1; i<=n; i++)
			dp[i][0] = 1;

		for(i = 2; i <= n; i++)
			for(t = 1; t <= i; t++)
			{
				dp[i][t] = dp[i- 1][t - 1] + dp[i-1][t];
			}

		ret = 0;
		for(i = a; i <= n; i++)
			if ( n - i >= b )
			{
				ret += dp[n][i];
				printf("ret %d %llx\n", i, dp[n][i]);
			}
		printf("ret is %d\n", ret);
	}
	return 0;
}
*/
/* misunderstand the meaning of the question */
/* two consutive mix */




