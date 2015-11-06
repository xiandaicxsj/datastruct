/*
 * not test 	
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 500005
#define MAX(a,b) (a >= b? a: b)
#define MIN(a,b) (a >= b? b: a)
struct city
{
	int q;
	int r;
}b[N]
int b[N]={0};//0 is not used
int com(const void *a, const void *b)
{
	struct city *t = (struct city *)a;
	struct city *s = (struct city *)b;
	return t.q > s.q;
}
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
		
		b[index].q = q;
		b[index].r = r;
		max = MAX(max,MAX(p,r));
		case_index++;
	}
	qsort(b,case_index-1,sizeof(struct city),cmp);
	memset(m, 0, sizeof(int)*case_index);

	int i=0;
	int j=0;
	for (i;i<case_index; i++)
	{
		j=0;
		int tmp=0;
		for(;j<i;j++)
		{
			if(b[j].r <= b[i].r)
			{
				tmp = MAX(tmp, m[j] +1 );
			}
		}
		m[i] = tmp;
	}
	printf("Case %d:\n",case_n);
	printf("My king, at most %d road can be built.\n",m[case_index-1]);
	case_n++;

	}
}
