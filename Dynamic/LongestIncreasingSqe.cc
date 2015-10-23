#include<iostream>
using namespace std; 
int FindLongest(int *array,int len);
int main()
{
	int *array=new int[6];
	array[0]=1;
	array[1]=6;
	array[2]=2;
	array[3]=5;
	array[4]=4;
	array[5]=7;
	int len=6;
	FindLongest(array,len);
	return 0;
}
#define INF 0
int FindLongest(int *array,int len)
{
		int i=0;
		int j=0;
		int max=0;
		int index=0;
		int *d=new int[len];
		int *pre=new int[len];
		int *visited=new int[len];
		for(i=0;i<len;i++)
		{
			d[i]=0;
			pre[i]=-1;
			visited[i]=1;
		}
		d[0]=1;
		pre[0]=0;
		for(i=1;i<len;i++)
		{
					max=0;
					index=-1;
			for(j=0;j<i;j++)
			{
					if(d[j]>max&&array[i]>array[j]&&(visited[j]==1))
					{
							max=d[j];
							index=j;
					}
			}
			d[i]=max+1;
			pre[i]=index;
			visited[i]=1;
			visited[index]=0;
		}
		for(i=0;i<len;i++)
			cout<<d[i]<<" ";
		return 0;

}
