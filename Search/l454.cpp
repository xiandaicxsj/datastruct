/*
454. 4Sum II
Medium

923

68

Add to List

Share
Given four lists A, B, C, D of integer values, compute how many tuples(i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of - 228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [1, 2]
B = [-2, -1]
C = [-1, 2]
D = [0, 2]

Output :
	2

	Explanation :
	The two tuples are :
1. (0, 0, 0, 1)->A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0)->A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
AC
这个程序确实很精巧，如果是用开始的想法，一层一程的便利的话应该是O(N4)
这个方法的话，是 0(n2)
*/
class Solution {
public:

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> absum;
        int res = 0;
        for (auto a : A)
            for (auto b : B)
                absum[a + b]++;
        for (auto c : C)
            for (auto d : D)
            {
                auto it = absum.find(0 - c - d);
                if (it != absum.end())
                    res += it->second;
            }
        return res;

    }
};