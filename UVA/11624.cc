#include<iostream>
using namespace std;
#include<queue>
class Node {
	public: 
	Node(int _r,int _c,int _step)
	{
			r=_r;
			c=_c;
			step=_step;
	}
	int r;
	int c;
	int step;
};
queue<Node> qNode;
#define MAXNUM 1000
int G[MAXNUM][MAXNUM]={MAXNUM+1};
void CalFire(int r,int c,int rLimit,int cLimit,int time,int flag)//进行扩展得函数
{
		if(r>=rLimit)
				return;
		if(r<0)
				return;
		if(c>=cLimit)
				return ;
		if(c<0)
				return ;
		if(G[r][c]==-1)
			return ;
		if(flag)
		{
				G[r][c]=time;
				CalFire(r+1,c,rLimit,cLimit,time+1,false);
				CalFire(r-1,c,rLimit,cLimit,time+1,false);
				CalFire(r,c+1,rLimit,cLimit,time+1,false);
				CalFire(r,c-1,rLimit,cLimit,time+1,false);
		}
		else
		{
			if(G[r][c]>time)
			{
				G[r][c]=time;
				CalFire(r+1,c,rLimit,cLimit,time+1,false);
				CalFire(r-1,c,rLimit,cLimit,time+1,false);
				CalFire(r,c+1,rLimit,cLimit,time+1,false);
				CalFire(r,c-1,rLimit,cLimit,time+1,false);
			}
			return ;
		}
}
bool FindFireBase(int r,int c,int& rF,int &cF)
{
		int j=0;
		int i=0;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
			{
					if(G[i][j]==-2)
					{
							rF=i;
							cF=j;
							return true;
					}
			}
		return false;
}
int main()
{
	int testCase;
	int r;
	int c;
	int i;
	int j;
	int rJ=0;
	int cJ=0;
	cin>>testCase;
	while(testCase>0)
	{
		cin>>r;
		cin>>c;
		char tmpC;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
			{
				G[i][j]=MAXNUM;
			}
		for( i=0;i<r;i++)
			for( j=0;j<c;j++)
			{
				cin>>tmpC;
				if(tmpC=='#')
					G[i][j]=-1;
				if(tmpC=='J')
				{
						rJ=i;
						cJ=j;
				}
				if(tmpC=='F')
					G[i][j]=-2;
			}
		int rF;
		int cF;
		while(FindFireBase(r,c,rF,cF))
		{
			 CalFire(rF,cF,r,c,0,true);//这里直接利用全局变量
		}
		int step=-1;
		qNode.push(Node(rJ,cJ,0));
		while(!qNode.empty())
		{
				Node tmp=qNode.front();
				if(tmp.step==0)
				{
						qNode.push(Node(tmp.r,tmp.c+1,tmp.step+1));
						qNode.push(Node(tmp.r,tmp.c-1,tmp.step+1));
						qNode.push(Node(tmp.r+1,tmp.c,tmp.step+1));
						qNode.push(Node(tmp.r-1,tmp.c,tmp.step+1));
						qNode.pop();
						continue;
				}
				if(G[tmp.r][tmp.c]==-1)
				{
					qNode.pop();
					continue;
				}
				if(G[tmp.r][tmp.c]<=tmp.step)
				{
					qNode.pop();
					continue;
				}
				if(G[tmp.r][tmp.c]>tmp.step)
				{
						
						if(tmp.r==r-1||tmp.c==c-1)
						{	
							step=tmp.step;
							break;
						}
						qNode.push(Node(tmp.r,tmp.c+1,tmp.step+1));
						qNode.push(Node(tmp.r,tmp.c-1,tmp.step+1));
						qNode.push(Node(tmp.r+1,tmp.c,tmp.step+1));
						qNode.push(Node(tmp.r-1,tmp.c,tmp.step+1));
						qNode.pop();
				}
		}
		if(step==-1)
		{
				cout<<"IMPOSSIBLE"<<endl;
		}	
		else
		{
			cout<<step+1<<endl;
		}
		testCase--;
	}				
	return 0;
}
