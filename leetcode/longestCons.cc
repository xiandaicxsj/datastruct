#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
		public:
	/*	int Find(vector<int> array)
		{
				int max=0;
				int len=array.size();
				vector<int>dp(len,0);		
				dp[0]=1;
				for(int i=1;i<len;i++)
				{
						int tmp=0;
						for(int j=0;j<i;j++)
						{
							if(array[i]>=array[j])
							{	
									dp[i]=dp[j]+1;
									if(dp[i]>tmp)
										tmp=dp[i];
							}
						}
						dp[i]=tmp;
						if(tmp>max)
							max=tmp;
				}
				return max;
		}*/
		int Find(vector<int> array)
		{
				int size=array.size();
				vector<int> g(size,10000);
				vector<int> dp(size,0);
				for(int i=0;i<size;i++)
				{
						int j=lower_bound(g.begin(),g.end(),array[i])-g.begin();
						dp[i]=j+1;//这里个数的问题所以不能这样做的
						g[j]=array[i];//g[j]代表的就是j+1的
				}
				return dp[size-1];
		}
};
int main()
{
		vector<int> vec_int;
		vec_int.push_back(5);
		vec_int.push_back(6);
		vec_int.push_back(7);
		vec_int.push_back(1);
		vec_int.push_back(2);
		vec_int.push_back(4);
		vec_int.push_back(8);
		Solution s;	
		cout<<s.Find(vec_int);
	return 0;
}
