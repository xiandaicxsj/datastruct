/*
 * Free DIY Tour
 * Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
 * Total Submission(s): 10633    Accepted Submission(s): 3417
 *
 *
 * Problem Description
 * Weiwei is a software engineer of ShiningSoft. He has just excellently fulfilled a software project with his fellow workers. His boss is so satisfied with their job that he decide to provide them a free tour around the world. It's a good chance to relax themselves. To most of them, it's the first time to go abroad so they decide to make a collective tour.
 *
 * The tour company shows them a new kind of tour circuit - DIY circuit. Each circuit contains some cities which can be selected by tourists themselves. According to the company's statistic, each city has its own interesting point. For instance, Paris has its interesting point of 90, New York has its interesting point of 70, ect. Not any two cities in the world have straight flight so the tour company provide a map to tell its tourists whether they can got a straight flight between any two cities on the map. In order to fly back, the company has made it impossible to make a circle-flight on the half way, using the cities on the map. That is, they marked each city on the map with one number, a city with higher number has no straight flight to a city with lower number.
 *
 * Note: Weiwei always starts from Hangzhou(in this problem, we assume Hangzhou is always the first city and also the last city, so we mark Hangzhou both 1 and N+1), and its interesting point is always 0.
 *
 * Now as the leader of the team, Weiwei wants to make a tour as interesting as possible. If you were Weiwei, how did you DIY it?
 *  
 *
 *  Input
 *  The input will contain several cases. The first line is an integer T which suggests the number of cases. Then T cases follows.
 *  Each case will begin with an integer N(2 ≤ N ≤ 100) which is the number of cities on the map.
 *  Then N integers follows, representing the interesting point list of the cities.
 *  And then it is an integer M followed by M pairs of integers [Ai, Bi] (1 ≤ i ≤ M). Each pair of [Ai, Bi] indicates that a straight flight is available from City Ai to City Bi.
 *   
 *
 *   Output
 *   For each case, your task is to output the maximal summation of interesting points Weiwei and his fellow workers can get through optimal DIYing and the optimal circuit. The format is as the sample. You may assume that there is only one optimal circuit.
 *
 *   Output a blank line between two cases.
 *    
 *
 *    Sample Input
 *    2
 *    3
 *    0 70 90
 *    4
 *    1 2
 *    1 3
 *    2 4
 *    3 4
 *    3
 *    0 90 70
 *    4
 *    1 2
 *    1 3
 *    2 4
 *    3 4
 *     
 *
 *     Sample Output
 *     CASE 1#
 *     points : 90
 *     circuit : 1->3->1
 *
 *     CASE 2#
 *     points : 90
 *     circuit : 1->2->1
 *      
 *
 *      Author
 *      JGShining（极光炫影）
 *       
 *
 *       Source
 *       杭州电子科技大学第三届程序设计大赛
 *        
 *
 *        Recommend
 *        Ignatius.L
 *         
 *         dp[i] is city from 0 - i-1 to i's max interesting   
 *         dp[i] = max(d[i], d[j] + v[i])
 *        STATUS
*         T
 */
#include<stdio.h>
#include<string.h>
#define MAX 102
int map[MAX][MAX] = {0};
int dp[MAX] = {0};
int patch[MAX] = {0};
int cir[MAX] = {0};
int v[MAX] = {0};

int cal_i(int *v, int nr)
{
	int j = 0;
	int i = 0;
	memset(dp, 0, nr);
	memset(patch, 0, nr);
	memset(cir, 0, nr);
	for (i = 0; i < nr; i++) {
		for (j = 0; j < i;  j++) {
			if (map[j][i]) {
				if (dp[j] + v[i] > dp[i]) {
					dp[i] = dp[j] + v[i];
					patch[i] = j;
				}
			}
		}
	}
	i --;

	int max_c = dp[0];
	int max_i = 0;
	for(j = 1; j < nr; j++) {
		if (dp[j] > max_c) {
			max_c  = dp[j];
			max_i = j;
		}
	}

	int r = 1;
	printf("point : %d\n", dp[max_i]);
	printf("circuit : ");
	if (max_i == 0)
		goto skip;
	cir[r] = max_i;
	r++;
	i = patch[max_i];
	while (i) {
		cir[r] = i;
		i = patch[i];
		r ++;
	}
skip:
	r --;
	printf("1->");
	while(r) {
		printf("%d->", cir[r] + 1);
		r--;
	}
	printf("1\n");
	
	return 0;
}

int main()
{
	int ts;
	scanf("%d", &ts);
	int t = 1;
	while (t <= ts)
	{
		int nr_c = 0;
		int nr_m = 0;
		int i = 0;
		int e,b;

		scanf("%d", &nr_c);
		for (i = 0; i< nr_c; i++)
			scanf("%d", &v[i]);
		scanf("%d", &nr_m);
		for (i = 0; i< nr_m; i++) {
			scanf("%d %d", &b, &e);
			map[b - 1][e - 1] = 1;
		}
		printf("CASE %d#\n", t);
		cal_i(v, nr_c);
		t ++ ;
	}

}
