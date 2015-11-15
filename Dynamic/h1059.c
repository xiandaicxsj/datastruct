/*
 * d[i][value] = max{ d[i-1][value], d[i-1][value-v[i]] + v[i] }
 * d[i][value] = d[i-1][value] || (d[i-1][value-v[i]] && v[i]) 
 * 因为只需要是否满足就可以了
 * d[i][value] 代表前i 个物品value是否可以满足
 */
#include<stdio.h>
int main()
{
		
}
