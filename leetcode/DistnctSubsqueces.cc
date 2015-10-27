#include<iostream>
#include<vector>
using namespace std;
class Solution
{
		public:
			int numDistrinct(string s,string t)
			{
					int slen=s.length();
					int tlen=t.length();
					vector<vector<int> >dp(slen+1,vector<int>(tlen+1,0));
					for(int i=0;i<=slen;i++)
						dp[i][0]=1;
					for(int i=1;i<=slen;i++)
						for(int j=1;j<=tlen;j++)
						{
							dp[i][j]=dp[i-1][j];
							if(s[i-1]==t[j-1])
								dp[i][j]+=dp[i-1][j-1];
						}
					return dp[slen][tlen];
			}

};
int main()
{
	string s1="rabbbit";
	string s2="rabbit";
	Solution s3;
	cout<<s3.numDistrinct(s1,s2);
	
	return 0;
}
