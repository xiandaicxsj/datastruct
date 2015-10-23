#include<iostream>
#include<vector>
using namespace std;
//这里实在是不想写了。。。。
class Solution
{
		public:
			int minCut(string s)
			{
				int len=s.length();
				vector<int> dp(len+1,0);//i-len minCut
				vector<int> pre(len+1,0);//位于的
				dp[len]=0;
				pre[len]=-1;
				for(int i=len-1;i>=0;i--)
				{
						if(pre[i+1]==-1)
						{
								pre[i]=i;
								dp[len]=1;
								continue;
						}
						dp[i]=dp[i+1]+1;
						pre[i]=i;
						if(pre[i+1]<len&&s[i]==s[pre[i+1]])
						{
								if(pre[i+1]>=len-1)
								{
									pre[i]=len-1;
									dp[i]=1;
								}
								else
								{
									if(dp[pre[i+1]+1]+1<dp[i])
									{
											if(pre[i+1]+1==len-1)
												dp[i]=1;
											else
											dp[i]=dp[pre[i+1]+1]+1;
											pre[i]=pre[i+1]+1;
									}
								}
						}
				}
				for(auto s:dp)
					cout<<s<<" ";
				return dp[0];
			}

};
int main()
{
	Solution s;
	string s1;
	cin>>s1;
	cout<<s.minCut(s1);
	return 0;
}
