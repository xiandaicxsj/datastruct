#include<iostream>
using namespace std;
int main()
{

}
//没有进行测试，
void kmp(string str1)
{
		int len=str1.length();
		int *f=new int[len];
		for(int i=0;i<len;i++)
		{
				f[i]=0;
		}
		//下面是否可以从i=0开始呢？不能从0开始
		for(int i=1;i<len;i++)
		{
				int j=f[i];
				while(j&&str1[i]!=str1[j])
				{
						j=f[j];
				}
				f[i+1]=str1[i]==str1[j]?j+1:0;
		}
		
}
