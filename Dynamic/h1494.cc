/*
 * 跑跑卡丁车是时下一款流行的网络休闲游戏，你可以在这虚拟的世界里体验驾驶的乐趣。这款游戏的特别之处是你可以通过漂移来获得一种
 * 加速卡，用这种加速卡可以在有限的时间里提高你的速度。为了使问题简单化，我们假设一个赛道分为L段，并且给你通过每段赛道的普通耗时Ai和用加速卡的耗时Bi。加速卡的获得机制是：普通行驶的情况下，每通过1段赛道,可以获得20%的能量(N2O).能量集满后获得一个加速卡(同时能量清0).加速卡最多可以储存2个,也就是说当你有2个加速卡而能量再次集满,那么能量清零但得不到加速卡。一个加速卡只能维持一段赛道，游戏开始时没有加速卡
 *
 * Input
 * 每组输入数据有3行，第一行有2个整数L(0<L<100),N(0<N<100)分别表示一圈赛道分为L段和有N圈赛道，接下来两行分别有L个整数Ai和Bi
 * (Ai > Bi).
 *  
 *
 *  Output
 *  对于每组输入数据，输出一个整数表示最少的用时.
 *   
 *
 *   Sample Input
 *
 *   18 1
 *   9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
 *   8 8 8 8 8 8 8 8 8 8 8 8 8 8 1 1 8 8
 *
 *    
 *
 *    Sample Output
 *
 *    145
 *
 *    Hint
 *    Hint
 *     
 *     对于sample这组数据，你可以先在普通情况下行驶前14段，这时你有2个加速卡以及80%的能量(N2O).在第15和16段用掉2个加速卡，通过第
 *     17段赛道后又可以得到一个加速卡，在第18段赛道使用.
 */

/* 
 * dp[k][energy]; k represent the seg number energy represent the 0-10 energy status
 *
 * dp[k + 1][i] = min(dp[k][i - 1] + h[k + 1], dp[k][i + 4] + l[k + 1]);
 * 
 * Thinking:
 *
 * We should know which variable is the "state" variable. For example, for k phrase, what k + 1 choose should not depend on k. 
 */

#include<stdio.h>
#define MAX 10001
#define EN_NUM 10
#define MAX_DATA 0xffffffff
typedef unsigned long long var_t;
var_t dp[MAX][EN_NUM+2];
int h[MAX];
int l[MAX];

#ifdef TEST
void dp_print(int idx)
{
	int en = 0;
	for(en = 0; en <= EN_NUM; en ++) {
		printf("0x%llx  ", dp[idx][en]);
	}
	printf("\n");
}
#else
void dp_print(int idx)
{

}
#endif

#define cal_idx(a, b) (a)
#define min(a, b) ((a) > (b) ? (b) : (a))
int cal_dp(int seg, int round)
{
	int idx = 1;
	int en = 0;
	var_t mina;

	dp[1][0] = h[1];

	dp_print(1);
	for(idx = 2; idx <= seg * round; idx++) {
		for(en = 0; en <= EN_NUM; en ++) {
			if (!en) {

				var_t k = dp[idx - 1][(EN_NUM/2) - 1];
				k = ((k == MAX_DATA) ? MAX_DATA : (k + l[cal_idx(idx, seg)]));
				dp[idx][en] = k;
			} else { 
				int idxx = (en + (EN_NUM/2) - 1) > EN_NUM ? (EN_NUM + 1) : (en + (EN_NUM/2) - 1);
				var_t a = (dp[idx - 1][en -1] == MAX_DATA ? MAX_DATA: (dp[idx - 1][en - 1] + h[cal_idx(idx, seg)]));
				var_t b = dp[idx - 1][idxx];
				
				if (idxx == EN_NUM + 1)
					b = MAX_DATA;
				else
					b = ((b >= MAX_DATA) ? MAX_DATA : (b + l[cal_idx(idx, seg)]));

				dp[idx][en] = min(a, b);

			}
		}
		dp_print(idx);

	}
	
	mina = dp[idx - 1][0]; 
	for (en = 1; en <= EN_NUM; en++) {
		mina = min(mina, dp[idx -1][en]);
	}

	printf("%lld\n", mina);
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
				dp[idx][j] = MAX_DATA;
		}

		cal_dp(seg, round);
	}
	
	return 0;
}
























