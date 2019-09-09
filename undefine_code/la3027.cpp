//这里是利用的并查集的问题
//
#include<iostream>
using namespace std;
int pa[100000];
int da[100000];
int find_set(int x){
	int tmp=pa[x];
	da[x]+=pa[tmp];
}
int zip(int x)
{
		while(pa[x]!=x)
		{
				da[x]+=da[x];
		}

}
int main()
{
	for(int i=0;i<100000;i++)
		pa[i]=i;
	int num;
	int x;
	int y;
	char ops;
	cout<<"Input the num fo data you find"<<endl;
	cin>>num;
	for (int i=0;i<num;i++)
	{
			cin>>x;
			cin>>y;
			cin>>dst;
			cout>>"Choose I / E"<<endl;
			cin>>ops;
			if (ops=='I')
			{
			if(pa[x]!=x)
			{
				cout<<"dsdss"<<endl;	
			}
			pa[x]=y;
			}
			if(ops=='E')
			{
					cout<<da[x[
			}
	}

}
