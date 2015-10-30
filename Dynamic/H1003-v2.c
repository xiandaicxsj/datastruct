/*
 * passed H1003
 */
#include<stdio.h>
int main()
{
	int kk_case;
	int i;
	scanf("%d", &kk_case);
	for (i=0; i<kk_case; i++)
	{
		int l;
		int j=0;
		int tmp;
		int max_b =0;
		int max_e =0;
		int max_v;
		int pre_v;
		int pre_b;
		scanf("%d",&l);
		for(j = 0;j<l;j++)
		{
			scanf("%d", &tmp);
			if (j==0)
			{
				max_v = tmp;
				pre_v = tmp;
				pre_b = 0;
				continue;
			}
			if ( tmp + pre_v >= tmp)
			{
				pre_v = tmp + pre_v;
			}
			else
			{
				pre_v = tmp;
				pre_b = j;
			}
			if ( pre_v > max_v)
			{
				max_v = pre_v;
				max_b = pre_b;
				max_e = j;
			}
		}
		printf("Case %d:\n",i+1); 
		printf("%d %d %d\n",max_v, max_b+1, max_e+1);
		if(i != kk_case-1)
		printf("\n");
	}
	return 0;
}
