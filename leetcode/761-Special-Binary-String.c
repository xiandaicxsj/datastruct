/*
Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings of S, and swapping them. (Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.)

At the end of any number of moves, what is the lexicographically largest resulting string possible?

Example 1:
Input: S = "11011000"
Output: "11100100"
Explanation:
The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
Note:

S has length at most 50.
S is guaranteed to be a special binary string as defined above.
*/
























char* makeLargestSpecial(char* S) {
    
}

































































long long str_to_num(char *S, int s1, int e1, int s2, int e2)
{

}

char *finds(char *S)
{
	long long *dp;
	int len = strlen(S);
	int i = 0;
	int s = 0;
	int j = 0;

	dp = malloc(sizeof(*dp) * len *len);
	for (; i< len * len; i++)
		dp[i] = 0; 

	for (s = 1; s < len; s++) {
		for(i = 0; i + s < len; i++) {
			j = i;
			for(; j < i + s; j++) {
				max = MAX(max, str_to_num(dp[i][j], dp[j+1][i+s])) 
			}
			dp[i][j] = max;
		}
	}


}

int main()
{

}
