#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>
using namespace std;
class Node
{
		public:
		Node(int _x=0,int _y=0,int _value=0):x(_x),y(_y),value(_value)
		{
		}
		int x;
		int y;
		int value;
};
struct CmpMin{
	bool operator ()(Node &x,Node &y)
	{
			return x.value>y.value;
	}
};
Node array[100][100];
vector<Node> vecArray[100];
int lineIndex[100];
int compare(const Node &x,const Node &y)
{
		
		/*if((*(Node *)x).value<(*(Node *)y).value)
			return -1;
		if((*(Node *)x).value==(*(Node *)y).value)
			return 0;
		if((*(Node *)x).value<(*(Node *)y).value)
			return 1;
			*/
	return x.value<y.value;
}
bool fitNode(deque<Node>&finalQue,Node tmpNode,int m,int n,int&count)
{
		
}
bool fitNode(deque<Node>&finalQue,Node tmpNode,int m,int n,int&count)
{
	deque<Node>::iterator d_iter=finalQue.begin();
		int x_f=0;
		int y_f=0;
		if(n>m)
		{
				for(;d_iter<finalQue.end();d_iter++)
				{
						if((*d_iter).y==tmpNode.y)
								return 0;
						if((*d_iter).x==tmpNode.x)
									x_f=1;
				}
				if(x_f==0)
					return 1;
				if(count>0&&x_f==1)
				{
						count--;
						return 1;
				}
				return 0;
		}
		else
		{
				for(;d_iter<finalQue.end();d_iter++)
				{
						if((*d_iter).x==tmpNode.x)
								return 0;
						if((*d_iter).y==tmpNode.y)
									y_f=1;
				}
				if(y_f==0)
					return 1;
				if(count>0&&y_f==1)
				{
						count--;
						return 1;
				}
				return 0;
		}
}
int abs(int m)
{
		return m>0?m:-m;
}
int findMax(int m,int n)
{
		int max=m>n?m:n;
		int num=0;
		int count=abs(m-n);
		priority_queue<Node,vector<Node>,CmpMin> priQue;
		deque<Node> finalQue;
		for(int i=0;i<m;i++)
		{
			priQue.push(array[i][0]);
		}
		while(num<max)
		{
				Node minNode=priQue.top();
				priQue.pop();
				if(fitNode(finalQue,minNode,m,n,count))
				{
						finalQue.push_back(minNode);
						num++;
				}
				lineIndex[minNode.x]++;
				if(lineIndex[minNode.x]==n)
				{
						continue;
				}
				priQue.push(array[minNode.x][lineIndex[minNode.x]]);
		}
		int sum=0;	
		deque<Node>::iterator iterNode=finalQue.begin();
		for(;iterNode<finalQue.end();iterNode++)
		{
				cout<<(*iterNode).x<<" ";
				cout<<(*iterNode).y<<" ";
				cout<<(*iterNode).value<<endl;
				sum+=(*iterNode).value;
		}
		return sum;
}
int main() {
	int m;
	int n;
	int i=0;
	int j=0;
	int _value;
	cin>>m;
	cin>>n;
	for(i=0;i<m;i++)
		{
			lineIndex[i]=0;
			for(j=0;j<n;j++)
			{
					cin>>_value;
					vecArray[i].push_back(Node(i,j,_value));
			}
		}
	for(i=0;i<m;i++)
	{
			j=0;
			sort(vecArray[i].begin(),vecArray[i].end(),compare); 
			vector<Node>::iterator n_iter=vecArray[i].begin();
			for(;n_iter<vecArray[i].end();n_iter++)
			{
					array[i][j]=*n_iter;
					j++;
			}
	}
	int res=findMax(m,n);
	cout<<res;
}

