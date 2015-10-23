#include<iostream>
#include<vector>
using namespace std;
class A
{
		public:
			A(int _i,int _j)
			{
				i=_i;
				j=_j;
			}
				int i;
				int j;
};

int main()
{
		vector<A> v_a;
		v_a.push_back(A(1,2));
}
