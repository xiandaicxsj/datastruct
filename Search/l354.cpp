/*
   354. Russian Doll Envelopes
Hard

859

34

Add to List

Share
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Accepted
57,686
Submissions
165,540
   */
bool comp(vector<int>& p1, vector<int>& p2) {
    if (p1[0] == p2[0])
        return p1[1] > p2[1];
    return p1[0] < p2[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        int c = 0;
        int pl = 0;
        int ph = 0;
        int res = INT_MIN;
        vector<int> vec;
        if (!e.size())
            return 0;
#if 0
        for (int i = 0; i < e.size(); i++) {
            int t1 = e[i][0];
            int t2 = e[i][1];
            e[i][0] = min(t1, t2);
            e[i][1] = max(t1, t2);
        }
#endif

        sort(e.begin(), e.end(), comp);
        vec.push_back(e[0][1]);
        pl = e[0][0];
        for (auto ele : e) {
            auto iter = lower_bound(vec.begin(), vec.end(), ele[1]);
            if (iter == vec.end()) {
                if (ele[0] != pl) {
                    vec.push_back(ele[1]);
                    pl = ele[0];
                    //continue;
                }
                continue;
            }

            if (*iter != ele[1]) {
                *iter = ele[1];
                pl = ele[0];
            }
        }
        return vec.size();
    }
};

int main()
{
    int n;
    int t1;
    int t2;
    vector<vector<int>> e;
    Solution s;
    cin >> n;
    int i = 0;
    while (n) {
        vector<int> tmp;
        cin >> t1;
        cin >> t2;
        tmp.push_back(t1);
        tmp.push_back(t2);
        e.push_back(tmp);
        n--;
    }
    cout << s.maxEnvelopes(e);





}
#endif