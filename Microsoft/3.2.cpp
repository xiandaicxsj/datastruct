/**
 *这是关于电话的一个，我记得有一个.
 *给出一个字符串或者手哦的点击顺序是否可以迅速的查找到相应的单词，这里还没有明确的题目
 *
 */
#include<iostream>
#include<string>
using namespace std;
string c[10]=
{

	"",
	"",
	"ABC",
	"DEF",
	"GHI",
	"JKL",
	"MNO",
	"PQRS",
	"TUV",
	"WXYZ",
};
void Find(int* a,string answer,int i,int size)
{
		int l=0;
		if(i==size)
		{
			cout<<answer<<endl;
			return;
		}
		string t=c[a[i]];
		if(t.length()==0)
		{
			Find(a,answer,i+1,size);
			return ;
		}
		for(int j=0;j<t.length();j++)
		{
				answer=answer+t[j];
				Find(a,answer,i+1,size);
				l=answer.length();	
				answer.erase(l-1,l);
		}
}
int main()
{
		int a[3]={3,5,7};
		int size;
		Find(a,"",0,3);

}



