//这个程序好像是有点问题,没有进行深入得测试问题
#include<iostream>
#include<vector>
using namespace std;
int Find(vector<int> vec_int)
{
		vector<int>vecLeftmax(vec_int.size(),0);
		vector<int>vecRightmax(vec_int.size(),vec_int.size()-1);
		cout<<vecLeftmax.size()<<endl;
		cout<<vecRightmax.size()<<endl;
		int max=0;	
		for(int i=1;i<vec_int.size();i++)
		{
				vecLeftmax[i]=max;
				if(vec_int[i]>vec_int[max])
				{
						max=i;
				}
		}
		max=vec_int.size()-1;
		for(int i=vec_int.size()-1;i>=0;i--)
		{
				vecRightmax[i]=max;
				if(vec_int[i]>vec_int[max])
				{
						max=i;
				}
		}
		cout<<vecLeftmax.size();
		for(auto k:vecLeftmax)
		{
				cout<<k<<"--";
				cout<<endl;
		}
		for( auto l: vecRightmax)
		{
				cout<<l<<"--";
				cout<<endl;
		}
		int sum=0;
		int tmp=0;
		for(int i=1;i<vec_int.size()-1;i++)
		{
				tmp=vecRightmax[i]>vecLeftmax[i]?vecLeftmax[i]:vecRightmax[i];
				if(tmp-vec_int[i]<0)
					continue;
				sum=sum+tmp-vec_int[i];
		}
		return sum;
}
int main()
{
		int tmp=0;
		vector<int> vec_int;
		cin>>tmp;
		while(tmp!=-1)
		{
			vec_int.push_back(tmp);
			cin>>tmp;
		}
		cout<<Find(vec_int);
		return 0;
}
