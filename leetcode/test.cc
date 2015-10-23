#include<iostream>
#include<vector>
#include<string>
#define MAX 1000
int Array[MAX][MAX];
using namespace std;
int main()
{
		string a;
		string b;
		for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
				Array[i][j]=0;
		for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
			{
					if(a[i]==b[j])
					{
						if(i==0)
							Array[i][j]=1;
						if(j==0)
							Array[i][j]=1;
					}
			}
		return 0;
}
