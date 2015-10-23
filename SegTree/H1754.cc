/* There is still porblem related with this*/
#include<iostream>
#include<stdio.h>
using namespace std;
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) ((a+b)>>1)
const int N = 200005;
int y[ N * 4 ];
struct node
{
    int lfv;
    int rhv;
    int sum;
    int mid(){return MID(lfv,rhv);};
};
struct SegTree
{
    node tree[N*4];
    void build(int lfv,int rhv,int id)
    {
        
        tree[id].lfv=lfv;
        tree[id].rhv=rhv;
        int mid=tree[id].mid();
        if( lfv != rhv)
        {
            build(lfv, mid, LL(id));
            build(mid+1, rhv, RR(id));//左边是包含mid的结构
            tree[id].sum = tree[LL(id)].sum > tree[RR(id)].sum 
			   ? tree[LL(id)].sum:tree[RR(id)].sum;
            return ;
        }
        tree[id].sum = y[lfv];
        return ;
    }
    void update(int id, int pos, int v)
    {
        if((tree[id].lfv == tree[id].rhv)&&tree[id].lfv == pos)
        {
            tree[id].sum = v;
            return ;
        }
        int mid=tree[id].mid();
        if(pos<=mid)
        {
            update(LL(id), pos, v);
        }
        if(pos>mid)
        {
            update(RR(id), pos, v);
        }
        tree[id].sum = tree[LL(id)].sum > tree[RR(id)].sum ?
		       tree[LL(id)].sum : tree[RR(id)].sum;
        return;
    }
    int Query(int id,int b,int e)
    {
        if(tree[id].lfv>=b&&tree[id].rhv<=e)
        {
            return tree[id].sum;
        }
        int mid = tree[id].mid();
        int sum1 = 0;
        int sum2 = 0;
        if(b<=mid)
        {
            sum1 = Query(LL(id),b,e);
        }
        if(e>mid)
        {
            sum2 = Query(RR(id),b,e);
        }
        return sum1 > sum2 ? sum1:sum2;
    }
    
};
SegTree s;//大变量必须声为global 应为如果声明为局部变量的会出现栈溢出的问题
int main()
{
    int n;
    int m;
    char c[10];
    int a1;
    int a2;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&(y[i+1]));
        s.build(1,n,1);
        for(int i=0;i<m;i++)
        {
            scanf("%c %d %d",c,&a1,&a2);
            if(c[0]=='U')
            {
                s.update(1,a1,a2);
                continue;
            }
            if(c[0]=='Q')
            {
		if ( a1 > a2 )
		{
			int tmp=a1;
			a1 = a2;	
			a2 = tmp;
		}
                printf("%d\n",s.Query(1,a1,a2));
                continue;
            }
        }
        
        
    }
    return 0;
}
