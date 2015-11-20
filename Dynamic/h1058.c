/*  this should be the format problem need to track ?? */
#include<stdio.h>
#define N 5843
long long a[N];
long long max(long long a, long long b, long long c, long long d)
{
		long long max = a;
		if (b < max)
				max = b;
		if (c < max)
				max = c;
		if (d < max)
				max = d;
		return max;
}
int main()
{
	int two=0;
	int three=0;
	int five=0;
	int seven=0;
	int order;
	int case_index;
	a[0] =1;
	long long two_a;
	long long three_a;
	long long five_a;
	long long seven_a;
	case_index=1;
	while(scanf("%d", &order),order)
	{
		while(case_index < order)
		{
			two_a = a[two] *2;
			three_a = a[three] *3;
			five_a = a[five] *5;
			seven_a = a[seven] *7;
			long long max_a;
			max_a = max(two_a, three_a, five_a, seven_a);
			
			if (two_a == max_a)
				two++;
			if (three_a == max_a)
				three++;	
			if (five_a == max_a)
				five++;
			if (seven_a == max_a)
				seven++;
			a[case_index++] =  max_a;
		}
		if ( ((order % 10) == 1) && !(order <=20 && order >=10))
			printf("The %dst humble number is %lld.\n", order, a[order-1]);
		else if ( ((order % 10)==2) && !(order <=20 && order >=10))
			printf("The %dnd humble number is %lld.\n", order, a[order-1]);
		else if ( ((order % 10) ==3) && !(order <=20 && order >=10))
			printf("The %drd humble number is %lld.\n", order, a[order-1]);
		else printf("The %dth humble number is %lld.\n", order, a[order-1]);
	}
	return 0;
}
