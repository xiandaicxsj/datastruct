#include<iostream>
#include<vector>
using namespace std;
//最大的字符串匹配工作
class Solution
{
		public:
			int longestValidParentheses(string s)
			{
					int size=s.length();
					vector<int> dp(size+1,0);
					dp[size]=0;
					int max=0;
					for(int i=size-1;i>=0;i--)
					{
							if(s[i]=='(')
							{
									/*for(int j=i+1;j<=size-1;j++)
									{
											if(s[j]==')'&&!dp[j])
											{
												dp[i]=dp[j+1]+2;
												break;
											}
									}*/
									int j=i+dp[i+1];
									for(j;j<=size-1;j++)
									{
											if(s[j]==')')
											{
													dp[i]=dp[i+1]+2;
													dp[i]+=dp[j+1];
													break;
											}
									}
							}
							if(dp[i]>max)
								max=dp[i];
					}
					return max;
			}
			
};
int main()
{
	string s;
	cin>>s;
	Solution s1;
	cout<<s1.longestValidParentheses(s);
	return 0;
}

