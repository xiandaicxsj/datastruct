/*
 * d[i][value] = max{ d[i-1][value], d[i-1][value-v[i]] + v[i] }
 * d[i][value] = d[i-1][value] || (d[i-1][value-v[i]] && v[i]) 
 * 因为只需要是否满足就可以了
 * d[i][value] 代表前i 个物品value是否可以满足
 */
#include<stdio.h>
#define N 3000
int d[N][N] ={0};
int value[N] ={0};
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
		scanf("%d", &tmp);
		for (j=0; j<tmp; j++)
		{ 
			end = 0;
			value[index++] = m_a;
			max_value += m_a;
		}
		m_a++;
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
	d[1][value[1]] = 1;	
	int i=2;
	for (; i<index; i++)
	{
		int j_v = 0;
		d[i][j_v] = 1;

		for (j_v; j_v<= max_value; j_v++)
		{
			d[i][j_v] = (d[i-1][j_v]) || (j_v > value[i] ? (d[i-1][j_v - value[i]]) :0);
		}

		if (d[i][max_value])
		{
			found =1;
			break;
		}
	}
	if (found)
	{
		printf("Collection #%d:\n", test_case);
		printf("Can be divided.\n\n");
	}
	else
	{
		printf("Collection #%d:\n", test_case);
		printf("Can't be divided.\n\n");
	}
	}
	return 0;

}
