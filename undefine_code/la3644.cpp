//这里是利用的并查集的问题
//
#include<iostream>
using namespace std;
int pa[100000];
int find_set(int x){
	return x==pa[x]?x:find_set(pa[x]);
}
int main()
{
	for(int i=0;i<100000;i++)
		pa[i]=i;
	int num;
	int x;
	int y;
	cout<<"Input the num fo data you find"<<endl;
	cin>>num;
	for (int i=0;i<num;i++)
	{
			cin>>x;
			cin>>y;
			if(find_set(x)==find_set(y))
			{
					cout<<"no"<<endl;
					continue;
			}
			pa[x]=y;
	}

}
