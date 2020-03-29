/*
658. Find K Closest Elements
Medium

974

201

Add to List

Share
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
UPDATE (2017/9/19):
The arr parameter had been changed to an array of integers (instead of a list of integers). Please reload the code definition to get the latest changes.

Accepted

这个问题很难理解，尤其是直接利用二分搜索做的这个解决方法：


*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int l = 0;
        int h = arr.size() - k;
        int m = 0;
        int i = 0;
        while (l < h)
        {
            int m = (l + h) / 2;
            if (arr[m] - x >= x - arr[m + k])
                h = m;
            else
                l = m + 1;
        }

        while (i < k) {
            res.push_back(arr[l + i]);
            i++;
        }
        return res;
    }
    vector<int> findClosestElementsNon(vector<int>& arr, int k, int x) {
        auto itr = lower_bound(arr.begin(), arr.end(), x);
        vector<int> res;
        int pre = 0;
        int end = 0;
        // if (*itr == x)
          //   k --;
        int idx = itr - arr.begin();

        pre = end = idx;
        int f_pre = -1;
        int f_end = -1;
        if (*itr != x) {
            pre--;
            if (pre > 0)
                if (abs(arr[pre] - x) <= abs(arr[idx] - x))
                    end = pre;
        }

        while (k)
        {

            if (pre == -1) {
                pre = 0;
                end += k;
                f_pre = pre;
                f_end = end;
                break;
            }
            if (end == arr.size()) {
                end = arr.size() - 1;
                pre -= k;
                f_pre = pre;
                f_end = end;
                break;
            }

            if (abs(arr[pre] - x) > abs(arr[end] - x)) {
                if (pre == end)
                    pre--;
                f_end = end;
                end++;
            }
            else {
                if (pre == end)
                    end++;
                f_pre = pre;
                pre--;
            }
            k--;

        }
        if (f_pre == -1)
            f_pre == pre + 1;
        if (f_end == -1)
            f_end == end - 1;
        while (f_pre <= f_end) {
            res.push_back(arr[f_pre]);
            f_pre++;
        }

        return res;
    }
};


int main() {
    vector<int> arr;
    int k = 0;
    int x = 0;
    int n;
    int t;

    Solution s;
    cin >> k;
    cin >> x;
    cin >> n;
    while (n) {
        cin >> t;
        arr.push_back(t);
        n--;
    }
    s.findClosestElements(arr, k, x);



    return 0;
}