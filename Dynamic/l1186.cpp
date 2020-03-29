/*
  1186. Maximum Subarray Sum with One Deletion
Medium

340

14

Add to List

Share
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.



Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
Example 2:

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.
Example 3:

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.


Constraints:

1 <= arr.length <= 10^5
-10^4 <= arr[i] <= 10^4

    */
class Solution {
public:
    /* pass */
    int maximumSum2(vector<int>& arr) {
        vector<int> dp(arr.size(), INT_MIN);
        vector<int> dp_s(arr.size(), INT_MIN);

        // = INT_MAX;
        int ret = INT_MIN;
        dp[0] = arr[0];
        ret = dp[0];
        //dp_s[0] = 
        //bool get_neg = false;
        for (int i = 1; i < arr.size(); i++)
        {

            if (dp[i - 1] < 0)
                dp[i] = arr[i];
            else
                dp[i] = dp[i - 1] + arr[i];


            if (arr[i] < 0) {
                if (dp_s[i - 1] != INT_MIN)
                    dp_s[i] = max(dp_s[i - 1] + arr[i], dp[i - 1]);
                else
                    dp_s[i] = dp[i - 1];
            }
            else {
                if (dp_s[i - 1] >= 0)
                    dp_s[i] = dp_s[i - 1] + arr[i];
            }
#define DEBUG 
#ifdef DEBUG
            cout << "arr[" << i << "]:" << arr[i] << " ";
            cout << "dp[" << i << "]:" << dp[i] << " ";
            cout << "dp_s[" << i << "]:" << dp_s[i] << endl;
#endif
            ret = max(ret, dp[i]);
            ret = max(ret, dp_s[i]);

        }
        return ret;

    }
    /* Alwsome solution, split the arry
        dps[i]  means max sub_arry end with arr[i]
        dpe[i] means max sub_arry begin with [i].
    */
    int maximumSum(vector<int>& arr) {
        vector<int> dps(arr.size(), INT_MIN);
        vector<int> dpe(arr.size(), INT_MIN);

        // = INT_MAX;
        int ret = arr[0];
        dps[0] = arr[0];
        dpe[arr.size() - 1] = arr[arr.size() - 1];
        ret = max(ret, dpe[arr.size() - 1]);
        for (int i = 1; i < arr.size(); i++) {
            dps[i] = dps[i] - 1 <= 0 ? arr[i] : dps[i - 1] + arr[i];
            //cout << "dps[" << i << "]:" << dps[i] << endl;
        }
        for (int j = arr.size() - 2; j >= 0; j--) {
            dpe[j] = dpe[j + 1] <= 0 ? arr[j] : dpe[j + 1] + arr[j];
            // cout << "dps[" << j << "]:" << dpe[j] << endl;
        }
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < 0) {
                ret = max(ret, dps[i - 1] + dpe[i] - arr[i]);
            }
        }
        return ret;

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
        vector<int> arr = stringToIntegerVector(line);

        int ret = Solution().maximumSum(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}