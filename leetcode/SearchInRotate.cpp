#include<iostream>
using namespace std;
int transferInt(int rawIndex,int sub,int n)
{
	rawIndex=rawIndex+sub;
	if (rawIndex>=sub-1)	
		rawIndex=rawIndex%n;
	return rawIndex;
}
int search(int array[],int n,int target)
{
		int sub=0;
		while(sub<n-1&&array[sub]<array[sub+1])
			sub++;
		if(sub==n-1)
			sub=0;
		else
		sub=sub+1;//i+sub==??
		int l=0;
		int h=n-1;
		int m;
		int t_m;
		while(l<=h)
		{
				m=(l+h)/2;
				t_m=transferInt(m,sub,n);
				if(array[t_m]>target)
					h=m-1;
				if(array[t_m]<target)
					l=m+1;
				if(array[t_m]==target)
				{
					return t_m;
				}
		}
		return -1;

}
int main()
{
		int b[1]={1};
		cout<<search(b,1,1);
		int a[1]={0};
		cout<<search(a,1,1);
}

