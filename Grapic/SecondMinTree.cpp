#include<iostream>
#include<vector>
using namespace std;
class Edge{
	public:
	Edge(int _x,int _y,int _v=-1)
	{
	}
	int x;
	int y;
	int v;
};
#define MAX  1000
#define MAXVALUE 65521
int G[MAX][MAX];
int FindMin(int *dis,bool *in,int size)
{
		int min=MAXVALUE;
		int minIndex=-1;
		for(int i=0;i<size;i++)
		{
				if(!in[i]&&dis[i]<min)
				{
					min=dis[i];
					minIndex=i;
				}				
		}
		return minIndex;

}
void FormEdgeVector(vector<Edge*>&g,int iG[][MAX],int size)
{
		int i=0;
		int j=0;
		for(;i<size;i++)
			for(;j<size;j++)
			{
				if(iG[i][j]<MAXVALUE)
				{
					g.push_back(new Edge(i,j,iG[i][j]));
				}
			}
}
void FormGrapic(vector<Edge*>&g,int iG[][MAX],int size)
{
	vector<Edge*>::iterator iter=g.begin();
	for(iter;iter<g.end();iter++)
	{
			iG[(*iter)->x][(*iter)->y]=(*iter)->v;
	}
}
vector<int>  BroadTraverse(int iG[][MAX],int *father,int node,int size)
{
	vector<int> nodeList;
}
/**寻找在iG内部但是不再tTree中边(iG代表的整个图的结构，tTree代表的是最小生成树的模型
*/
vector<Edge*> FindVExcludeTree(int iG[][MAX],vector<Edge*>tTree,int size)
{
		
		vector<Edge*> eList;
		int iF[][MAX]={-1};
		vector<Edge *>::iterator eIter=tTree.begin();
		for(;eIter<tTree.end();eIter++)
		{
				iF[(*eIter)->x][(*eIter)->y]=1;
		}
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
			{
					if(iF[i][j]==-1&&iG[i][j]!=MAXVALUE)
					{
							eList.push_back(new Edge(i,j,iG[i][j]));
					}
			}
		return eList;
}
//在iG中寻找u->v的路径上最大权值的边
void FindMaxVU(int iG[][MAX],Edge max[][MAX],int *father,int size)
{
		vector<int>::iterator nodeIter;//这里到底是否是这样的
		for(int node=0;node<size;node++)
		{
			vector<int> nodeList=BroadTraverse(iG,father,node,size);
			nodeIter=nodeList.begin();
			for(;nodeIter<nodeList.end();nodeIter++) 
			{
					if(max[node][*nodeIter].v<iG[father[node]][*nodeIter])
					{
						max[node][*nodeIter].v=iG[father[node]][*nodeIter];
						max[node][*nodeIter].x=father[node];
						max[node][*nodeIter].v=iG[father[node]][*nodeIter];
					}
			}
		}
}
vector<Edge*> prim(vector<Edge*> &g)
{
		int size=0;
		int iG[MAX][MAX];
		FormGrapic(g,iG,size);
		vector<Edge *> tTree;
		int u=0;
		int *dis=new int[size];
		int *father=new int[size];
		bool *in=new bool[size];
		for(int i=0;i<size;i++)
		{
			
			if(u!=i)	
			{
				dis[i]=iG[u][i];
				in[i]=false;
				father[i]=u;
			}
			else
			{
					in[i]=true;
			}
		}
		int v_num=0;
		int node=-1;
		while(v_num<size-1)
		{
				node=FindMin(dis,in,size);
				in[node]=true;
				for(int i=0;i<size;i++)
				{
						if(!in[node]&&(iG[node][i]<dis[i]))
						{
								dis[i]=iG[node][i];
								father[i]=node;
						}
				}
				tTree.push_back(new *Edge(father[node],node,iG[father[node]][node]));
		}
}
void SecondMinTree()
{
	int iG[MAX][MAX]={MAXVALUE};
	int iTG[MAX][MAX]={MAXVALUE};
	Edge maxEdge[MAX][MAX];
	int size=0;
	cin>>size;//可以理解为图结点的个数
	Init(iG);//输入生成图结构
	vector<Edge*>all;
	FormEdgeVector(all,iG,size);
	vector<Edge*>tTree=prim(all);
	vector<Edge*> eEdgeList=FindVExcludeTree(iG,tTree,size);
	FormGrapic(tTree,iTG,size);	//转化为图的结构
	FindMaxVU(iTG,maxEdge,size);
//寻找不再最小树中的边和在最小树中的边的最大差值	
	int t_x;
	int m_x;
	int t_y;
	int m_y;
	int t_v;
	int m_v;
	vector<Edge*>::iterator iter=eEdgeList.begin();
	for(;iter<eEdgeList.end();iter++)
	{
			t_x=(*iter)->x;
			t_y=(*iter)->y;
			t_v=(*iter)->v;
			if(t_v-maxEdge[t_x][t_y].v>m_v)
			{
					m_x=t_x;
					m_y=t_y;
					m_v=t_v-maxEdge[t_x][t_y];
			}
	}
	RemoveEdge(maxEdge[m_x][m_y],tTree);
	AddEdge(m_x,m_y,iG[m_x][m_y],tTree);
}
/*添加一条边,带最小生成树的结合中*/
void AddEdge(int m_x,int m_y,int value,vector<Edge *>tTree)
{
		tTree.push_back(new Edge(m_x,m_y,value));
}
void RemoveEdge(Edge &e,vector<Edge *>tTree)//在最小生成数树中删除相应的e对应的边
{
		vector<Edge *>::iterator iter=tTree.begin();
		vector<Edge *>::iterator s1=tTree.end();
		vector<Edge *>::iterator s2=tTree.end();
		for(;iter<tTree.end();iter++)
		{
				if((*iter)->x==e.x&&(*iter)->y==e.y)
				{
						s1=iter;
				}
				if((*iter)->x==e.y&&(*iter)->y==e.x)
				{
						s2=iter;
				}
		}
		if(s1!=tTree.end())
			tTree.remove(s1);
		if(s2!=tTree.end())
			tTree.remove(s2);
}


