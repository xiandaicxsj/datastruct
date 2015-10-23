#include<iostream>
#include<vector>
//最长公共子穿
using namespace std;
class Solution
{
		public:
		string find(string s,string t)
		{
				int m=s.length();
				int n=t.length();
				vector<vector<int> > dp(m+1,vector<int>(n+1,0));

				int begin=0;
				int end=0;
				int max=0;
				for(int i=1;i<m+1;i++)
					for(int j=1;j<n+1;j++)
					{
							if(s[i-1]==t[j-1]&&dp[i-1][j-1])
							{
									dp[i][j]=dp[i-1][j-1];
									if(max<i-dp[i][j])
									{
											max=i-dp[i][j];
											begin=dp[i][j];
											end=i-1;
									}
							}
							if(s[i-1]==t[j-1])
							{
									dp[i][j]=i-1;
							}
					}
				cout<<begin<<" "<<end<<endl;
				cout<<s[begin]<<" "<<s[end]<<endl;
				return  s.substr(begin,end-begin+1);
		}
};
int main()
{
		string s1;
		string s2;
		cin>>s1;
		cin>>s2;
		Solution s;
		cout<<s.find(s1,s2);
		return 0;
}
