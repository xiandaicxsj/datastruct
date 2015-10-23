#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
//这个回溯版本的
class Solution
{
		public:
			vector<string> wordBreak(string s,unordered_set<string> &dict)
			{
					int length=s.length();
					vector<vector<bool> > flag(length,vector<bool>(length,false));
					vector<string> res;
					vector<string> fres;
					wordBreak2(s,0,length-1,dict,res,fres,flag);
					return fres;
			}
			void wordBreak2(string s,int begin,int end,unordered_set<string>&dict,vector<string> &res,vector<string> &fres,vector<vector<bool> > &flag)
			{
					if(begin>end)
					{
							string tmp;
							for(auto str:res)
								tmp+=str+" ";
							fres.push_back(tmp);
							return ;
					}
					int i=0;
					int len=0;
					string subStr;
					for(i=begin,len=1;i+len<=end+1;len++)
					{
							subStr=s.substr(i,len);
							if(dict.count(subStr)>0)
							{
									res.push_back(subStr);
									wordBreak2(s,begin+len,end,dict,res,fres,flag);
									res.pop_back();
							}
					}

			}
		
};
int main()
{
		Solution s;
		string s1="catsanddog";
		unordered_set<string>  dict;
		dict.insert("cat");
		dict.insert("cats");
		dict.insert("and");
		dict.insert("sand");
		dict.insert("dog");
		vector<string> res=s.wordBreak(s1,dict);
		for (auto str:res)
			cout<<str<<endl;
}
