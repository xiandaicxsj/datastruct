#include<iostream>
//这个还没用提交的问题
using namespace std;
class Solution
{
		public:
			double findMedianSortedArrays(int A[],int m,int B[],int n)
			{
				int t=m+n;
				if(t&1)
				{
						return (findMedian(A,m,0,B,n,0,t/2)+findMedian(A,m,0,B,n,0,t/2+1))/2;
				}
				else
				{
						return findMedian(A,m,0,B,n,0,t/2);
				}
			}
			int min(int a,int b)
			{
					return a>b?b:a;
			}
			double findMedian(int A[],int m,int aIndex,int B[],int n,int bIndex,int k)
			{
					if(m>n)
						return findMedian(B,n,bIndex,A,m,aIndex,k);
					if(m==0)
						return B[bIndex+k-1];
					if(k==1)
						return min(A[aIndex],B[bIndex]);
					int pa=min(k/2,m);
					int pb=k/2-pa;
					if(A[aIndex+pa-1]<B[bIndex+pb-1])
					{
							return findMedian(A,m-pa,aIndex+pa,B,n,bIndex,k-pa);
					}
					if(A[aIndex+pa-1]<B[bIndex+pb-1])
					{
							return findMedian(A,m,aIndex,B,n-pb,bIndex+pb,k-pb);
					}
					return A[aIndex+pa-1];
			}

};

