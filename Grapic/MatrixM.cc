#include<iostream>
using namespace std;
#define MAX 1000
float G[MAX][MAX];
float T[MAX][MAX];
void Multip(int size)
{
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
			{
					float tmp=0;
					for(int k=0;k<size;k++)
						tmp=tmp+G[i][k]*G[k][j];
					T[i][j]=tmp;
			}
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
					G[i][j]=T[i][j];
}
int main()
{
		int size;
		cin>>size;
		int i=0;
		int j=0;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
			{	
				cin>>G[i][j];
			}
		cout<<"DDD"<<endl;
		int timers;
		cin>>timers;
		for(i=0;i<timers;i++)
			Multip(size);
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
					cout<<G[i][j]<<" ";
			cout<<endl;
		}
		return 0;

}
