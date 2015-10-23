#include<iostream>
using namespace std;
class Solution
{
		public:
			double findMedianSortedArray(int A[],int m,int B[],int n)
			{
					int size=(m+n)/2;
					findM(A,m,B,n,size);
			}
			double findM(int A[],int m,int B[],int n,int size)
			{
					if(A[m/2]<B[n/2])
					{
						findM(A+m/2,m/2,B,n,size-m/2);
					}
					else
						findM(A,m,B+n/2,,size-m/2);
			}
};

