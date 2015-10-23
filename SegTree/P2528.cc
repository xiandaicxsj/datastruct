//runtime Error ,但是测试的没问题.应该是去最大值做了了右边缘的问题,需要进行离散化的工作了 //首先是将相应的跟新的数据记录下来，然后求的最大值，根据1到最大值建立线段树，延迟跟新，查找的时候利用map进行记录 //因为院士的数据是没有用处的,最后只保存了一个编号就可以了
//离散化的方法来处理，这样就不需要进行相应的求最大值了
//最后对应线段树必须是对应的一段区间。
//
#include<iostream>
#include<stdio.h>
#include<vector>
#include<map> 
#include<algorithm>
using namespace std;
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) ((a+b)>>1)
const int N=20005;
int hashF[N];
map<int ,int>H;
int a[N];
int b[N];
struct node
{
    int lfv;
    int rhv;
    int type;
    int value;
    void fresh(int _type)
    {
	type=_type;//表明还没有进行更新得
    }
    int mid(){return MID(lfv,rhv);};
};
struct SegTree
{
    node tree[N*4];
    void build(int lfv,int rhv,int id)
    {
        
        tree[id].lfv=lfv;
        tree[id].rhv=rhv;
	tree[id].type=0;//??
        if(lfv+1!=rhv)//这里对应的应该是成段的更新方法
        {
            int mid=tree[id].mid();/***/
            build(lfv,mid,LL(id));
            build(mid,rhv,RR(id));//左边是左右都是带有mid的
	    return ;
        }
        return ;
    }
    void update(int id,int begin,int end,int type)
    {
        if(tree[id].lfv>=begin&&tree[id].rhv<=end)
        {
	    tree[id].fresh(type);
            return ;
        }
	if(tree[id].type)//如果当前的层次还没,传递到下一个层次的话,继续想下面进行传递,并且设置为已经传递（0）,最后如果查询的情况比较特殊的话会
	{
		tree[LL(id)].fresh(tree[id].type);
		tree[RR(id)].fresh(tree[id].type);
		tree[id].type=0;//表示更新了
	}
        int mid=tree[id].mid();
        if(begin<mid)//这里是区间跟新,不能使用等号，不存在单点处理的方式
        {
            update(LL(id),begin,end,type);
        }
        if(end>mid)
        {
            update(RR(id),begin,end,type);
        }
        return;
    }
    void Query(int id,int b,int e)
    {
			
        if(tree[id].type!=0||tree[id].lfv+1==tree[id].rhv)
        {
		if(tree[id].type!=0)
		{
			hashF[tree[id].type]=1;
		}
		return ;
        }
            Query(LL(id),b,e);
            Query(RR(id),b,e);
    }
    
};
SegTree s;
vector<int> y;
int main()
{
		int caseNums=0;
		cin>>caseNums;
		int caseIndex=0;
		int num;
		int i=0;
		int begin=0;
		int end=0;
		while(caseIndex<caseNums)
		{
				y.clear();
				H.clear();
				scanf("%d",&num);
				i=0;
				while(i<num)
				{
						hashF[i+1]=0;
						scanf("%d %d",&a[i],&b[i]);
						b[i]++;	//b[i]++;的原因是因为输入必须转换为边界上
						y.push_back(a[i]);
						y.push_back(b[i]);
					//	b[i]++;
						i++;
				}
				sort(y.begin(),y.end());
				y.erase(unique(y.begin(),y.end()),y.end());
				for(int j=0;j<y.size();j++)
				{
						H[y[j]]=j+1;
				}
				s.build(1,y.size(),1);//这里还是这样的
				for(i=0;i<num;i++)
				{
				   s.update(1,H[a[i]],H[b[i]],i+1);
				}
				s.Query(1,1,y.size());
				int hSize=0;
				for(int i=1;i<num+1;i++)
				{
						if(hashF[i])
						{
							hSize++;
						}
				}
				printf("%d\n",hSize);
				caseIndex++;
		}
    return 0;
}
