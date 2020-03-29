#ifdef DEBUG_542
/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.



Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]


Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
Accepted
69,665
Submissions
181,350
*/
class Solution {
public:
    void traverse(int x, int y, vector<vector<int>>& ma, vector<vector<int>>& v, vector<vector<int>>& d, vector<vector<int>>& dire, int s, int m, int n, int f) {

        //v[x][y] = 1;
       // s++;
        if (!ma[x][y] && !f) {
            return;
        }

        f = 0;
#ifdef DEBUG
        if (x == 1 && y == 3)
            cout << "#";
#endif
        if (s > d[x][y] && s)
            return;
#ifdef DEBUG
        cout << x << " " << y << " " << s << endl;
#endif
        d[x][y] = s;


        v[x][y] ++;

        for (int i = 0; i < 4; i++) {
            int t_x = x + dire[i][0];
            int t_y = y + dire[i][1];

            if (t_x < m && t_x >= 0 && t_y < n && t_y >= 0 && !v[t_x][t_y]) {
                traverse(t_x, t_y, ma, v, d, dire, s + 1, m, n, f);
            }
        }

        v[x][y] --;
    }

    vector<vector<int>> updateMatrix2(vector<vector<int>>& matrix) {
        vector<vector<int>> visit(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> dis(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        vector<vector<int>> dire = { {0, -1},{0, 1},{1, 0}, {-1, 0} };
        //vector<vector<int>> dire = { {1, 0},{-1, 0},{0, 1}, {0, -1} };
        int x;
        int y;
        for (x = 0; x < matrix.size(); x++) {
            for (y = 0; y < matrix[0].size(); y++) {
                if (!matrix[x][y]) {
                    visit[x][y]++;
#ifdef DEBUG
                    cout << "------------------" << endl;
                    cout << "x:" << x << " " << "y:" << y << endl;
                    if (x == 3 && y == 3)
                        cout << x;
#endif
                    traverse(x, y, matrix, visit, dis, dire, 0, matrix.size(), matrix[0].size(), 1);

                }
                // goto begin;
            }
        }
        // begin:
         //dis[x][y] = 0;
        // traverse(x, y, matrix, visit, dis, dire, 0, matrix.size(), matrix[0].size());
        return dis;

    }
    /* Dynamic program form top-left to down-right can make sure */
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

        int i = 0;
        int j = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    int left = j >= 1 ? matrix[i][j - 1] : INT_MAX;
                    int up = i >= 1 ? matrix[i - 1][j] : INT_MAX;
                    up = min(left, up);
                    if (up != INT_MAX)
                        up++;
                    matrix[i][j] = up;
                }
            }
        }
        for (i = m - 1; i >= 0; i--) {
            for (j = n - 1; j >= 0; j--) {
                if (matrix[i][j]) {
                    int right = j + 1 <= n - 1 ? matrix[i][j + 1] : INT_MAX;
                    int down = i + 1 <= m - 1 ? matrix[i + 1][j] : INT_MAX;
                    down = min(right, down) + 1;
                    matrix[i][j] = min(down, matrix[i][j]);
                }
            }
        }
        return matrix;

    }
};

int main()
{
    vector<vector<int>> matrix;
    int m;
    int n;
    cin >> m;
    cin >> n;
    Solution s;
    for (int i = 0; i < m; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            tmp.push_back(t);
        }
        matrix.push_back(tmp);
    }
    auto res = s.updateMatrix(matrix);
    for (auto row : res) {
        for (auto v : row)
            cout << v << " ";
        cout << endl;

    }

}
#endif
#ifdef DEBUG_472
/*
472. Concatenated Words
Hard

500

87

Add to List

Share
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
Accepted
43,382
Submissions
106,972

*/

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {


    }
};
#endif

