#include<iostream>
#include<vector>
#include<functional>
#include<map>
#include<algorithm>
using namespace std;
typedef function<void()> fp;
class A
{
		public:
				virtual void f()
				{
						cout<<"A::f()"<<endl;
				}
				void p()
				{
						cout<<"p"<<endl;
				}
				void init()
				{
				}
				~A()
				{
						cout<<"~Test"<<endl;
				}
};
void g_fun(int i)
{
		cout<<i<<endl;
		cout<<"In g_fun"<<endl;
}
int main()
{
	/*vector<int> vec_int;
	vec_int.push_back(1);
	vec_int.push_back(2);
	vec_int.push_back(4);
	vec_int.push_back(3);
	map<int,vector<int> > k_map;
	k_map[1]=vec_int;
	for(auto map1=begin(k_map);map1!=end(k_map);map1++)
	{
			cout<<(*map1).first;
	}*/
//	k();

	vector<int> ivec(10,0);
	for_each(ivec.begin(),ivec.end(),[](int n) { cout<<n<<; } );
	return 0;
}
