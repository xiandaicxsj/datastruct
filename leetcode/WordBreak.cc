#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;
class Solution
{
		public:
				bool wordBreak(string s,unordered_set<string> &dict)
				{
						int size=s.length();
						vector<bool> dp(size+1,false);
						dp[0]=true;
						for(int i=0;i<=size;i++)
						{
								if(dp[i])
								for(int len=1;i+len-1<=size;len++)
								{
										if(dict.count(s.substr(i,len))>0)
												dp[i+len]=true;
								}
						}
						return dp[size];
				}
};
int main()
{
	Solution s;
	string s1="a";
	unordered_set<string> us;
	cout<<s.wordBreak(s1,us);
	return 0;
}
