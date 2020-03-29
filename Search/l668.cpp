/*
668. Kth Smallest Number in Multiplication Table
Hard

442

18

Add to List

Share
Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?

Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number in this table.

Example 1:
Input: m = 3, n = 3, k = 5
Output:
Explanation:
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th smallest number is 3 (1, 2, 2, 3, 3).
Example 2:
Input: m = 2, n = 3, k = 6
Output:
Explanation:
The Multiplication Table:
1	2	3
2	4	6

The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
Note:
The m and n will be in the range [1, 30000].
The k will be in the range [1, m * n]
Accepted
17,428
Submissions
39,363
Seen this question in a real interview before?

Yes

No
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
    int data;
    tu(int _x, int _y, long _data) {
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
     /* effency */
     /* time limit */
    int findKthNumber1(int m, int n, int k) {
        int i = 0;
        priority_queue<tu, vector<tu>, tu_compare> pq;
        int min = m > n ? n : m;
        int max = m > n ? m : n;
        n = min;
        m = max;
        if (n)
            return 0;

        for (i = 0; i < n; i++)
            pq.push(tu(0, i, 1 * (i + 1)));

        while (k && !pq.empty())
        {
            class tu t = pq.top();
            int x = t.x;
            int y = t.y;
            k--;
            pq.pop();
            if (k == 0)
                return t.data;
            if (x == m - 1)
                continue;
            pq.push(tu(x + 1, y, (x + 1 + 1) * (y + 1)));

        }
    }
    /* AC but
        Runtime: 72 ms, faster than 5.14% of C++ online submissions for Kth Smallest Number in Multiplication Table.
        Memory Usage: 8.3 MB, less than 60.00% of C++ online submissions for Kth Smallest Number in Multiplication Table.
        Next challenges:
        */
    int findKthNumber(int m, int n, int k) {
        int i = 0;
        long l = 0;
        long h = m * n;
        long mid = 0;
        long count = 0;
        int min = m > n ? n : m;
        int max = m > n ? m : n;
        while (l <= h) {
            mid = (l + h) / 2;
            count = 0;
            for (i = 0; i < min; i++)
                count = count + ((mid / (i + 1)) > max ? max : (mid / (i + 1)));

            if (count < k)
                l = mid + 1;
            else
                h = mid - 1;

        }
        return l;
    }

};

int main()
{
    Solution s;
    int m, n, k;
    cin >> m;
    cin >> n;
    cin >> k;
    cout << s.findKthNumber(m, n, k);

    return 0;

}