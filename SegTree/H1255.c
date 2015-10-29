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
int maintain(int o, int l, int r)
{
	if ( val[o] > 1)
	sum[o] =  y[r] - y[l];
	else
	{
		sum[o] = sum[2*o] + sum[2*o+1];
		printf("sum l %d, r %d is %f\n", l,r, sum[o]);
	}
}
void pass_down(int o)
{
	val[o*2] = val[o*2+1] = val[o];
	val[o] = 0;
}
void  update(int o, int l, int r)
{
	printf("l %d: %f --- r %d:%f\n", l, y[l], r, y[r]);
	if(y[l] >= ql && y[r] <= qr)
	{
		val[o] += value;
		if (val[o]>1)
			printf("for val > 1 l %d: %f --- r %d:%f\n", l, y[l], r, y[r]);
		printf("maintain\n");
		maintain(o, l, r);
		return ;
	}
	if (val[o])
		pass_down(o);
	int m = (l + r) >> 1;	
	if (ql < y[m])
		update(o*2, l, m);
	else
		maintain(o*2, l, m);
	if (qr > y[m] )
		update(o*2+1, m, r);
	else 
		maintain(o*2+1, m, r);
	maintain(o, l, r);
}
void show (int o, int l ,int r)
{
	
	printf("l%d--%f, r%d--%f sum is %f\n",l,y[l], r,y[r], sum[o]);
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
		for (j=1; j<n; j++)
		{
			printf("y[%d] %f\n",j, y[j]);
		}
		for (j=1; j<k; j++)
		{
			printf("line x1:%f, y1:%f, y2:%f value %d\n", line[j].x1, line[j].y1, line[j].y2, line[j].value);
		}
		float area=0;
		val[1] = 0;
		int ii;
		for (ii=1; ii < k ;ii++)
		{
			ql = line[ii].y1;
			qr = line[ii].y2;
			printf("%f %f\n", ql, qr); 
			value = line[ii].value;
			update(1, 1, n-1); 
			//show(1,1,n);
			printf("cover is %f\n",sum[1]);
			printf("after\n");
			if (i >1)
				area += (line[i].x1 - line[i-1].x1) * sum[1];
		}
		printf("%f\n", area);
	}
	return 0;
}
