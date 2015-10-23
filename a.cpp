#include<iostream>
using namespace std;
int FindMax(int *array,int len);
int main()
{
	int *array=new int [5];
	array[0]=0;
	array[1]=-11;
	array[2]=1;
	array[3]=2;
	array[4]=3;
	FindMax(array,5);
		return 1;
}

int FindMax(int *array,int len)
{
		int *tmp =new int[len];
		for(int i=0;i<len;i++)
				tmp[i]=array[i];
		int t_begin=0;
		int t_end=0;
		int f_end=0;
		int f_begin=0;
		int max=tmp[0];
		for (int i=1;i<len;i++)
		{
				if(tmp[i-1]<0)
				{
					//cout<<"cc"<<tmp[i-1]<<endl;
					continue;
				}
					tmp[i]=tmp[i-1]+array[i];
					if(tmp[i]>max)
					{
					//		cout<<"dd"<<endl;
							max=tmp[i];
					}
					
		}
		cout<<"Max is"<<max<<endl;
		return 0;

}
