#include<stdio.h>
#define MAX 45
/* ok, but not test on the acm.timus.ru */
int dp[MAX][4];/* 0-white  1-red  2-red-blue 3-white-blue*/
int main()
{
	int n;
	int m;
	int i;
	int j;
	int sum;
	scanf( "%d", &n);
	dp[0][0]=1;
	dp[0][1]=1;
	dp[0][2]=0;
	dp[0][3]=0;
	for(i=1; i< n; i++)
	{
		dp[i][0] = dp[i-1][1] + dp[i-1][2];
		dp[i][1] = dp[i-1][0] + dp[i-1][3];
		dp[i][2] = dp[i-1][1];
		dp[i][3] = dp[i-1][0];
	}
	sum +=dp[i-1][0];
	sum +=dp[i-1][1];
	printf("%d\n", sum);
	return 0;
}

