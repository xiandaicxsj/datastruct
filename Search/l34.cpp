/*

74. Search a 2D Matrix
Medium

1309

140

Add to List

Share
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int h = m * n - 1;
        int mid = 0;
        int x;
        int y;
        while (l <= h) {
            mid = l + (h - l) / 2;
            y = mid / n;
            x = mid % n;

            if (matrix[y][x] == target)
                return true;
            if (matrix[y][x] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;

    }
};