/*
786. K-th Smallest Prime Fraction
Hard

300

17

Add to List

Share
A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]
Note:

A will have length between 2 and 2000.
Each A[i] will be between 1 and 30000.
K will be between 1 and A.length * (A.length - 1) / 2.
Accepted
11,092
Submissions
26,670
AC
*/

#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

#include <utility>
using namespace std;



class tu {
public:
    int x;
    int y;
    float data;
    tu(int _x, int _y, float _data) {
        x = _x;
        y = _y;
        data = _data;
    };

};

class tu_compare {
public:
    bool operator()(tu& p1, tu& p2) {
        return p1.data > p2.data;
    }

};


class Solution {
public:
    /* AC */
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
        priority_queue<tu, vector<tu>, tu_compare> pq;
        int i = 0;
        int a_size = A.size();
        vector<int> res;
        for (i = 0; i < a_size; i++) {
            pq.push(tu(0, i, (float)A[0] / (float)A[i]));
        }
        if (!a_size)
            return res;


        while (k && !pq.empty()) {
            class tu t = pq.top();
            int x = t.x;
            int y = t.y;
            k--;
            pq.pop();
            if (k == 0) {
                res.push_back(A[t.x]);
                res.push_back(A[t.y]);
                // cout << t.data;
                return res;
            }
            if (t.x + 1 == t.y)
                continue;
            if (t.x + 1 == a_size)
                continue;
            pq.push(tu(x + 1, y, (float)A[x + 1] / (float)A[y]));
        }
        return res;

    }
    /* benarey search should finish */
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k)
    {
        float l = 0;
        float h = 1;
        float m = 0;
        int count = 0;
        int i = 0;
        while (true) {
            m = (1 + h) / 2;
            count = 0;
            for (i = 0; i < A.size(); i++) {
                count = count + (lower_bound(A.begin(), A.end(), A[i] / m) - A.begin());
            }
            if (cout < k)
                l = m;
            else
                h = m;

        }


    }


};


int main()
{
    Solution s;
    int n;
    int t;
    cin >> n;
    vector<int> m;
    vector<int> res;
    while (n)
    {
        cin >> t;
        m.push_back(t);
        n--;
    }
    cin >> n;
    res = s.kthSmallestPrimeFraction(m, n);
    for (auto&& i : res)
        cout << i << " ";
    cout << endl;

    return 0;

}