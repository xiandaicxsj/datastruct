/*
 * Squares and rectangles fascinated the famous Dutch painter Piet Mondriaan. One night, after producing the drawings in his 'toilet series' (where he had to use his toilet paper to draw on, for all of his paper was filled with squares and rectangles), he dreamt of filling a large rectangle with small rectangles of width 2 and height 1 in varying ways.




Expert as he was in this material, he saw at a glance that he'll need a computer to calculate the number of ways to fill the large rectangle whose dimensions were integer values, as well. Help him, so that his dream won't turn into a nightmare!





Input
The input file contains several test cases. Each test case is made up of two integer numbers: the height h and the width w of the large rectangle. Input is terminated by h=w=0. Otherwise, 1<=h,w<=11.


Output
For each test case, output the number of different ways the given rectangle can be filled with small rectangles of size 2 times 1. Assume the given large rectangle is oriented, i.e. count symmetrical tilings multiple times.


Sample Input
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0


Sample Output
1
0
1
2
3
5
144
51205

 * 
 * dp[k][energy]; k represent the seg number energy represent the 0-10 energy status
 *
 * dp[k + 1][i] = min(dp[k][i - 1] + h[k + 1], dp[k][i + 4] + l[k + 1]);

   dp[k][en] at the end of each seg
   if en == 0
	no;
   dp[k] 
 * 
 * Thinking:
 *
 * We should know which variable is the "state" variable. For example, for k phrase, what k + 1 choose should not depend on k. 
 */
#include<iostream>
using namespace std;

int dp[2][10000];
int idx_is_set(int m, int i)
{
	return m & (1 << i);
}

int cal_method(int w, int h)
{
	int m = w * h;
	int i = 0;
	int j = 0;
	int p = 0;

	for (i = 0; i< h; i++) {	
		for(j = 0; j< w; j++) {
			p ^= 1;
			memset(&dp[p], 0, (1 << m));

			for(s = 0; s < (1 << m); s++) {
				/* no */
				if (idx_is_set(s, m - 1))
					dp[p][s << 1] += dp[p ^ 1][s];
				/* up */
				if (!i && !idx_is_set(s, m - 1))
					dp[p][(s << 1) | 1] += dp[p ^ 1][s];
				/* left */
				if (!j && idx_is_set(s, m - 1) && !idx_is_set(s, 0))
					dp[p][(s << 1) | 3] += dp[p ^ 1][s];
			}
		}
	}
	return dp[p][1 << m -1];
}

int main() {
	
	int h, w;
	while(scanf("%d %d\n", &h, &w) !=0) {
		if (!h || !w)
			break;

		cout << cal_method(h, w);
	}
	
	return 0;
}
























