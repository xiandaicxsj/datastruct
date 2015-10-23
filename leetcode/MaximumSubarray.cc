#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	int maxSubArray(int A[],int n)
	{
			if(n==1)
				return A[1];
			vector<int> sum(n);
			sum[0]=A[0];
			int max=A[0];
			for(int i=1;i<n;i++)
			{
					sum[i]=A[i];
					if(sum[i-1]+A[i]>sum[i])
						sum[i]=sum[i-1]+A[i];
					if(sum[i]>max)
					max=sum[i];
			}
			for(auto i:sum)
				cout<<i<<" ";
			cout<<endl;
			return max;
	}
};
int main()
{
	int Array[1000];
	int size;
	cin>>size;
	for(int i=0;i<size;i++)
	cin>>Array[i];
	Solution s;
cout<<s.maxSubArray(Array,size);
}
