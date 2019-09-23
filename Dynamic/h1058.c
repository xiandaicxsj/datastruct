/*  this should be the format problem need to track ?? */
/*
 *
 * Problem Description
 * A number whose only prime factors are 2,3,5 or 7 is called a humble number. The sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, ... shows the first 20 humble numbers.
 *
 * Write a program to find and print the nth element in this sequence
 *  
 *
 *  Input
 *  The input consists of one or more test cases. Each test case consists of one integer n with 1 <= n <= 5842. Input is terminated by a value of zero (0) for n.
 *   
 *
 *   Output
 *   For each test case, print one line saying "The nth humble number is number.". Depending on the value of n, the correct suffix "st", "nd", "rd", or "th" for the ordinal number nth has to be used like it is shown in the sample output.
 *    
 *
 *    Sample Input
 *    1
 *    2
 *    3
 *    4
 *    11
 *    12
 *    13
 *    21
 *    22
 *    23
 *    100
 *    1000
 *    5842
 *    0
 *     
 *
 *     Sample Output
 *     The 1st humble number is 1.
 *     The 2nd humble number is 2.
 *     The 3rd humble number is 3.
 *     The 4th humble number is 4.
 *     The 11th humble number is 12.
 *     The 12th humble number is 14.
 *     The 13th humble number is 15.
 *     The 21st humble number is 28.
 *     The 22nd humble number is 30.
 *     The 23rd humble number is 32.
 *     The 100th humble number is 450.
 *     The 1000th humble number is 385875.
 *     The 5842nd humble number is 2000000000.
 *      
 *
 *      Source
 *      University of Ulm Local Contest 1996
 *      STAUS: W
 */
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
