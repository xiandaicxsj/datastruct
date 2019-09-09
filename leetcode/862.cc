#include<stdio.h>
# if 0
/* this for > 0 array
 */
int shortestSubarray(int* A, int ASize, int K)
{
	int s = 0;
	int e = 0;
	int r = -1;
	int sum = 0;

	while(s < ASize) {
		for (; e < ASize; e++) {
			if (sum >= K) {
				break;
			}
			sum += A[e];
		}

		printf("sum is %d\n", sum);
		if (sum >=K) {
			if (r == -1)
				r = e - s;
			else if ((e - s) < r)
				r = e - s;
		}
		sum -= A[s];
		s++;
	}
	return r;
}
#endif

int shortestSubarray(int* A, int ASize, int K)
{
	return r;
}
int A[200];
int main()
{
	int size;
	int i ;
	int k;
	scanf("%d", &size);
	i = 0;
	while(i < size) {
		scanf("%d", &A[i]);
		i++;
	}
	scanf("%d", &k);
 	printf("%d\n", shortestSubarray(A,size,k));
}

