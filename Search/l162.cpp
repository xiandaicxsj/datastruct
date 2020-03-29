/*
162. Find Peak Element
Medium

1289

1746

Add to List

Share
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ¡Ù nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -¡Þ.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
             or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.

Accepted
307,443
Submissions
722,775

AC

*/
class Solution {
public:
    /* o(n) */
    int findPeakElement_ON(vector<int>& nums) {
        int i = 0;
        int size = nums.size();
        while (i < size)
        {
            if ((i + 1) != size && nums[i] > nums[i + 1])
                return i;
            i++;

        }
        return size - 1;
    }
    int findPeakElement(vector<int>& nums) {
        int i = 0;
        int l = 0;
        int h = nums.size() - 1;
        int size = nums.size();
        int m = 0;


        while (l <= h)
        {
            m = (l + h) / 2;

            if ((m == 0 || nums[m] >= nums[m - 1]) &&
                (m == size - 1 || nums[m] >= nums[m + 1]))
                return m;
            if (nums[m] < nums[m + 1])
                l = m + 1;
            else if (nums[m] < nums[m - 1])
                h = m - 1;

        }
        return h;
    }

};
int main()
{
    int n = 0;
    Solution s;
    vector<int> nums;
    cin >> n;
    int t;
    while (n) {
        cin >> t;
        nums.push_back(t);
        n--;
    }
    cout << s.findPeakElement(nums);



}
