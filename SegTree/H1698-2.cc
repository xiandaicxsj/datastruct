#include<stdio.h>
#include<string.h>
//accept
/*test case
 * 1
 * 10
 * 2
 * 1 5 2
 * 5 9 3
 * Result: 24
 * passed h1698
 * a lot of error is cause by printf
 */
#define LL(node) ( 2 * node )
#define RR(node) ( 2 * node + 1)
#define MID(lf, rf) ((lf+rf)>>1)
#define N 200010
int tree[N*8];
int data[N*4];
int sum [N*8];
int type[N*8]={0};
int ql, qr, value;
int _sum = 0;
void maintain(int node_index, int lf, int rf)// maintain 
{
	int ln = node_index * 2;
	int rn = node_index *2 + 1;
	if ( type[node_index] && rf >= lf)
	{
		sum[node_index] =  tree[node_index] * (rf - lf +1);
	}
	else
	{
		if ( rf == lf)
		{
			sum[node_index] = tree[node_index];
		}
		else
		sum[node_index] = sum[ln] + sum[rn];
	}
}
void build_tree(int node_index, int lf, int rf)
{
	int ln = LL(node_index);
	int rn = RR(node_index);
	if (lf == rf)
	{
		tree[node_index] = 1;
		sum[node_index] = 1;
		return;
	}
	int mid = MID(lf, rf);
	build_tree(ln,lf, mid);
	build_tree(rn,mid+1, rf);
	maintain(node_index,lf, rf);
}
void pass_down(int node_index)
{
	int lc = node_index * 2;
	int rc = node_index * 2 +1;
	int value = tree[node_index];
	if (type[node_index])
	{
		tree[lc]=value;
		tree[rc]=value;
		
		type[node_index]=0;
		type[lc] = 1;
		type[rc] = 1;
	}
	return ;
}
void update(int node_index, int lf, int rf)
{
	int ln = LL(node_index);
	int rn = RR(node_index);
	/*if( type[node_index] )
		pass_down(node_index);//should pass_down*/
	if ( ql <= lf && qr >= rf )
	{
		tree[node_index] = value;
		type[node_index] = 1;
		maintain(node_index, lf, rf);
		return; 
	}	
	if( type[node_index] )
		pass_down(node_index);//should pass_down
	if (lf == rf)
		return;
	int mid = MID(lf, rf);

	if ( ql <= mid )
		update(ln, lf, mid);  
	else
		maintain(ln, lf, mid);// it should be maitain ,because after passdown(), we need to recaulate _sum_array 

	if (qr > mid )
		update(rn, mid+1, rf);
	else 
		maintain(rn, mid+1, rf);

	maintain(node_index, lf, rf);
}
void query(int node, int lf, int rf)
{
	if ( ql <= lf && qr >= rf )
	{
		_sum += sum[node];
		return;
	}
	int mid = MID(lf, rf);
	if ( ql <= mid )
		query(node * 2, ql, mid);
	if ( qr > mid )
		query(node * 2 +1, mid+1, qr);
}
int main()
{
	int test_case;
	int hook_num;
	scanf("%d", &test_case);
	for (int i = 0; i<test_case; i++)
	{
		int s_c;
		memset(tree,0,N*8);
		memset(sum,0,N*8);
		memset(type,0,N*8);
		scanf("%d", &hook_num);
		build_tree(1, 1, hook_num);
		scanf("%d", &s_c);
		for (int j=0; j<s_c; j++)
		{
			scanf("%d%d%d", &ql, &qr, &value);
			update(1, 1, hook_num);
		}
		ql=1;qr=hook_num;
		query(1, 1, hook_num);
		printf("Case %d: The total value of the hook is %d.\n",i+1,sum[1]);
		
	}
    	return 0;
}
