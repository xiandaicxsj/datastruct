#include<iostream>
#include<stack>
#include<vector>
#define MAX 1000
using namespace std;
class Node
{
		public:
/*		Node(Node &n)
		{
			x=n.x;
			y=n.y;
			v=n.v;
		}*/
		Node(int _x,int _y,int _v=-1)
		{
					y=_y;
					v=_v;
		}
		Node()
		{
				x=-1;
				y=-1;
				v=-1;
		}
		int x;
		int y;
		int v;
};
int flag=0;
Node G[MAX][MAX];
int tG[MAX][MAX];
int  SSC[MAX];
void InitGrapic(int size)
{
	for(int i=0;i<size;i++)
		{
			SSC[i]=-1;
			for(int j=0;j<size;j++)
			{
				tG[i][j]=-1;
				G[i][j].x=i;
				G[i][j].y=j;
				G[i][j].v=-1;
			}
		}
}
int main()
{

	int size;
	cin>>size;
	InitGrapic(size);
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
		{
				cin>>tG[i][j];
		}
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
		{
				G[i][j].x=i;
				G[i][j].y=j;
				G[i][j].v=tG[i][j];
		}
}
void Update(int i,int j,int size)
{
		for(int k=0;i<size;k++)
		{
				if(SSC[k]==i)
				{
						SSC[k]=j;
				}
		}

}
void FindMinK(int &x,int &y,int size)
{
	int min=10000;
	int t_i=0;
	int t_j=0;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
		{
			if(G[i][j].v!=-1&&G[i][j].v<min)
			{
				if((SSC[i]==-1&&SSC[j]==-1)||(SSC[i]!=SSC[j]))
				{
					min=G[i][j].v;
					t_i=i;
					t_j=j;
				}
			}
		}	
		if((SSC[t_i]==-1&&SSC[t_j]==-1)||(SSC[t_i]!=SSC[t_j]))
		{
				if(SSC[t_i]!=SSC[t_j])
				{
						if(SSC[t_i]==-1||SSC[t_j]==-1)
						{
								int t=SSC[t_j]==-1?SSC[t_i]:SSC[t_j];
								SSC[t_i]=t;
								SSC[t_j]=t;

						}
						else
						{
							if(SSC[t_i]>SSC[t_j])
							{
									Update(SSC[t_i],SSC[t_j],size);
							}
							else
							{
									Update(SSC[t_j],SSC[t_i],size);
							}
								
						}
				}
				else
				{
						SSC[t_i]=flag;
						SSC[t_j]=flag;
						flag++;
				}
		}
		
		x=t_i;
		y=t_j;
}
int FindMinP(int *dis,int size)
{
		int min=10000;
		int index=-1;
		for(int i=0;i<size;i++)
		{
				if(dis[i]!=-1&&dis[i]<min)
				{
						min=dis[i];
						index=i;
				}
		}
		return index;
}
void BroadTraverse(vector<Node*> v,int nodeIndex,stack<int>)//广度遍历
{

}
vector<Node*> Prim(int size,vector<Node*> vec_G)
{
		Node G[MAX][MAX];
		int x;
		int y;
		int v;
		vector<Node *>::iterator iter=vec_G.begin();			
		for(iter;iter<vec_G.end();iter++)
		{
				x=(*iter)->x;
				y=(*iter)->y;
				v=(*iter)->v;
				G[x][y]=Node(x,y,v);
		}//生成新的G图

		vector<Node*> v_node;
		int v_num=0;
		int node=0;
		int *dis=new int(size);
		int *pre=new int(size);
		int *in=new int(size);
		for(int i=0;i<size;i++)
		{	
			in[i]=-1;
			dis[i]=G[node][i].v;
			pre[i]=node;
		}
		in[node]=0;
		while(v_num<size-1)
		{
				int index=FindMinP(dis,size);
				in[index]=1;
				v_node.push_back(new Node(pre[index],index));
				v_num++;
				for(int i=0;i<size;i++)
				{
						if(!in[i]&&G[index][i].v<dis[i])
						{
								if(G[index][i].v!=-1)
								{
										pre[i]=index;
										dis[i]=G[index][i].v;
								}
						}
				}
		}
		return v_node;
}

void Kruskal(int size)
{
		vector<Node*> v_node;	
		int num=0;
		int x;
		int y;
		int flag;
		while(num<size-1) 
		{ 
			FindMinK(x,y,size); 
			num++;
			Node* t =new Node(x,y,G[x][y].v);
			v_node.push_back(t);
		} 
		vector<Node*>::iterator iter=v_node.begin();
		for(;iter<v_node.end();iter++)
		{
				cout<<(*iter)->x<<" "<<(*iter)->y<<endl;
		}
}
int FindMinVWithScc(vector<Node*>&scc,int v)
{
		int min=MAX;//这里应该是MAXVALUE
		int minIndex=-1;
		int t_x;
		int t_y;
		vector<Node*>::iterator nodeIter=scc.begin();
		for(;nodeIter<scc.end();nodeIter++)
		{
				t_x=(*nodeIter)->x;
				t_y=(*nodeIter)->y;
				if(G[v][t_x].v<min)
				{
					min=G[v][t_x].v;
					minIndex=t_x;
				}
				if(G[v][t_y].v<min)
				{
					min=G[v][t_y].v;
					minIndex=t_y;
				}
		}
		return minIndex;
}
/* size : 结点得个数
 * v :对于有限制得结点得编号
 * k :有限制结点得度数得限制
 */
