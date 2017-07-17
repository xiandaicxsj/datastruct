/*
 * MAX SUM PLUS PLUS
 * Problem Description
 * Now I think you have got an AC in Ignatius.L's "Max Sum" problem. To be a brave ACMer, we always challenge ourselves to more difficult problems. Now you are faced with a more difficult problem.
 *
 * Given a consecutive number sequence S1, S2, S3, S4 ... Sx, ... Sn (1 ≤ x ≤ n ≤ 1,000,000, -32768 ≤ Sx ≤ 32767). We define a function sum(i, j) = Si + ... + Sj (1 ≤ i ≤ j ≤ n).
 *
 * Now given an integer m (m > 0), your task is to find m pairs of i and j which make sum(i1, j1) + sum(i2, j2) + sum(i3, j3) + ... + sum(im, jm) maximal (ix ≤ iy ≤ jx or ix ≤ jy ≤ jx is not allowed).
 *
 * But I`m lazy, I don't want to write a special-judge module, so you don't have to output m pairs of i and j, just output the maximal summation of sum(ix, jx)(1 ≤ x ≤ m) instead. ^_^
 *  
 *
 *  Input
 *  Each test case will begin with two integers m and n, followed by n integers S1, S2, S3 ... Sn.
 *  Process to the end of file.
 *   Output
 *   Output the maximal summation described above in one line.
 *    
 *
 *    Sample Input
 *
 *    1 3 1 2 3
 *    2 6 -1 4 -2 3 -2 3
 *
 *     
 *
 *     Sample Output
 *
 *     6
 *     8
 *
 *     Hint
 *
 *     Huge input, scanf and dynamic programming is recommended.
 */

/* thinking 
 * dp[num][k] means the max sum value of (0 - num) have k pair 
 * dp[num][k] = v[k] < 0 max(dp[j][k]) 0 < j <num -1
 * 		v[k] > 0 max(dp[j][k - 1] + cal_one(v[j], v[k]): 0 < j <num -1)
 *
 *
 */
