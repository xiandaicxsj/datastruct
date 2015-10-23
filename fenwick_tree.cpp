#include<iostream>
using namespace std;
//这里代表的是树形数组的相应的操作。在取得sum[0-i]的时间复杂度为lgN
#define MAX 100
int c[MAX];
int s[MAX];
int array[MAX];
int LowBit(int x)
{
		return x&(-x);
}
int GetSumEnd(int x)
{
		int n=x;
		int ret=0;
		while(n>0)
		{
				ret+=c[n];
				n=n-LowBit(n);
		}
		return ret;
}
int GetPeriodSum(int x)
{
	int ret=0;
	int n=x-LowBit(x)+1;
	while(n<=x)
	{
		ret+=array[n];
		n++;
	}
		return ret;
}
void Add(int index,int x)
{
	//这里怎么确定是
	int i=index;
	while(i<MAX)
	{
			c[i]+=x;
			i=i+LowBit(i);
	}
}
int main()
{
		int array_size=16;
		for(int i=1;i<=array_size;i++)
		{
			array[i]=i;
			c[i]=0;
			s[i]=0;
		}
		for(int i=1;i<=array_size;i++)
		{
				c[i]=GetPeriodSum(i);
		}

		Add(3,1);
		cout<<GetSumEnd(4);
		return 0;
}

	
