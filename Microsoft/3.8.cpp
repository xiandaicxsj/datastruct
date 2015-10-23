#include<iostream>
//深度遍历的非递归方式就可以 
using namespace std;
typedef struct node
{
	struct node *l;
	struct node *r;
	int max_l;
	int max_r;
	int v;
}node;
void FindMax(node *root);
int MaxV=0;
int main()
{
	node *root=new node;	
	node *l1=new node;
	node *l2=new node;
	node *l3=new node;
	node *l4=new node;
	node *l5=new node;
	root->l=l1;
	root->r=l2;
	l1->l=NULL;
	l2->l=NULL;
	l2->r=l3;
	l3->l=NULL;
	l3->r=NULL;
	l2->l=l4;
	l1->r=l5;
	l4->l=l4->r=NULL;
	l5->l=l5->r=NULL;
	FindMax(root);
	cout<<MaxV<<endl;
}
void FindMax(node *root)
{
		if(!root->l)
				root->max_l=0;
		if(!root->r)
				root->max_r=0;
		if(root->l)
		{
				int tmp;
				FindMax(root->l);
				if(root->l->max_l>root->r->max_r)
				{
						tmp=root->l->max_l;
				}
				else
						tmp=root->l->max_r;
				root->max_l=tmp+1;
		}
		if(root->r)
		{
				int tmp;
				FindMax(root->r);
				if(root->r->max_l>root->r->max_r)
				{
						tmp=root->r->max_l;
				}
				else
						tmp=root->r->max_r;
				root->max_r=tmp+1;
		}
		if(root->max_r+root->max_l+1>MaxV)
		{
				cout<<MaxV<<endl;
				MaxV=root->max_r+root->max_l+1;
		}
}
