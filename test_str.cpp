#include<iostream>
#include<string>
using namespace std;
int main()
{
		string s1("blue key");
		int begin=0;
		int end=s1.find("a",begin);
		string substr=s1.substr(begin,end-1);
		string::iterator b_iter=s1.begin();
		string::iterator r_iter=s1.end();
		//string::reverse_iterator r_iter=s1.rbegin();
		r_iter--;
		while(b_iter<=r_iter)
		{
				cout<<"end is "<<*r_iter<<endl;
				cout<<"begin is"<<*b_iter<<endl;
				cout<<endl;
				char tmp=*r_iter;
				*r_iter=*b_iter;
				*b_iter=tmp;
				b_iter++;
				r_iter--;
		}
		cout<<s1<<endl;

		


}
