/*
33. Search in Rotated Sorted Array
Medium

3718

404

Add to List

Share
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
AC
两种解法
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

        while (l <= h) {
            m = (l + h) / 2;
            if (nums[m] == target)
                return m;

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

                /* m - h is order*/
            }


        }

        return -1;
    }
};

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
        }
        //cout << l;
        rote = l;
        l = 0;
        h = nums.size() - 1;
        while (l <= h) {
            m = (l + h) / 2;
            rm = (m + rote) % size;
            if (nums[rm] == target)
                return rm;
            if (target > nums[rm])
                l = m + 1;
            else
                h = m - 1;
        }
        return -1;
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

        int ret = Solution().search(nums, target);

        cout << ret << endl;
    }
    return 0;
}