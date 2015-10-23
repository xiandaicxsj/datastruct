#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution
{
		public:
			int largestRetangkeArea(vector<int> &height)
			{
				stack<int> indexStack;
				stack<int> numStack;
				int max=0;
				for(int i=0;i<height.size();i++)
				{
						if(numStack.empty())
						{
								indexStack.push(i);
								numStack.push(height[i]);
								continue;
						}
						int top=numStack.top();
						if(height[i]>=top)
						{
								indexStack.push(i);
								numStack.push(height[i]);
								continue;
						}
						while(height[i]<top&&!numStack.empty())
						{
								top=numStack.top();
								int tmp=top*(i-indexStack.top());
								max=max>tmp?max:tmp;
								indexStack.pop();
								numStack.pop();
						}
						if(numStack.empty())
						{
								int tmp=height[i]*(i+1);
								max=max>tmp?max:tmp;
						}
						indexStack.push(i);
						numStack.push(height[i]);
				}
				while(!numStack.empty())
				{
						int top=numStack.top();
						int tmp=top*(height.size()-indexStack.top());
						max=max>tmp?max:tmp;
						indexStack.pop();
						numStack.pop();
				}
				return max;
			}

};
int main()
{
	vector<int>height;
	int size;
	cin>>size;
	int tmp;
	for(int i=0;i<size;i++)
	{
		cin>>tmp;
		height.push_back(tmp);
	}
	Solution s;
	cout<<s.largestRetangkeArea(height);
	return 0;
}

