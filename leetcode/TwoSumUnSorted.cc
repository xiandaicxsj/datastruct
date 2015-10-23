#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
//two sum 但是不一定是排好序列的
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target) 
{
		map<int,int> indexMap;
		int size=numbers.size();
		for(int i=0;i<size;i++)
			{
					indexMap[numbers[i]]=i;
			}
		map<int,int>::iterator iter;
		int left=0;
		vector<int> res;
		for(int i=0;i<size;i++)
		{
				left=target-i;
				if((iter=indexMap.find(left))!=indexMap.end())
				{
						int index1=indexMap[i];
						int index2=indexMap[left];
						if(index1>index2)
						{
								res.push_back(index2);
								res.push_back(index1);
						}
						else
						{
								res.push_back(index1);
								res.push_back(index2);
						}

						}
								
				}
		return res;
}
int main()
{
	vector<int> s;
	int n;
	int t;
	cin>>n;
	while(n)
	{
		cin>>t;
		s.push_back(t);
		n--;
	}	
	int ta;
	cin>>ta;
	vector<int> tv=twoSum(s,ta);
	vector<int>::iterator iter=tv.begin();
	for(;iter<tv.end();iter++)
	{
			cout<<*iter<<endl;
	}
	return 0;
}
