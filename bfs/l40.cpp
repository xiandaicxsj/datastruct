/*
40. Combination Sum II
Medium

1298

54

Add to List

Share
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
Accepted
281,089
Submissions
620,771
*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:

    void bfs(vector<int>& c, int target, vector<vector<int>>& ret, vector<int>& tmp, int begin)
    {
        int n = c.size();
        int i = 0;

        if (target == 0)
        {
            ret.push_back(tmp);
            return;
        }
        if (target < 0 || begin >= n)
            return;

        for (i = begin; i < n; i++)
        {
            // if (visit[i])
              //   continue;

             /* choose 0*/
            if (i > begin&& c[i] == c[i - 1])
                continue;

            //  visit[i] = 1;
            tmp.push_back(c[i]);
            bfs(c, target - c[i], ret, tmp, i + 1);
            //visit[i] = 0;
            tmp.pop_back();

        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmp;
        int size = candidates.size();

        sort(candidates.begin(), candidates.end());
        // visit = (int*)malloc(sizeof(int) * size);
       //  memset(visit, 0, sizeof(int) * size);

        bfs(candidates, target, ret, tmp, 0);
        return ret;
    }
    // int* visit;
};
int main()
{


    int n1;
    int n2;
    int t;
    vector<int> vec1;
    vector<vector<int>> ret;
    Solution s;
    cin >> n1;
    while (n1) {
        cin >> t;
        vec1.push_back(t);
        n1--;
    }
    cin >> n2;

    ret = s.combinationSum2(vec1, n2);
    cout << ret.size() << endl;

    for (auto&& tvec : ret) {
        for (auto&& t : tvec) {
            cout << t << " ";
        }
        cout << endl;

    }
}