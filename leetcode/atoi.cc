#include<iostream>
using namespace std;
//这个应没有问题，需要考虑的是前面有多个＋－的情况,没有空格的情况
class Solution
{
		public:
				int atoi(const char *str)
				{
						//这里是如何判断的是否大于最大或者最小的情况的
						long long max=2147483647;
						long long min=-2147483648;
						int i=0;
						long long sum=0;
						bool reverse=false;
						while(str[i]==' ')
								i++;
						while(str[i]=='-'||str[i]=='+')
						{
								if(str[i]=='+')
								{
										i++;
										continue;
								}
								reverse=!reverse;
								i++;
						}
						while(str[i]!='\0')
						{
								if(str[i]<'0'||str[i]>'9')
									return 0;
								sum=10*sum+str[i]-'0';
								if(reverse)
								{
										if(-sum<min)
												return 0;
								}
									if(sum>max)
											return 0;
								i++;
						}
						return reverse==false?sum:-sum;
				}
};
int main()
{

	Solution s;
	string tmp;
	cin>>tmp;
	cout<<s.atoi(tmp.c_str());
	return 0;
}
