/* k-based v1 / v2 */
/* how about 0 , is it volaue*/
#include<stdio.h>
int main()
{
	int n = 2;
	int k = 10;
	scanf("%d", &n);
	scanf("%d", &k);

	int a0 = 1;
	int ak = (k -1);
	int tmp0;
	int tmpk;
	int i = 1;
	while(i < n)
	{
		tmp0 = ak ;
		tmpk =  (k - 1) * (a0 + ak);
		a0 = tmp0;
		ak = tmpk;
		i++;
	}
	printf("%d", ak);
}
