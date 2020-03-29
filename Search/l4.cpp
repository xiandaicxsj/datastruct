/*
4. Median of Two Sorted Arrays
Hard

5825

876

Add to List

Share
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
Accepted
584,641
Submissions
2,070,431

AC

nums[
*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#ifdef DEBUG
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = (n1 + n2) >> 1;
        int o = (n1 + n2) % 2;
        int n1_s = 0;
        int n2_s = 0;
        double ret = 0;
        int idx;


        while (n && n1_s < n1 && n2_s < n2) {
            if (nums1[n1_s] > nums2[n2_s]) {
                idx = lower_bound(nums2.begin(), nums2.end(), nums1[n1_s]) - nums2.begin();
                if (idx - n2_s < n) {
                    n = n - (idx - n2_s);
                    n2_s = idx;
                }
                else
                {
                    if (o)
                        ret = nums2[n + n2_s];
                    else
                    {
                        ret = nums2[n + n2_s];
                        if (n + n2_s + 1 >= idx)
                            ret += nums1[n1_s];
                        else
                        {
                            ret += nums2[n + n2_s + 1];
                        }
                        ret = ret / 2;
                    }
                }
            }

            if (nums1[n1_s] == nums2[n2_s]) {
                n1_s++;
                n2_s++;
            }
            if (nums1[n1_s] < nums2[n2_s]) {
                idx = lower_bound(nums1.begin(), nums1.end(), nums2[n2_s]) - nums1.begin();
                if (idx - n1_s < n) {
                    n = n - (idx - n1_s);
                    n1_s = idx;
                }
                else
                {
                    if (o)
                        ret = nums1[n + n1_s];
                    else
                    {
                        if (n1_s + n < n1) {
                            ret = nums1[n + n1_s];
                            if (n + n1_s + 1 >= idx)
                                ret += nums2[n2_s];
                            else
                            {
                                ret += nums1[n + n1_s + 1];
                            }
                            ret = ret / 2;
                        }
                        else {
                            ret = nums2[n2_s + n1_s + n - n1];

                        }
                    }
                }
            }

        }
        return ret;

    }
};
#endif
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
#ifdef DEBUG
class Solution {
public:
    double findMedianSortedArrays(vector<int>& x, vector<int>& y) {
        int l = 0;
        int r = x.size() - 1;
        int x_m = 0;
        int xlmax;
        int xrmin;
        int ylmax;
        int yrmin;
        int min_v = numeric_limits<int>::min();
        int max_v = numeric_limits<int>::max();
        int y_m;
        double ret = 0;
        int k = 0;
        if (x.size() > y.size())
            return findMedianSortedArrays(y, x);
        int h_s = (x.size() + y.size() + 1) / 2;
        if (x.size() == 0)
        {
            if (y.size() == 0)
                return (double)0;
            return y.size() % 2 ? (double)y[y.size() / 2] : (y[y.size() / 2 - 1] + y[y.size() / 2]) / (double)2;
        }
        /* nums1 have short length */
        while (!k) {
            //cout << "l:" << l << "r" << r << endl;
            if (r >= 0) {
                x_m = (l + r) / 2;
                /* error here */
                y_m = h_s - x_m - 2;
            }
            else
            {
                x_m = -1;
                y_m = h_s - x_m - 2;
                k = 1;
            }
            xlmax = x_m < 0 ? min_v : x[x_m];
            xrmin = x_m + 1 >= x.size() ? max_v : x[x_m + 1];
            ylmax = y_m < 0 ? min_v : y[y_m];
            yrmin = y_m + 1 >= y.size() ? max_v : y[y_m + 1];

            if (xlmax <= yrmin) {
                if (ylmax <= xrmin) {
                    if ((x.size() + y.size()) % 2)
                        ret = MAX(xlmax, ylmax);
                    else
                        ret = (MAX(xlmax, ylmax) + MIN(xrmin, yrmin)) / (double)2;
                    return ret;
                    //break;
                    /* ok find the value*/
                }
                else {
                    l = x_m + 1;

                }
            }
            else {
                r = x_m - 1;
#ifdef DEBUG
                if (r < 0) {
                    int n = (x.size() + y.size() + 1) > 1;
                    /* odd */
                    if ((x.size() + y.size()) % 2) {
                        if (y.size() >= n)
                            return y[n - 1];
                        else
                        {
                            return x[n - y.size() - 1];
                        }
                    }/* even */
                    else {
                        if (y.size() > n)
                            return y[n - 1]


                    }
                }
#endif

            }

        }
        return ret;

    }


};
#endif
class Solution {
public:
    double findMedianSortedArrays(vector<int>& x, vector<int>& y) {
        int l = 0;
        int r = x.size();
        int px = 0;
        int py = 0;
        int xlmax;
        int xrmin;
        int ylmax;
        int yrmin;
        int min_v = numeric_limits<int>::min();
        int max_v = numeric_limits<int>::max();
        int y_m;
        double ret = 0;
        int k = 0;
        if (x.size() > y.size())
            return findMedianSortedArrays(y, x);
        int h_s = (x.size() + y.size() + 1) / 2;

        /* nums1 have short length */
        while (l <= r) {
            //cout << "l:" << l << "r" << r << endl;
            /* give */
            px = (l + r) / 2;
            /* error here */
            py = h_s - px;


            xlmax = px == 0 ? min_v : x[px - 1];
            xrmin = px >= x.size() ? max_v : x[px];
            ylmax = py == 0 ? min_v : y[py - 1];
            yrmin = py >= y.size() ? max_v : y[py];

            if (xlmax <= yrmin) {
                if (ylmax <= xrmin) {
                    if ((x.size() + y.size()) % 2)
                        ret = MAX(xlmax, ylmax);
                    else
                        ret = (MAX(xlmax, ylmax) + MIN(xrmin, yrmin)) / (double)2;
                    return ret;
                    //break;
                    /* ok find the value*/
                }
                else {
                    l = px + 1;

                }
            }
            else {
                r = px - 1;
#ifdef DEBUG
                if (r < 0) {
                    int n = (x.size() + y.size() + 1) > 1;
                    /* odd */
                    if ((x.size() + y.size()) % 2) {
                        if (y.size() >= n)
                            return y[n - 1];
                        else
                        {
                            return x[n - y.size() - 1];
                        }
                    }/* even */
                    else {
                        if (y.size() > n)
                            return y[n - 1]


                    }
                }
#endif

            }

        }
        return ret;

    }


};
int main()
{


    int n1;
    int n2;
    int t;
    vector<int> vec1;
    vector<int> vec2;
    Solution s;
    cin >> n1;
    while (n1) {
        cin >> t;
        vec1.push_back(t);
        n1--;
    }
    cin >> n2;
    while (n2) {
        cin >> t;
        vec2.push_back(t);
        n2--;
    }
    cout << s.findMedianSortedArrays(vec1, vec2) << endl;
}