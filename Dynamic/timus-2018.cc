#include<stdio.h>

#define MAX  50003
#define MOD  1000000007
unsigned long long  dp[MAX];

int main()
{
	int n,a,b;
	unsigned long long maxb;
	unsigned long  long maxa;
	int i = 0;
	int j = 0;
	scanf("%d%d%d", &n, &a, &b);
	i = 1;
	j = 1;

	for(i; i<=a+b; i++)
		dp[i] = 0;

	dp[1] = 1;
	dp[a + 1] = 1;

	for(i = 2; i<=n ; i++)
	{
		maxa = 0;
		maxb = 0;
		for (j = 1; j<=a; j++)
		{
			maxa += dp[j];
		}

		for(j; j<=a+b; j++)
		{
			maxb += dp[j];
		}

		for (j = a + b - 1; j > a; j--)
		{
			dp[j] = dp[j-1] % MOD;
		}
		dp[j] = maxb % MOD;
		j --;

		for(;j > 1; j--)
		{
			dp[j] = dp[j-1] %MOD;
		}
		dp[j] = maxa % MOD;

	}
	maxa = 0;
	for(i=1 ; i<=a+b; i++)
		maxa += dp[i];

	printf("%lld\n", maxa % MOD);
	return 0;
}
