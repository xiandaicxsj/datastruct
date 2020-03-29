/*
436. Find Right Interval
Medium

287

113

Add to List

Share
Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:

You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.


Example 1:

Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.


Example 2:

Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.


Example 3:

Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

Accepted
31,961
Submissions
72,322
Seen this question in a real interview before?

Yes

No
Contributor

*/
bool cmp_pare(const pair<int, int>& p1, const pair<int, int>& p2)
{
    return p1.first < p2.first;
}


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        //map<int, int> i_map;
        //map<int, int> j_map;
        vector<pair<int, int>> vec;
        vector<int> res;
        for (int i = 0; i < intervals.size(); i++) {
            auto v = intervals[i];
            vec.push_back(make_pair(v[0], i));
        }
        sort(vec.begin(), vec.end(), cmp_pare);

        for (int i = 0; i < intervals.size(); i++) {
            auto v = intervals[i];

            auto iter = lower_bound(vec.begin(), vec.end(), make_pair(v[1], 0), cmp_pare);
            if (iter == vec.end())
                res.push_back(-1);
            else
            {
                res.push_back(iter->second);
            }

        }
        return res;

    }
};

int main()
{

    vector<vector<int>> intervals;
    int n;
    cin >> n;
    int t1;
    int t2;
    Solution s;
    vector<int> res;
    while (n) {
        vector<int> tmp;
        cin >> t1;
        cin >> t2;
        tmp.push_back(t1);
        tmp.push_back(t2);
        intervals.push_back(tmp);
        n--;
    }
    res = s.findRightInterval(intervals);
    for (auto r : res) {
        cout << r << " " << endl;
    }



}