#include<stdio.h>
#define A_MAX 301 
#define B_MAX 301
#define N_MAX 50001
long long a_dp[2][A_MAX] = {0};
long long b_dp[2][A_MAX] = {0};

int main()
{
	int a,b,n;
	scanf("%d %d %d", &n, &a, &b);
	int idx = 1;	
	int i=0;
	int j=0;
	long  long sum = 0;
	a_dp[0][1] = 1;
	b_dp[0][1] = 1;
	while(idx < n)
	{
		for(i =1 ; i <= a; i++)
		{
			if (i == 1)
			{
				for(j=1; j<=b; j++)
					a_dp[1][i] += b_dp[0][j];
			}
			else
			a_dp[1][i] += a_dp[0][i-1];
		}

		for(i =1 ; i <= b; i++)
		{
			if (i == 1)
			{
				for(j=1; j<= a; j++)
					b_dp[1][i] += a_dp[0][j];
			}
			else
			b_dp[1][i] += b_dp[0][i-1];
		}

		for (i= 1; i<=a; i++)
		{
			a_dp[0][i] = a_dp[1][i];
			a_dp[1][i] = 0;
		}

		for (i= 1; i<=b; i++)
		{
			b_dp[0][i] = b_dp[1][i];
			b_dp[1][i] = 0;
		}
		idx ++;
	}
		for (i= 1; i<=a; i++)
		{
			sum += a_dp[0][i];
		}

		for (i= 1; i<=b; i++)
		{
			sum += b_dp[0][i];
		}
	printf("%lld\n", sum);
}
