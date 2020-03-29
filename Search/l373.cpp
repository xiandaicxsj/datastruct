/*
373. Find K Pairs with Smallest Sums
Medium

989

83

Add to List

Share
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence:
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
Accepted
85,061
Submissions
240,994

AC now
*/

#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

#include <utility>
using namespace std;


class pare_comp {
public:
    bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first + p1.second < p2.first + p2.second;
    }
};

class tu {
public:
    int x;
    int y;
    int data;
    tu(int _x, int _y, int _data) {
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

    /* legacy method */
    vector<vector<int>> kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
        int i = 0;
        int j = 0;
        int n1_size = nums1.size();
        int n2_size = nums2.size();
        vector<vector<int>> res;
        //  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, pare_comp> pq;

        for (i = 0; i < n1_size; i++) {
            for (j = 0; j < n2_size; j++)
            {
                if (pq.size() < k) {
                    pq.push(make_pair(nums1[i], nums2[j]));
                    continue;
                }
                if (nums1[i] + nums2[j] < pq.top().first + pq.top().second) {
                    pq.push(make_pair(nums1[i], nums2[j]));
                    pq.pop();
                }
            }
        }

        while (!pq.empty()) {
            vector<int> t;
            t.push_back(pq.top().first);
            t.push_back(pq.top().second);
            res.push_back(t);
            pq.pop();
        }

        return res;
    }
    /* effency */
    vector<vector<int>> kSmallestPairs2(vector<int>& nums1, vector<int>& nums2, int k) {
        int i = 0;
        int j = 0;
        int n1_size = nums1.size();
        int n2_size = nums2.size();
        vector<vector<int>> res;
        //  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        if (!n1_size || !n2_size)
            return res;
        priority_queue<tu, vector<tu>, tu_compare> pq;
        for (j = 0; j < n2_size; j++)
            pq.push(tu(0, j, nums1[0] + nums2[j]));
        while (k && !pq.empty()) {
            class tu t = pq.top();
            int x = t.x;
            int y = t.y;
            int data = t.data;
            vector<int> vec;
            vec.push_back(nums1[x]);
            vec.push_back(nums2[y]);
            res.push_back(vec);
            k--;
            pq.pop();
            if (x >= n1_size - 1)
                continue;
            pq.push(tu(x + 1, y, nums1[x + 1] + nums2[y]));

        }
        return res;
    }


};

int main()
{
    Solution s;
    vector<int> i_v;
    vector<int> j_v;
    int i = 0;
    int t = 0;
    vector <vector<int>> res;


    cin >> i;
    while (i) {
        cin >> t;
        i_v.push_back(t);
        i--;
    }

    cin >> i;
    while (i) {
        cin >> t;
        j_v.push_back(t);
        i--;
    }
    cin >> i;
    res = s.kSmallestPairs(i_v, j_v, i);
    for (i = 0; i < res.size(); i++)
    {
        for (auto& k : res[i])
            cout << k << " ";
        cout << endl;
        //  cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;

}