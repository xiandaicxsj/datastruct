#include<stdio.h>
#include<stdlib.h>
#define N 20000
int val[N] = {0};
float sum[N] = {0};
float y[N];
float tmp[N];
float qr;
float ql;
int value;
struct ele_line 
{
	float x1;
	float y1;
	float y2;
	int value;
};
struct ele_line line[N];
int cmp_line(const void *_x, const void *_y)
{
	struct ele_line *x= (struct ele_line *)_x;
	struct ele_line *y= (struct ele_line *)_y;
	return x->x1 > y->x1; 
}
int cmp_int(const void *_x, const void *_y)
{
	return *((float *)_x) > *((float *)_y);
}
void pass_down(int o)
{
	val[o*2] = val[o*2+1] = val[o];
	val[o] = 0;
}
void down(int o, int l, int r)
{
	//printf("down--> l %d:%f, r%d:%f\n", l,y[l],r,y[r]);
	if (l+1 == r)	
	{
		val[o] += value;
		if (val[o] >= 2)
		{	
			sum[o] = y[r] - y[l];
			//printf(" val[%d] %d value %d\n",o, val[o], value);
		//	printf("down update--> l %d:%f, r%d:%f sum %f\n", l,y[l],r,y[r], sum[o]);
			return ;
		}
		if (val[o] < 0)
			val[o] = 0;
		sum[o] = 0;
		return ;
	}
	int m = (l + r)>>1;
	down(2*o, l, m);
	down(2*o+1,m, r);
	sum[o] = sum[2*o] + sum[2*o+1];
	//printf("down--> l %d:%f, r%d:%f sum %f\n", l,y[l],r,y[r], sum[o]);
}
void  update(int o, int l, int r)
{
	//nprintf("update->> l %d:%f, r%d:%f\n", l,y[l],r,y[r]);
	if(ql <= y[l] && y[r] <= qr)
	{
		//printf("down begin l %d:%f, r%d:%f\n", l,y[l],r,y[r]);
		down(o, l, r);
		return ;
	}
	int m = (l + r) >> 1;	
	if (ql < y[m])
		update(o*2, l, m);
	if (qr > y[m] )
		update(o*2+1, m, r);
	sum[o] = sum[2*o] + sum[2*o+1];
}
void show (int o, int l ,int r)
{
	
	//printf("node %d :l%d--%f, r%d--%f sum is %f value is %d\n",o, l,y[l], r,y[r], sum[o], val[o]);
	if (l+1==r)
		return ;
	int m=(l+r)>>1;
	show(2*o, l, m);
	show(2*o+1, m, r);
}
int main()
{
	
	int test_case = 0;
	scanf("%d", &test_case);
	int k=0;
	int i=0;
	for (; i< test_case ;i++)
	{
	
		float x1,y1,x2,y2;
		int num_s = 0;
		scanf("%d",&num_s);
		k = 1;
		int j=0;
		for(j=0; j< num_s; j++)
		{
			scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
			line[k].x1 = x1;
			line[k].y1 = y1;
			line[k].y2 = y2;
			line[k].value = 1;
			tmp[k]=y1;
			k++;
			line[k].x1 = x2;
			line[k].y1 = y1;
			line[k].y2 = y2;
			line[k].value = -1;
			tmp[k]=y2;
			k++;
		}
		qsort((void *)(&line[1]), k-1, sizeof(struct ele_line),cmp_line);//sort line by x1 
		qsort((void *)(&tmp[1]), k, sizeof(float), cmp_int);
		y[1]=tmp[1];
		int n=1;
		for (j=2; j < k; j++)	
		{
			if(tmp[j] == tmp[j-1])
			continue;	
			y[n] = tmp[j];
			n++;
		}
		/*for (j=1; j<n; j++)
		{
			printf("y[%d] %f\n",j, y[j]);
		}
		for (j=1; j<k; j++)
		{
			printf("line x1:%f, y1:%f, y2:%f value %d\n", line[j].x1, line[j].y1, line[j].y2, line[j].value);
		}*/
		float area=0;
		val[1] = 0;
		int ii;
		for (ii=1; ii < k ;ii++)
		{
			ql = line[ii].y1;
			qr = line[ii].y2;
			//printf("%f %f\n", ql, qr); 
			value = line[ii].value;
			//show(1,1,n-1);
			if (ii >1)
			{
				area += (line[ii].x1 - line[ii-1].x1) * sum[1];
				update(1, 1, n-1); 
			}
			else
			update(1, 1, n-1); 
		}
		printf("%f\n", area);
	}
	return 0;
}
