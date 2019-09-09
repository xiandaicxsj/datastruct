#include<iostream>
using namespace std;
struct ListNode{
int val;
ListNode *next;
ListNode(int x):val(x),next(NULL){}
};
class Solution
{
	public:
			ListNode *mergeTwoList(ListNode *l1,ListNode *l2)
			{
				ListNode *head;
				ListNode *tail;
				if(!l1)
				{
					head=l2;
					return head;
				}
				if(!l2)
				{
					head=l1;
					return head;
				}
				if(l1->val<=l2->val)
				{
						head=l1;
						l1=l1->next;
				}
				else
				{
						head=l2;
						l2=l2->next;
				}
				tail=head;
				while(l1&&l2)
				{
						if(l1->val<=l2->val)
						{
								tail->next=l1;
								l1=l1->next;
								tail=tail->next;
								continue;
						}
						if(l1->val>l2->val)
						{
								tail->next=l2;
								l2=l2->next;
								tail=tail->next;
								continue;
						}
				}
				if(!l1)
				{
						tail->next=l2;
				}
				if(!l2)
				{
						tail->next=l1;
				}
				return head;

			}
	

	};
void Display(ListNode *l)
{
		while(l)
		{
				cout<<l->val<<endl;
				l=l->next;
		}

}
int main()
{
	ListNode * first=new ListNode(1);
	ListNode * second=new ListNode(2);	
/*	ListNode * t_f=first;
	ListNode * t_s=second;
	int i=0;
	for(i=2;i<5;i++)
	{
			t_f->next=new ListNode(i*1);
			t_s->next=new ListNode(i*2);	
			t_f=t_f->next;
			t_s=t_s->next;
	}
	Display(first);
	cout<<"second"<<endl;
	Display(second);
	cout<<"final"<<endl;
	first=NULL;*/
		Solution s;
		ListNode *ml=s.mergeTwoList(first,second);
		Display(ml);
	}


