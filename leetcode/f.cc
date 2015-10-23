#include<iostream>
using namespace std;
class Solution
{
		public:
				int firstMissingPositive(int A[],int n)
				{
						if(n<0||!A)
							return 1;
						int pos;
						int tmp=0;
						for(pos=0;pos<n;)
						{
								if(A[pos]>0&&A[pos]!=pos+1&&A[pos]<n&&A[pos]!=A[A[pos]-1])
								{//A[1]!=ps
										tmp=A[A[pos]-1];
										A[A[pos]-1]=A[pos];
										A[pos]=tmp;
								}
								else pos++;
						}
						int i=0;
						for(i=0;i<n;i++)
							cout<<A[i]<<" ";
						for(i=0;i<n;i++)
							if(A[i]!=i+1)
							{
									return i+1;
							}
						return i+1;
				}
				int KfirstMissingPositive(int A[],int n)
				{
						int sum=0;
						int pN=0;
						int min=1;
						int max=-1;
						for(int i=0;i<n;i++)
							if(A[i]>0)
							{
								if(i>=1)
								{
										if(A[i]==A[i-1])
											continue;
								}
								sum=sum+A[i];
								pN++;
								if(A[i]>max)
									max=A[i];
							}
					if(max==-1)
						return 1;
					if(max-min+1==pN)
					{
							return max+1;
					}
					if(max-min+1>pN)
					{
							return ((min+max)*(max-min+1))/2-sum;
					}
			}
};
int main()
{
		Solution s;
		int a[6]={-1,4,2,1,9,10};
		cout<<s.firstMissingPositive(a,6);
		return 0;
}
