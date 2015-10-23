#include<iostream>
using namespace std;
class Solution
{
		public:
				int search(int A[],int n,int target)
				{
						int l=0;
						int r=n-1;
						int mid=0;
						while(l<=r)
						{
							mid=(l+r)/2;
							if(A[mid]==target)
							{
										return mid;
							}
							/*if(A[r]>A[l])
							{
									if(A[mid]>=target)
											r=mid-1;
									else
											l=mid+1;
							}*/
							if(A[mid]>=A[l])//l-mid sorted//这里是很关键的地方
							{
									if(target<A[mid]&&target>=A[l])//这里是关键的地方
											r=mid-1;		
									else
											l=mid+1;
							}
							else//mid -r sorted
							{
									if(target>A[mid]&&target<=A[r])
											l=mid+1;
									else
											r=mid-1;
							}
						}
						return -1;
				}

};
int main()
{
		int a[2]={3,1};
	 	Solution s;	
		int i;
		cin>>i;
		cout<<s.search(a,2,i);
		return 0;
}
