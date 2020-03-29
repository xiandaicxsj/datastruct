/*

   PASS

   813. Largest Sum of Averages
Medium

729

29

Add to List

Share
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input:
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation:
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.


Note:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
Answers within 10^-6 of the correct answer will be accepted as correct.

    */


class Solution {
public:
    double largestSumOfAverages(vector<int>& a, int K) {
        vector<vector<double>> dp(a.size() + 1, vector<double>(K + 1, 0));

        int k = 0;
        int i = 0;
        int j = 0;

        vector<double> sum(a.size() + 1, 0);
        for (i = 0; i < a.size(); i++)
        {
            sum[i + 1] = sum[i] + a[i];

        }

        for (k = 1; k <= K; k++)
        {
            for (i = 1; i <= a.size(); i++) {
                if (i <= k) {
                    dp[i][k] = (double)sum[i];
                    //   cout << "dp[" << i << "]" << "[" << k << "]: " << double(dp[i][k]) << endl;
                    continue;
                }
                for (j = k - 1; j < i; j++) {
                    if (k - 1 == 0 && j != 0)
                        continue;
                    dp[i][k] = max(dp[i][k], dp[j][k - 1] + double(sum[i] - sum[j]) / (double)(i - j));
                }
                // cout << "dp[" << i << "]" << "[" << k << "]: " << double(dp[i][k]) << endl;
            }

            //cout << "dp[" << i << "]" << "[" << k << "]: " << dp[i][k] << endl;

        }

        return dp[a.size()][K];

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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int K = stringToInteger(line);

        double ret = Solution().largestSumOfAverages(A, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}