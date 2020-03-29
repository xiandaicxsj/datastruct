
/*
81. Search in Rotated Sorted Array II
Medium

972

407

Add to List

Share
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
Accepted
210,079
Submissions
638,412
AC status;
Slotion1:
retotate sort ��ؼ������������Ѱ��retotate����Ŀ��
1.�������ö��ַ�����rotate�˼���Ԫ�ء�
2.Ȼ�����ö��ַ�����target���Ǽ��϶�Ӧ��ƫ�Ƽ��ɡ�

�������ظ�������˵��Ҫ������ǻ���1. Ѱ��ƫ�ƵĹ��̣��Ƚϸ��ӡ���ʵѰ��ƫ��Ҳ��Ѷ��nums �����ֵ����Сֵ�ı߽硣
��û���ظ����ݵ�����¡�
����
nums[m] > nums[h] l = m + 1 ������Ϊ����ȷ����֪��m��Ӧ��Ԫ�ز�����С��Ԫ��,���Կ��Զ�����m
nums[m] < nums[h] h = m  ���������޷�ȷ������m ��Ӧ��Ԫ���Ƿ�Ϊ��С�����Բ��ܶ��� m
����ĵȺ�û�б�Ҫ

�������ظ����ݵ������˵��
nums[m] > nums[h] l = m + 1
nums[m] < nums[h] h = m
nums[m] ==  nums[h] && nums[m] == nums[l] ��������������޷�֪����ǰ�������Ǵ����� [l-m] ���Ǵ�����
m - h, ������Ҫ����m - h �Ƿ���� nums[t_m] (m < t_m < h) != nums[m], �������˵��ƫ����[m - h] ��
��������ڣ�˵��ƫ����[l-h]�С�

Solutions 2:
ֱ��ѡ������ƫ�ƣ�
ѡ�� m ���ж�[l-m] ��˳��ģ����� [m -h] ��ѭ��ģ�
���� [l-m] ������ģ�
nums[m] > target > nums[l] ˵��target�� l -  ���档 h = m -1;
���治�����Ļ�������˵ target �� [m-h]���棬ֱ�� l = m + 1;

ͬ�����[m - h] ������ġ�Ҳ��һ����



    */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int m = 0;
        int rote = 0;
        int rm = 0;
        int size = nums.size();

        while (l < h) {
            m = (l + h) / 2;
            if (nums[m] < nums[h])
                h = m;
            else if (nums[m] > nums[h])
                l = m + 1;
            else
            {

                if (nums[m] != nums[l])
                    h = m;
                else
                {
                    int t_m = m;
                    while (t_m <= h && nums[t_m] == nums[h]) t_m++;
                    if (t_m != h + 1)
                        l = t_m;
                    else
                        h = m;
                    /* nums[m] == nums[l] == nums[h]*/
                   // l = m + 1;
                }

                //
            }
        }
        //cout << l;
        rote = l;
        // return rote;
        l = 0;
        h = nums.size() - 1;
        while (l <= h) {
            m = (l + h) / 2;
            rm = (m + rote) % size;
            if (nums[rm] == target)
                return true;
            if (target > nums[rm])
                l = m + 1;
            else
                h = m - 1;
        }
        return false;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int m = 0;
        int rote = 0;
        int rm = 0;
        int size = nums.size();

        while (l <= h) {
            m = (l + h) / 2;
            if (nums[m] == target)
                return true;

            if (nums[m] == nums[l] && nums[m] == nums[h])
            {
                l++;
                h--;
                continue;

            }
            if (nums[m] >= nums[l])
            {
                /* l - m is order*/
                if (target < nums[m] && target >= nums[l])
                    h = m - 1;
                else
                    l = m + 1;
                continue;
            }

            if (nums[m] <= nums[h])
            {
                if (target > nums[m] && target <= nums[h])

                    l = m + 1;
                else
                    h = m - 1;
                continue;
                /* m - h is order*/
            }

        }

        return false;
    }
};
void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
        }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        bool ret = Solution().search(nums, target);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
#ifdef DEBUG
int main() {
    int n;
    vector<int> v;
    cin >> n;
    int i = 0;
    int t = 0;
    Solution s;

    for (i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }
    cin >> t;
    cout << s.search(v, t);
    return 0;

}
#endif