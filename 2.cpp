#include<iostream>
using namespace std;
int compare(int *buffer,int b1,int b2,int len)
{
		for(int i=0;i<len;i++)
		{
				if(buffer[b1+i]!=buffer[b2+i])
						return 0;
		}
		return 1;

}
int main()
{
		int n;
        cin>>n;
		int buffer[300];
		int len=n/2;
		for(int i=0;i<n;i++)
		{
				cin>>buffer[i];
		}
		while(len>0)
		{
				int f_b=0;
				int s_b=0;
				for(f_b=0;f_b<n;f_b++)
				{
						s_b=f_b+len;
						while(s_b+len-1<n)
						{
							if(compare(buffer,f_b,s_b,len)==1)
							{
								cout<<len;
								return 0;
							}
							s_b++;
						}
				}
				len--;
		}
		cout<<0;
		return 0;

}
