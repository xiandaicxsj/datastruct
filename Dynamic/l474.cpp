/*
  474. Ones and Zeroes
Medium

800

192

Add to List

Share
In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:

The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.


Example 1:

Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are ¡°10,¡±0001¡±,¡±1¡±,¡±0¡±


Example 2:

Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
    */
class Solution {
public:
    int get_1(string str) {

        int c = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1')
                c++;
        }
        return c;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector <vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int res = 0;
        //int k = 0;
        for (auto str : strs)
        {
            int n1 = get_1(str);
            int m1 = str.size() - n1;

            for (int i = m - m1; i >= 0; i--) {
                for (int j = n - n1; j >= 0; j--) {
                    if (i == 0 && j == 0 && i + m1 <= m && j + n1 <= n) {
                        dp[i + m1][j + n1] = max(dp[i + m1][j + n1], 1);
                        res = max(res, dp[i + m1][j + n1]);
                        continue;
                    }


                    if (dp[i][j] != 0 && i + m1 <= m && j + n1 <= n) {
                        dp[i + m1][j + n1] = max(dp[i][j] + 1, dp[i + m1][j + n1]);
                        res = max(res, dp[i + m1][j + n1]);
                    }

                }
            }
#ifdef DEBUG
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    cout << "dp[" << i << "]" << "[" << j << "]" << dp[i][j] << endl;
                }
            }
            cout << "==========================" << endl;
#endif
        }
#ifdef DEBUG
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << "dp[" << i << "]" << "[" << j << "]" << dp[i][j] << endl;
            }
        }
#endif

        return res;
    }
    int findMaxForm2(vector<string>& strs, int m, int n) {
        vector <vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

        int res = 0;
        int k = 0;
        for (auto str : strs)
        {
            int n1 = get_1(str);
            int m1 = str.size() - n1;

            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i == 0 && j == 0 && i + m1 <= m && j + n1 <= n) {
                        dp[i + m1][j + n1][1 - k] = max(dp[i + m1][j + n1][k], 1);
                        res = max(res, dp[i + m1][j + n1][1 - k]);
                        continue;
                    }

                    if (dp[i][j][k] != 0) {
                        dp[i][j][1 - k] = max(dp[i][j][1 - k], dp[i][j][k]);
                    }
                    if (dp[i][j][k] != 0 && i + m1 <= m && j + n1 <= n) {
                        dp[i + m1][j + n1][1 - k] = max(dp[i][j][k] + 1, dp[i + m1][j + n1][k]);
                        res = max(res, dp[i + m1][j + n1][1 - k]);
                    }

                }
            }
            k = 1 - k;
            //#define DEBUG
#ifdef DEBUG
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    cout << "dp[" << i << "]" << "[" << j << "]" << dp[i][j][k] << endl;
                }
            }
            cout << "==========================" << endl;
#endif
        }
#ifdef DEBUG
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << "dp[" << i << "]" << "[" << j << "]" << dp[i][j][k] << endl;
            }
        }
#endif

        return res;
    }
};

int main()
{
    vector<string> strs;
    Solution s;
    int m;
    int n;

    int c;
    cin >> c;
    while (c) {
        string tmp;
        cin >> tmp;
        strs.push_back(tmp);
        c--;
    }
    cin >> m;
    cin >> n;

    cout << s.findMaxForm(strs, m, n);

}