#include<iostream>
#include<string>
using namespace std;
int main()
{

		string s="abcd";
		s.erase(s.length()-1,s.length());
		cout<<s;
}
