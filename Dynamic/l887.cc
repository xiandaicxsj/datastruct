/*
 * 887. Super Egg Drop
 * Hard
 *
 * 502
 *
 * 50
 *
 * Favorite
 *
 * Share
 * You are given K eggs, and you have access to a building with N floors from 1 to N. 
 *
 * Each egg is identical in function, and if an egg breaks, you cannot drop it again.
 *
 * You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.
 *
 * Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 
 *
 * Your goal is to know with certainty what the value of F is.
 *
 * What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?
 *
 *  
 *
 *  Example 1:
 *
 *  Input: K = 1, N = 2
 *  Output: 2
 *  Explanation: 
 *  Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
 *  Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
 *  If it didn't break, then we know with certainty F = 2.
 *  Hence, we needed 2 moves in the worst case to know what F is with certainty.
 *  Example 2:
 *
 *  Input: K = 2, N = 6
 *  Output: 3
 *  Example 3:
 *
 *  Input: K = 3, N = 14
 *  Output: 4
 *   
 *
 *   Note:
 *
 *   1 <= K <= 100
 *   1 <= N <= 10000
 *   Accepted
 *   10,626
 *   Submissions
 *   41,239
 *   Seen this question in a real interview before?
 *
 *   Yes
 *
 *   No
 *   Contributor
 *   Han_V
 *
 *   Problems
 *
 *   Pick One
 *
 *   Prev
 *   114/167
 *
 *   Next
 *
 *
 *
*
*
*
*
*   int superEggDrop(int K, int N){
	*
		*   }
		*   1
		*   ​
		*   2
		*   ​
		*   3
		*   int superEggDrop(int K, int N){
			*   4
				*   ​
				*   5
				*   }
				*   6
				*   ​
				*   7
				*   ​
				*   Console 
				*   Contribute
				*
				*   Run Code
				*
				*   Submit
				*
*/

/*
 * try k/2 if k/2 not broken, then we need to cal dp[k/2][n], 
 * if k/2 is broken, then we know k/2 is not F, check k - k/2, 
 * 	if k - k/2 is 1, then return 0 ?  else
 * 	if k - k/2 is not 1, then -1 ? seems wrong ?
 * dp[k][n] = max(dp[k/2][n - 1], dp[k - k/2][n]] for (k - k/2) is not F); 
 * dp[2][1] = max(dp[1][1], dp[1][0])
 *
 * dp[2][1]  
 * 1. rount
 * 	dp[2][1] = max(dp[1][2], dp[1][1]) + 1
 *
 * 2. dp[1][2] = max(dp[0][2], dp[1][1]) + 1
 * 	dp[0][2] = 0;
 * 	dp[1][1] = 1;
 *
 * dp[1][2] = 2;
 * dp[2][1] = 3;
 *
 * wrong
 *
 * dp[6][2]
 * 	dp[6][2] = max(dp[3][2], dp[3][1]) + 1
 *
 * dp[3][2] = max(dp[1][2], dp[2][1]) + 1 
 *
 * dp[1][2]= 1
 *
 * dp[2][1] = max(dp[1][0], dp[1][1]) + 1 here dp[1][1] should be 0
 * dp[1][1] = 1;
 * maybe we should take zero stair into consideration
 *
 * dp[3][2] = max(dp[1][2], dp[2][1]) + 1 
 *
 * dp[4][2] = max(dp[2][2], dp[2][1]) + 1
 * dp[2][2] = max(dp[1][2], dp[1][1]) + 1
 * dp[2][1] = max(dp[1][0], dp[1][1]) + 1
 *
 * dp[2][1] = 2
 * dp[1][2] = 1
 * dp[3][2] = dp[4][2] = 3
 *
 * dp[6][2] = dp[7][2]
 * dp[7][2] = max(dp[3][2], dp[4][1]) + 1
 * dp[3][2] = max(dp[1][2], dp[2][1]) + 1;
 * dp[2][1] = max(dp[1][0], dp[1][1]) + 1;
 * dp[1][1] = 0 
 *
 * dp[7][2] = 3
 *
 * dp[14][3] = dp[15][3]
 * 1. dp[15][3] = max(dp[7][2], dp[8][3]) + 1
 *
 * 2 dp[7][2] = max(dp[3][1], dp[4][2]) + 1
 * d[3][1] = 2;
 * dp[4][2] = max(dp[2][1], dp[2][2]) + 1;
 * dp[2][1] = 1;
 * dp[4][2] = 2;
 * dp[7][2] = 3
 *
 * 3 dp[8][3] = max(dp[4][2], dp[4][3]) + 1
 * dp[4][2] = 2
 * dp[4][3] = max(dp[2][2], dp[2, 3]) + 1
 * dp[2][2] = 1
 * dp[2][3] = 1
 * dp[4][3 = 2;
 * dp[8][3] = 3;
 * dp[15][3] = 4; 
 *
 * dp[2][1] = dp[3][1]
 *
 * dp[3][1] = max(dp[0][0], dp[2][1]) + 1;
 * 	
*
* dp[3][1] = dp[4][1]
* dp[4][1] = max(dp[2][0], dp[2][1]) + 1
* dp[2][1] = max(dp[1][0], dp[1][1]) + 1
* dp[1][1] = ?
 *
 */
#include<stdio.h>
int dp[10001][101];
#define max(a, b) ((a) > (b) ? (a) : (b))
/* K eggs N stairs */
int get_dp(int n, int k) {
	printf("check dp[%d][%d] \n", n, k);
	if (dp[n][k] >= 0)
		return dp[n][k];
	if (k <= 0)
		return 0;
	if (n <= 0)
		return 0;
	dp[n][k] = max(get_dp(n / 2 - 1, k - 1), get_dp(n - n/2, k)) + 1;
	printf("dp[%d][%d]:%d \n", n, k, dp[n][k]);
	return dp[n][k];
}

int superEggDrop(int K, int N){
	int i = 0;
	int j = 0;

	for (i = 0; i <= N + 1; i++)
		for (j = 0; j <=K + 1; j++)
			dp[i][j] = -1; 

	for (i = 0; i <= N + 1; i++)
		dp[i][0] = 0; 

	for (i= 1; i <= K + 1; i++)
		dp[1][i] = 1;

	return get_dp(N + 1, K);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", superEggDrop(k, n));
	return 0;
}
