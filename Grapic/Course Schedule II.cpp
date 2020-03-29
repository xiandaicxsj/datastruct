/*
 2. Course Schedule II
Medium

2962

149

Add to List

Share
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.


Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
Accepted
332,059
Submissions
810,777

  */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> g(numCourses, vector<int>());

        vector<int> in_dgree(numCourses, 0);
        deque<int> dq;
        int t;
        if (!prerequisites.size()) {
            for (int i = 0; i < numCourses; i++)
                res.push_back(i);
            return res;
        }
        for (auto v : prerequisites) {
            in_dgree[v[0]]++;
            g[v[1]].push_back(v[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!in_dgree[i])
                dq.push_back(i);
        }
        int n = numCourses;
        while (!dq.empty()) {
            t = dq.front();
            dq.pop_front();
            res.push_back(t);
            n--;
            for (auto n : g[t]) {
                in_dgree[n]--;
                if (!in_dgree[n])
                    dq.push_back(n);
            }
        }
        if (n != 0)
            res.clear();
        return res;

    }



};

int main()
{
    int nc;
    int t;
    int t1;
    int cc;
    cin >> nc;
    cin >> cc;
    Solution s;
    vector<vector<int>> pre;

    while (cc) {
        vector<int> tmp;
        cin >> t;
        cin >> t1;
        tmp.push_back(t);
        tmp.push_back(t1);
        pre.push_back(tmp);
        cc--;

    }
    auto vec = s.findOrder(nc, pre);
    for (auto v : vec) {

        cout << v << " ";
    }
}