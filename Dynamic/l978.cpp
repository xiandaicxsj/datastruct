/*
  978. Longest Turbulent Subarray
Medium

227

70

Add to List

Share
A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:

For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

Return the length of a maximum size turbulent subarray of A.



Example 1:

Input: [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
Example 2:

Input: [4,8,12,16]
Output: 2
Example 3:

Input: [100]
Output: 1


Note:

1 <= A.length <= 40000
0 <= A[i] <= 10^9
Accepted
21,131
Submissions
45,790

  */

class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {


        int ret = 1;
        int dp;
        /*
        0 bign
        1 small
        2 erver
        */
        int d = 2;
        for (int i = 1; i < a.size(); i++) {
            if (d == 2) {
                dp = 2;
                if (a[i] > a[i - 1])
                    d = 1; /* next should dp[i+1] <dp[i]*/
                if (a[i] < a[i - 1])
                    d = 0;
                if (a[i] == a[i - 1]) {
                    d = 2;
                    dp = 1;

                }
                goto out;
            }

            if (d == 1) {
                if (a[i] < a[i - 1]) {
                    dp++;
                    d = 0;
                }

                if (a[i] == a[i - 1]) {
                    dp = 1;
                    d = 2;
                }

                if (a[i] > a[i - 1]) {
                    dp = 2;
                }
                goto out;
            }
            if (d == 0) {
                if (a[i] > a[i - 1]) {
                    dp++;
                    d = 1;
                }

                if (a[i] == a[i - 1]) {
                    dp = 1;
                    d = 2;
                }
                if (a[i] < a[i - 1]) {
                    dp = 2;
                }
                goto out;
            }
        out:
            //cout << "dp[" << i << "]:" << dp[i] << endl;
            ret = max(ret, dp);
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
        vector<int> A = stringToIntegerVector(line);

        int ret = Solution().maxTurbulenceSize(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}