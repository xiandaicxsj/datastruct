#include<stdio.h>
#define N 100
int tmp[N];
int begin[N];
int array[N];
int get_len(int length, int * begin, int * end)
{
	int max_index=0;
	tmp[0]=array[0];
	begin[0]=0;
	int max=tmp[0];
	for (int i=1; i< length; i++)
	{
		if (tmp[i-1] + array[i] >= array[i])
		{
			tmp[i] = tmp[i-1] + array[i];
			begin[i]  = begin[i-1];
		}
		else
		{
			tmp[i] = array[i]; 
			begin[i] = i;
		}
		if (tmp[i] >max)
		{
			max = tmp[i];
			max_index = i;
		}
	}
	*begin = begin[max_index]+1;
	*end = max_index + 1;
	return max;
}
int main()
{
	int kk_case;
	int i;
	scanf("%d", &kk_case);
	for (i=0; i<kk_case; i++)
	{
		int l;
		int j=0;
		int b;
		int e;
		int m;
		scanf("%d",&l);
		printf("end %d %d\n",i, kk_case);
		for(j = 0;j<l;j++)
			scanf("%d", &(array[j]));
		printf("end %d %d\n",i, kk_case);
		m = get_len(l, &b, &e);
		printf("end %d %d\n",i, kk_case);
		printf("Case %d:\n",i+1); 
		printf("%d %d %d\n",m, b, e);
		printf("end %d %d\n",i, kk_case);
	}
	return 0;
}
