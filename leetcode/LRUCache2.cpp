#include<iostream>
#include<deque>
#include<map>
//这里是需要重新写的需要写成map以及map写下这个内容
//这块代码没问题了
//这里还是不明白哪里出现了问题，对于下面的测试适合是由问题的
using namespace std;
typedef pair<int,int>KV;
typedef deque<KV>::iterator iter;
class LRUCache{
public:
		    LRUCache(int capacity)
				{
						_capacity=capacity;
			  }
				int get(int key)
				{
						int ret=-1;
						map<int,iter>::iterator Iter=map_cache.find(key);
						if(Iter!=map_cache.end())
						{
								iter t_i=Iter->second;
								KV t=*t_i;
								ret=t.second;
								cache.erase(t_i);
								cache.push_back(t);
								iter t_iter=cache.end()-1;
								Iter->second=t_iter;
						}
						return ret;
			  }
				void set(int key, int value) 
				{
						map<int,iter>::iterator Iter=map_cache.find(key);
						if(Iter!=map_cache.end())
						{
								iter t_i=Iter->second;
								KV t=*t_i;
								t.second=value;
								cache.erase(t_i);
								deque<KV>::iterator t_iter=cache.end();
								Iter->second=t_iter;
								cache.push_back(t);
						}
						else
						{
								if(map_cache.size()>=_capacity)
								{
										KV t=cache.front();
										cache.pop_front();
										map_cache.erase(map_cache.find(t.first));
								}
								cache.push_back(KV(key,value));
								iter t=cache.end()-1;
								map_cache[key]=t;	
						}
				}
	private:
								int _capacity;
								deque<KV> cache;
								map<int,iter>map_cache;
};
int main()
{
	LRUCache* l=new LRUCache(10);
	l->set(10,13);
	l->set(3,17);
	l->set(6,11);
	l->set(10,5);
	l->set(9,10);
	cout<<l->get(13)<<endl;
	l->set(2,19);
	cout<<l->get(2)<<endl;
	cout<<l->get(3)<<endl;
	l->set(5,25);
	cout<<l->get(8)<<endl;
	l->set(9,22);
	l->set(5,5);
	l->set(1,30);
	cout<<l->get(11)<<endl;
	l->set(9,12);
	cout<<l->get(7)<<endl;
	cout<<l->get(5)<<endl;
	cout<<l->get(8)<<endl;
	cout<<l->get(9)<<endl;
	l->set(4,30);
	l->set(9,3);
	cout<<l->get(9)<<endl;
	cout<<l->get(10)<<endl;
	cout<<l->get(10)<<endl;
	l->set(6,14);
	l->set(3,1);
	cout<<l->get(3)<<endl;
	l->set(10,11);
	cout<<l->get(8)<<endl;
	l->set(2,14);
	cout<<l->get(1)<<endl;
	cout<<l->get(5)<<endl;
	cout<<l->get(4)<<endl;
	l->set(11,4);
	l->set(12,24);
	l->set(5,18);
	cout<<l->get(13)<<endl;
	l->set(7,23);
	cout<<l->get(8)<<endl;
	cout<<l->get(12)<<endl;
	l->set(3,27);
	l->set(2,12);
	cout<<l->get(5)<<endl;
	l->set(2,9);
	l->set(13,4);
	l->set(8,18);
	l->set(1,7);
	cout<<l->get(6)<<endl;
	l->set(9,29);
	l->set(8,21);
	cout<<l->get(5)<<endl;
	l->set(6,30);
	l->set(1,12);
	cout<<l->get(10)<<endl;
	l->set(4,15);
	l->set(7,22);
	l->set(11,26);
	l->set(8,17);
	l->set(9,29);
	cout<<l->get(5)<<endl;
	l->set(3,4);
	l->set(11,30);
	cout<<l->get(12)<<endl;
	l->set(4,29);
	cout<<l->get(3)<<endl;
	cout<<l->get(9)<<endl;
	cout<<l->get(6)<<endl;
	l->set(3,4);
	cout<<l->get(1)<<endl;
	cout<<l->get(10)<<endl;
	l->set(3,29);
	l->set(10,28);
	l->set(1,20);
	l->set(11,13);
	cout<<l->get(3)<<endl;
	l->set(3,12);
	l->set(3,8);
	l->set(10,9);
	l->set(3,26);
	cout<<l->get(8)<<endl;
	cout<<l->get(7)<<endl;
	cout<<l->get(5)<<endl;
	l->set(13,17);
	l->set(2,27);
	l->set(11,15);
	cout<<l->get(12)<<endl;
	l->set(9,19);
	l->set(2,15);
	l->set(3,16);
	cout<<l->get(1)<<endl;
	l->set(12,17);
	l->set(9,1);
	l->set(6,19);
	cout<<l->get(4)<<endl;
	cout<<l->get(5)<<endl;
	cout<<l->get(5)<<endl;
	l->set(8,1);
	l->set(11,7);
	l->set(5,2);
	l->set(9,28);
	cout<<l->get(1)<<endl;
	l->set(2,2);
	l->set(7,4);
	l->set(4,22);
	l->set(7,24);
	l->set(9,26);
	l->set(13,28);
	l->set(11,26);}
