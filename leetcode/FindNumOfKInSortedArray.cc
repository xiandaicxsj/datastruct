#include<iostream>
using namespace std;
//寻找有序数组中得某个数得个数
//
//
class Solution
{
	public:
	int find(int *A,int n,int t)
	{
			int fOrder=findFirst(A,n,t);
			int SOrder=findSecond(A,n,t);
			return SOrder-fOrder;
	}
	int findFirst(int *A,int n,int t)
	{
			int l=0;
			int r=n;
			int mid=0;
			while(l<=r)
			{
					mid=(l+r)/2;
					if(A[mid]==t)
					{
						if((mid>0&&A[mid-1]!=t)||mid==0)
								return mid;
						return r=mid-1;
					}
					if(A[mid]>t)
						l=mid+1;
					if(A[mid]<t)
						r=mid-1;
			}
	}
	int findSecond(int *A,int n,int t)
	{
			int l=0;
			int r=n;
			int mid=0;
			while(l<=r)
			{
					mid=(l+r)/2;
					if(A[mid]==t)
					{
						if((mid<n-1&&A[mid+1]!=t)||mid==n-1)
								return mid;
						l=mid+1;
					}
					if(A[mid]>t)
						l=mid+1;
					if(A[mid]<t)
						r=mid-1;
			}
	}
};
int main()
{
	Solution s;
	int a[5]={1,2,2,2,3};
	cout<<s.find(a,5,2);	
	return 0;
}
