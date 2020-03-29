/*
787. Cheapest Flights Within K Stops
Medium

1269

46

Add to List

Share
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
Note:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.
Accepted
69,795
Submissions
187,256

*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //vector<vector<int>> dp(n, vector<int>(K + 1, INT_MAX));
        vector <vector<int>> f(n, vector<int>(n, INT_MAX));

        K++;
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));
        for (auto fl : flights) {
            //cout << fl[0] << " " << fl[1] << " " << fl[2] << endl;
            f[fl[0]][fl[1]] = fl[2];
        }

        int idx = 0;
        dp[0][src] = 0;
        //deque<int> dq;
        //

        //int idx = 1;
        for (int k = 1; k <= K; k++) {
            //idx = 1 - idx;
            for (int i = 0; i < n; i++) {
                dp[1 - idx][i] = min(dp[idx][i], dp[1 - idx][i]);
                if (dp[idx][i] != INT_MAX)
                {
                    for (int j = 0; j < n; j++) {
                        if (f[i][j] != INT_MAX)
                            dp[1 - idx][j] = min(dp[1 - idx][j], dp[idx][i] + f[i][j]);
                    }
                }
            }
            idx = 1 - idx;
        }
        if (dp[idx][dst] == INT_MAX)
            return -1;
        return dp[idx][dst];

    }
};

int main()
{
    int n = 0;
    cin >> n;
    int e = 0;
    int src;
    int dst;
    int k;
    Solution s;
    vector<vector<int>> f;
    cin >> e;
    while (e) {
        int t1;
        int t2;
        int t3;
        vector<int> tmp;
        cin >> t1;
        cin >> t2;
        cin >> t3;
        tmp.push_back(t1);
        tmp.push_back(t2);
        tmp.push_back(t3);
        e--;
        f.push_back(tmp);
    }
    cin >> src;
    cin >> dst;
    cin >> k;
    cout << s.findCheapestPrice(n, f, src, dst, k);



}