#include<stdio.h>
int binary_search(int *d, int value, int _begin, int _end)
{
     int begin = _begin;
     int end = _end;
     while (begin <= end)
     {
	       int mid = (begin + end) >> 1;
				 if ( value == d[mid] )  return mid;
				 if ( value > d[mid] ) begin = mid+1;
				 else
				 end = mid - 1;
		 }
		 return end;
}
