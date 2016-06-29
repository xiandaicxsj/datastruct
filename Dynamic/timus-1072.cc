/* 1072.cc */
/* */
#include<stdio.h>
#define MAX_VALUE 65535
#define MAX 500
int dp[MAX] ;

int min(int a, int b)
{
	return a>b? b:a;
}

int main()
{
	int max_size;
	int size_idx = 1;
	int size_2 = size_idx * size_idx;
	int size = 1;
	int tmp_min = MAX_VALUE;
	int tmp_size = 0;
	int i =0;
	while(scanf("%d", &max_size) != EOF)
	{
		size_idx = 1;
		size_2 = size_idx *size_idx;
		size = 1;
		tmp_min = MAX_VALUE;
		tmp_size = 0;
	for (i = 0; i<=max_size; i++)
	{
		dp[i] = MAX_VALUE;
	}
	while(size <= max_size)
	{
		if (size < size_2)
		{
			tmp_size = 1;
			tmp_min = dp[size];
			while(tmp_size < size)
			{
				tmp_min = min(tmp_min, dp[tmp_size] + dp[size - tmp_size]);
				tmp_size ++;
			}
			dp[size] = tmp_min;
		}
		else
		{
			size_idx ++;
			size_2 = size_idx *size_idx;
			dp[size] = 1;
		}
		size ++;
	}
	printf("%d\n", dp[max_size]);
	}
}
