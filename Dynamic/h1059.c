/*
 * d[i][value] = max{ d[i-1][value], d[i-1][value-v[i]] + v[i] }
 * d[i][value] = d[i-1][value] || (d[i-1][value-v[i]] && v[i]) 
 * 因为只需要是否满足就可以了
 * d[i][value] 代表前i 个物品value是否可以满足
 */
#include<stdio.h>
#define N 500001
int d[N] ={0};
int num[N] ={0};
void complete_bag(int value, int num, int max_value)
{
	int j = value;
	for (; j<= max_value; j++)
		d[j] = d[j-value] + value;	
}
void zero_bag(int value, int num, int max_value)
{
	int j=max_value;
	for (; j >=value; j--)
	 	d[j] = d[j-value] +value;
}
int multi_bag(int value, int num, int max_value)
{
	if (num*value > max_value)
	{
		complete_bag(value, num, max_value);
	}
	else
		zero_bag(value, num, max_value);
	return 0;
}
int main()
{
	int test_case=0;
	while (1)
	{
		test_case ++;
	int found =0;
	int tmp;
	int index=1;
	int m_a=1;
	int j=0;
	int max_value=0;
	int k=0;
	int end=1;
	for ( ; k<6;k++)
	{
		scanf("%d", &(num[k]));
		max_value += num[k]*(k+1);
	}
	if (max_value ==0)
		break;
	if (max_value %2 !=0)
	{
		printf("Collection #%d:\n", test_case);
		printf("Can't be divided.\n");
		continue;
	}
	max_value = max_value >> 1;
	int i=1;
	for (; i<6; i++)
		if (num[i])
			multi_bag(i+1, num[i], max_value);
	//printf("max_value is %d %d\n", max_value, d[max_value]);
	if (d[max_value] == max_value)
	{
		printf("Collection #%d:\n", test_case);
		printf("Can be divided.\n");
	}
	else
	{
		printf("Collection #%d:\n", test_case);
		printf("Can't be divided.\n");
	}
	}
	return 0;

}
