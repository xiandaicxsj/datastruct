/*
3. Longest Substring Without Repeating Characters
Medium

7843

468

Add to List

Share
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
Accepted
1,342,950
Submissions
4,538,213

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(0xff, 0);
        int c = 0;
        int res = INT_MIN;
        int j = 0;

        if (!s.length())
            return 0;
        //cout << s.length() << endl;
        for (int i = 0; i < s.length(); i++) {
            if (!map[s[i]]) {
                c++;
                res = max(c, res);
                map[s[i]] ++;
            }
            else {
                while (s[j] != s[i]) {
                    //j++;
                    map[s[j]]--;
                    c--;
                    j++;
                }
                if (s[j] == s[i])
                    j++;
            }
        }
        res = max(c, res);
        return res;

    }
};
string stringToString(string input) {
    //assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"': result.push_back('\"'); break;
            case '/': result.push_back('/'); break;
            case '\\': result.push_back('\\'); break;
            case 'b': result.push_back('\b'); break;
            case 'f': result.push_back('\f'); break;
            case 'r': result.push_back('\r'); break;
            case 'n': result.push_back('\n'); break;
            case 't': result.push_back('\t'); break;
            default: break;
            }
            i++;
        }
        else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}