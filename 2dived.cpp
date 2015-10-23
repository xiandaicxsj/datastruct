#include<iostream>
using namespace std;
int array[100];
void BinarySearch(int i,int size)
{
	int l=0;
	int h=size-1;
	int m=0;
	while(l<=h)
	{
			m=(l+h)/2;
			if(array[m]<i)
					l=m+1;
			else if(array[m]>i)		
					h=m-1;
			else
			{
					cout<<m<<endl;
					break;
			}

	}
	
}

int main()
{
	for(int i=0;i<100;i++)
		array[i]=0;
	for(int i=0;i<5;i++)
	{
		array[i]=i;
	}
	BinarySearch(4,5);
}
