#include<iostream>
using namespace std;
class Solution
{
		public:
				string getPermutation(int n,int k)
				{
						long long ss=1;
						for(int i=0;i<n;i++)
								ss*=n;
						if(k>ss)
								return "";
						string s="";
						for(int i=1;i<=n;i++)
								s=s+char(i+'0');
						Permutation(s,0,n-1,k);
						return g;
				}
				string g;
				bool Permutation(string s,int p,int n,int &k)
				{
						if(p==n)
						{
								k--;
								if(k==0)
								{
										g=s;
										return true;
								}
								return false;
						}
						char tmp;
						int i=p;
						for(i=p;i<=n;i++)
						{
								tmp=s[i];
								s[i]=s[p];
								s[p]=tmp;
								if(Permutation(s,p+1,n,k))
										return true;
								tmp=s[i];
								s[i]=s[p];
								s[p]=tmp;
						}
				}
};
int main()
{
		Solution s;
		cout<<s.getPermutation(3,5);
		return 0;
}
