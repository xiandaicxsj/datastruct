#include<iostream>
using namespace std;
#define MAX 1000001
int array[MAX];
int sum[MAX];
int b[MAX];
int Ca(int * array, int size)
{
	int max = -1000;
	int end_index=0;
	sum[0] = array[0];
	
	for ( int i = 0; i < size; i++)
		b[i]=i;
	for(int i = 1; i < size ;i++)
	{
		  if ( sum[i-1] + array[i] >= array[i] )
			{
					sum[i] = sum[i-1] + array[i];
					b[i]=b[i-1];
			}
			else
					sum[i] = array[i];
			//cout<<sum[i]<<endl;
			if ( sum[i] > max)
			{
				max=sum[i];
				end_index=i;
			}
	}
	cout<<max<<" "<<b[end_index]+1<<" "<<end_index+1<<endl;
	return 0;
}
int main()
{
	int case_num;
	cin>>case_num;
	int case_index = 0;
	while ( case_index < case_num )
	{
			int case_nn;
			cin>>case_nn;
			int i=0;
			while( i < case_nn )
			{
				cin>>array[i];
				i++;
			}
			cout<<"Case "<<case_num<<":"<<endl;
			Ca(array,case_nn);
			case_index++;
	}
	return 0;
}


