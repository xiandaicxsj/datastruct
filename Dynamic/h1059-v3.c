/*
 * h1059-v3 use binary to represent num of good and use 0-1 bag.
 * Passed
 */
#include<stdio.h>
#include<string.h>
#define N 500001
#define MAX(a, b) (a > b ? a : b)
int dp[N] ={0};
int v[N] ={0};
int num[6] ={0};
int main()
{
	int test_case=0;
	while (1)
	{
	test_case ++;
	int i=0;
	int j=0;
	int max_value=0;
	int k=0;
	int count=0;
	int end=1;
	memset(dp ,0, sizeof(int)*N);
	memset(v ,0, sizeof(int)*N);
	for (k=0; k<6;k++)
	{
		scanf("%d", &(num[k]));
		max_value += num[k]*(k+1);
	}
	if (max_value ==0)
		break;
	if (max_value %2 !=0)
	{
		printf("Collection #%d:\n", test_case);
		printf("Can't be divided.\n");
		continue;
	}
	max_value = max_value >> 1;
	for (i=0;i<6;i++)
	{
		int t = max_value;
		if ( !num[i] )
			continue;
		for(k=1; k<num[i]; k = k<<1)
		{
			v[count++] = k*(i+1);
			num[i] -= k;
		}
		if (num[i])
			v[count++] = num[i]*(i+1);
	}
	for (i=0; i< count; i++)
	{
		/* 0-1 bag */
		for(j = max_value; j >=v[i] ; j--)
			dp[j] = MAX(dp[j], dp[j-v[i]] + v[i]);
	}
	if (dp[max_value] == max_value)
	{
		printf("Collection #%d:\n", test_case);
		printf("Can be divided.\n");
	}
	else
	{
		printf("Collection #%d:\n", test_case);
		printf("Can't be divided.\n");
	}
	}
	return 0;

}
