#include<iostream>
#include<vector>
using namespace std;
#define MAX 0xffffffff
int contain(int x)
{
		int num=0;
		while(x)
		{
			x&=(x-1);
			num++;
		}
		return num;
}
void del(int i,int zeroNum,int oneNum)
{
	vector<int> oVec;
	for(int j=0;j<zeroNum+oneNum;j++)
	{
			if((i&1)==1)
				oVec.push_back(1);
			else
				oVec.push_back(0);
			i=i>>1;
	}
	vector<int>::reverse_iterator iter=oVec.rbegin();
	for(;iter!=oVec.rend();iter++)
	{
			cout<<*iter;
	}
	cout<<endl;
	
		
}
int main()
{
	int testNum=0;
	int zeroNum=0;
	int oneNum=0;
	int index;
	cin>>testNum;
	vector<int>resData;
	for(int i=0;i<testNum;i++)
	{
			cin>>zeroNum;
			cin>>oneNum;
			cin>>index;
			int count=0;
			int oCount;
			for(int j=0;j<MAX;j++)
			{	
				oCount=contain(j);
				if(oCount>oneNum)
				{
					cout<<"Impossible"<<endl;
					break;
				}
				if(oCount==oneNum)
				{
						count++;
						if(count==index)
						{
								del(j,oneNum,zeroNum);
								break;
						}
				}
			}

	}

}

