#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 100
class Solution
{
		public:
			int table[MAXSIZE][MAXSIZE];
			bool isInterleave(string s1,string s2,string s3)
			{
					if(s1.size()+s2.size()!=s3.size())
					return false;
					int size=s1.size();
					int i=0;
					int j=0;
					int f=0;
					for(;i<s1.size();i++)
						for(j=0;j<s2.size();j++)
								table[i][j]=false;
					for(i=0;i<size;i++)
					{
							if(s1[i]==s3[i])
							{
								if(i==0)
									{	
											table[i+1][0]=true;
											continue;
									}
								if(table[i][0])
									table[i+1][0]=true;
							}
					}
					size=s2.size();
					for(i=0;i<size;i++)
					{
							if(s2[i]==s3[i])
							{
								if(i==0)
									{	
											table[0][i+1]=true;
											continue;
									}
								if(table[0][i])
									table[0][i+1]=true;
							}	
					}
					i=0;
					j=0;
					table[0][0]=true;
					for(i=1;i<=s1.size();i++)
						for(j=1;j<=s2.size();j++)
						{
								if(table[i-1][j])
								{
										if(s1[i-1]==s3[i+j-1])
										{
												
											table[i][j]=true;
										}
								}
								if(table[i][j-1])
								{
										if(s2[j-1]==s3[i+j-1])
										{
											table[i][j]=true;
										}
								}
						}
						return table[s1.size()][s2.size()];
	}
};
int main()
{
	string s1("aabcc");
	string s2("dbbca");
	string s3("aabbdbccca");
	//string s3("aadbbcbcac");
	Solution s;
	cout<<s.isInterleave(s1,s2,s3);
	return 0;
}
