#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
	int shortestSubarray(vector<int>& A, int K) {
	    int e = 0;
	    int min = 0xfffffff;
	    deque<int> d;
	    vector<int> sum;
	    int tmp = 0;

	    while(e < A.size()) {
		    tmp += A[e];
		    sum.push_back(tmp);
		    e++;
	    }

	    e++;
	    while(e < A.size())
	    {
		while(!d.empty() && (A[e] - A[d.front()]) >= K) {
			if (min > (e - d.front() + 1))
				min = e - d.front();
			d.pop_front();
		}
		while(!d.empty() && A[e] >= A[d.back()])
			d.pop_back();
		d.push_back(e);
		e++;
	    }
	    return min;
    }
};
int main()
{
	int i = 0;
	int num = 0;
	int k = 0;
	int t;
	int r;
	Solution s;
	vector<int> nums;

	cin >> num;
	while (i < num) {
		cin  >> t;
		nums.push_back(t);
		i ++;
	}
	cin >> k;
	r = s.shortestSubarray(nums, k);
	cout << r;
	return 0;
}
