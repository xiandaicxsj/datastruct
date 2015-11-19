#include<stdio.h>
#define N 2000
int dp[N];
int value[N];
int w[7];
int main()
{


		int i = 0;
		int j = 0;
		int sum = 0;
		int count;
		for (i; i<=6; i++)
		{
				count = 0;
				sum += w[i]*i;
				for (j = 1; j<w[i] ;j =j<< 1)
				{
						value[count++] = j * i;
						w[i] -= j;
				}
				if (w[i])
					value[count++] = w[i] *i;
		}
		for (i=0; i<count ;i++)
		{
				for(j=sum/2; j >= value[i]; j--)
						dp[j] = max(dp[j], dp[j-value[i]]+value[i]);
		}
}
