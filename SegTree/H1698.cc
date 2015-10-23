/* h1698 segtree update */
#include<iostream>
#include<stdio.h>
#include<vector>
#include<map> 
#include<algorithm>
using namespace std;
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) ((a+b)>>1)
const int N=100005;
struct node
{
    int lfv;
    int rhv;
    int type;
    int value;
    int sum;
    void fresh(int _type, int _value)
    {
	type=_type;//表明还没有进行更新得
	value= _value;
	sum = (rhv - lfv) *value;
    }
    int mid(){return MID(lfv,rhv);};
};
struct SegTree
{
    node tree[N*4];
    void build(int lfv,int rhv,int id)
    {
        
        tree[id].lfv = lfv;
        tree[id].rhv = rhv;
        if(lfv+1!=rhv)//这里对应的应该是成段的更新方法
        {
            int mid=tree[id].mid();/***/
            build(lfv,mid,LL(id));
            build(mid,rhv,RR(id));//左边是左右都是带有mid的
	    tree[id].sum = tree[LL(id)].sum + tree[RR(id)].sum;
	    //printf("node : left %d , right %d ,valud %d sum is %d\n", lfv, rhv, tree[id].value, tree[id].sum);
	    return ;
        }
	tree[id].fresh(0, 1);
	//printf("node : left %d , right %d ,valud %d sum is %d\n", lfv, rhv, tree[id].value, tree[id].sum);
        return ;
    }
    void update(int id,int begin,int end,int type, int value)
    {
	//printf("update left %d end %d \n", begin, end);
	//printf("node detail: left %d , right %d ,valud %d, sum %d\n", tree[id].lfv, tree[id].rhv, tree[id].value, tree[id].sum);
        if(tree[id].lfv>=begin&&tree[id].rhv<=end)
        {
	    tree[id].fresh(type, value);
	//printf("node 1: left %d , right %d ,valud %d, sum %d\n", tree[id].lfv, tree[id].rhv, tree[id].value, tree[id].sum);
            return ;
        }
	/*if (  tree[id].lfv + 1 == tree[id].rhv)
	{
	    tree[id].fresh(0, value);
	    printf("node2 : left %d , right %d ,valud %d\n", tree[id].lfv, tree[id].rhv, tree[id].value);
	    return ;
	}*/
	if(tree[id].type)//如果当前的层次还没,传递到下一个层次的话,继续想下面进行传递,并且设置为已经传递（0）,最后如果查询的情况比较特殊的话会
	{
		tree[LL(id)].fresh(tree[id].type, tree[id].value);
		tree[RR(id)].fresh(tree[id].type, tree[id].value);
		tree[id].type=0;//表示更新了
	}
        int mid = tree[id].mid();
        if(begin < mid)//这里是区间跟新,不能使用等号，不存在单点处理的方式
        {
            update(LL(id), begin, end, type, value);
        }
        if(end > mid)
        {
            update(RR(id), begin, end, type, value);
        }
	tree [id].sum = tree[LL(id)].sum + tree[RR(id)].sum;
	//printf("node3 : left %d , right %d ,valud %d\n", tree[id].lfv, tree[id].rhv, tree[id].value);
        return;
    }
    int query()
    {
		return tree[1].sum;
    }
    
};
SegTree s;
vector<int> y;
int main()
{
		int caseNums=0;
		cin>>caseNums;
		int caseIndex=0;
		int num_hook = 0;
		int num_operation = 0;
		int begin,end;
		int value ;
		while(caseIndex<caseNums)
		{
			scanf("%d", &num_hook);
			scanf("%d", &num_operation);
			s.build(0, num_hook, 1);
			for(int i=0; i<num_operation; i++)
			{
				scanf("%d %d %d",&begin, &end, &value); 
				//printf("%d %d %d\n",begin, end, value); 
				s.update(1, begin-1, end, 1, value);
			} 
			printf("Case %d: The total value of the hook is %d \n",caseIndex+1,s.query());
			
		}
    return 0;
}
