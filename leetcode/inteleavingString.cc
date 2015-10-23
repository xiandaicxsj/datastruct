#include<iostream>
#include<string>
#include<stack>
class item
{
	public:
	item(int _i,int _j,int _k):i(_i),j(_j),k(_k)
	{

	}
	int i;
	int j;
	int k;
};
using namespace std;
bool IsInterleave(string s1,string s2,string s3)
{
	stack<item> s;	
	int i=0;
	int j=0;
	int s1Len=s1.length();
	int s2Len=s2.length();
	int k=0;
	int f=0;
	while((i<s1Len&&j<s2Len)||s.empty()==false)
	{
			if(i==s1Len)
			{
					while(j<s2Len)
					{
							if(s3[k]!=s2[j])
							{
									f=1;
									break;
							}
							k++;
							j++;
					}
					if(f)
						goto l;
					return true;
			}	
			if(j==s2Len)
			{
					while(j<s1Len)
					{
							if(s3[k]!=s1[j])
							{
									
								f=1;
								break;
							}
							k++;
							j++;
					}
					if(f)
						goto l;
					return true;
			}
l:
			if(f||(s1[i]!=s3[k]&&s2[j]!=s3[k]))
			{//就这里有问题了
					item it=s.top();
					s.pop();
					f=0;
					i=it.i;
					j=it.j;
					k=it.k;
			}
			if(s1[i]==s3[k]&&s2[j]==s3[k])
			{
					s.push(item(i,j+1,k+1));
					i++;
					k++;
					continue;
			}
			if(s1[i]==s3[k])
			{
					i++;
					k++;
					continue;
			}
			if(s2[j]==s3[k])
			{
					j++;
					k++;
					continue;
			}
	}
	f=0;
		if(i==s1Len)
			{
					while(j<s2Len)
					{
							if(s3[k]!=s2[j])
							{
									return false;
							}
							k++;
							j++;
					}
					return true;
			}	
			if(j==s2Len)
			{
					while(j<s1Len)
					{
							if(s3[k]!=s1[j])
							{	
									return false;
							}
							k++;
							j++;
					}
					return true;
				}
	//这里在需要和上面的判断是是一样的
	return 0;
}
int main()
{

	string s1("aabcc");
	string s2("dbbca");
	string s3("aadbbbaccc");
	//string s3("aadbbcbcac");
	//string s1("abc");
	//string s2("afcg");
	//string s3("aafbccg");
	cout<<IsInterleave(s1,s2,s3);
	return 0;
}
