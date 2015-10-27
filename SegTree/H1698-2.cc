#include<stdio.h>
/*test case
 * 1
 * 10
 * 2
 * 1 5 2
 * 5 9 3
 * Result: 24
 * passed h1698
 */
#define LL(node) ( 2 * node )
#define RR(node) ( 2 * node + 1)
#define MID(lf, rf) ((lf+rf)>>1)
#define N 20000
int tree[N*8];
int data[N*4];
int sum [N*8];
int type[N*8]={0};
int ql, qr, value;
int _sum = 0;
void maintain(int node_index, int lf, int rf)
{
	int ln = node_index * 2;
	int rn = node_index *2 + 1;
	if ( type[node_index] && rf >= lf)
	{
		sum[node_index] =  tree[node_index] * (rf - lf +1);
	}
	else
	{
		if ( rf==lf)
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
	if( type[node_index] )
		pass_down(node_index);
	if ( ql <= lf && qr >= rf )
	{
		tree[node_index] = value;
		type[node_index] = 1;
		maintain(node_index, lf, rf);
		return; 
	}	
	if (lf == rf)
		return;
	int mid = MID(lf, rf);

	if ( ql <= mid )
		update(ln, lf, mid); //if not main 
	else
		maintain(ln, lf, mid);

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
		printf("sum from %d to %d is %d\n", lf, rf, sum[node]);
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
		printf("%d %d\n",_sum, sum[0]);
		
	}
    	return 0;
}
