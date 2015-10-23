#include<iostream>
using namespace std;
template <unsigned long n>
/*struct binary
{
		static unsigned const value=binary<n/10>::value*2+n%10;

};
template<>
struct binary<0>
{
	static unsigned const value=0;

};
*/
//这里想测试下类型的萃取但是还是有问题的
template <typename T>
struct r_type_traits
{
	typedef T value_type;
};
int main()
{
	r_type_traits<int>::value_type i;
	cout<<sizeof(i);
} 
