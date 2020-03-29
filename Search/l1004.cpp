/*
*/
/*
 1004. Max Consecutive Ones III
Medium

660

15

Add to List

Share
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s.



Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation:
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
Example 2:

Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation:
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.


Note:

1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1
   *//*

   Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

Accepted
223,051
Submissions
683,559

   */


class Solution {
public:
    vector<vector<int>> insert2(vector<vector<int>>& is, vector<int>& ni) {
        int b = ni[0];
        int e = ni[1];
        bool merged = false;
        vector<vector<int>> res;
        bool need = false;
        //auto iter = lower_bound(is.begin(), is.end(), ni, cmp_lower) - is.begin();

        //while()
        if (!is.size()) {
            res.push_back(ni);
            return res;
        }

        for (int i = 0; i < is.size(); i++) {
            if (merged || is[i][1] < ni[0]) {
                res.push_back(is[i]);
                continue;
            }
            if (b > is[i][0])
                b = min(b, is[i][0]);
            if (e < is[i][1]) {
                if (e >= is[i][0])
                    e = is[i][1];
                else
                    need = true;
                vector<int> t;
                t.push_back(b);
                t.push_back(e);
                res.push_back(t);
                merged = true;
                if (need) {
                    res.push_back(is[i]);
                }
            }
        }
        if (!merged)
        {
            vector<int> t;
            t.push_back(b);
            t.push_back(e);
            res.push_back(t);

        }
        return res;
    }
    /* more clear */
    vector<vector<int>> insert(vector<vector<int>>& is, vector<int>& ni) {

        vector<vector<int>> left;
        vector<vector<int>> right;
        vector<int> t;
        for (int i = 0; i < is.size(); i++)
        {
            if (is[i][1] < ni[0])
                left.push_back(is[i]);
            if (is[i][0] > ni[1])
                right.push_back(is[i]);
        }

        int s = ni[0];
        int e = ni[1];
        if (left.size() + right.size() != is.size()) {
            s = min(is[left.size()][0], s);
            e = max(is[is.size() - right.size() - 1][1], e);
        }
        t.push_back(s);
        t.push_back(e);
        //vector<int> t;

        left.push_back(t);
        left.insert(left.end(), right.begin(), right.end());
        return left;

    }
};

int main() {
    vector<vector<int>> ins;
    vector<int> ni;
    int n;
    int t1;
    int t2;

    Solution s;
    cin >> n;
    while (n) {
        cin >> t1;
        cin >> t2;
        vector<int> t;
        t.push_back(t1);
        t.push_back(t2);
        ins.push_back(t);
        n--;
    }
    cin >> t1;
    cin >> t2;
    ni.push_back(t1);
    ni.push_back(t2);
    auto r = s.insert(ins, ni);

    for (auto res : r) {
        cout << res[0] << " " << res[1] << endl;
    }




}