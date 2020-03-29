/*

646. Maximum Length of Pair Chain
Medium

711

65

Add to List

Share
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].
Accepted
47,534
Submissions
94,125
AC

*/
class CMyClass
{
public:
    static struct _CompareFloatField
    {
        bool operator() (const vector<int>& x, const vector<int>& y) //...
        {
            return y[0] > x[1];
        }
        // ...
    } CompareFloatField;
};
bool sort_fn(const vector<int>& x, const vector<int>& y)
{
    return y[0] > x[1];
}
bool sort_fn1(const vector<int>& x, const vector<int>& y)
{
    return y[0] > x[0];
}
bool sort_fn_tail(const vector<int>& x, const vector<int>& y)
{
    return y[1] > x[1];
}
class Solution {
public:

    int findLongestChainBenary(vector<vector<int>>& pairs) {
        int i = 0;
        int size = pairs.size();

        sort(pairs.begin(), pairs.end(), sort_fn1);
        vector<vector<int>> res;
        vector<vector<int>>::iterator itr;
        for (i = 0; i < size; i++) {

            itr = lower_bound(res.begin(), res.end(), pairs[i], sort_fn);
            if (itr != res.end())
            {
                if (pairs[i][1] < (*itr)[1])
                    *itr = pairs[i];
            }
            else res.push_back(pairs[i]);
        }
        return res.size();
    }


    int findLongestChain_GREEDY(vector<vector<int>>& pairs) {

        int count = 0;
        sort(pairs.begin(), pairs.end(), sort_fn_tail);

        int max_v = 0;
        int end = INT_MIN;
        for (auto vec : pairs) {
            if (vec[0] > end) {
                count++;
                end = vec[1];
            }

        }
        return count;
    }
};


int main()
{
    int n = 0;
    int a1 = 0;
    int a2 = 0;
    cin >> n;
    Solution s;
    vector<vector<int>> res;
    while (n)
    {
        vector<int> tmp;
        cin >> a1;
        cin >> a2;
        tmp.push_back(a1);
        tmp.push_back(a2);
        res.push_back(tmp);
        n--;
    }
    cout << s.findLongestChain(res);


}