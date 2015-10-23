/*利用线段树，得到逆序树
 * 还没有提交主要问题在于,对于test case的多少以及相应的N的大小是多闲
 * 这里可以学到的是利用数据作为索引来update
 */
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
    int sum;
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
        int mid=tree[id].mid();
        if(lfv!=rhv)
        {
            build(lfv,mid,LL(id));
            build(mid+1,rhv,RR(id));//左边是包含mid的结构
            tree[id].sum=tree[LL(id)].sum+tree[RR(id)].sum;
            return ;
        }
        tree[id].sum=y[lfv];
        return ;
    }
    void update(int id,int pos,int v)
    {
        if((tree[id].lfv==tree[id].rhv)&&tree[id].lfv==pos)
        {
            tree[id].sum+=v;
            return ;
        }
        int mid=tree[id].mid();
        if(pos<=mid)
        {
            update(LL(id),pos,v);
        }
        if(pos>mid)
        {
            update(RR(id),pos,v);
        }
        tree[id].sum=tree[LL(id)].sum+tree[RR(id)].sum;
        return;
    }
    int Query(int id,int b,int e)
    {
        if(tree[id].lfv>=b&&tree[id].rhv<=e)
        {
            return tree[id].sum;
        }
        int mid=tree[id].mid();
        int sum1=0;
        int sum2=0;
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
		int num;
		int i=0;
		int res=0;
		int min=100000;
		cin>>num;
		for(i=0;i<num;i++)
			y[i]=0;
		s.build(0,num-1,1);
		for(i=0;i<num;i++)
		{
			cin>>y[i];
			s.update(1,y[i],1);
			res=res+s.Query(1,y[i]+1,num-1);
		}
		for(int i=0;i<num;i++)
		{
				cout<<res<<endl;
				res-=y[i];
				res+=num-y[i]-1;
				if(res<min)
					min=res;
		}
		cout<<min;
    return 0;
}
