#include<iostream>
#include<vector>
using namespace std;
//下面是回溯的方法
/*class Solution{
	public:
		bool isMatch(const char *s,const char *p)
		{
				
				return Match(p,0,s,0);
		}
		bool Match(const char *s,int sIndex,const char *p,int pIndex)
		{
				bool f=false;
				if(p[pIndex]=='\0'&&s[sIndex]=='\0')
					return true;
				else
					if(!(p[pIndex]!='\0'&&s[sIndex]!='\0'))
						return false;
				if(s[sIndex]==p[pIndex])
						f=f|Match(s,sIndex+1,p,pIndex+1);
				else
				{
						if(s[sIndex]=='.')
						{
							f=f|Match(s,sIndex+1,p,pIndex+1);
						}
						if(s[sIndex]=='*')
						{
								int i=-1;
								do{
										i++;
										f=f|Match(s,sIndex+1,p,pIndex+i);
									}while(p[pIndex+i]!='\0');
						}
						f=f|Match(s,sIndex+1,p,pIndex);
				}
				return f;
		}
};*/
class Solution
{
		public:
			bool isMatch(const char *s,const char *p)
			{
					int m=0;
					while(s[m]!='\0')
						m++;
					int n=0;
					while(p[n]!='\0')
						n++;
					vector<vector<bool> > f(n+1,vector<bool>(m+1,false));
					int sIndex=1;
					int pIndex=1;
					f[0][0]=true;
					for(pIndex=1;pIndex<n+1;pIndex++)
						for(sIndex=1;sIndex<m+1;sIndex++)
						{
								if(s[sIndex-1]==p[pIndex-1]&&f[pIndex-1][sIndex-1])
									f[pIndex][sIndex]=true;
								else
								{
										if(p[pIndex-1]=='*')
										{
												for(int j=sIndex;j<m+1;j++)
												{
														if(pIndex==1)
															f[pIndex][j]=true&&f[pIndex-1][0];
														else
														f[pIndex][j]=true&&f[pIndex-1][sIndex-1];
												}
												continue;
										}
										else
										if(p[pIndex-1]=='?')
										{
												f[pIndex][sIndex]=true&&f[pIndex-1][sIndex-1];
										}
										//f[sIndex][pIndex]=true;//这里是处理的开头是
								}
									
						}
					return f[n][m];
			}
};

int main()
{
	Solution s;
	string s1;
	string s2;
	cin>>s1;
	cin>>s2;
	cout<<s.isMatch(s1.c_str(),s2.c_str());
	return 0;
}
