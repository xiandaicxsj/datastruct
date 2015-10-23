#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution
{
		public:
			int longestConsecutive(const vector<int> &num)
			{
					map<int,bool> uFlag;
					int size=num.size();
					if(size==0)
							return -1;
					if(size==1)
							return 1;
					int value;
					int tl=0;
					int maxl=0;
					for(int i=0;i<size;i++)
					{
							if(uFlag.find(num[i])!=uFlag.end())
							{
								continue;
							}
							uFlag.insert(pair<int,bool>(num[i],false));
						}
					for(int i=0;i<size;i++)
					{
							if(uFlag[num[i]])
									continue;
							tl=1;
							value=num[i]+1;
							while(uFlag.find(value)!=uFlag.end())
							{
								uFlag[value]=true;
								tl++;	
								value++;
							}
							value=num[i]-1;
							while(uFlag.find(value)!=uFlag.end())
							{
								uFlag[value]=true;
								tl++;	
								value--;
							}
							if(tl>maxl)
								maxl=tl;
					}
					return maxl;
			}
};
int main()
{
		vector<int> int_v;
		Solution s;
		cout<<s.longestConsecutive(int_v);
		return 0;
}

