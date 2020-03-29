/*
300. Longest Increasing Subsequence
Medium

3658

81

Add to List

Share
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

Accepted
311,837
Submissions
744,450

AC
*/

class Solution {
public:
#ifdef SED
    bool volid(vector<int>& nums, int m)
    {
        int i = 0;
        int n = nums.size();
        int j = 0;
        int k = 0;
        if (!m)
            return true;
        for (i = 0; i < n - m + 1; )
        {
            k = 0;
            for (j = 1; j < m; j++) {
                if (nums[i + j] <= nums[i + j - 1]) {
                    k = 1;
                    i = i + j;
                    goto check_next;
                }
            }
        check_next:
            if (!k)
                return true;

        }
        return false;

    }
    int lengthOfLIS(vector<int>& nums) {

        int l = 0;
        int h = nums.size();
        int m = 0;
        if (h == 0)
            return 1;
        while (l < h) {
            m = (l + h) / 2;
            if (volid(nums, m))
                l = m + 1;
            else
                h = m - 1;
        }
        return l;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int i = 0;
        int j = 0;
        for (i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
        }

        for (i = 0; i < nums.size(); i++)
            cout << dp[i] << " ";
        cout << endl;
        return dp[nums.size() - 1];
    }
#endif
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        vector<int>::iterator itr;
        for (auto num : nums)
        {
            itr = lower_bound(res.begin(), res.end(), num);
            if (itr != res.end())
                *itr = num;
            else
                res.push_back(num);
        }
        return res.size();
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().lengthOfLIS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
