#include<iostream>
#include<vector>
#define MAX 10000
//这个题目会出现有很多解的情况
using namespace std;
int array[MAX];
int main()
{
		int n;
		int r;
		cin>>n;
		cin>>r;
		vector<int> vec_int;
		for(int i=0;i<n;i++)
			cin>>array[i];
		int s=array[0];
		int i=1;
		int begin;
		while(i<n)
		{
				while(array[i]<=s+r&&i<n)
						i++;
				begin=array[i-1];
				cout<<begin<<endl;
				vec_int.push_back(i-1);
				while(array[i]<=begin+r&&i<n)
					i++;
				s=array[i];
		}
		/*for(auto i:vec_int)
			cout<<array[i]<<endl;
		*/
}
