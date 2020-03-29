/*
 1300. Sum of Mutated Array Closest to Target
Medium

123

16

Add to List

Share
Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.



Example 1:

Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
Example 2:

Input: arr = [2,3,5], target = 10
Output: 5
Example 3:

Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361


Constraints:

1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5
Accepted
5,216
Submissions
11,368
Seen this question in a real interview before?

Yes

No
Contributor
LeetCode
AC

*/
class Solution {
public:

    int value(vector<int>& arr, int t)
    {
        int v = 0;
        for (auto a : arr)
            if (a > t)
                v += t;
            else
                v += a;
        return v;
    }
    int findBestValue_method2(vector<int>& arr, int target) {
#define MAX(a,b) (a > b ? a: b)
#define MIN(a,b) (a < b ? a: b)
        int l = 0;
        int h = 0;
        int max = INT_MIN;
        for (auto a : arr) {
            max = MAX(a, max);
        }
        h = max;
        int d = INT_MAX;
        int m = 0;
        int v = 0;
        int res = 0;
        while (l <= h)
        {
            m = (l + h) / 2;
            v = value(arr, m);
            if (v > target)
                h = m - 1;
            else if (v < target)
                l = m + 1;
            if (abs(v - target) <= d)
            {

                if (abs(v - target) == d)
                    res = MIN(res, m);
                else

                    res = m;
                d = abs(v - target);
            }
            if (v == target)
                return m;
        }
        return res;

    }
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int i = 0;
        int n = arr.size();
        for (i = 0; i < n; i++) {
            if ((arr[i] * (n - i)) < target)
                target -= arr[i];
            else
                break;
        }
        /* 怎么确定 abs(arr[i] * (n - i) - target) 和 abs(target/ (n - i) * (n - i) - target) 的大小的*/
        //return i == n ? arr[n - 1] : (int(round((target - 0.0001) / (n - i))));
        return i == n ? arr[n - 1] : (int((target - 0.0001 + (n - i) / 2.0) / (n - i)));
        //下面这个写法是对的
        /* 例如 7/3 = 2.33 最后要选择的是，2 * 3， 也就是返回 2*/
        /* 例如 8/3 = 2.66 最后要选择的是 3*3 而不是 2*3，返回3 */
        /* target + (n-i)/2.0 - 0.01  (n-i)/2.0 相当于最后的结果加了 0.5 */
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
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().findBestValue(arr, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}