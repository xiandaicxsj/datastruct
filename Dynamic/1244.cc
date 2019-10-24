/*
 *
 * Problem Description
 * 给定一个由n个正整数组成的整数序列
 *
 * a1 a2 a3 ... an
 *
 * 求按先后次序在其中取m段长度分别为l1、l2、l3...lm的不交叠的连续整数的和的最大值。
 *  
 *
 *  Input
 *  第一行是一个整数n(0 ≤ n ≤ 1000)，n = 0表示输入结束
 *  第二行的第一个数是m(1 ≤ m ≤ 20)，
 *  第二行接下来有m个整数l1，l2...lm。
 *  第三行是n个整数a1, a2, a2 ... an.
 *   
 *
 *   Output
 *   输出m段整数和的最大值。
 *    
 *
 *    Sample Input
 *    3
 *    2 1 1
 *    1 2 3
 *    4
 *    2 1 2
 *    1 2 3 5
 *    0
 *     
 *
 *     Sample Output
 *     5
 *     10
 *
 */


int array[MAX];
int dp[i][j];
int steps[MAX];

int cal_per(int b, int e, int num)
{

	int b1 = b;
	int e1 = e + num - 1;
	int sum = 0;
	int res ;

	if (e - b + 1 < num)
		return 0;

	for (int i = b1; i < b1 + num; i ++)
		sum += array[b1];

	ret = sum;

	while(e1 <= e) {
		sum -= array[b1];
		b1++;
		e1 ++;
		sum += array[e1];
		res = max(sum, res);
	}

	return sum;

#ifdef 0
	int sum = 0;
	int b1 = b;
	int e1 = b;
	int res;

	sum = array[e1];
	if (b == e)
		return sum;

	res = sum;
	e1++;

	while(e1 < e) {
		if (sum < 0) {
			b1 = e1;
			sum = array[e1]; 
			e1 ++;
			continue;
		}
		res = max(res, sum);
		sum += array[e1];
		e1 ++;
	}

	return res;
#endif
}

int cal_max(int a_num, int step)
{
	int n = 0;
	int s = 1;
	int k = 0;

	for(n = 0; n < a_num, n++) {
		for (s = 0; s<= step; s++)
			dp[n][s] = 0;
	}

	for (s = 1; s <= step; s++) {
		for(n = 0; n < a_num, n++) {
			for (k = 0; k < n; k++)
				dp[n][s] = max(dp[n][s], dp[k][s-1] + cal_per(k + 1, n, steps[s]));
		}
	}
}

int main()
{
	int a_num;
 
}