//这里先针对得是无向图得问题
void MinKTree(int size,int v,int k)
{
		vector<Node *>vec_G;
		int i=0;
		int j=0;
		for(i=0;i<size;i++)
			for(j=i+1;j<size;j++)
			{
					if(i!=v&&j!=v)
					{
							if(G[i][j].v!=0)
							{
								vec_G.push_back(new Node(i,j,G[i][j].v));
								vec_G.push_back(new Node(j,i,G[i][j].v));
							}
					}
			}
		vector<vector<Node*> >sccList=UDSCC(size,vec_G);
		if(k<sccList.size())
		{
			//error in it 
		}
		vector<Node *>tTree;
		int sccSize=sccList.size();//强连通分量的个数
		vector<vector<Node*> >::iterator sccIter;
		int u=0;
		for(sccIter=sccList.begin();sccIter<sccList.end();sccIter++)
		{
				u=FindMinVWithScc(*sccIter,v);
				tTree.push_back( new Node(v,u,G[v][u].v));//这里这一个G[v][u]是全局的
		}
		for(sccIter=sccList.begin();sccIter<sccList.end();sccIter++)
		{
				vector<Node*>a=Prim(size,*sccIter);
				tTree.insert(tTree.begin(),a.begin(),a.end());
		}
		while(sccSize<k)
		{
			AddEdge(tTree,v,size);
			sccSize++;
		}
		//下面就是重每SCC中得最小生成树,这里需要修改相应得代码了
		//根据与v点链接得边得权值进行排序,选择边并且加入到相应 SCC中
		//根据sccList.size()继续加入边使得最后v结点得度到达k后可以继续
}
void AddEdge(vector<Node *>tTree,int v,int size)
{
		int G[MAX][MAX];
		vector<Node *>::iterator t_iter=tTree.begin();
		for(t_iter;t_iter<tTree.end();t_iter++)
		{
				G[(*t_iter)->x][(*t_iter)->y]=(*t_iter)->v;
		}
		//下面是根据动态规划求解v 到每个连通分量的的每个结点的路程中的边的最大值
		stack<int> nodeOrder;
		int father[MAX]={0};
		int maxV[MAX]={-1};
		int maxVV[MAX];
		BroadTraves(G[][MAX],nodeOrder,father,size);// 这个还没实现,主要是将访问的序列加入到nodeOrder中，并且father更新father对应的是每个结点的父亲结点
		int u=0;
		while(nodeOrder.IsEmpty()&&u=nodeOrder.top())
		{
				if(fater[u]!=v)
				{
						if(maxV[father[u]]<G[father[u]][u])
						{
								maxV[u]=G[father[u]][u];
								maxVV[u]=maxVV[father[u]];
						}
						else
						{
								maxV[u]=maxV[father[u]];
								maxVV[u]=father[u];
						}
				}
		}
		//找到v相连的，并且不在tTree 中的点，假设为Vk,那么求得
		vector<int> nodeList=FindNotIntTreeButLinkV(v);
		vector<int>::intIter=nodeList.begin();
		int node;
		int sNode;
		int max=-1;
		for(intIter;intIter<nodeList.end();intIter++)
		{
					node=*intIter;
					int v=G[father[maxVV[node]]][maxVV[node]];
					int v2=G[v][node];
					if(v2>v)
					{
							continue;							
					}
					if(v2<v)
					{
							if(v-v2>max)
							{
									max=v-v2;
									sNode=node;
							}
					}
					//得到v2-v最大的值，但是这里我没法确定的是 v2是否一定大于v
		}
		tTree.push_back(new Node(v,sNode,G[v][sNode]));
}
void DFS(int u,vector<Node *>&G,bool* visited,int size)
{
		for(int i=0;i<size;i++)
		{
				if(tG[u][i]>0)
				{
						G.push_back(new Node(u,i,tG[u][i]));
						if(!visited[i])
						{
							visited[i]=true;
							DFS(i,G,visited,size);
						}
				}
		}
}
	
vector<vector<Node *> > UDSCC(int size,vector<Node*> &G)//第二个参数是边得集合

{
		int i=0;
		int j=0;
		for(;i<size;i++)
			for(;j<size;j++)
			{
					tG[i][j]=0;
			}
		vector<Node *>::iterator iter=G.begin();
		for(;iter<G.end();iter++)
		{
				tG[(*iter)->x][(*iter)->y]=(*iter)->v;
		}
		bool *visited=new bool[size];
		for(i=0;i<size;i++)
			visited[i]=false;
		vector<vector<Node *> > sccList;
		for(i=0;i<size;i++)
		{
				vector<Node* >scc;//这里可能会有点问题得
				if(!visited[i])
				{
					DFS(i,scc,visited,size);
				}
				sccList.push_back(scc);
				//加入到最后得结点中
		}
		return sccList;
}

