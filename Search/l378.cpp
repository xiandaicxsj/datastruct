/*
378. Kth Smallest Element in a Sorted Matrix
Medium

1752

105

Add to List

Share
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
    [ 1, 5, 9],
        [10, 11, 13],
        [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü n2.

Accepted
151, 299
Submissions
290, 706
Seen this question in a real interview before ?

Yes

No
Contributor
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int i = 0;
        int l = matrix[0][0];
        int h = matrix[n - 1][n - 1];
        int m = 0;
        int count = 0;

        while (l <= h) {
            m = (l + h) / 2;
            count = 0;
            for (i = 0; i < n; i++) {

                count += (upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin());

            }
            if (count >= k)
                h = m - 1;
            else
                l = m + 1;
        }
        return l;

    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;
    int i = 0;
    int j = 0;
    int t;
    int k;
    int n;
    cin >> n;

    for (i = 0; i < n; i++) {
        vector<int> tmp;
        for (j = 0; j < n; j++) {
            cin >> t;
            tmp.push_back(t);
        }
        matrix.push_back(tmp);
    }
    cin >> k;
    cout << s.kthSmallest(matrix, k);

}