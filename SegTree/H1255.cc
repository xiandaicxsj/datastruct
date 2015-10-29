#include<stdio.h>
#include<algorithm>
#define N 20000
int val[N] = {0};
int sum[N] = {0};
int y[N];
int tmp[N];
int qr;
int ql;
int value;
struct ele_line 
{
	int x1;
	int y1;
	int y2;
	int value;
};
struct ele_line line[N];
bool cmp(struct ele_line x, struct ele_line y)
{
	return x.x1 > y.x1; 
}
int maintain(int o, int l, int r)
{
	if ( val[o] > 1)
	sum[o] =  y[r] - y[l];
	else
	sum[o] = sum[2*o] + sum[2*o+1];
}
void pass_down(int o)
{
	val[o*2] = val[o*2+1] = val[o];
	val[o] = 0;
}
void  update(int o, int l, int r)
{
	if(y[l] == ql && y[r] == qr)
	{
		val[o] += value;
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
int main()
{
	
	int test_case = 0;
	scanf("%d", &test_case);
	int k=0;
	for (int i=0 ; i< test_case ;i++)
	{
	
		int x1,y1,x2,y2;
		int num_s = 0;
		scanf("%d",&num_s);
		k = 1;
		for(int j=0; j< num_s; j++)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
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
		sort(line+1, line + k, cmp);//sort line by x1 
		sort(tmp+1, tmp + k);
		y[1]=tmp[1];
		int n=0;
		for (int j=2; j < k; j++)	
		{
			if(tmp[i] == tmp[i-1])
			continue;	
			y[++n] = tmp[i];
		}
		float area=0;
		val[1] = 0;
		for (int ii=1; ii < k ;ii++)
		{
			ql = line[ii].y2;
			qr = line[ii].y1;
			value = line[i].value;
			update(1, 1, n); 
			if (i >1)
				area += (line[i].x1 - line[i-1].x1) * sum[1];
		}
		printf("%f\n", area);
	}
	return 0;
}
