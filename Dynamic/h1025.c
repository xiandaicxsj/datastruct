/*
 *
 * another version to do this
 * change to longest 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 500005
#define MAX(a,b) (a >= b? a: b)
#define MIN(a,b) (a >= b? b: a)
int b[N][N]={0};//0 is not used
int main()
{
	int line_num;
	int case_n=1;
	while(scanf("%d",&line_num)!=EOF)
	{
	int case_index=0;
	int max = 0;
	int r;
	int p;
	memset(b,0,N*2*sizeof(int));
	int *m ;
	while(case_index <  line_num)
	{
		scanf("%d%d", &p, &r);
		
		b[MIN(p,r)][MAX(p,r)]=1;
		max = MAX(max,MAX(p,r));
		case_index++;
	}
	m = (int *)malloc(sizeof(int) *max);
	memset(m, 0, sizeof(int)*max);
	m[1] = b[1][1];
	int i=2;
	int j=1;
	for (; i <= max; i++)
	{
		int tmp=0;
		for (j = 1;j<i;j++)
		{
			if ( b[j][i] )
			{
				tmp = MAX(tmp,b[j][i]+m[j]);
			}
		}
		tmp +=b[i][i];
		m[i] = tmp;
	} 
	 printf("Case %d:\n",case_n);
	 printf("My king, at most %d road can be built.\n",m[max]);
	 case_n++;

	}
}
