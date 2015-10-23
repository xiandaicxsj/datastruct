#include<iostream>
using namespace std;
//有没有更好得方法
class Solution
{
		public:
			bool canJump(int A[],int n)
			{
					bool *reach=new bool[n];
					for(int i=0;i<n;i++)
						reach[i]=false;
					reach[0]=true;
					for(int i=1;i<n;i++)
						for(int j=0;j<i;j++)
						{
								if(reach[j]&&j+A[j]>=i)
								{	
									reach[i]=true;
									break;
								}
						}
					return reach[n-1];
			}
};
int main()
{
	
	Solution s;
//	int a[5]={2,3,1,1,4};
	int a[5]={3,2,1,0,4};
	cout<<s.canJump(a,5);
	return 0;
}
