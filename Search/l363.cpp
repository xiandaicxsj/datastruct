/*
 363. Max Sum of Rectangle No Larger Than K
Hard

621

42

Add to List

Share
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
             and 2 is the max number no larger than k (k = 2).
Note:

The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
Accepted

 */
class Solution {
public:
    int get_sum(vector<int>& arr, int r, int k) {
        int size = arr.size();
        set<int> s;
        s.insert(0);
        int t = 0;
        for (int i = 0; i < size; i++)
        {
            t += arr[i];
            set<int>::iterator sit = s.lower_bound(t - k);
            if (sit != s.end()) {
                if (r == INT_MAX || k - r > k - (t - *sit))
                    r = t - *sit;
            }
            //if (t <= k && (r == INT_MAX || k - r > k - t))
              //  r = t;

            s.insert(t);
        }
        return r;

    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = INT_MAX;
        bool r = false;

        if (m > n) {
            m = n;
            n = m;
            r = true;

        }
        for (int i = 0; i < m; i++) {
            vector<int> sum(n, 0);
            for (int j = i; j < m; j++) {

                for (int k = 0; k < n; k++)
                    sum[k] += r ? matrix[k][j] : matrix[j][k];
                res = get_sum(sum, res, k);
            }
        }
        return res;
    }
};


int main()
{

    int m;
    int n;
    int t;
    int k = 0;
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
    cout << s.maxSumSubmatrix(matrix, k);

}