/*
 * nlog(n) len[n] record lowest value of n leng max  queue 
 * if len[k -1] > len[k]
 * 	it means there is value < len[k] < len[k-1] will always have length of k-1 , it is confit with the definin of the len[] 
 * 	never passed, feel sick of finding 
 * 	binary_search and func work ok. But  use struct city and qsort is wrong.
 * 	ok passed
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 500001 
int max_len = 0;
int len[N] = {0};
int d[N];
int a[N];
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
	return (t->q) > (s->q);
}
int binary_search(int value, int _begin, int _end)
{
		int begin = _begin;
		int end = _end;
		int found = 0;
		while (begin <= end)
		{
			int mid = (begin + end) >> 1;
			if ( value == d[mid] )  
			{
					found = 1;
					break;
			}
			if ( value > d[mid] ) begin = mid+1;
			else
				end = mid - 1; 
		}
		if (!found)
		return begin;
		return -1;
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

void fun(int n,int num)
	 {
		       int i=0,j=n-1;
			      int mid,find=0;
			         while(i<=j)
					         {
						                   mid=(i+j)/2;
							                 if( d[mid]==num )   {  find=1;break ; }
							                 else if( d[mid]>num )  j=mid-1;
								               else i=mid+1;
								   }
									             if(!find)  d[i]=num;
   }
int main()
{
	int line_num;
	int case_n=1;
	while(~scanf("%d",&line_num))
	{
	int case_index=0;
	int max = 0;
	int r;
	int p;
	memset(b,0,2*N*sizeof(int));
	while(case_index <  line_num)
	{
		scanf("%d%d", &p, &r);
		
		/*b[case_index].q = p;
		b[case_index].r = r;*/
		a[p-1]=r;
		case_index++;
	}
	//qsort(b,case_index,sizeof(struct city),cmp);
	/*  int t=0;
	for (; t<case_index; t++)
		printf(" %d %d \n",b[t].q, b[t].r); */
	int i=0;
	int max_low_index = 0;
	max_len = 1;
//	d[0] = b[0].r;
	d[0] = a[0];

  	for (i =1 ;i<case_index; i++)
	{
			if (a[i] > d[max_len -1])
				d[max_len++]=a[i];
			else if (a[i]<d[max_len-1])
			{
		 	max_low_index = binary_search(a[i], 0, max_len-1);
			if (max_low_index == -1)
				continue;
			d[max_low_index] = a[i];
			}
					
	}
  /* for (i = 1; i<case_index; i++)
	{
		if ( b[i].r > d[max_len-1])
		{
			d[max_len++] = b[i].r;
			continue;
		}
		else if (b[i].r < d[max_len-1])
		{
		 max_low_index = binary_search(b[i].r, 0, max_len-1);
		 printf(" %d \n", max_low_index);
		if (max_low_index == -1)
				continue;
			d[max_low_index] = b[i].r;
		}
  }*/
	printf("Case %d:\n",case_n);
	if (max_len <= 1)
  printf("My king, at most %d road can be built.\n\n",max_len);
	else
  printf("My king, at most %d roads can be built.\n\n",max_len);
	case_n++;

	}
}
