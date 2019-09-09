/*
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
TEST PASSED
not AC
think of where to put dp[][]? and the size of 
*/
/* dynamic */
#include<string>
#include<iostream>
using namespace std;

int dp[200][200] = {0};
class Solution {
public:
    bool isMatch(string s, string p) {

	int i = 0;
	int j = 0;

	dp[0][0] = 1;
	if (!s.length()) {
		if (!p.length())
			return true;
		else {
			for (i = 0; i<p.length(); i++)
				if (p[i] !='*')
					return false;
			return true;
		}
	}

	if (!p.length())
		return false;

	dp[0][0] = 1;
	for (i = 0; i <= s.length() ; i++)
 		for (j = 1; j <= p.length() ; j++) {

			if (i == 0) {
				if (j == 1 && p[0] =='*')
					dp[0][j] = 1;
				continue;
			} 
			
			if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
				dp[i][j] = dp[i-1][j-1];
				continue;
			}
			if (p[j - 1] == '*')
				dp[i][j] = (i >= 1 ? (dp[i][j-1] | dp[i-1][j-1] | dp[i-1][j]) : dp[i][j-1]);
	}

#if 0
	for (i = 1; i <= s.length() ; i++)
 		for (j = 1; j <= p.length() ; j++) {
			cout <<i<<" "<<j<<" "<<dp[i][j]<<endl;
	}
#endif
	
	if(dp[s.length()][p.length()] == 1)
		return true;
	return false;
    }
};

int main()
{
	class Solution s1;
	string s;
	string n;

	cin>>s;
	cin>>n;

	if (s1.isMatch(s,n))
		cout<<"true"<<endl;
	else 
		cout<<"false"<<endl;
	return 0;
}
