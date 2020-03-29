// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
57. Insert Interval
Hard

1238

143

Add to List

Share
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> ret;
		vector<int> tmp;
		int i = 0;
		bool merged = false;
		int last_v;
		int pre_v;

		for (i = 0; i < intervals.size(); i++)
		{
			tmp = intervals[i];
			if (merged) {
				ret.push_back(tmp);
				continue;
			}
			if (newInterval[0] > tmp[1]) {
				ret.push_back(tmp);
				continue;
			}
			else {
				if (newInterval[0] < tmp[0]) {
					pre_v = tmp[0];
				}
				else
				{
					pre_v = tmp[0];
				}

			}
			if (newInterval[1] < tmp[1]) {
				if (newInterval[1] >= tmp[0]) {
					last_v = tmp[1];
					ret.push_back({ pre_v,last_v });
					merged = true;
				}
				else {
					ret.push_back({ pre_v, newInterval[1] });
					ret.push_back(tmp);
					merged = true;
				}
			}

		}

	}
};

int main()
{

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，