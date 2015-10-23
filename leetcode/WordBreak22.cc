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
						vector<vector<int> > path(size);
						dp[0]=true;
						for(int i=0;i<=size;i++)
						{
								if(dp[i])
								for(int len=1;i+len-1<=size;len++)
								{
										if(dict.count(s.substr(i,len))>0)
										{
												path[i+len].push_back(i-1);
												dp[i+len]=true;
										}
								}
						}
						int end=size-1;
						vector<string> resStr;
						vector<string> tmpStr;
						GetPath(s,path,end,tmpStr,resStr);
						return resStr;
				}
				vector<string> GetPath(string s,vector<vector<int> >path,int end,vector<string>&res,vector<string>&fres)
				{//下面得的距离
						if(end==0)
						for(auto sumPath:path[end])
						{

						}
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
