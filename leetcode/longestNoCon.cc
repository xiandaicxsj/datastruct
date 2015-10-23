#include<iostream>
#include<vector>
//最长子序列
using namespace std;
class Solution
{
		public:
		int find(string s,string t)
		{
				int m=s.length();
				int n=t.length();
				vector<vector<int> > dp(m+1,vector<int>(n+1,0));
				for(int i=0;i<m+1;i++)
					dp[i][0]=0;
				for(int i=0;i<n+1;i++)
					dp[0][i]=0;
				dp[0][0]=0;
				for(int i=1;i<m+1;i++)
					for(int j=1;j<n+1;j++)
					{
							if(s[i-1]==t[j-1])
							{
									dp[i][j]=dp[i-1][j-1]+1;
							}
							else
							{
									dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
							}
					}
				return dp[m][n];
		}

};
int main()
{
	string s1;
	string s2;
	Solution s;
	cin>>s1;
	cin>>s2;
	cout<<s.find(s1,s2);
	return 0;

}
