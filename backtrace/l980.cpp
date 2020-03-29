/*
980. Unique Paths III
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.



Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation:
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.


Note:

1 <= grid.length * grid[0].length <= 20
Accepted
23,283
Submissions
32,203
Seen this question in a real interview before?

Yes

No
Contributor
AC

*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool all_visted(vector<vector<int>>& grid, vector<vector<int>>& visited)
    {
        int h;
        int w;
        int i;
        int j;
        h = grid.size();
        w = grid[0].size();
        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++) {
                if (grid[i][j] == 0) {
                    if (visited[i][j])
                        continue;
                    else
                        return false;
                }
            }
        return true;
    }
    void traverse(vector<vector<int>>& grid, vector<vector<int>>& visited, int h1, int w1, int hl, int wl) {
        int i = 0;
        int th, tw;

        if (grid[h1][w1] == 2) {
            if (all_visted(grid, visited))
                patch++;
            return;
        }

        for (i = 0; i < 4; i++) {
            th = h1;
            tw = w1;
            switch (i) {
            case 0:
                th++;
                break;
            case 1:
                th--;
                break;
            case 2:
                tw++;
                break;
            case 3:
                tw--;
                break;
            }
            //cout << "tmp"<<th << " " << tw << endl;
            if (th <0 || th > hl || tw < 0 || tw > wl)
                continue;
            if (visited[th][tw] || grid[th][tw] == -1)
                continue;
            //cout << th << " " << tw << endl;
            visited[th][tw] = 1;
            traverse(grid, visited, th, tw, hl, wl);
            visited[th][tw] = 0;

        }


    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        long h;
        long w;
        h = grid.size();
        w = grid[0].size();
        patch = 0;
        vector<vector<int>> visited(h + 1, vector <int>(w + 1, 0));
        int h1 = 0;
        int w1 = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == 1) {
                    h1 = i;
                    w1 = j;
                    break;
                }

            }
        visited[h1][w1] = 1;
        //cout << h1 <<" "<< w1 << endl;
        traverse(grid, visited, h1, w1, h - 1, w - 1);
        return  patch;

    }
    int patch;
};
int main()
{
    Solution s;
    int h;
    int w;
    cin >> h;
    cin >> w;
    int t;
    vector<vector<int>> res;
    for (int i = 0; i < h; i++) {
        vector<int> tmp;
        for (int j = 0; j < w; j++) {
            cin >> t;
            tmp.push_back(t);

        }
        res.push_back(tmp);
    }
    cout << s.uniquePathsIII(res) << endl;

}