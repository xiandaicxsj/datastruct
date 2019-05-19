/*
 * 887. Super Egg Drop
Hard

340

36

Favorite

Share
You are given K eggs, and you have access to a building with N floors from 1 to N.

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N).

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?



Example 1:

Input: K = 1, N = 2
Output: 2
Explanation:
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
Example 2:

Input: K = 2, N = 6
Output: 3
Example 3:

Input: K = 3, N = 14
Output: 4


Note:

1 <= K <= 100
1 <= N <= 10000
dp[N][K] = MAX(dp[(n-1)/2][K], dp[(n-1)/2 + (n-1) % 2][K-1]) + 1; (K > 1) 
dp[N][K] 代表的 
TEST PASS
NOT AC
*/
#include<iostream>
using namespace std;
int dp[10000][100] = {0};
#define max(a, b)  ((a) > (b) ? (a):(b))
class Solution {
public:
    int superEggDrop(int K, int N) {

	    int ll;
	    int rl;
	    int j = 0;
	    int i = 0;
	    int max_t = 0;
	    for (j = 1; j <= K; j++)
		    dp[1][j] = 1;

	    for (i = 2; i <= N; i++) {
#if 0
		    cout<<"begin ";
		    cout<<i<<endl;
#endif
		    for (j = 1; j <= K; j++) {
			  max_t = (max(dp[(i + 1)/2 - 1][j - 1], dp[i - (i+1)/2][j]));
			   dp[i][j] = max_t == 0 ? 0 : max_t + 1;
#if 0

			    if (dp[i/2][j]  == 0 ||
				    dp[i/2 + i%2][j -1] ==0)
				    dp[i][j] = 0;
			    else
				   dp[i][j] = (max(dp[i/2][j], dp[i/2 + i%2][j -1])) ==0 ? 0: max(dp[i/2][j], dp[i/2 + i%2][j -1]) + 1;
#endif
			}

	   }	

#if 0
	   for (i = 1; i <= N; i++) {
		    for (j = 1; j <= K; j++) {
		cout <<i <<" "<<j<<':'<<dp[i][j]<<endl;
	    }
	  }
#endif
	    return dp[N][K];
    }
};

int main()
{
	int n, k;
	cin >> k;
	cin >> n;
	Solution S;
	cout << S.superEggDrop(k, n);

	return 0;
}

