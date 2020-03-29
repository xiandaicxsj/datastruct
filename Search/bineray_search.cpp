/*


    binery search tree realted


  */
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int bsearch(vector<int>& nums, int k) {
        int l = 0;
        int h = nums.size() - 1;
        int m;
        while (l < h) {
            m = (l + h) / 2;

            if (nums[m] < k)
                l = m + 1;
            else /* nums[m] >= k */
                h = m;
            /* if l + 1 = h, m = l, also h is checked. so next l = m + 1 is ok. all l and h is checked.
               no one is left. */
        }
        return l;
    }

    int bsearch1(vector<int>& nums, int k) {
        int l = 0;
        int h = nums.size() - 1;
        int m;
        while (l < h) {
            m = (l + h) / 2;

            if (nums[m] <= k)
                l = m;
            else
                h = m - 1;

            cout << l << h;
            /* this will cause infinite loop error so add break
               1 2 2 3 search 2. get infinite loop
            */
            break;
        }
        return l;

    }

    int bsearch2(vector<int>& nums, int k) {
        int l = 0;
        int h = nums.size() - 1;
        int m;
        while (l < h) {
            m = (l + h) / 2;

            if (nums[m] < k)
                l = m + 1;
            else if (nums[m] > k)
                h = m - 1;
            else
                return m;
        }
        return l;

    }

    int bsearch4(vector<int>& nums, int k) {
        int l = 0;
        int h = nums.size() - 1;
        int m;
        /* infinite loop */
        while (l <= h) {
            m = (l + h) / 2;

            if (nums[m] < k)
                l = m + 1;
            else /* nums[m] >= k */
                h = m;
        }
        return l;
    }

    int bsearch5(vector<int>& nums, int k) {
        int l = 0;
        int h = nums.size() - 1;
        int m;
        while (l <= h) {
            m = (l + h) / 2;

            if (nums[m] < k)
                l = m + 1;
            else if (nums[m] >= k)
                h = m - 1;
        }
        return l;

    }

    int bsearch6(vector<int>& nums, int k) {
        int l = 0;
        int h = nums.size() - 1;
        int m;
        while (l <= h) {
            m = (l + h) / 2;

            if (nums[m] <= k)
                l = m + 1;
            else if (nums[m] > k)
                h = m - 1;
        }
        return l;

    }
};
/* bsearch can find k with samllest idx(like lower bound)
   bsearch2 can find k with random idx
   for example
   1 2 2 2 2 2 2 2 2 4
   Search 2.
   bsearch: get idx = 1
   bsearch2: get idx = 4;
   Search 3.
   all get idx = 9

   bearch3 can cause infinite loop because:
   m = (1+h)/2;
   if l+1 == h:
       m = (1+h)/2 = l;
   Follow logic:
   if (nums[m] <= k)
     l = m;
   l will keep as m. while (1 < h) will never meet, so infinite loop.

   bsearch 4 is almost same with bsearch 1:
   but while(l<=h), this will cause infinite loop too.
   Remember if there is r = m or l = m, it may cause infinite loop.


   bsearch5 is lower_bound
   bsearch6 is high_bound

   bsearch and bsearch5 when search can not found.
   1 2 2 4 search 5
   bsearch return 3
   bsearch6 return 4
   because bsearch l < h, l will never reach h only equal will break.
   but bsearch6 can do this.

   So if (l <= h), r= m-1 or l = m+1, we can not do r = m or l = m;


 */
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
    cout << "first:" << s.bsearch(nums, k) << endl;
    cout << "second: " << s.bsearch6(nums, k) << endl;
}