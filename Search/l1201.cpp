/*
1201. Ugly Number III
Medium

134

156

Add to List

Share
Write a program to find the n-th ugly number.

Ugly numbers are positive integers which are divisible by a or b or c.



Example 1:

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
Example 2:

Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
Example 3:

Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
Example 4:

Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
Output: 1999999984


Constraints:

1 <= n, a, b, c <= 10^9
1 <= a * b * c <= 10^18
It's guaranteed that the result will be in range [1, 2 * 10^9]
Accepted
6,148
Submissions
24,620
*/
class Solution {
public:
    int f(int mid, int a, int b, int c) {
        return mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;

    }
    int nthUglyNumber(int n, int A, int B, int C) {
        long l = 0;
        long h = 1;
        long m;
        int i = 0;

        long a = long(A), b = long(B), c = long(C);
        ab = a * b / __gcd(a, b);
        bc = b * c / __gcd(b, c);
        ac = a * c / __gcd(a, c);
        abc = a * bc / __gcd(a, bc);
        int min = a > b ? b : a;
        min = min > c ? c : min;
        int count = 0;

        h = 2000000000;

        while (l <= h) {
            m = (l + h) / 2;
            count = f(m, a, b, c);
            if (count < n)
                l = m + 1;
            else/* count >= n */
                h = m - 1;
        }
        return l;
    }
    long bc;
    long ac;
    long abc;
    long ab;
};


int main()
{
    int n;
    int a;
    int b;
    int c;
    Solution s;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    cout << s.nthUglyNumber(n, a, b, c) << endl;


    return 0;

}