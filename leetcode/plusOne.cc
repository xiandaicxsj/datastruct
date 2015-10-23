#include<iostream>
#include<vector>
using namespace std;
void add(vector<int> &dig,int d)
{
		int carry=d;
		int tmp;
		for(auto i=dig.rbegin();i!=dig.rend();i++)
		{
				*i=*i+carry;
				carry=*i/10;
				*i=(*i)%10;
		}	
		if(carry>0)
			dig.insert(dig.begin(),1);
}

int main()
{
		vector<int> dig;
		dig.push_back(2);
		dig.push_back(3);
		dig.push_back(4);
		add(dig,1);
		for(auto i:dig)
		{
				cout<<i;
		}
		return 0;
}
