/*
   287. Find the Duplicate Number
       Medium

       3513

       438

       Add to List

       Share
       Given an array nums containing n + 1 integers where each integer is between 1 and n(inclusive), prove that at least one duplicate number must exist.Assume that there is only one duplicate number, find the duplicate one.

       Example 1:

Input: [1, 3, 4, 2, 2]
Output : 2
Example 2 :

    Input : [3, 1, 3, 4, 2]
    Output : 3
    Note :

    You must not modify the array(assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be repeated more than once.

    */
class Solution {
public:
    /* wrong [1,1,3,4,5]*/
    int volid_count(vector<int> nums, int m) {
        int c = 0;
        for (auto num : nums)
            if (num <= m)
                c++;
        return c;
    }
    /* wrong */
    int volid_sum(vector<int> nums, int m) {
        int c = 0;
        int sum = 0;
        int low = 0;
        for (auto num : nums)
            if (num <= m) {
                low = num > low ? num : low;
                sum += num;
            }
        /* no if lower part not all accupy like [7,9,7,4,2,8,7,7,1,5] */
        if ((1 + low) * low / 2 == sum)
            return 1;
        return 0;
    }
    int findDuplicateBS(vector<int>& nums) {
        //sort(nums.begin(), nums.end());

        int l = 0;
        int h = nums.size();
        int m = 0;

        while (l < h) {
            m = (l + h) / 2;

            //i = lower_bound(nums.begin(), nums.end(), m) - nums.begin();
            //if (volid_count(nums, m) <= m)
            if (volid_sum(nums, m))
                l = m + 1;
            else
                h = m;
        }
        return l;

    }

    int findDuplicate(vector<int>& nums) {
        //sort(nums.begin(), nums.end());

        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        slow = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            if (slow == fast)
                break;
        }
        return slow;

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

        int ret = Solution().findDuplicate(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}