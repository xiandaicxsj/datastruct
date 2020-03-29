/*

  718. Maximum Length of Repeated Subarray
Medium

954

41

Add to List

Share
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation:
The repeated subarray with maximum length is [3, 2, 1].


Note:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100



 */

class Solution {
public:
    int volid(vector<int>& a, vector<int>& b, int len) {
        int t = 0;
        for (int i = 0; i <= a.size() - len; i++) {
            for (int j = 0; j <= b.size() - len; j++)
            {
                for (t = 0; t < len; t++)
                    if (a[i + t] != b[j + t])
                        goto next;
                return 1;
            next:
                continue;
            }
        }
        return 0;

    }

    int findLength_DP(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int i = 0;
        int j = 0;
        int max_v = 0;
        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max_v = max(dp[i][j], max_v);
                }
                else

                    dp[i][j] = 0;
            }
        return max_v;
    }


    int findLength2(vector<int>& a, vector<int>& b) {
        int l = 0;
        int h = min(a.size(), b.size());
        int m = 0;
        int res = 0;
        if (!h)
            return res;
        int i = 0;
        int j = 0;
        int  t = 0;
        while (l <= h)
        {
            m = (l + h) / 2;

            for (; i <= a.size() - m; i++) {
                for (j = 0; j <= b.size() - m; j++)
                {
                    for (t = 0; t < m; t++)
                        if (a[i + t] != b[j + t])
                            goto next;
                    goto find;
                next:
                    continue;
                }
            }
            h = m - 1;
            i = 0;
            j = 0;
            continue;
        find:
            res = max(m, res);
            l = m + 1;
        }
        return res;
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
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);

        int ret = Solution().findLength(A, B);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}