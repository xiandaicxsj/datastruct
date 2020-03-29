/*
1283. Find the Smallest Divisor Given a Threshold
Medium

99

30

Add to List

Share
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.



Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).
Example 2:

Input: nums = [2,3,5,7,11], threshold = 11
Output: 3
Example 3:

Input: nums = [19], threshold = 5
Output: 4


Constraints:

1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6

*/
class Solution {
public:
    int get_th(vector<int> nums, int d)
    {
        int res = 0;
        for (auto num : nums) {
            res += (num + d - 1) / d;
        }

        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l;
        int h;
        int m = 0;
        int t = 0;

        sort(nums.begin(), nums.end());
        l = 1;
        h = nums[nums.size() - 1];
        if (l == h)
            return get_th(nums, threshold);
        while (l <= h)
        {
            m = (l + h) / 2;
            t = get_th(nums, m);
            if (t > threshold)
                l = m + 1;
            else if (t <= threshold)
                h = m - 1;
            //   if (h < k)
              //     k = h;

          // if (t == threshold)
            //   return m;
        }
        //cout << l;
        return l;

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
        int threshold = stringToInteger(line);

        int ret = Solution().smallestDivisor(nums, threshold);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}