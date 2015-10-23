//p3468,主要是完成的区域查询以及区域修改.还没有提交,需要修改的应该是N的值
#include<iostream>
#include<stdio.h>
using namespace std;
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) ((a+b)>>1)
const int N=50005;
struct node
{
    int lfv;
    int rhv;
		int type;
		int value;
		void fresh(int _type)
		{
				type=_type;
				value=value+type*(rhv-lfv+1);
		}
    int mid(){return MID(lfv,rhv);};
};
int y[N];
struct SegTree
{
    node tree[N*4];
    void build(int lfv,int rhv,int id)
    {
        
        tree[id].lfv=lfv;
        tree[id].rhv=rhv;
				tree[id].fresh(1);
				tree[id].type=0;
        int mid=tree[id].mid();
        if(lfv!=rhv)
        {
            build(lfv,mid,LL(id));
            build(mid+1,rhv,RR(id));//左边是包含mid的结构
           	tree[id].value=tree[LL(id)].value+tree[RR(id)].value; //这里更新的必要性
						return ;
        }
				tree[id].value=y[lfv-1];
        return ;
    }
    void update(int id,int begin,int end,int type)
    {
        if((tree[id].lfv>=begin)&&tree[id].rhv<=end)
        {
						tree[id].fresh(type);
            return ;
        }
				if(tree[id].type)//如果当前的层次还没,传递到下一个层次的话,继续想下面进行传递,并且设置为已经传递（0）,最后如果查询的情况比较特殊的话会
				{
						tree[LL(id)].fresh(tree[id].type);
						tree[RR(id)].fresh(tree[id].type);
						tree[id].type=0;
				}
        int mid=tree[id].mid();
        if(begin<=mid)
        {
            update(LL(id),begin,end,type);
        }
        if(end>mid)
        {
            update(RR(id),begin,end,type);
        }
        tree[id].value=tree[LL(id)].value+tree[RR(id)].value;
        return;
    }
    int Query(int id,int b,int e)
    {
        if(tree[id].lfv>=b&&tree[id].rhv<=e)
        {
            return tree[id].value;
        }
        int mid=tree[id].mid();
        int sum1=0;
        int sum2=0;
				if(tree[id].type)
				{
						tree[LL(id)].fresh(tree[id].type);
						tree[RR(id)].fresh(tree[id].type);
						tree[id].type=0;
				}
        if(b<=mid)
        {
            sum1=Query(LL(id),b,e);
        }
        if(e>mid)
        {
            sum2=Query(RR(id),b,e);
        }
        return sum1+sum2;
    }
};
SegTree s;
int main()
{
		int N;
		int askT;
		char askN;
		int begin;
		int end;
		int value;
		cin>>N;
		cin>>askT;
		for(int i=0;i<N;i++)
		{
				cin>>y[i];
			
		}
		s.build(1,N,1);
		for(int i=0;i<askT;i++)
		{
				cin>>askN;
				if(askN=='Q')
				{
					cin>>begin;
					cin>>end;
					cout<<s.Query(1,begin,end)<<endl;
				}
				if(askN=='C')
				{
						cin>>begin;
						cin>>end;
						cin>>value;
						s.update(1,begin,end,value);
				}
		}
    return 0;
}
