/*
424. Longest Repeating Character Replacement
Medium

956

64

Add to List

Share
Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.

In one operation, you can choose any character of the string and change it to any other uppercase English character.

Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.


Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.


Accepted
52,469
Submissions
115,463
Seen this question in a real interview before?

Yes

No

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(100, 0);
        int ret = 0;
        int i = 0;
        int b = 0;
        int e = 0;
        int t_k = k;
        if (!s.length())
            return 0;
        while (true) {
            while (e < s.length() && s[e] == s[b]) {
                count[s[e] - 'A']++;
                e++;
            }
            while (e < s.length() && t_k && s[e] != s[b]) {
                count[s[e] - 'A']++;
                e++;
                t_k--;
            }

            while (e < s.length() && s[e] == s[b]) {
                count[s[e] - 'A']++;
                e++;
            }
            if (!t_k || e == s.length()) {
                count[s[b] - 'A']--;
                ret = max(ret, min(e - b + t_k, (int)s.length()));
                b++;
                if (e == s.length())
                    break;
                do {
                    t_k = (e - b) - count[s[b] - 'A'];
                    if (t_k <= k) {
                        t_k = k - t_k;
                        break;
                    }
                    count[s[b] - 'A']--;
                    b++;
                } while (t_k > k&& e > b);
                //    goto 
            }

        }
        return ret;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().characterReplacement(s, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
