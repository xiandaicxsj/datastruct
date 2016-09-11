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

	i = 1;
	printf(" %d --------\n", i);
	for(j = 1; j <= a+b; j++)
		printf("j %d: %d\n", j, dp[j]);
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

		for (j = a + b; j > a + 1; j--)
		{
			dp[j] = dp[j-1] % MOD;
		}
		printf("j: %d, %d\n", j, maxb);
		dp[j] = maxb % MOD;
		j --;

		for(;j > 1; j--)
		{
			dp[j] = dp[j-1] %MOD;
		}
		dp[j] = maxa % MOD;

		printf("%d--------\n", i);
		printf("maxa %d maxb %d\n", maxa, maxb);
		for(j = 1; j <= a+b; j++)
			printf("j %d: %d\n", j, dp[j]);

	}
	maxa = 0;
	for(i=1 ; i<=a+b; i++)
		maxa += dp[i];

	printf("%lld\n", maxa % MOD);
	return 0;
}
