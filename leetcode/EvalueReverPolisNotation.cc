#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution
{
		public:
			int evalRPB(vector<string> &tokens)
			{
					stack<int> s_int;
					int arg1=0;
					int arg2=0;
					for(auto s:tokens)
					{
							if(s=="*")
							{
									arg1=s_int.top();
									s_int.pop();
									arg2=s_int.top();
									s_int.pop();
									s_int.push(arg1*arg2);
									continue;
							}
							if(s=="/")
							{
									arg1=s_int.top();
									s_int.pop();
									arg2=s_int.top();
									s_int.pop();
									s_int.push(arg2/arg1);
									continue;
							}
							if(s=="+")
							{
									arg1=s_int.top();
									s_int.pop();
									arg2=s_int.top();
									s_int.pop();
									s_int.push(arg2+arg1);
									continue;
							}
							if(s=="-")
							{
									arg1=s_int.top();
									s_int.pop();
									arg2=s_int.top();
									s_int.pop();
									s_int.push(arg2-arg1);
									continue;
							}
							s_int.push(atoi(s.c_str()));
					}
					return s_int.top();
			}
};
