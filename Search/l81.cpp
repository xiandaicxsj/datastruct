
/*
81. Search in Rotated Sorted Array II
Medium

972

407

Add to List

Share
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
Accepted
210,079
Submissions
638,412
AC status;
Slotion1:
retotate sort 最关键的问题是如何寻找retotate的数目，
1.首先利用二分法可以rotate了几个元素。
2.然后在用二分法查找target的是加上对应的偏移即可。

对于有重复数据来说主要处理的是还是1. 寻找偏移的过程，比较复杂。其实寻找偏移也是讯在nums 中最大值和最小值的边界。
在没有重复数据的情况下。
利用
nums[m] > nums[h] l = m + 1 这里因为我们确定的知道m对应的元素不是最小的元素,所以可以丢弃掉m
nums[m] < nums[h] h = m  这里我们无法确定的是m 对应的元素是否为最小，所以不能丢弃 m
这里的等号没有必要

对于有重复数据的情况来说，
nums[m] > nums[h] l = m + 1
nums[m] < nums[h] h = m
nums[m] ==  nums[h] && nums[m] == nums[l] 这种情况我们是无法知道当前的数据是存在于 [l-m] 还是存在于
m - h, 所以需要所有m - h 是否存在 nums[t_m] (m < t_m < h) != nums[m], 如果存在说明偏移在[m - h] 中
如果不存在，说明偏移在[l-h]中。

Solutions 2:
直接选择不再找偏移：
选择 m 后，判断[l-m] 是顺序的，还是 [m -h] 是循序的，
假设 [l-m] 是升序的，
nums[m] > target > nums[l] 说明target在 l -  里面。 h = m -1;
上面不成立的话，就是说 target 在 [m-h]里面，直接 l = m + 1;

同样如果[m - h] 是升序的。也是一样。



    */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int m = 0;
        int rote = 0;
        int rm = 0;
        int size = nums.size();

        while (l < h) {
            m = (l + h) / 2;
            if (nums[m] < nums[h])
                h = m;
            else if (nums[m] > nums[h])
                l = m + 1;
            else
            {

                if (nums[m] != nums[l])
                    h = m;
                else
                {
                    int t_m = m;
                    while (t_m <= h && nums[t_m] == nums[h]) t_m++;
                    if (t_m != h + 1)
                        l = t_m;
                    else
                        h = m;
                    /* nums[m] == nums[l] == nums[h]*/
                   // l = m + 1;
                }

                //
            }
        }
        //cout << l;
        rote = l;
        // return rote;
        l = 0;
        h = nums.size() - 1;
        while (l <= h) {
            m = (l + h) / 2;
            rm = (m + rote) % size;
            if (nums[rm] == target)
                return true;
            if (target > nums[rm])
                l = m + 1;
            else
                h = m - 1;
        }
        return false;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int m = 0;
        int rote = 0;
        int rm = 0;
        int size = nums.size();

        while (l <= h) {
            m = (l + h) / 2;
            if (nums[m] == target)
                return true;

            if (nums[m] == nums[l] && nums[m] == nums[h])
            {
                l++;
                h--;
                continue;

            }
            if (nums[m] >= nums[l])
            {
                /* l - m is order*/
                if (target < nums[m] && target >= nums[l])
                    h = m - 1;
                else
                    l = m + 1;
                continue;
            }

            if (nums[m] <= nums[h])
            {
                if (target > nums[m] && target <= nums[h])

                    l = m + 1;
                else
                    h = m - 1;
                continue;
                /* m - h is order*/
            }

        }

        return false;
    }
};
void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
        }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        bool ret = Solution().search(nums, target);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
#ifdef DEBUG
int main() {
    int n;
    vector<int> v;
    cin >> n;
    int i = 0;
    int t = 0;
    Solution s;

    for (i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }
    cin >> t;
    cout << s.search(v, t);
    return 0;

}
#endif