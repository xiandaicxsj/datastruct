#include<iostream>
#include<vector>
using namespace std;
class Solution
{ 
	public:
		int minPathSum(vector<vector<int> >&grid)
		{
				int m=grid.size();
				int n=grid[0].size();
				int sum=0;
				vector<vector<int> > sumPath(m,vector<int>(n,0));
				sum=0;
				for(int i=0;i<m;i++)
				{
					sum=sum+grid[i][0];
					sumPath[i][0]=sum;
				}
				sum=0;
				for(int i=0;i<n;i++)
				{
					sum=sum+grid[0][i];
					sumPath[0][i]=sum;
				}	
				for(int i=1;i<m;i++)
					for(int j=1;j<n;j++)
					{
							int tmp=sumPath[i-1][j]>sumPath[i][j-1]?sumPath[i][j-1]:sumPath[i-1][j];
							sumPath[i][j]=tmp+grid[i][j];
					}
				return sumPath[m-1][n-1];
				
		}
};
