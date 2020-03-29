/*
  221. Maximal Square
Medium

2209

55

Add to List

Share
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
Accepted
190,880
Submissions
538,133

   */


   /* AC but need of think of DP case */

class Solution {
public:
    bool valid(vector<vector<int>>& sums, int m) {
        for (int i = m - 1; i < sums.size(); i++)
        {
            for (int j = m - 1; j < sums[0].size(); j++) {
                if (sums[i][j] - (j >= m ? sums[i][j - m] : 0) - (i >= m ? sums[i - m][j] : 0) + (i >= m && j >= m ? sums[i - m][j - m] : 0) == m * m)
                    return true;
            }
        }
        return false;
    }
    int maximalSquare_bineary_search(vector<vector<char>>& matrix) {

        if (matrix.size() == 0)
            return 0;
        vector<vector<int>> sums(matrix.size(), vector<int>(matrix[0].size(), 0));

        int n = min(matrix.size(), matrix[0].size());
        sums[0][0] = matrix[0][0] - '0';
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++) {
                sums[i][j] = (j - 1 >= 0 ? sums[i][j - 1] : 0) + (i - 1 >= 0 ? sums[i - 1][j] : 0) - (i - 1 >= 0 && j - 1 >= 0 ? sums[i - 1][j - 1] : 0) + (matrix[i][j] - '0');
            }
        }
        int l = 1;
        int h = n;
        int m = 0;
        int ret = 0;
        while (l <= h) {
            m = (h + l) / 2;
            if (valid(sums, m)) {
                ret = max(m, ret);
                l = m + 1;
                //ret = max(l, ret);
            }
            else
                h = m - 1;
        }

        return ret * ret;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        vector<vector<int>> dp(2, vector<int>(matrix[0].size(), 0));
        //vector<vector<int>> dp_h(matrix.size(), vector<int>(matrix[0].size(), 0));

        int i = 0;
        int j = 0;
        int idx = 0;
        int s = 0;
        for (i = 0; i < matrix.size(); i++)
        {
            idx = 1 - idx;
            for (j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] - '0' == 1) {
                    dp[idx][j] = min(j > 0 ? dp[idx][j - 1] : 0, min(dp[1 - idx][j], j > 0 ? dp[1 - idx][j - 1] : 0)) + 1;
                    s = max(s, dp[idx][j]);
                    //cout << "dp[" << i << "]" << "[" << j << "]" << dp[idx][j] << endl;
                }
                else dp[idx][j] = 0;
                //out << "dp[" << i << "]" << "[" << j << "]" << dp[idx][j] << endl;
            }
        }
        //out << s << endl;
        return s * s;

    }
};

int main()
{
    int n;
    int m;
    vector<vector<char>> ma;

    int i = 0;
    int j = 0;
    char t;
    Solution s;
    cin >> m;
    cin >> n;
    for (i; i < m; i++)
    {
        vector<char> tmp;
        for (j = 0; j < n; j++) {
            cin >> t;
            tmp.push_back(t);
        }
        ma.push_back(tmp);
    }
    cout << s.maximalSquare(ma);



} /*
   221. Maximal Square
Medium

2209

55

Add to List

Share
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
Accepted
190,880
Submissions
538,133

   */


   /* AC but need of think of DP case */

class Solution {
public:
    bool valid(vector<vector<int>>& sums, int m) {
        for (int i = m - 1; i < sums.size(); i++)
        {
            for (int j = m - 1; j < sums[0].size(); j++) {
                if (sums[i][j] - (j >= m ? sums[i][j - m] : 0) - (i >= m ? sums[i - m][j] : 0) + (i >= m && j >= m ? sums[i - m][j - m] : 0) == m * m)
                    return true;
            }
        }
        return false;
    }
    int maximalSquare_bineary_search(vector<vector<char>>& matrix) {

        if (matrix.size() == 0)
            return 0;
        vector<vector<int>> sums(matrix.size(), vector<int>(matrix[0].size(), 0));

        int n = min(matrix.size(), matrix[0].size());
        sums[0][0] = matrix[0][0] - '0';
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++) {
                sums[i][j] = (j - 1 >= 0 ? sums[i][j - 1] : 0) + (i - 1 >= 0 ? sums[i - 1][j] : 0) - (i - 1 >= 0 && j - 1 >= 0 ? sums[i - 1][j - 1] : 0) + (matrix[i][j] - '0');
            }
        }
        int l = 1;
        int h = n;
        int m = 0;
        int ret = 0;
        while (l <= h) {
            m = (h + l) / 2;
            if (valid(sums, m)) {
                ret = max(m, ret);
                l = m + 1;
                //ret = max(l, ret);
            }
            else
                h = m - 1;
        }

        return ret * ret;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        vector<vector<int>> dp(2, vector<int>(matrix[0].size(), 0));
        //vector<vector<int>> dp_h(matrix.size(), vector<int>(matrix[0].size(), 0));

        int i = 0;
        int j = 0;
        int idx = 0;
        int s = 0;
        for (i = 0; i < matrix.size(); i++)
        {
            idx = 1 - idx;
            for (j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] - '0' == 1) {
                    dp[idx][j] = min(j > 0 ? dp[idx][j - 1] : 0, min(dp[1 - idx][j], j > 0 ? dp[1 - idx][j - 1] : 0)) + 1;
                    s = max(s, dp[idx][j]);
                    //cout << "dp[" << i << "]" << "[" << j << "]" << dp[idx][j] << endl;
                }
                else dp[idx][j] = 0;
                //out << "dp[" << i << "]" << "[" << j << "]" << dp[idx][j] << endl;
            }
        }
        //out << s << endl;
        return s * s;

    }
};

int main()
{
    int n;
    int m;
    vector<vector<char>> ma;

    int i = 0;
    int j = 0;
    char t;
    Solution s;
    cin >> m;
    cin >> n;
    for (i; i < m; i++)
    {
        vector<char> tmp;
        for (j = 0; j < n; j++) {
            cin >> t;
            tmp.push_back(t);
        }
        ma.push_back(tmp);
    }
    cout << s.maximalSquare(ma);



}