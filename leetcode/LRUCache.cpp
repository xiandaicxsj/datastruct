#include<iostream>
#include<deque>
//这里是需要重新写的需要写成map以及ke
using namespace std;
struct Cache
{
	Cache(int _key,int _value):key(_key),value(_value)
	{
	}
		int key;
		int value;
};
class LRUCache{
	public:
		    LRUCache(int capacity)
				{
						_capacity=capacity;
						size=0;
			  }
				int get(int key)
				{
					int retValue=-1;
					deque<Cache*>::iterator c_iter=cache.begin();
					while(c_iter<cache.end())
					{
							if((*c_iter)->key==key)
							{
									retValue=(*c_iter)->value;
									Cache *t_c=*c_iter;
									cache.erase(c_iter);
									cache.push_back(t_c);
									break;
							}
							c_iter++;
					}

				return retValue;
						
			  }
				 void set(int key, int value) 
				 {
					 int flag=0;
					deque<Cache*>::iterator c_iter=cache.begin();
					while(c_iter<cache.end())
					{
							if((*c_iter)->key==key)
							{
									(*c_iter)->value=value;
									Cache *t_c=*c_iter;
									cache.erase(c_iter);
									cache.push_back(t_c);
									flag=1;
									break;
							}
							c_iter++;
					}
					if(!flag)
					{
							Cache *t_c=new Cache(key,value);
							if(size>=_capacity)
							{
									Cache *t=cache.front();
									cache.pop_front();
									cache.push_back(t_c);
									free(t);
							}
							else
							{
									cache.push_back(t_c);
									size++;
							}
					}
						return ;
				
				 }
	private:
								int _capacity;
								int size;
								deque<Cache*> cache;
};
int main()
{
	LRUCache* l=new LRUCache(2);
	l->set(1,1);
	l->set(2,2);
	cout<<l->get(2)<<endl;
	l->set(3,0);
	cout<<l->get(1)<<endl;
	cout<<l->get(2)<<endl;
	l->set(1,0);
	cout<<l->get(3)<<endl;	
}
