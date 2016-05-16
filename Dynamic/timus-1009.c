/* passed */
#include<stdio.h>

typedef unsigned long long u64;
int main()
{
	int n;
	int k;
	u64 dp0;
	u64 dpk;
	u64 t0;
	u64 tk;
	while(scanf("%d%d",&n,&k)!=EOF)
	{

	dp0 = 0;
	dpk = k-1;
	tk = dpk;
	t0 = dp0;
	n--;
	while(n)
	{
		t0 = dpk;
		tk = (dp0 + dpk) *(k-1);
		dpk = tk;
		dp0 = t0;
		n--;
	}
	printf("%lld\n", tk + t0);
	}
	return 0;
}
