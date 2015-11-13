/*
 * nlog(n) len[n] record lowest value of n leng max  queue 
 * if len[k -1] > len[k]
 * 	it means there is value < len[k] < len[k-1] will always have length of k-1 , it is confit with the definin of the len[] 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 500001 
#define MAX(a,b) (a >= b? a: b)
#define MIN(a,b) (a >= b? b: a)
int max_len = 0;
int len[N] = {0};
int d[N];
struct city
{
	int q;
	int r;
};
struct city b[N];
int cmp(const void *a, const void *b)
{
	struct city *t = (struct city *)a;
	struct city *s = (struct city *)b;
	return t->q > s->q;
}
int binary_search(int value, int _begin, int _end)
{
		int begin = _begin;
		int end = _edn;
		while (begin < end)
		{
			int mid = (begin + end) >> 1;
			if ( value = d[mid] )  return mid;
			if ( value > d[mid] ) begin = mid+1;
			else
				end = mid - 1; 
		}
}
/*int binary_search(int value, int begin, int end)
{
		if (begin == end)
		{
			return begin;
		}
		int mid = (begin + end)>>1;
		if ( begin + 1 == end)
		{
			if ( value < d[begin] )
				return begin;
			return end;
		}
		if ( value  > d[mid] )
			return binary_search(value, mid, end); 
		if ( value  < d[mid] )
			return binary_search(value, begin, mid);
		if ( value == d[mid] )
			return mid;
}*/

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
	while(case_index <  line_num)
	{
		scanf("%d%d", &p, &r);
		
		b[case_index].q = p;
		b[case_index].r = r;
		case_index++;
	}
	qsort(b,case_index-1,sizeof(struct city),cmp);

	int i=0;
	int max_low_index = 0;
	max_len = 1;
	d[1] = b[0].r;

	for (i = 1; i<case_index; i++)
	{
		if ( b[i].r >= d[max_len])
		{
			d[++max_len] = b[i].r;
			continue;
		}
		if ( b[i].r == d[max_len] )
		{
			if (b[i].q == b[i-1].q)
				continue;
			d[++max_len] = b[i].r;
		}
		max_low_index = binary_search(b[i].r, 1, max_len);
		d[max_low_index] = b[i].r;
	}
	printf("Case %d:\n",case_n);
	if (max_len <= 1)
	printf("My king, at most %d road can be built.\n\n",max_len);
	else
	printf("My king, at most %d roads can be built.\n\n",max_len);
	case_n++;

	}
}
