#include<iostream>
#include<string>
using namespace std;
class Solution
{
		public:
			string Predel(string s)
			{//这是问题的需要处理有空格的情况，下次在处理吧
			}
			void reverseWords(string &s)
			{
					int len=s.length();
					if(len==1)
						return ;
					if(len==0)
						cout<<"DD"<<endl;
					reverseWord(s,0,len-1);
					int begin=0;
					int found=s.find(" ",begin);
					while(found!=string::npos)
					{
							reverseWord(s,begin,found-1);
							begin=found+1;
							found=s.find(" ",begin);
					}
					reverseWord(s,begin,len-1);
			}
			void reverseWord(string& s,int begin,int end)
			{
					int i=begin;
					char tmp;
					while(begin<end)
					{
							tmp=s[begin];
							s[begin]=s[end];
							s[end]=tmp;
							begin++;
							end--;
					}
			}
};
int main()
{
		string s=" ";
		Solution s1;
		s1.reverseWords(s);
		cout<<s;


}
