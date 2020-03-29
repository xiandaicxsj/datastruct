/*
992. Subarrays with K Different Integers
Hard

682

13

Add to List

Share
Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.



Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].


Note:

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length
Accepted
19,139
Submissions
41,265
Seen this question in a real interview before?

Yes

No

*/

class Solution {
public:
    /* TIME LIMITED */
    int subarraysWithKDistinct3(vector<int>& a, int k) {
        map<int, int> m;
        int i = 0;
        int b = 0;
        int c = 0;
        int j = 0;
        //int k = 0;

        for (i = 0; i < a.size(); i++)
        {
            m.clear();
            for (j = i; j < a.size(); j++) {
                auto miter = m.find(a[j]);
                if (miter == m.end()) {
                    if (m.size() < k) {
                        m[a[j]] = 1;
                        if (m.size() == k)
                            c++;
                        continue;
                    }
                    else
                    {
                        break;
                    }

                }
                else {
                    m[a[j]]++;
                    if (m.size() == k)
                        c++;
                }
            }
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& a, int k) {
        vector<int> m(a.size() + 2, 0);

        int j = 0;
        int i = 0;
        int c = 0;
        int prefix = 0;
        int res = 0;
        for (i = 0; i < a.size(); i++)
        {
            if (!m[a[i]]) {
                c++;
            }
            m[a[i]]++;

            if (c == k + 1) {
                m[a[j]]--;
                _ASSERT(!m[a[j]]);
                j++;
                prefix = 0;
                c--;

            }

            if (c == k) {
                while (m[a[j]] > 1) {
                    m[a[j]]--;
                    prefix++;
                    j++;
                }
                res = res + prefix + 1;
            }
        }
        return res;
    }
    int subarraysWithKDistinct2(vector<int>& a, int k) {
        map<int, int> m;
        int i = 0;
        int b = 0;
        int c = 0;

        for (i = 0; i < a.size(); i++)
        {
            auto miter = m.find(a[i]);
            if (miter == m.end()) {
                if (m.size() < k) {
                    m[a[i]] = 1;
                    if (m.size() == k)
                        c++;
                }
                else {

                    while (m.size() != k - 1) {
                        m[a[b]]--;
                        if (!m[a[b]])
                            m.erase(a[b]);
                        b++;
                        if (m.size() == k)
                            c++;
                    }
                    m[a[i]] = 1;
                    c++;
                }
            }
            else {
                miter->second++;
                c++;
            }
        }

        while (b < a.size()) {
            if (m.size() < k)
                break;
            m[a[b]]--;
            if (!m[a[b]])
                m.erase(a[b]);
            b++;
            if (m.size() == k)
                c++;
        }
        return c;

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

        int ret = Solution().subarraysWithKDistinct(A, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}