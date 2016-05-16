#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100001
#define MAX_TIME 30001
int max(int a, int b, int c)
{
	int max = a;
	if (max <b)
		max = b;
	if (max <c)
		max = c;
	return max;
}
/* dp[e] = max(dp[e-1], dp[s-1]+1); */
struct mt
{
	int s;
	int e;
};
struct mt meeting[MAX];
int dp[MAX_TIME];
int cmp(const void *a, const void *b)
{
	return ((struct mt *) a)->e - ((struct mt *)b)->e;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d%d", &(meeting[i].s), &(meeting[i].e));
	qsort((void *)(meeting), n, sizeof(struct mt), cmp);
	memset(dp, 0,n*sizeof(int));
	dp[meeting[0].e] = 1; 
	int b = 0;
	int e = 0;
	int tmp = 0;
	dp[0] = 0;
	for(int i=1; i<n; i++)
	{
		dp[meeting[i].e] = max(dp[meeting[i-1].e], dp[meeting[i].s - 1]+1,dp[meeting[i].e]); /* is 3rd needed ? Not need as meeting[i-1].e can be the same with meeting[i].e*/

		e = meeting[i].e;
		tmp = dp[b];
		while(b < e)
		{
			dp[b] = max(tmp, dp[b], 0);
			b ++;
		}
		//dp[meeting[i].e] = max(dp[meeting[i-1].e],dp[meeting[i].s]+1,0);
	}
	printf("%d\n", dp[meeting[n-1].e]);
	return 0;
}
