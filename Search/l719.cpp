
/*
719. Find K-th Smallest Pair Distance
Hard

721

25

Add to List

Share
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
Accepted
26,337
Submissions
86,447

*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int size = nums.size();
        int i = 0;
        int j = 0;
        sort(nums.begin(), nums.end());
        int l = 0;
        int h = nums[nums.size() - 1];
        int m = 0;
        int count = 0;
        //int j = 0;
        while (l < h) {
            m = (l + h) / 2;
            count = 0;
            j = 0;
            for (i = 0; i < size; i++) {
                while (j < size && nums[j] <= (nums[i] + m)) j++;
                count = count + ((j - i - 1) > 0 ? j - i - 1 : 0);
            }
            //count = count + prefix[nums[i] + m] - prefix[nums[i]];
            if (count < k)
                l = m + 1;
            else
                h = m;
        }
        return l;


    }
    class Solution {
    public:
        int smallestDistancePair(vector<int>& nums, int k) {
            int size = nums.size();
            int i = 0;
            int j = 0;
            sort(nums.begin(), nums.end());
            int l = 0;
            int h = nums[nums.size() - 1];
            int m = 0;
            int count = 0;
            //int j = 0;
            while (l <= h) {
                m = (l + h) / 2;
                count = 0;
                j = 0;
                for (i = 0; i < size; i++) {
                    while (j < size && nums[j] <= (nums[i] + m)) j++;
                    count = count + ((j - i - 1) > 0 ? j - i - 1 : 0);
                }
                //count = count + prefix[nums[i] + m] - prefix[nums[i]];
                if (count < k)
                    l = m + 1;
                else
                    h = m - 1;
            }
            return l;

        }
    };
};

int main()
{
    Solution s;
    vector<int> nums;
    int k, n, t;
    cin >> n;
    while (n) {
        cin >> t;
        nums.push_back(t);
        n--;
    }
    cin >> k;
    cout << s.smallestDistancePair(nums, k);

}