/*
 * It is well known that a human gene can be considered as a sequence, consisting of four nucleotides, which are simply denoted by four letters, A, C, G, and T. Biologists have been interested in identifying human genes and determining their functions, because these can be used to diagnose human diseases and to design new drugs for them.
 *
 * A human gene can be identified through a series of time-consuming biological experiments, often with the help of computer programs. Once a sequence of a gene is obtained, the next job is to determine its function. One of the methods for biologists to use in determining the function of a new gene sequence that they have just identified is to search a database with the new gene as a query. The database to be searched stores many gene sequences and their functions – many researchers have been submitting their genes and functions to the database and the database is freely accessible through the Internet.
 *
 * A database search will return a list of gene sequences from the database that are similar to the query gene. Biologists assume that sequence similarity often implies functional similarity. So, the function of the new gene might be one of the functions that the genes from the list have. To exactly determine which one is the right one another series of biological experiments will be needed.
 *
 * Your job is to make a program that compares two genes and determines their similarity as explained below. Your program may be used as a part of the database search if you can provide an efficient one.
 *
 * Given two genes AGTGATG and GTTAG, how similar are they? One of the methods to measure the similarity of two genes is called alignment. In an alignment, spaces are inserted, if necessary, in appropriate positions of the genes to make them equally long and score the resulting genes according to a scoring matrix.
 *
 * For example, one space is inserted into AGTGATG to result in AGTGAT-G, and three spaces are inserted into GTTAG to result in –GT--TAG. A space is denoted by a minus sign (-). The two genes are now of equal length. These two strings are aligned:
 *
 * AGTGAT-G
 * -GT--TAG
 *
 *  In this alignment, there are four matches, namely, G in the second position, T in the third, T in the sixth, and G in the eighth. Each pair of aligned characters is assigned a score according to the following scoring matrix.
 *
 *  * denotes that a space-space match is not allowed. The score of the alignment above is (-3)+5+5+(-2)+(-3)+5+(-3)+5=9.
 *
 *  Of course, many other alignments are possible. One is shown below (a different number of spaces are inserted into different positions):
 *
 *  AGTGATG
 *  -GTTA-G
 *
 *  This alignment gives a score of (-3)+5+5+(-2)+5+(-1) +5=14. So, this one is better than the previous one. As a matter of fact, this one is optimal since no other alignment can have a higher score. So, it is said that the similarity of the two genes is 14.
 *   
 *
 *   Input
 *   The input consists of T test cases. The number of test cases ) (T is given in the first line of the input. Each test case consists of two lines: each line contains an integer, the length of a gene, followed by a gene sequence. The length of each gene sequence is at least one and does not exceed 100.
 *    
 *
 *    Output
 *    The output should print the similarity of each test case, one per line.
 *     
 *
 *     Sample Input
 *
 *     2 
 *     7 AGTGATG 
 *     5 GTTAG 
 *     7 AGCTATT 
 *     9 AGCTTTAAA 
 *
 *      
 *
 *      Sample Output
 *
 *      14 
 *      21 
 *
 *       
 *
 *       Source
 *       Asia 2001, Taejon (South Korea)
 */
 /*  AGTGATG
  *  -GTTA-G
  */
/* max str problem */
/* 
 * dp[i][j] means the score of 
 * between i - j 
 * STATUS:
 * T
 *
 */
#include<iostream>
#include<string>

using namespace std;
#define MAX_NUM 1000
int dp[MAX_NUM][MAX_NUM] = {0};
int max(int a, int b , int c)
{
	int r;
	r = a > b ? a: b;
	r = c > r?  c: r;
	return r;
}

int cal_max_score(string a, string b)
{
	int a_s = a.size();
	int b_s = b.size();
	int i = 0;
	int j = 0;
	int score[100][100];

	score['A']['A'] = 5;
	score['A']['C'] = -1;
	score['A']['G'] = -2;
	score['A']['T'] = -1;
	score['A']['-'] = -3;
	score['C']['A'] = -1;
	score['C']['C'] = 5; 
	score['C']['G'] = -3; 
	score['C']['T'] = -2; 
	score['C']['-'] = -4;
	score['G']['A'] = -2;
	score['G']['C'] = -3;
	score['G']['G'] = 5; 
	score['G']['T'] = -2; 
	score['G']['-'] = -2; 
	score['T']['A'] = -1; 
	score['T']['C'] = -2; 
	score['T']['G'] = -2; 
	score['T']['T'] = 5; 
	score['T']['-'] = -1; 
	score['-']['A'] = -3; 
	score['-']['C'] = -4; 
	score['-']['G'] = -2; 
	score['-']['T'] = -1; 
	score['-']['-'] = -1000000; 
	dp[0][0] = 0;
	for (i = 1; i<= a_s; i++)
		dp[i][0] = dp[i -1][0] + score[a[i-1]]['-'];

	for (j = 1; j<= b_s; j++)
		dp[0][j] = dp[0][j - 1] + score['-'][b[j-1]];


	for (i = 1; i <= a_s; i++) {
		for (j = 1; j <= b_s; j++) {
			dp[i][j] = max(dp[i-1][j-1] + score[a[i-1]][b[j-1]],
				       dp[i-1][j] + score[a[i-1]]['-'],
				       dp[i][j - 1] + score['-'][b[j-1]]);
		}
	}
	printf("%d\n", dp[a_s][b_s]);
	return 0;
}

int main()
{
	string a;
	string b;
	cin >> a;
	cin >> b;
	cal_max_score(a, b);
	return 0;
}
