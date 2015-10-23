#include<iostream>
using namespace std;
#define MAX 100000
int array[MAX][MAX];
int shorDist[MAX][MAX];//valaue代表的是下一个node
int CaclueShortDistance(int nodeNum)
{
		
}
int main()
{
		int nodeNum;
		cin>>nodeNum;
		int x;
		int y;
		int value;
		for(int i=0;i<nodeNum;i++)
		{
			cin>>x;
			cin>>y;
			cin>>value;
			array[x][y]=value;
		}
		CaclueShortDistance(nodeNum);
		return 0;
}


