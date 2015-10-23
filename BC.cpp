#include<iostream>
using namespace std;
int array[100][100];
int main()
{
	int m;
	int n;
	cin>>m;
	cin>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>array[i][j];
	return 0;

}

