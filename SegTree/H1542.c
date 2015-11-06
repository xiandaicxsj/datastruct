#include<stdio.h>
#include<stdlib.h>
#define LL(node) (2*node)
#define RR(node) (2*node +1)
#define MID(l, r) ((l + r)>>1)
#define N 100
typedef struct ele_line
{
	int x1;
	int y1;
	int y2;
	int cover;
}ele_line; 

typedef struct node
{
	int l;
	int r;
	int cover;
	int sum;
}node;
int value[N*4];
node tree[N*4];
ele_line line[N*4];
int cover;
int qr;
int ql;
void main_tain(int node_index)
{
	tree[node_index].sum = tree[LL(node_index)].sum + tree[RR(node_index)].sum;
}
void build_tree(int node_index, int l, int r)
{
	if (l==r)
	{
		tree[node_index].l = l;
		tree[node_index].r = r;
		tree[node_index].cover = 0;
		tree[node_index].sum = 0;
		return ;
	}
	if (l + 1 == r)
	{
		tree[node_index].l = l;
		tree[node_index].r = r;
		tree[node_index].cover = 0;
		tree[node_index].sum = 0;
		return ;
	}
	int m = MID(l,r);	
	build_tree(LL(node_index),l, m); 
	build_tree(RR(node_index),m, r); 
	main_tain(node_index);
}
void down(int node_index, int l, int r)
{
	if (l + 1 == r)
	{
		tree[node_index].cover +=cover;
		if (tree[node_index].cover)
		{
			tree[node_index].sum = value[r] - value[l];
		}
		return;
	}
	if (l==r)
		return;
	int m = MID(l,r);	
	down(LL(node_index), l, m);
	down(RR(node_index), m, r);
	main_tain(node_index);
}
void update(int node_index, int l, int r)
{
	//printf("l-%d:%d r-%d:%d\n",l,value[l],r,value[r]);
	if (l == r)
		return;
	if ( ql <= value[l]  && qr >= value[r] ) 
	{
		down(node_index, l, r);
		return ;
	}
	int m = MID(l,r);	
	if (ql < value[m] )
	{
		update(LL(node_index), l, m);
	}
	if (qr > value[m] )
	{
		update(RR(node_index),m, r);
	}
	/*if (qr <= value[m])
		update(LL(node_index), l, m);
	else if(ql >= value[m])
		update(RR(node_index), m, r);
	else
	{
		update(LL(node_index),l,m);
		update(RR(node_index),m, r);
	}*/
	main_tain(node_index);
}
int cmp_line(const void *_x, const void *_y)
{
         struct ele_line *x= (struct ele_line *)_x;
         struct ele_line *y= (struct ele_line *)_y;
         return x->x1 > y->x1;
}
int cmp_int(const void *_x, const void *_y)
{
         return *((int *)_x) > *((int *)_y);
}
int main()
{
	int index = 1;
	int x1,y1,x2,y2;
	int area = 0;
	while(1)
	{
	scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
	if (x1 == -1 || x1 == -2)
	{
                qsort((void *)(&value[1]), index-1, sizeof(float), cmp_int);
		int k = 2;
		int n =2;
		while (n < index)
		{
			if ( value[n] != value[n-1])
			{
				value[k] = value[n];
				k++;
			}
			n++;
		}
		build_tree(1,1,k-1);
		qsort((void *)(&line[1]), index-1, sizeof(struct ele_line),cmp_line);//sort line by x1 
		int i =1;	
		for (; i< index; i++)
		{
			ql = line[i].y1;
			qr = line[i].y2;
			cover = line[i].cover;
			if (i == 1)
			{
				update(1, 1, index-1);
				continue;
			}
			area +=  (line[i].x1 - line[i-1].x1) * tree[1].sum;
			update(1, 1, index-1);
		}
		printf("%d\n", area);
		index = 1;
		area = 0;
		if (x1 == -2)
		    break;
	}
	else
	{
		int tmp;
		if (y1 > y2)
		{
			tmp=y1;
			y1=y2;
			y2=tmp;
		}
		if (x1 > x2)
		{
			tmp=x1;
			x1=x2;
			x2=tmp;
		}
		value[index] = y1;
		line [index].x1=x1;
		line [index].y1=y1;
		line [index].y2=y2;
		line [index].cover=1;
		index ++;
		value[index] = y2;
		line [index].x1=x2;
		line [index].y1=y1;
		line [index].y2=y2;
		line[index].cover=-1;
		index ++;
	}
}
	return 0;
}
