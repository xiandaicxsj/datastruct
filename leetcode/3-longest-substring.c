/* Given a string, find the length of the longest substring without repeating characters.

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
*/

/* status: AC */

#include<stdio.h>
int lengthOfLongestSubstring(char* s) {
	int a[255];
	int i = 0;
	int j = 0;
	int max = 0;
	int p;
	int c = 0;
	int min_p = -1;
	for(j = 0; j< 255; j++) 
		a[j] = -1;

	while(s[i] != '\0')
	{
		p = a[s[i]];
		if (p < min_p)
			p = min_p;
		c = 0;
		for (j = 0; j< 255 ; j++) {
			if(a[j] > p && a[j] < i)
				c++;
		}

		if (c + 1 > max)
			max = c + 1;
		a[s[i]] = i;
		min_p = p;
		i++;
	}    
	return max;
}


int main()
{
	char k[123];
	scanf("%s", k);
	printf("%d\n", lengthOfLongestSubstring(k));
	return 0;
}

