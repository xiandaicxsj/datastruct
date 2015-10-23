// 主要是针对的字符串的hash
//
//
//
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
const int N=16000005;
#define MAXALP  256
int M[MAXALP]={0};
bool Hash[N]={false};
char str[1000000];
int main()
{
		int n;
		int nc;
		int seed=1;
		memset(Hash,false,sizeof(Hash));
		memset(M,0,sizeof(M));
		cin>>n>>nc;
		scanf("%s",str);
		int len=0;
		while(str[len]!='\0')
				len++;
		int i=0;
		int j=0;
		for(i=0;i<len;i++)
		{
				M[str[i]]=seed++;
		}
		int ans=0;
		int sum=0;
		for(i=0;i<len-n;i++)
		{
			sum=0;
			for(j=i;j<i+n-1;j++)
			{
					sum=sum*nc+M[str[i]];
			}
			if(!Hash[sum])
			{
					ans++;
			}
		}
		cout<<ans;
	return 0;
}
