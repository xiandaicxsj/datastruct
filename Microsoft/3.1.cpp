 /*
 *其实对于这个题目找规律是很重要的 ,发现规律后在查找就会很方便了
 *
 *
 *
 *
 *
 * 
 * /
#include<iostream>
using namespace std;
string Expand(string s1)
{
		int len=s1.length();
		for(int i=0;i<len;i++)
		{
				s1+=s1[i];
				
		}
		return s1;

}
int main()
{
		string s1="ABCD";
		string s2="CDAB";
		string s3=Expand(s1);
		if(s3.find(s2))
		{
				cout<<"True"<<endl;
		}
}
