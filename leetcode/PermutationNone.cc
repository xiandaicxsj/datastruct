#include<iostream>
using namespace std;
class Solution
{
		public:
				string getPermutation(int n,int k)
				{
						string s(n,'0');
						int j=1; 
						for(int i=1;i<=n;i++)
						{	
							j*=i;
							s[i-1]+=i;
						}
						int index=0;
						int m=0;
						char tmp;
						k--;
						for(int i=0;i<n;i++)
						{
								if(k==0)
										return s;
								j/=(n-i);
								index=k/j;
								tmp=s[i+index];
								m=i+index;
								for(;m>i;m--)
										s[m]=s[m-1];
								s[i]=tmp;
								k%=j;
						}
						return s;
				}
};
int main()
{
		Solution s;
		cout<<s.getPermutation(3,4);
		return 0;
}
