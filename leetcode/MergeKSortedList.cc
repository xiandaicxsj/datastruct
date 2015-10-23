#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	    int val;
	    ListNode *next;
	    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
	public:
		    ListNode *mergeKLists(vector<ListNode *> &lists) 
							{
									int size=lists.size();
									int i=0;
									ListNode **pointArray=(ListNode **)malloc(sizeof(ListNode*)*size);
									ListNode *l=NULL;
									ListNode *p=NULL;
									for(i=0;i<size;i++)
										pointArray[i]=lists[i];
									int index=0;
									int value=0;
									while(true)
									{
										i=0;
										while(i<size&&!pointArray[i])
										{
											i++;
										}
										if(i==size)
												break;
										
										value=pointArray[i]->val;
										index=i;
										for(;i<size;i++)
										{
												if(pointArray[i]&&pointArray[i]->val<value)
												{
														index=i;
														value=pointArray[i]->val;
												}
										}
										if(!l)
										{
												l=pointArray[index];
												p=l;
												pointArray[index]=pointArray[index]->next;
												continue;
										}
										l->next=pointArray[index];
										l=l->next;
										pointArray[index]=pointArray[index]->next;
										for(i=0;i<size;i++)
										{
												if(pointArray[i])
												{
														break;
												}
										}
										if(i==size)
										{
												break;
										}
									}
							l=p;
							return p;
					   }

};
int main()
{
		ListNode *l1=new ListNode(1);
		ListNode *l2=new ListNode(2);
		ListNode *l3=new ListNode(3);
		ListNode *l4=new ListNode(4);
		ListNode *l5=new ListNode(5);
		ListNode *l6=new ListNode(6);
		ListNode *l7=new ListNode(7);
		l1->next=l3;
		l3->next=l5;
		l5->next=NULL;
		l2->next=l4;
		l4->next=l6;
		l6->next=NULL;
		l7->next=NULL;
		vector<ListNode*> v;	
		v.push_back(l1);
		v.push_back(l2);
		v.push_back(l7);
		Solution s;
		ListNode *l=s.mergeKLists(v);
		while(l)
		{
			cout<<l->val;
			l=l->next;
		}
		return 0;
}
