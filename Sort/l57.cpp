// ConsoleApplication1.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ��