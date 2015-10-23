#include<iostream>
#include<string>
using namespace std;

int main()
{
		int text_case;
		int case_num=0;
		string A;
		int len_a;
		string B;
		char c='0';
		int len_b;
		int max_len;
		cin>>text_case;
		while(case_num<text_case)
		{
				string res;
				string res1;
				char t; 
				c='0';
				cin>>A;
				cin>>B;
				len_a=A.length();
				len_b=B.length();
				while(len_a>0&&len_b>0)
				{
						t=(A[len_a-1]-'0'+B[len_b-1]-'0'+c-'0')%10+'0';
						c=(A[len_a-1]-'0'+B[len_b-1]-'0'+c-'0')/10+'0';
						len_a--;
						len_b--;
						res=res+t;
				}
				if(len_a==0&&len_b==0&&c!='0')
					{
							res=res+c;
					}
				while(len_a>0)
				{
						t=(A[len_a-1]-'0'+c-'0')%10+'0';
						c=(A[len_a-1]-'0'+c-'0')/10+'0';
						len_a--;
						res=res+t;
				}
				while (len_b>0)
				{
						t=(B[len_b-1]-'0'+c-'0')%10+'0';
						c=(B[len_b-1]-'0'+c-'0')/10+'0';
						len_b--;
						res=res+t;
				}
				int i=res.length();
				while(i>0)
				{
						res1=res1+res[i-1];
						i--;
				}
				cout<<"Case "<<case_num+1<<':'<<endl;
				cout<<A<<' '<<'+'<<' '<<B<<' '<<'='<<' '<<res1<<endl;
				case_num++;
				if(case_num<text_case)
				cout<<endl;
			}

	return 0;
}

