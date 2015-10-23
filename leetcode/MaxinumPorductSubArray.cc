#include<iostream>
using namespace std;
class Solution
{
		public:
				int MAXV(int a,int b,int c)
				{
						int max=a;
						if(b>max)
							max=b;
						if(c>max)
							max=c;
						return max;
				}
				int MINV(int a,int b,int c)
				{
						int min=a;
						if(b<min)
							min=b;
						if(c<min)
							min=c;
						return min;


				}
				int maxProduct(int A[],int n)
				{
					int Resmax;
					int *maxA=new int[n];
					int *minA=new int[n];
					maxA[0]=A[0];
					minA[0]=A[0];
					Resmax=A[0];
					int max;
					int min;
					for(int i=1;i<n;i++)
					{
							maxA[i]=MAXV(maxA[i-1]*A[i],minA[i-1]*A[i],A[i]);
							minA[i]=MINV(maxA[i-1]*A[i],minA[i-1]*A[i],A[i]);
							if(Resmax<maxA[i])
								Resmax=maxA[i];
					}
					cout<<Resmax;
				}

};
int main()
{
		int Array[4]={2,3,-2,4};
		Solution s;
		s.maxProduct(Array,4);
}
