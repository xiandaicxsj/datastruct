/*1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
Medium

171

9

Add to List

Share
Given a m x n matrix mat and an integer threshold. Return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.



Example 1:


Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
Example 2:

Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0
Example 3:

Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
Output: 3
Example 4:

Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
Output: 2


Constraints:

1 <= m, n <= 300
m == mat.length
n == mat[i].length
0 <= mat[i][j] <= 10000
0 <= threshold <= 10^5
Accepted
6,734
Submissions
14,878
Seen this question in a real interview before?

Yes

No

*/
class Solution {
public:
    int check_th(vector<vector<int>>& mat, int th, int m) {
        int x = mat.size();
        int y = mat[0].size();
        int sum = 0;

        if (!m)
            return 0;
        for (int i = 0; i <= x - m; i++)
            for (int j = 0; j <= y - m; j++)
            {

                sum = mat[i + m - 1][j + m - 1] + ((i == 0 || j == 0) ? 0 : mat[i - 1][j - 1]) - (j != 0 ? mat[i + m - 1][j - 1] : 0) - (i != 0 ? mat[i - 1][j + m - 1] : 0);

                if (sum <= th)
                    return 1;
            }
        return 0;

    }
    /* O(mnlog(m)*/
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int l = 0;
        int h = 0;
        int m = 0;
        int res = 0;

        int x = mat.size();
        int y;
        if (x)
            y = mat[0].size();
        if (!x && !y)
            return 0;

        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
            {
                if (!i && !j) {
                    continue;
                }
                if (i == 0) {
                    mat[i][j] = mat[i][j] + mat[i][j - 1];
                    continue;
                }
                if (j == 0) {
                    mat[i][j] = mat[i][j] + mat[i - 1][j];
                    continue;
                }
                mat[i][j] = mat[i][j] + mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            }
        l = 0;
        h = min(x, y);

        while (l <= h)
        {
            m = (l + h) / 2;
            if (check_th(mat, threshold, m)) {
                res = max(res, m);
                l = m + 1;
                //res = max(res, l);
            }
            else
                h = m - 1;
        }
        return res;
    }
    /* O(mn) */
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = 0;
        int n = 0;
        int max = 0;
        m = mat.size();
        n = mat[0].size();

        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];

                if (i - max >= 0 && j - max >= 0 &&
                    sum[i + 1][j + 1] - sum[i - max][j + 1] - sum[i + 1][j - max] + sum[i - max][j - max] <= threshold)

                    max++;

            }
        }
        return max;
    }
};

int main() {
    int m;
    int t;
    int k;
    int n;
    Solution s;
    vector<vector<int>> matrix;
    cin >> m;
    cin >> n;

    for (int i = 0; i < m; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++)
        {
            cin >> t;
            tmp.push_back(t);
        }
        matrix.push_back(tmp);
    }

    cin >> k;
    cout << s.maxSideLength(matrix, k);
    return 0;
}