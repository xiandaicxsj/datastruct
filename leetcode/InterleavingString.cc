#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution
{
		public:
			bool isInterleave(string s1,string s2,string s3)
			{
				int m=(int)s1.length();
				int n=(int)s2.length();
				if(m+n!=s3.length())
					return false;
				vector<vector<bool> >bVec(m+1,vector<bool>(n+1,false));
				bVec[0][0]=true;
				for(int i=0;i<=m;i++)
					for(int j=0;j<=n;j++)
					{
							if(i==0&&j==0)
								continue;
							if(j>=1)
							{
								if(bVec[i][j-1]&&s2[j-1]==s3[i+j-1])
									bVec[i][j]=true;
							}
							if(i>=1)
							{
									if(bVec[i-1][j]&&s1[i-1]==s3[i+j-1])
										bVec[i][j]=true;
							}
					}
				return bVec[m][n];
			}

};
int main()
{
		Solution s;
		string s1="aabcc";
		string s2="dbbca";
		string s3="kadbbcbcac";	
		cout<<s.isInterleave(s1,s2,s3);
		return 0;
}
