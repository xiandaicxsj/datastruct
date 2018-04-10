/*
 * dp[seg][e] means before running seg, have e enough, time is what
   dp[seg][e] = min (dp[seg- 1][e + 5] + Bi, dp[seg - 1][e - 1] + Ai)
   min(dp[seg + 1][k]) 
 */
#define MAX_INF
#define MAX_DP 10002
#define MAX_SEG 100
int h[MAX_SEG];
int l[MAX_SEG];
#define MAX_EN 10
long long dp[MAX_DP][MAX_EN];

long long sum(long long a, long long b)
{
	if ( a == MAX_INF || b == MAX_INF)
		return MAX_INF;
}

int round_up(int k)
{
	if (k > (MAX_EN -1))
		return MAX_EN -1;
	return k;
}

void cal_dp(int nr_seg) 
{
	int i = 1;
	int en = 0;

	dp[1][0] = 0;
	i = 2;
	for(; i <  nr_seg + 1; i++) {
		for(en = 1; en <= MAX_EN; en ++)
			dp[i][en - 1] = min(sum(dp[i-1][round_up(en - 1 +5)], l[i]), sum(dp[i-1][en-1], h[i]));  
	}
}

int main() {
	
	int seg;
	int round;
	int idx = 0;

	while(scanf("%d %d\n", &seg, &round) !=0) {
		for(idx = 1; idx <= seg; idx++)
			scanf("%d", &h[idx]);
		for(idx = 1; idx <= seg; idx++)
			scanf("%d", &l[idx]);
		for(idx = 0; idx <= seg * round; idx++) {
			for(int j = 0; j <= EN_NUM + 1; j++)
				dp[idx][j] = INF;
		}
		
		cal_dp(seg, round);
	}
	
	return 0;
}
