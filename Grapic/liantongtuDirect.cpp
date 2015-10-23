#include<iostream>
#include<stack>
#define MAX 100
//tragan算法用于求有向图的联通分量
using namespace std;
int DG[MAX][MAX];
int b[MAX];
int f[MAX];
int low[MAX];
int pre[MAX];
int G[MAX][MAX];
int G_T[MAX][MAX];
int v_num=0;
stack<int> i_stack;
void Tragan(int u,int size);
void Kosaraju(int size );
void init()
{
		int j=0;
		for(int i=0;i<MAX;i++)
		{
				b[i]=-1;
				f[i]=-1;
				pre[i]=-1;
				low[i]=-1;
				for(j=0;j<MAX;j++)
				{
						G[i][j]=-1;
				}
		}

}
int main()
{
	int size=4;
	init();
	/*G[0][1]=1;
	G[1][0]=1;
	G[1][2]=1;
	G[2][3]=1;
	G[3][2]=1;*/
	cin>>size;
	for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
			{
					cin>>G[i][j];
			}
			
	Kosaraju(size);
	/*Tragan(0,size);*/
	return 0;
}
/*Test case 
 * 6
 * -1 1 -1 -1 -1 -1
 *  -1 -1 1 -1 -1 1
 *  1 -1 -1 1 -1 -1
 *  -1 -1 -1 -1 1 -1
 *  -1 -1 -1 1 -1 -1
 *  -1 -1 1 -1 -1 -1
 *  -1 1 -1 -1 -1 -1 
 *  output 
 *  5 2 1 0
 *  4 3
 */
int visit_t=0;
void DFS(int u,int flag,int size)
{
	if(flag)
	{
		b[u]=visit_t++;
	}
	else
	{
			cout<<u;
			b[u]=-1;
	}
	for(int v=0;v<size;v++)
	{
			if(G[u][v]==-1)
			{
					continue;
			}
			if(flag)
			{
				if(b[v]==-1)
				{
					DFS(v,flag,size);
				}
				else
						continue;
			}
			else
				DFS(v,flag,size);
	}
	if(flag)
	{
			f[u]=visit_t++;
			cout<<f[u]<<endl;
	}
	else
		f[u]=-1;
	return ;
}
void ReverseG(int size)
{
		int tmp=0;	
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
			{
					tmp=G[i][j];
					G[i][j]=G[j][i];
					G[j][i]=tmp;
			}
}
int FindMax(int size)
{
		int max=-1;
		int index=-1;
		for(int i=0;i<size;i++)
		{
				if(f[i]>max)
				{
					max=f[i];
					index=i;
				}
		}
		return index;
}
void Kosaraju(int size )
{
		DFS(0,true,size);
		ReverseG(size);
		cout<<"dddddddddd"<<endl;
		for(int i=0;i<size;i++)
			cout<<f[i]<<" ";
		cout<<endl;
		cout<<"ddddd"<<endl;
		int u=FindMax(size);
		while(u!=-1)
		{
			cout<<u<<endl;
			DFS(u,false,size);
			cout<<"DDD"<<endl;
		 	u=FindMax(size);
		}
}
void Tragan(int u,int size)
{
		int min=low[u]=pre[u]=v_num++;
		i_stack.push(u);
		for(int v=0;v<size;v++)
		{
				if(G[u][v]!=-1)//代表的是
				{
						if(pre[v]==-1)//代表的是没有被访问
						{
							Tragan(v,size);
						}		
						if(low[v]<min)
						{
								min=low[v];
						}
				}
		}
		if(low[u]>min)
		{
				low[u]=min;
				return ;
		}
		else//这里不会出现大于的情况//并且应该是第一次出现＝号的时候对应的是
		{
				int tmp;
				do
				{
						tmp=i_stack.top();
						i_stack.pop();
						cout<<tmp<<" ";
				}while(tmp!=u);
		}
		
}



