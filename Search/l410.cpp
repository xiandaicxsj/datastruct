/*
410. Split Array Largest Sum
Hard

1334

75

Add to List

Share
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Accepted
72,901
Submissions
167,449


 */


class Solution {
public:
    bool check_sum(vector<int>& nums, int m, int n)
    {

        /*
        int i = 0;
        int target = 0;
        int base = 0;
        while (n) {
            //int t_i = i;
            target = base + m;
            i = lower_bound(sums.begin() + i, sums.end(), target) - sums.begin();
            if (i == sums.size()) {
                if (n == 1)
                    return true;
                else
                    return false;
            }
            if (i == 0)
                return false;

            if (sums[i] - base != m)
                i--;
            if (i == sums.size() - 1) {
                if (n == 1)
                    return true;
            }


            base = sums[i];
            n--;
        }
        return false;
        */
        //int num;
        long long sum = 0;
        int count = 0;
        int i = 0;

        /* 这里最大的问题是如何证明下面这种方法取得是有效的，这个方法是用的贪心法。需要看下如何证明贪心法是最优的
           也就是如果这种方法是无法满足的，是否可以保证一定没有其他的选择法是正确的。
        */

        for (i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum > m)
            {
                sum = nums[i];
                count++;
                if (sum > m)
                    return false;
                if (count > n)
                    return false;
                if (count == n && i != nums.size() - 1)
                    return false;
                if (i == nums.size() - 1) {
                    if (sum > m)
                        return false;
                    else
                    {
                        count++;
                        if (count > n)
                            return false;
                    }
                }
            }
        }
        return true;


    }
    int splitArray(vector<int>& nums, int m) {




        int i = 0;
        long long l;
        long long h;
        long long mid;
        long long sum = 0;

        for (i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        l = 0;
        h = sum;
        while (l < h) {
            mid = (h + l) / 2;

            if (check_sum(nums, mid, m))
                h = mid;
            else
                l = mid + 1;

        }
        return l;

    }

    long get_max(long x, long y)
    {

        if (x == LLONG_MAX)
            return y;
        if (y == LLONG_MAX)
            return x;
        return x > y ? x : y;
    }

    long get_min(long x, long y) {
        return x > y ? y : x;

    }
    int splitArrayDP(vector<int>& nums, int m) {

        vector<vector<long long>> dp(m + 1, vector<long long>(nums.size() + 1, LLONG_MAX));

        int i = 0;
        int j = 0;
        int n = nums.size();
        int k = 0;
        vector<long long> sums(n + 1, 0);

        sums[0] = 0;
        for (i = 1; i <= n; i++) {
            cout << sums[i] << endl;
            sums[i] = sums[i - 1] + (long long)nums[i - 1];
            dp[1][i] = sums[i];
            cout << sums[i] << endl;
        }

        for (i = 1; i <= m; i++) {
            for (j = i; j <= n; j++) {
                for (k = i - 1; k < j; k++) {

                    if (i == 1)
                        dp[i][j] = sums[j] - sums[0];
                    else
                        dp[i][j] = get_min(get_max(dp[i - 1][k], sums[j] - sums[k]), dp[i][j]);

                }
#ifdef DEBUG
                cout << "caculate dp[" << i << "]" << "[" << j << "]:" << dp[i][j] << " ";
#endif
            }
        }

        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                cout << "dp[" << i << "]" << "[" << j << "]:" << dp[i][j] << " ";
            }
            cout << endl;
        }


        return dp[m][n];

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
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);

        int ret = Solution().splitArrayDP(nums, m);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
