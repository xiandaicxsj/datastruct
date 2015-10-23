#include<iostream>
using namespace std;
//下面的线段是实现的对点进行更新的情况，如果是针对的边的更需的话是需要在
//并且这里的实现其实是可以换成为数组进行实现的
struct lineTree
{
		int value;
		lineTree *l;	
		lineTree *r;
		int lv;
		int rv;
		lineTree(int v,int _lv,int _rv):value(v),lv(_lv),rv(_rv),l(NULL),r(NULL)
		{
		}
};
lineTree *head;
lineTree* BuildTree(int base,int end)
{
		if(base==end)
		{
				return new lineTree(0,base,end);
		}
			int mid=(base+end)/2;
			lineTree *node = new lineTree(0,base,end);
			node->l=BuildTree(base,mid);
			node->r=BuildTree(mid+1,end);
			return node;
}
void UpdateTree(lineTree *node ,int i,int value)
{
		
		int mid=(node->lv+node->rv)/2;
		if(node->lv==node->rv&&i==mid)
		{
			node->value=node->value+value;
			return; 
		}
		if(i<=mid)
			UpdateTree(node->l,i,value);
		if(i>mid)
			UpdateTree(node->r,i,value);
		if(node->l&&node->r)//这里是一定成立的
			node->value=node->l->value+node->r->value;
}
int Qury(lineTree *node ,int base,int end)
{
		int left=node->lv;
		int right=node->rv;
		if(left>=base&&right<=end)
				return node->value;
		else
		{
				int sum1=0;
				int sum2=0;
				int mid=(left+right)/2;
				if(base<=mid)
					sum1=Qury(node->l,base,mid);
				if(base>mid)
					sum2=Qury(node->r,mid,end);
				return sum1+sum2;
		}	
}
int main()
{
	int num;
	int i;
	num=10;
	lineTree *head=BuildTree(1,num);
	for(i=1;i<=num;i++)
	{
		UpdateTree(head,i,i);
	}
	cout<<Qury(head,1,5);
}
