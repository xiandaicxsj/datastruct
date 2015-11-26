#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dp[2][11]={0};
#define MAX(a,b) ( a >b ? a:b)
int main()
{
	int n;
	while( scanf("%d", &n) && n)
	{
		int pos;
		int time;
		int i = 0;
		int max = 0;
		int pre_time = 0;
		memset(dp, 0, 2*11*sizeof(int));
		while(i < n)
		{
			scanf("%d %d", &pos, &time);
			i++;
			if (time == 1 )
			{
				pre_time = 1;
				if ( pos >= 4 && pos <=6)
				{
					dp[1][pos] ++;
					max = MAX(max, dp[1][pos]);
				}
				continue;
			}
			if (time != pre_time)
			{
				int i=0;
				for(; i<11;i++)
					dp[0][i] = MAX(dp[1][i], dp[0][i]);
				pre_time = time;
			}
			int tmp_pos = (pos - 1 >= 0 ? pos - 1: pos); 
			if (dp[1][pos])
				dp[1][pos] ++ ;
			for (tmp_pos ; tmp_pos <= pos +1 && tmp_pos <= 10 ;tmp_pos ++)
				dp[1][pos] = MAX(dp[0][tmp_pos] + 1, dp[1][pos] );
			max = MAX(max, dp[1][pos]);
		}
		printf("%d\n", max);
	}
	return 0;
}
