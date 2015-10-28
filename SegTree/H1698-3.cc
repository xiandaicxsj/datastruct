#include<stdio.h>
#include<string.h>
/*test case
 * 1
 * 10
 * 2
 * 1 5 2
 * 5 9 3
 * Result: 24
 * passed h1698
 * accept
 */
#define LL(node) ( 2 * node )
#define RR(node) ( 2 * node + 1)
#define MID(lf, rf) ((lf+rf)>>1)
#define N 200010
int val[N*8]={0};
int ql, qr, value;
void pass_down(int o)
{
	val[o *2] = val[o*2+1]= val[o];
	val[o]=0;
}
void update(int o, int lf, int rf)
{
	if (ql <= lf && qr >= rf)
		val[o]= value;
	else
	{
		if(val[o])
			pass_down(o);
		int m = (lf + rf) >> 1;
		if (ql <= m)
		update(o*2, lf, m);
		if (qr >m )
		update(o*2+1, m+1, rf);
	}
}
int query(int o, int lf, int rf)
{
	if (val[o]) return (rf - lf + 1) * val[o];
	int m = (lf + rf) >> 1;
	return query(o*2, lf, m) + query(o*2+1, m+1, rf);
}
int main()
{
	int test_case;
	int hook_num;
	scanf("%d", &test_case);
	for (int i = 0; i<test_case; i++)
	{
		val[1] = 1;
		int s_c;
		scanf("%d", &hook_num);
		scanf("%d", &s_c);
		for (int j=0; j<s_c; j++)
		{
			scanf("%d%d%d", &ql, &qr, &value);
			update(1, 1, hook_num);
		}
		printf("Case %d: The total value of the hook is %d.\n",i+1,query(1,1,N));
		
	}
    	return 0;
}
