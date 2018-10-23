/*
Sjpecial binary strings are binary strings with the following two properties:

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

S has length at most MAX_NUM.
S is guaranteed to be a special binary string as defined above.
status: TESTDONE
*/

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX_NUM 30

char* makeLargestSpecial(char* S) {
    
}
char dp[MAX_NUM][MAX_NUM][MAX_NUM];
int linkstr(char *src1, char *src2, char* dest)
{
	int len = strlen(src1);
	int i = 0;
	int j = 0;

	while(i < len) {
		dest[j] = src1[i];
		j++;
		i++;
	}
	len = strlen(src2);
	i = 0;
	while(i < len) {
		dest[j] = src2[i];
		j++;
		i++;
	}
	dest[j] = '\0';
}

int is_zero(char *s)
{
	int i = 0;
	int nr_0 = 0;
	int nr_1 = 0;
	while(i < strlen(s))
	{
		if (s[i] == '0')
			nr_0 ++;
		if (s[i] == '1')
			nr_1 ++;
		i++;
	}

	if(nr_0 == nr_1)
		return 0;
	return 1;
}

char *finds(char *S)
{
	//char *dp;
	int len = strlen(S);
	int i = 0;
	int s = 0;
	int j = 0;
	int max_idx;
	char max[MAX_NUM];
	char tmp[MAX_NUM];

	printf("%s\n", S);
	//dp = (char *)malloc(sizeof(char) * MAX_NUM * len *len);
	for (; i< len; i++)
		for (j = i; j< len; j++)
		{
			strncpy(dp[i][j], &S[i], j - i + 1);
		}

	for (s = 1; s < len; s++) {
		for(i = 0; i + s < len; i++) {
			j = i;

			strncpy(max, dp[i][i+s], s + 1);
			printf("%d-%d max %s s %d\n", i, i+s, max, s); 
			for(; j + 1<= i + s; j++) {

				linkstr(dp[i][j], dp[j+1][i+s], tmp);
				
				printf("----%d--%d %d--%d %s\n", i, j, j+1, i+s, tmp);
				if (strncmp(tmp, max, strlen(max)) > 0)
					strncpy(max, tmp, strlen(max));

				if (S[j] < S[j+1]) {
					if (!is_zero(dp[j+1][i+s]) && !is_zero(dp[i][j])) {
						linkstr(dp[j+1][i+s], dp[i][j], tmp);
						if (strncmp(tmp, max, strlen(max)) > 0)
							strncpy(max, tmp, strlen(max));
						printf("after change ----%d-%d-%d %s max is %s\n", i, j, i+s, tmp, max);
						printf(" %s %s\n", dp[j+1][i+s], dp[i][j]);
					}
				}
			}
			printf("max is %s\n", max);
			strncpy(dp[i][j], max, s + 1);
		}
	}
	printf("%s\n", dp[0][len-1]);
}

int main()
{
	finds("11011000");

}
