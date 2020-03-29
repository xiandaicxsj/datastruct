/*
174. Dungeon Game
Hard

979

25

Add to List

Share
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.



Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)


Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
Accepted
77,842
Submissions
270,475

AC now:
*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int h;
        int w;
        int i, j;
        h = dungeon.size();
        w = dungeon[0].size();
        int m_v;

        vector<vector<int>> dp(h + 1, vector<int>(w + 1, INT_MAX));
        dp[h][w - 1] = 1;
        dp[h - 1][w] = 1;

        for (i = h - 1; i >= 0; i--) {
            for (j = w - 1; j >= 0; j--) {
                m_v = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = m_v <= 0 ? 1 : m_v;
            }

        }
        return dp[0][0];
    }
};
int main()
{
    int h;
    int w;
    int i = 0;
    int j = 0;
    Solution s;
    vector<vector<int>> res;
    cin >> h;
    cin >> w;
    int t;
    for (i = 0; i < h; i++) {
        vector<int> tmp;
        for (j = 0; j < w; j++) {
            cin >> t;
            tmp.push_back(t);
        }
        res.push_back(tmp);
    }
    cout << s.calculateMinimumHP(res) << endl;

}