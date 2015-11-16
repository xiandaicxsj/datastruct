#include<stdio.h>
#define N 2000
int dp[N];
int v[N];
int w[N];
int 
void find_max(int n, int w)// weight
{
	int i = 0;
	int j = 0;
	for (; i<n; i++)
	{
		for(j=W; j>=w[i]; j--)
			dp[j] = max(dp[j], d[j-w[i]] +v[i]);
	}
}


