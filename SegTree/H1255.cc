#include<stdio.h>
#define N 20000
int val[N] = {0};
int sum[N] = {0};
int y[N];
int qr;
int ql;
struct ele_line 
{
	int x1;
	int y1;
	int y2;
};
struct ele_line line[N];
int maintain(int o, int l, int r)
{
	if ( val[o] > 0)
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
		return 0;
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
	main_tain(o, l, r);
}
int main()
{
	
	int test_case = 0;
	scanf("%d", &test_case);
	for (int i=0 ; i< test_case ;i++)
	{
	
		int num_s = 0;
		scanf("%d",&num_s);
		k = 0;
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
		sort(line,line+1, comp);//sort line by x1 
		sort(tmp);
		y[0]=tmp[0];
		int n=0;
		for (int j=1; j < k; j++)	
		{
			if(tmp[i] == tmp[i-1])
			continue;	
			y[++n] = tmp[i];
		}
		float area=0;
		for (int ii=0; ii <k ;ii++)
		{
			ql = line[ii].y2;
			qr = line[ii].y1;
			value = line[i].value;
		}
	return 0;
}
