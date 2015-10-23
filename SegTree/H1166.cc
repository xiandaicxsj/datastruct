#include<iostream>
#include<stdio.h>
using namespace std;
#define LL(x) ( x<<1 )
#define RR(x) ( x<<1|1 )
#define MID(a,b) ( (a+b)>>1 )
const int N=50005;
struct node
{
    int lfv;
    int rhv;
    int sum;
    int mid(){return MID(lfv, rhv);};
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
            build(lfv, mid, LL(id));
            build(mid+1, rhv, RR(id));//左边是包含mid的结构
            tree[id].sum=tree[LL(id)].sum+tree[RR(id)].sum;
            return ;
        }
        tree[id].sum= y[lfv];
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
        if(tree[id].lfv >= b && tree[id].rhv <= e)
        {
            return tree[id].sum;
        }
        int mid = tree[id].mid();
        int sum1 = 0;
        int sum2 = 0;
        if(b <= mid)
        {
            sum1 = Query(LL(id), b, e);
        }
        if(e>mid)
        {
            sum2 = Query(RR(id), b, e);
        }
        return sum1 + sum2;
    }
    
};
SegTree s;
int main()
{
    int t=0;
    scanf("%d",&t);
    int num=0;
    char cmd[10];
    int a1;
    int a2;
    int j=0;
    while(j<t)
    {
        scanf("%d",&num);
        printf("%s %d%s\n","Case",j+1,":");
        for(int i=0;i<num;i++)
            scanf("%d",&(y[i+1]));
        s.build(1,num,1);
        while(1)
        {
            scanf("%s",cmd);
            if(strcmp(cmd,"End")==0)
                break;
            scanf("%d",&a1);
            scanf("%d",&a2);
            if(strcmp( cmd, "Query")==0)
                printf("%d\n",s.Query(1,a1,a2));
            if(strcmp( cmd, "Add")==0)
                s.update( 1, a1, a2 );
            if(strcmp(cmd,"Sub")==0)
                s.update( 1, a1, -a2 );
        }
        j++;
    }
    return 0;
}
