/*
 h1003
Problem des:

Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.

Input:

The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).

Output:
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.

Sample input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5

Sample output
Case 1:
14 1 4

Case 2:
7 1 6

Status:
ACKED
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100000];
int dp[100000];
int b[100000];
int main()
{
	int n;
	int num;
	int idx;
	int max_sum;
	int max_idx;
	int i=0;
	
	scanf("%d", &n);
	while(i < n) {
		scanf("%d", &num);
		max_sum = 0;
		idx = 0;
		while(idx < num) {
			scanf("%d", &a[idx]);
			dp[idx] = a[idx];
			b[idx] = idx;
			idx ++;
		}
		max_sum = dp[0];
		max_idx = 0;
		idx = 1;
		while(idx < num) {
			if (dp[idx -1] >= 0) {
				dp[idx] = dp[idx - 1] + a[idx];
				b[idx] = b[idx -1];
			}
			if (dp[idx] > max_sum) {
				max_sum = dp[idx];
				max_idx = idx;
			}
			idx ++;
		}
		printf("Case %d:\n", i + 1);
		printf("%d %d %d\n", max_sum, b[max_idx] + 1, max_idx + 1);  		    //printf("\n");
		if (i != n-1)
			printf("\n");
		i++;
	}
	return 0;
}
