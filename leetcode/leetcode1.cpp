#include<iostream>
#include<string>
using namespace std;
class Solution {
	public:
		    void reverseWords(string &s)
				{
						string retStr;
						string tmpStr;
						reverseWord(s);
						int begin=0;
						int end=s.find(" ",begin); 
						do
						{
								tmpStr=s.substr(s,begin,end);
								reverseWord(tmpStr);
								if(retStr.length()==0)
										retStr=retStr+tmpStr;
								else
										retStr=retStr+" "+tmpStr;
								begin=end+1;
								if(end==(s.length()-1))
								{
										break;
								}
								end=s.find(" ",begin);		
								if(end==-1)
								{
										end=s.length()-1;
										continue;
								}
						}while(1);
						cout<<retStr<<endl;
						cout<<s<<endl;
					        
			  }//this not del with the blank
				void reverseWord(string &word)
				{
					char tmp;
					string::iterator begin_iter=word.begin();
					string::iterator end_iter=word.end();
					end_iter--;//del '/0'
					while(begin_iter<=end_iter)
					{
						tmp=*begin_iter;
						*begin_iter=*end_iter;
						*end_iter=tmp;	
						begin_iter++;
						end_iter--;
					}
				}
};
int main()
{
	Solution s;
	string str1("blue sky");
 	s.reverseWords(str1);
	return 0;
		
		
}
