#include<iostream>
#include<string>
using namespace std;
	float abs(float i)
	{
			if(i<0)
				i=-i;
			return i;
	}
int main()
{
	int num;
	cin>>num;
	float num1;
	char op;
	float num2;
	float min_value=9;
	int min_index=0;
	int flag=0;
	for(int i=0;i<num;i++)
	{
			float ret=0;
			cin>>num1;
			cin>>op;
			cin>>num2;
			if(flag)
			continue;
			if(op=='+')
				ret=num1+num2;
			if(op=='-')
				ret=num1-num2;
			if(op=='*')
				ret=num1*num2;
			if(op=='/')
				ret=num1/num2;
			ret=abs(ret-9);
			if(ret<min_value)
			{
					min_value=ret;
					min_index=i+1;
					if(ret==0)
						flag=1;
			}

	}
	cout<<min_index;
} 
