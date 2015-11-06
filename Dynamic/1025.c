/*
 * m[p][r]= max(m[p-1][r] , m[p][r-1]) + b[p][r] ? 1:0;
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100000
#define MAX(a,b) (a > b? a: b)
int b[N][N]={0};//0 is not used
int m[N][N]={0};

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
	int i=1;
	int j=1;
	memset(b,0,N*2*sizeof(int));
	memset(m,0,N*2*sizeof(int));
	while(case_index <  line_num)
	{
		scanf("%d%d", &p, &r);
		b[p][r]=1;
		max = MAX(max,MAX(p,r));
		case_index++;
	}
	m[1][1] = b[1][1];
	i=2;
	for (;i<=max;i++)
	{
		m[1][i] = b[1][i] + m[1][i-1];
		m[i][1] = b[i][1] + m[i-1][1];
	}
	for(i=2; i<=max; i++)
	    for(j=2; j<=max; j++)
	{
		m[i][j] = MAX(m[i-1][j], m[i][j-1]) + b[i][j]; 
	}
	printf("Case %d:\n",case_n);	
	printf("My king, at most %d road can be built.\n",m[max][max]);
	case_n++;
	}
	return 0;
}
