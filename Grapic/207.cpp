/*
 207. Course Schedule
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
    bool canFinish_wrong(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans(numCourses, -1);

        int t;
        for (auto v : prerequisites) {

            t = v[1];
            if (t == v[0])
                return false;
            while (ans[t] != -1) {
                if (ans[t] == v[0])
                    return false;
                t = ans[t];
            }
            ans[v[0]] = t;
        }
        return true;
    }

    bool find_loop(int i, vector<vector<int>>& a, vector<int>& v, vector<int>& done) {
        v[i] = 1;
        done[i] = 1;
        if (a[i].size() != 0) {
            for (auto vec : a[i])
            {

                if (v[vec])
                    return true;
                if (done[vec])
                    continue;

                if (find_loop(vec, a, v, done))
                    return true;
            }

        }

    out:
        v[i] = 0;

        return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> ans(numCourses, vector<int>());
        vector <int> dg(numCourses, -1);
        vector<int> visited(numCourses, 0);
        vector<int> done(numCourses, 0);
        int i;
        int check_one = 0;
        /* done 是用来剪枝的，成精访问过的都不在需要访问了， */
        for (auto v : prerequisites) {
            dg[v[0]] ++;
            ans[v[1]].push_back(v[0]);
        }
        //for (i = 0; i < )

        for (i = 0; i < dg.size(); i++) {
            if (done[i])
                continue;
            // check_one = 1;
                         /* done 是用来剪枝的，成精访问过的都不在需要访问了， */
             /*这里运行几次就代表有几个独立的树木*/
            if (find_loop(i, ans, visited, done)) {
                return false;
            }
        }
        return true;
        //return check_one ? true : false;
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
    cout << s.canFinish(nc, pre) << endl;
}