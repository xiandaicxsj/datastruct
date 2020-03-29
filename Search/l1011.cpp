/*
1011. Capacity To Ship Packages Within D Days
  A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.



Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation:
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], D = 3
Output: 6
Explanation:
A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], D = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1


Note:

1 <= D <= weights.length <= 50000
1 <= weights[i] <= 500
Accepted


    */

class Solution {
public:
    bool volid(vector<int>& weights, int m, int d) {
        int sum = 0;
        for (auto w : weights) {
            sum += w;

            if (sum > m) {
                d--;
                if (!d)
                    return false;
                sum = w;
            }
        }
        return true;
    }

    /* 20 ms too long */
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 1;
        int h = 0;
        int sum = 0;
        int m = 0;
        int min_v = INT_MIN;
        for (auto w : weights) {
            sum += w;
            min_v = max(w, min_v);
        }
        h = sum;
        l = min_v;
        while (l < h) {
            m = (l + h) / 2;
            if (volid(weights, m, D))
                h = m;
            else
                l = m + 1;
        }
        return l;
    }

    bool volid2(vector<int>& sums, int m, int d) {
        int target = m;
        int i = 0;

        while (d) {
            i = lower_bound(sums.begin() + i, sums.end(), target) - sums.begin();
            if (i == 0)
                return false;
            if (i != sums.size() && sums[i] == target)
                i++;
            if (i == sums.size())
                return true;
            target = sums[i - 1] + m;
            d--;
        }
        return false;
    }
    /* slower by shipwithDays1 */
    int shipWithinDays2(vector<int>& weights, int D) {
        vector<int> sums(weights.size() + 1, 0);
        int h, l;
        sums[0] = 0;
        int i = 1;
        int m = 0;

        for (auto w : weights) {
            sums[i] = w + sums[i - 1];
            i++;
        }
        h = sums[weights.size()];
        l = 0;
        while (l < h) {
            m = (l + h) / 2;
            if (volid2(sums, m, D))
                h = m;
            else
                l = m + 1;
        }
        return l;

    }

};

int main()
{
    int m;
    int t = 0;
    Solution s;
    cin >> m;
    int d;
    vector<int> weights;
    while (m) {
        cin >> t;
        weights.push_back(t);

        m--;
    }

    cin >> d;
    cout << s.shipWithinDays2(weights, d);

}