#include<cstdio> 
#include<cstring>
#include <algorithm>
#include<iostream>
using namespace std;
#define N 200005
int data [N*4]; 
int tree [N*8];
#define LL(a) (a*2)
#define RR(a) (a*2+1)
int q_l,q_r;
void update_tree( int node_index , int left, int right)
{
	if ( left == q_l )
	{
		tree[node_index] = q_r;
                printf("left %d right %d\n", left, right);

		return ;
	}
	int mid = (left + right)/2;
	if (q_l <= mid)
		update_tree( LL(node_index), left, mid);
	else	
		update_tree( RR(node_index), mid+1, right);
	tree [node_index] = max(tree[LL(node_index)] , tree[RR(node_index)]);
} 
void build_tree(int node_index, int left, int right)
{
	if ( left == right )
	{
		tree [node_index] = data[left-1];
		return ;
	}
	int mid = (left + right )/2;
	build_tree( LL(node_index), left, mid);
	build_tree( RR(node_index) , mid+1, right);
	tree [node_index] = max(tree[LL(node_index)] , tree[RR(node_index)]);
}
int find_max(int node_index, int left, int right)
{
	int max1 = 0x80000000;
	int mid = (left + right)/2; 
	if ( q_l <= left && q_r >= right )
	{
		return tree[node_index];
	}
	if ( q_l <= mid )
	{
		max1 = max(max1, find_max(LL(node_index), left, mid));
	}
	if ( q_r > mid)
	{
		max1 = max(max1, find_max(RR(node_index), mid + 1, right));
	}
	return max1;
}
int main()
{
	int n,m;
	char t[20];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(tree, 0 ,sizeof(tree));
		for (int i=0; i<n; i++)
			scanf("%d", &data[i]);
		build_tree(1, 1, n);
		while( m-- )
		{
			scanf("%s%d%d",t, &q_l, &q_r);
			if (t[0] == 'Q')
			{
				if( q_l > q_r)
				{
					int tmp = q_l;
					q_l = q_r;
					q_r = tmp;
				}
				printf("%d\n", find_max(1, 1, n));
			}
			if (t[0] == 'U')
			{
				update_tree(1, 1, n);
			}
		}

	}

	return 0;
}
