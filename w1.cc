#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
		int testC;
		scanf("%d",&testC);
		int i=0;
		while(i<testC)
		{
				int len;
				cin>>len;
				string tmp;
				cin>>tmp;
				int count=0;
				char tChar;
				int j=0;
				tChar=tmp[j];
				int tCount=1;
				j++;
				while(j<len)
				{
						if(tChar!=tmp[j])
						{
								if(tmp[j]!=tChar+1)
								{
									cout<<"NO"<<endl;
									break;
								}
								if(count==0)
									count=tCount;
								else
									if(count!=tCount)
									{
										cout<<"NO"<<endl;
										break;
									}
								tCount=1;
								tChar=tmp[j];
						}
						else
						{
								tCount++;
						}
						j++;
				}
				cout<<"YES"<<endl;
				i++;
		}
	return 0;
}
