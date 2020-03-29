// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
1235. Maximum Profit in Job Scheduling
Hard

240

3

Add to List

Share
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime , endTime and profit arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.



Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:




Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.
Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6


Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
1 <= startTime[i] < endTime[i] <= 10^9
1 <= profit[i] <= 10^4
Accepted
6,170
Submissions
14,012
SATUS:
AC
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

class job {
public:
	int st;
	int et;
	int pf;
};
bool sort_fn(const job& x, const job& y)
{
	return x.st < y.st;
}
using namespace std;
class Solution {
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int jsize = startTime.size();
		int i = 0;
		int max;
		vector<job> joblist;
		int dsize = *max_element(endTime.begin(), endTime.end());
		long* dp;

		dp = (long*)malloc(sizeof(long) * (dsize + 1));
		memset(dp, 0, sizeof(long) * (dsize + 1));
		//cout << "dsize" << dsize << endl;
		for (i = 0; i < jsize; i++) {
			job j;
			j.st = startTime[i];
			j.et = endTime[i];
			j.pf = profit[i];
			joblist.push_back(j);
		}
		sort(joblist.begin(), joblist.end(), sort_fn);
		int pre_st = 0;
		int pre_max = -1;
		for (auto j : joblist) {
			//cout << j.st << " " << j.et << endl;
			while (pre_st <= j.st) {
				pre_max = MAX(dp[pre_st], pre_max);
				dp[pre_st] = pre_max;
				pre_st++;
			}

			dp[j.et] = MAX(dp[j.et], dp[j.st] + j.pf);
			pre_st = j.st;
		}
		max = numeric_limits<int>::min();

		for (i = 0; i <= dsize; i++)
		{
			//cout << dp[i] << endl;
			max = MAX(max, dp[i]);
		}
		return max;
	}

};

int main()
{
	Solution s;
	int num;
	vector<int> st;
	vector<int> e;
	vector<int> p;
	vector<int> ret;
	int i = 0;

	cin >> num;
	while (i < num) {
		int t;
		cin >> t;
		st.push_back(t);
		i++;
	}
	i = 0;
	while (i < num) {
		int t;
		cin >> t;
		e.push_back(t);
		i++;
	}
	i = 0;
	while (i < num) {
		int t;
		cin >> t;
		p.push_back(t);
		i++;
	}
	cout << s.jobScheduling(st, e, p);

}