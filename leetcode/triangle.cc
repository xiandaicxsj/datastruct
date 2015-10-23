#include<iostream>
#include<vector>
using namespace std;
class Solution{

	public:
			int minimumTotal(vector<vector<int> >&triangle)
			{
					int size=triangle.size();
					int **indexArray=(int**)malloc(size*sizeof(int *));
					int **sumArray=(int**)malloc(size*sizeof(int *));
					for(int i=0;i<size;i++)
					{
						sumArray[i]=new int(size);
						indexArray[i]=new int(size);
					}
					for(int i=0;i<size;i++)
						for(int j=0;j<size;j++)
						{
							sumArray[i][j]=0;
							indexArray[i][j]=0;
						}
					int i=size-1;
					int j=0;
					for(i;i>=0;i--)
					{
							if(i==size-1)
							{	
									for(j=0;j<=size-1;j++)
									sumArray[i][j]=triangle[size-1][j];
									continue;
							}
							for(j=0;j<i+1;j++)
							{
									if(sumArray[i+1][j]+triangle[i][j]<sumArray[i+1][j+1]+triangle[i][j])
									{
											sumArray[i][j]=sumArray[i+1][j]+triangle[i][j];
											indexArray[i][j]=j;
									}
									else
									{
											sumArray[i][j]=sumArray[i+1][j+1]+triangle[i][j];
											indexArray[i][j]=j+1;
									}
							}
					}
					cout<<sumArray[0][0]<<endl;
					return 0;
			}
	void SminimumTotal(vector<vector<int> >&triangle)
	{
		int size=triangle.size();
		int *array=new int(size);
		int *tmp=new int(size);
		for(int i=0;i<size;i++)
		{
			array[i]=0;
			tmp[i]=0;
		}
		return;
	}
};
int main()
{
	vector<int>a4;
	a4.push_back(4);
	a4.push_back(1);
	a4.push_back(8);
	a4.push_back(3); 
	vector<int>a3;
	a3.push_back(6);
	a3.push_back(5);
	a3.push_back(7);
	vector<int>a2;
	a2.push_back(3);
	a2.push_back(4);
	vector<int>a1;
	a1.push_back(2);
	vector<vector<int> >s;
	s.push_back(a1);
	s.push_back(a2);
	s.push_back(a3);
	s.push_back(a4);
	Solution s1;
	s1.minimumTotal(s);
	return 0;
}


