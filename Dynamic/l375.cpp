/*

   375. Guess Number Higher or Lower II
Medium

688

1025

Add to List

Share
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ¡Ý 1, find out how much money you need to have to guarantee a win.

Accepted
55,277
Submissions
139,521
Seen this question in a real interview before?

Yes

No

    */
    /* min/max problem */
class Solution {
public:
    int getMoneyAmount1(int n) {
        int l = 1;
        int  h = n;
        int m = 0;
        long long sum = 0;

        while (true) {

            m = (l + h) / 2;
            //cout << "l:" << l << " " << "h:" << h << "m:"<<m<<endl;
            sum += m;
            if ((m + 1 == h || m == h) && (m - 1 == l || m == l))
                return sum;
            if (m + 1 == h || m == h)
                h = m - 1;
            else
                l = m + 1;
        }
    }

    int recurse(int l, int h, vector<vector<int>>& dp) {
        int i = 0;
        int ret = INT_MAX;
        if (l >= h)
            return 0;
        if (dp[l][h])
            return dp[l][h];

        for (i = l; i <= h; i++) {
            ret = min(ret, max(recurse(l, i - 1, dp), recurse(i + 1, h, dp)) + i);
        }
        dp[l][h] = ret;
        return ret;
    }
    int getMoneyAmount_recurse(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        return recurse(1, n, dp);
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int len = 1;
        int i = 0;
        int j = 0;

        for (len = 1; len < n; len++) {
            for (i = 1; i + len <= n; i++) {
                j = i + len;
                int tmp = INT_MAX;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; k++)
                {
                    int tmp = k + max(k - 1 >= i ? dp[i][k - 1] : 0, k + 1 <= j ? dp[k + 1][j] : 0);
                    dp[i][j] = min(dp[i][j], tmp);
                    //  cout << "i:" << i << " j:" << j << " :" << dp[i][j] << endl;
                }

            }
        }
        return dp[1][n];
    }
};

int main()
{
    int n;
    Solution s;
    cin >> n;
    cout << s.getMoneyAmount(n) << endl;
    return 0;
}