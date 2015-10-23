#include<iostream>
#include<string>
using namespace std;
void PiPei(string str1,int *f)//得到相应的匹配序列
{

		int length=str1.length();
		f[0]=0;
		f[1]=0;
		int j;
		for(int i=1;i<length;i++)
		{
				j=f[i];
				while(j&&str1[i]!=str1[j])
						j=f[j];
				f[i+1]=str1[i]==str1[j]?j+1:j;//这里最后写j或者0都是可以的
		}
}
int main()
{
		string str1="abracadabra";
		int size=str1.length();
		int *array=new int[size+1];
		PiPei(str1,array);
		string str2="aaa"+str1+"bbb";
		int j=0;
		int i=0;
		int manIndex=0;
		for(i=0;i<str2.length();i++)
		{
						if(str2[i]==str1[j]&&j<=str1.length())
						{	
								j++;
								continue;
						}
						if(j==str1.length())
						{
								cout<<manIndex<<endl;
								cout<<"KMP"<<endl;
								break;
						}
						j=array[j];
		}
}

