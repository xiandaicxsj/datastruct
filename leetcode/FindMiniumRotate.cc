#include<vector>
#include<iostream>
using namespace std;
/*class Solution
{
		public:
				int findMin(vector<int> &num)
				{
						int begin=0;
						int end=num.size()-1;
						int mid=0;
						while(begin<end)
						{
								mid=(begin+end)/2;
								if(num[mid]>=num[begin])
								{
										if(num[mid]>num[end])
										{
												begin=mid+1;
										}
										else
										{
												end=mid-1;
										}
								}
								else
								if(num[mid]<num[begin])
								{
										end=mid;
								}
						}
						return num[begin];
				}

};*/
/*class Solution
{
		public:
			int findMin( vector<int>&num)
			{
					int begin=0;
					int end=num.size()-1;
					int mid=0;
					while(begin<end)
					{
						if(num[begin]<num[end])
							break;
						mid=(begin+end)/2;
						if(num[mid]>num[end])
						{
								begin=mid+1;
						}
						else
							end=mid;
					}
					return num[begin];
			}


};*/
/*下面的这个解法还是有点问题的*/
class Solution
{
		public:
		int findMin(vector<int> &num)
		{
				int begin=0;
				int end=num.size()-1;
				int mid=0;
				while(begin<end)
				{
						if(num[begin]<num[end])
							break;
						mid=(begin+end)/2;
						if(num[mid]<num[begin])
						{
								begin=mid+1;
						}
						else
							end=mid;
				}
				return num[begin];
		}
};
int main()
{
	Solution s;
	vector<int> vec_int;
	int size;
	int tmp;
	cin>>size;
	for(int i=0;i<size;i++)
	{
			cin>>tmp;
			vec_int.push_back(tmp);
	}
	cout<<s.findMin(vec_int);
}
