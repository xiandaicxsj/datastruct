#include<iostream>
#include<vector>
using namespace std;
int BinarySearch(vector<int> &int_vec,int target,int b,int e)
{
		cout<<b<<"->"<<e<<endl;
		cout<<target<<endl;
		int mid=0;
		while(b<=e)
		{
				mid=(b+e)/2;
				if(int_vec[mid]==target)
					return mid;
				if(int_vec[mid]<target)
				{
						b=mid+1;
				}
				else
				{
						e=mid-1;
				}
		}
		return -1;
}
int main()
{
	int n;
	vector<int> int_vec;
	cin>>n;
	int i=0;
	int tmp;
	int target;
	while(i<n)
	{
			cin>>tmp;
			int_vec.push_back(tmp);
			i++;
	}
	int size=int_vec.size();
	cin>>target;
	cout<<BinarySearch(int_vec,target,0,size-1);
	return 0;
}
