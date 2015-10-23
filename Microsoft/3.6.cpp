#include<iostream>
using namespace std;
typedef struct node
{
	int value;
	node* next;
}node;
node *TwoListMerge(node *first,node *second);
node *Loop(node *head);
int main()
{
	node *a=new node;
	a->value=1;

	node *b=new node;
	b->value=2;

	node *c=new node;
	c->value=3;

	node *d=new node;
	d->value=4;
	
	node *e=new node;
	e->value=5;
	 
	 a->next=c;
	 b->next=c;
	 c->next=d;
	 d->next=e;
	 e->next=NULL;
	 //node *k=Loop(a);
	 node *k=TwoListMerge(a,b);
	 cout<<k->value;
	return 0;
}
/* 
* sPtr=2*fPtr   fPtr=p+n*l+a   sPter=fPter+m*l
* p: 头结点到循环入口点距离
* a: fPtr 离循环入口点的距离
* l: 为循环的长度 
 * 2*(p+n*l+a)=p+(m+n)*l+a ---->p+a=(m+n-2)*l ->p=(m+n-2)*l-a->p=(m+n-3)*l+l-a
 * 也就是p的值和n*l+l-a是一样的，那么就可以让fPtr继续走，sPtr指向了头指针就可以了
 *
 */
node *Loop(node *head)
{
		node *tPtr=head;
		node *oPtr=head;
		do
		{
				tPtr=tPtr->next->next;
				oPtr=oPtr->next;	
		}while(tPtr!=oPtr);
		tPtr=head;
		while(tPtr!=oPtr)
		{
				tPtr=tPtr->next;
				oPtr=oPtr->next;
		}
		return tPtr;
}
/*
 *
 * 寻找两个链表的公共结点，不存在环的情况下，如果存在环的情况，需要结合上面的函数发现环的入口点就可以了.然后已入口点为结点继续做
 *
 * 
 */
node *TwoListMerge(node *first,node *second)
{
		int nf=0;
		int ns=0;
		node* tfirst=first;
		node* tsecond=second;
		while(tfirst)
		{
				nf++;
				tfirst=tfirst->next;
		}
		while(tsecond)
		{
				ns++;
				tsecond=tsecond->next;
		}
		tfirst=first;
		tsecond=second;
		if(ns>nf)
		{
				while(ns!=nf)
				{
					tsecond=tsecond->next;
						ns--;
				}
				while(tfirst!=tsecond)
				{
					tfirst=tfirst->next;
					tsecond=tsecond->next;
				}
				return tfirst;
		}
		if(ns<=nf)
		{
				while(ns!=nf)
				{
					tfirst=tfirst->next;
						nf--;
				}
				while(tfirst!=tsecond)
				{
					tfirst=tfirst->next;
					tsecond=tsecond->next;
				}
				return tsecond;
		}
		return NULL;
}
