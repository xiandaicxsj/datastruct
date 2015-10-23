#include<iostream>
using namespace std;
#define MAX 1000
#define INF 77777
struct edge
{
	int i;
	int j;
	int v;
};
int BellFord(int G[][MAX],edge *edge,int nodeNum,int egeNum,int begin,int end );
int  Forld_Wall(int G[][MAX],int size,int b,int e);
edge ae[MAX];
int G[MAX][MAX];
bool Hash[MAX];//表示键入到了选择中
int Min(int *dis,int *pre,int size)
{
		int min=INF;	
		int minIndex=-1;
		for(int i=0;i<size;i++)
		{
				if(!Hash[i]&&dis[i]<min)
				{
					min=dis[i];
					minIndex=i;
				}
		}
		return minIndex;
}
int Dijkstra(int G[][MAX],int size,int b,int e)
{
		int *dis=new int(size);
		int *pre=new int (size);
		for(int i=0;i<size;i++)
		{
				Hash[i]=false;
				if(G[b][i]!=INF)
				{
					dis[i]=G[b][i];
					pre[i]=b;
				}else
				{
					dis[i]=INF;
					pre[i]=-1;
				}
		}
		int u=b;
		Hash[u]=true;
		while(true)
		{
			u=Min(dis,pre,size);
			Hash[u]=true;
			if(u==e)
				return dis[e];
			for(int i=0;i<size;i++)
				if(G[u][i]!=INF&&G[u][i]+dis[u]<dis[i])
				{
						pre[i]=u;
						dis[i]=G[u][i]+dis[u];
				}
		}
}
int main()
{
	int m;
	cin>>m;
	int t;
	int egeNum=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
		{
			cin>>t;
			if(t)
			{
				ae[egeNum].i=i;
				ae[egeNum].j=j;
				ae[egeNum].v=t;
				egeNum++;
				G[i][j]=t;
			}else
				G[i][j]=INF;
		}
	cout<<"Init Grapic"<<endl;
	int b;
	int e;
	cin>>b;
	cin>>e;
	cout<<Dijkstra(G,m,b,e)<<endl;
	//cout<<Forld_Wall(G,m,b,e)<<endl;
	//cout<<BellFord(ae,m,egeNum,b,e);
	BellFord(G,ae,m,egeNum,b,e);
	return 0;
}
int BellFord(int G[][MAX],edge *edge,int nodeNum,int egeNum,int begin,int end ) {//bellFord 的算法还需要继续写
	int *dis=new int[nodeNum];
	int j=0;
	for(int i=0;i<nodeNum;i++)
		if(i==begin)
		{
				dis[i]=0;//这里的设置问题
		}
		else
		{
				dis[i]=G[begin][i];
		}
	for(int i=0;i<nodeNum;i++)
	{
			for(j=0;j<egeNum;j++)
			{
				if(dis[edge[j].i]+G[edge[j].i][edge[j].j]<dis[edge[j].j])
				{
						dis[edge[j].j]=dis[edge[j].i]+G[edge[j].i][edge[j].j];
				}
			}
	}
			for(j=0;j<egeNum;j++)
			if(dis[edge[j].j]>dis[edge[j].i]+G[edge[j].i][edge[j].j])
			{
							cout<<"dd"<<endl;//这里是判断是否回出现负权值的回路 
			}
	cout<<dis[end]<<endl;
	return 0;
}
int  Forld_Wall(int G[][MAX],int size,int b,int e)
{
		int dis[MAX][MAX];
		int k=0;
		int i=0;
		int j=0;
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
				dis[i][j]=G[i][j];
		}
		for(k=1;k<size;k++)
			for(i=0;i<size;i++)
				for(j=0;j<size;j++)
				{
						/*for(int d=0;d<k;d++)
						{
								if(dis[i][d]+dis[d][j]<dis[i][j])
								{
										dis[i][j]=dis[i][d]+dis[d][j];
								}
						}*/
				if(dis[i][k-1]!=INF&&dis[k-1][j]!=INF&&dis[i][k-1]+dis[k-1][j]<dis[i][j])
						dis[i][j]=dis[i][k-1]+dis[k-1][j];
			}
		return dis[b][e];
}

