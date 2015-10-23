#include<iostream>
#include<vector>
using namespace std;
struct node
{
	public:
	node(int _v)
	{
			l=NULL;
			r=NULL;
			v=_v;
	}
	int v;
	node *l;
	node *r;
};
node *Tree;
void TraverseTree(node *tree)
{
		vector<node*> traList;
		traList.push_back(tree);
		int cur=0;
		int last=0;
		last=1;
		while(cur!=last)
		{
				node *t=traList[cur];
				cout<<t->v<<" ";
				if(t->l)
				traList.push_back(t->l);
				if(t->r)
				traList.push_back(t->r);
				cur++;	
				if(cur==last)
				{
					cout<<endl;
						last=traList.size();
				}
		} 
}
int main()
{
		node *l1=new node(1);
		node *l2=new node(2);
		node *l3=new node(3);
		node *l4=new node(4);
		node *l5=new node(5);
		l1->l=l2;
		l1->r=l3;
		l2->l=l4;
		l4->l=l5;
		TraverseTree(l1);
		return 0;
}
