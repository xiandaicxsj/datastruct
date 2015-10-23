#include<iostream>
#include<string>
//下面的程序是没问题的，但是有个问题就是需要看下别人如何写的这个程序，感觉有点特别复杂了
using namespace std;
class Solution {
	public:
		    void reverseWords(string &s)
				{
					cout<<s<<endl;
					string::iterator begin=s.begin();		
					string::iterator end1=s.end();
					reverseWord(s,begin,end1-1);
					string::iterator end=s.begin();
					while(end<s.end()&&begin<s.end())
					{
						while(*end!=' '&&end<s.end())
						{
									end++;
						}
						reverseWord(s,begin,end-1);
						end++;	
						begin=end;
					}
					cout<<s;
			  }//this not del with the blank
				void reverseWord(string &word,string::iterator begin,string::iterator end)
				{
					char tmp;
					while(begin<=end)
					{
						tmp=*begin;
						*begin=*end;
						*end=tmp;	
						begin++;
						end--;
					}
				}
};
int main()
{
	Solution s;
	string str1("blue sky ");
 	s.reverseWords(str1);
	return 0;
		
		
}
