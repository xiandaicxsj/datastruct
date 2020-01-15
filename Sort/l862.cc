/*
 * 862. Shortest Subarray with Sum at Least K
 * Hard
 *
 * 705
 *
 * 19
 *
 * Add to List
 *
 * Share
 * Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.
 *
 * If there is no non-empty subarray with sum at least K, return -1.
 *
 *  
 *
 *  Example 1:
 *
 *  Input: A = [1], K = 1
 *  Output: 1
 *  Example 2:
 *
 *  Input: A = [1,2], K = 4
 *  Output: -1
 *  Example 3:
 *
 *  Input: A = [2,-1,2], K = 3
 *  Output: 3
 *   
 *
 *   Note:
 *
 *   1 <= A.length <= 50000
 *   -10 ^ 5 <= A[i] <= 10 ^ 5
 *   1 <= K <= 10 ^ 9
 *   Accepted
 *   20,021
 *   Submissions
 *   87,087
 *
 *   Yes
 *
 *   No
 *   Contributor
 *   ywang172
 */
#include<set>
#include<vector>
#include<iostream>
#define MIN(a, b) ((a) > (b) ? (b) :(a))
using namespace std;
class Point {
	public:
		Point(int _v, int _i):v(_v), i(_i) {};
	long v;
	int i;
};
class mycompare 
{
	public:
		bool operator()(Point p1, Point p2) {
			if (p1.v == p2.v)
				return p1.i < p2.i;
			return p1.v < p2.v;
		}
};

class Solution {
	public:
	int shortestSubarray(vector<int>& A, int K) {
		multiset<Point,mycompare> s;
		multiset<Point,mycompare>::iterator itr; 
		vector<long> sum;
		long sv = 0;
		int i = 0;
		int v = 0;
		int min = -1;

		for (i = 0; i < A.size(); i++) {
			sv += A[i];
			sum.push_back(sv);
		}

		for (i = 0; i < sum.size(); i++) {
			v = sum[i] - K;
			itr = s.lower_bound(Point(v, -1));
			if (itr != s.end()) {
				if (min < 0)
					min = i - itr->i;
				else	
					min = MIN(i - itr->i, min);
			}
			s.insert(Point(v, i));
		}
		return min;
	}
};

int main()
{
	int size;
	int i = 0;
	int v;
	vector<int> array;
	Solution s;

	cin >> size;
	for(i = 0; i < size; i++) {
		cin >>v;
		array.push_back(v);
	}
	cin >> v;
	cout << s.shortestSubarray(array, v);
}

