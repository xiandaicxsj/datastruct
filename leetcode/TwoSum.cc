#include<vector>
#include<iostream>
#include<algorithm>
//two sum 但是不一定是排好序列的
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target) 
{
		vector<int>tmp;//这里的复制是一个问题
		vector<int>::iterator iter=numbers.begin();	
		for(;iter<numbers.end();iter++)
		{
				tmp.push_back(*iter);
		}
		sort(numbers.begin(),numbers.end());
		int size=numbers.size();
		int begin=-1;
		int end=-1;
		int i=0;
		while(numbers[i]<target/2)
		{
						i++;
		}
		begin=i-1;
		i=0;
		while(numbers[i]<target)
		{
						i++;
		}
		end=i-1;
		while(begin)
		{
				end=begin+1;
				while(numbers[begin]+numbers[end]<target)
				{
						end++;
				}
				if(numbers[begin]+numbers[end]==target)
				{
					break;
				}
				end--;//
				begin--;
		}
		int s=numbers[begin];
		int y=numbers[end];
		vector<int> res;
		i=0;  
		while(i<size)
		{
				if(tmp[i]==s ||tmp[i]==y)
						res.push_back(i+1);
				i++;
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
