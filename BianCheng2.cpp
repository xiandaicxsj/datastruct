#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
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
int s[101][101];
Node array[101][101];
vector<Node> vecArray[101];
int lineIndex[101];
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
		
bool fitNode(deque<Node>&finalQue,Node tmpNode,int m,int n)
{
	deque<Node>::iterator d_iter=finalQue.begin();
		for(;d_iter<finalQue.end();d_iter++)
				{
						if((*d_iter).y==tmpNode.y)
								return 0;
						if((*d_iter).x==tmpNode.x)
								return 0;
				}
		return 1;
}
int abs(int m)
{
		return m>0?m:-m;
}
int findMax(int m,int n)//m>n
{
		int min=n;
		int max=m;
		int *flag=new int[max];
		for(int i=0;i<max;i++)
			flag[i]=0;
		int num=0;
		int count=abs(m-n);
		priority_queue<Node,vector<Node>,CmpMin> priQue;
		deque<Node> finalQue;
		for(int i=0;i<m;i++)
		{
			priQue.push(array[i][0]);
		}
		while(num<min)
		{
				Node minNode=priQue.top();
				priQue.pop();
				if(fitNode(finalQue,minNode,m,n))
				{
						flag[minNode.x]=1;
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
				sum+=(*iterNode).value;
		}
		for(int i=0;i<max;i++)
		{
			if(flag[i]==0)
			{
					sum+=array[i][0].value;
			}
		}
		return sum;
}
int main() {
	int m;
	int n;
	int i=0;
	int j=0;
	int _value;
	int test_case;
	vector<int>resVec;
	cin>>test_case;
	int t_index=0;
	while(t_index<test_case)
	{
	cin>>m;
	cin>>n;
	int min=m>n?n:m;
	int max=m>n?m:n;
	for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
					cin>>_value;
					if(m>=n)
						s[i][j]=_value;
					else
						s[j][i]=_value;
			}
		}
	m=max;
	n=min;
	for(i=0;i<m;i++)
	{
			lineIndex[i]=0;
			for(j=0;j<n;j++)
				vecArray[i].push_back(Node(i,j,s[i][j]));
	}

	for(i=0;i<m;i++)
	{
			lineIndex[i]=0;
			j=0;
			sort(vecArray[i].begin(),vecArray[i].end(),compare); 
			vector<Node>::iterator n_iter=vecArray[i].begin();
			for(;n_iter<vecArray[i].end();n_iter++)
			{
					array[i][j]=*n_iter;
					j++;
			}
		vecArray[i].clear();
	}
	int res=findMax(m,n);
	resVec.push_back(res);
		t_index++;
}
vector<int>::iterator r_iter=resVec.begin();
int t=1;
for(;r_iter!=resVec.end();r_iter++)
{
		cout<<"Case ";
		cout<<t<<": ";
		cout<<*r_iter<<endl;
}
    return 0;
}

