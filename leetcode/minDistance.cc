#include<iostream>
#include<vector>

using namespace std;
class Solution{
	public:
			int min(int a,int b,int c)
			{
					int min=a;
					if(min>b)
						min=b;
					if(min>c)
						min=c;
					return min;
			}
			int minDistance(string word1,string word2)
			{
					int m=word1.length();
					int n=word2.length();
					vector<vector<int> >dis(m+1,vector<int>(n+1,0));
					for(int i=0;i<n+1;i++)
						dis[0][i]=i;
					for(int i=0;i<m+1;i++)
						dis[i][0]=i;
					for(int i=1;i<m+1;i++)
						for(int j=1;j<n+1;j++)
						{
								if(word1[i-1]==word2[j-1])
								{
									dis[i][j]=dis[i-1][j-1];
								}
								else
									dis[i][j]=min(dis[i-1][j],dis[i][j-1],dis[i-1][j-1])+1;
						}
					return dis[m][n];
			}
};
int main()
{
	string a1;
	string a2;
	cin>>a1;
	cin>>a2;
	Solution s;
	cout<<s.minDistance(a1,a2);
	return 0;
}

