#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{

		priority_queue<int>p_q;
		queue<int>q;
		stack<int>s;
		int p_q_f=0;
		int q_f=0;
		int s_f=0;
		int testCase;
		int op;
		int num;
		while(1)
		{
				cin>>testCase;
				for(int i=0;i<testCase;i++)
				{
						cin>>op;
						cin>>num;
						switch(op)
						{
								case 1:
										if(!p_q_f)
										{
												p_q.push(num);
										}
										if(!q_f)
										{
												q.push(num);
										}
										if(!s_f)
										{
												s.push(num);
										}
											break;
								case 2:
											if(s_f==0&&num==s.top())
											{
													s_f=1;
											}
											if(p_q_f==0&&num==p_q.top())
											{
												p_q_f=1;
											}
											if(q_f==0&&num==q.front())
											{
													q_f=1;
											}
											break;


						}
				}
		}
}
