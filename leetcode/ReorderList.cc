#include<iostream>
using namespace std;
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
	public:
		    void reorderList(ListNode *head) 
				{
						if(!head||!head->next)
							return ;
						int len=0;
						ListNode *tHead=head;
						while(tHead)
						{
								len++;
								tHead=tHead->next;
						}
						tHead=head;
						int mid=len/2;
						while(mid)
						{
								tHead=tHead->next;
								mid--;
						}
						tHead=Reverse(tHead);
						Show(tHead);
						ListNode *listNode=head;
						ListNode *tmpNode=NULL;
						while(tHead&&head)
						{
								if(!tmpNode)
								{
									tmpNode=head;
									head=head->next;
								}
								else
								{
									tmpNode->next=head;
									tmpNode=head;
									head=head->next;
								}		
								tmpNode->next=tHead;
								tmpNode=tHead;
								tHead=tHead->next;
						}
						if(tHead)
							tmpNode->next=head;
						if(head)
							tmpNode->next=tHead;
						while(listNode)
						{
								cout<<listNode->val<<endl;
								listNode=listNode->next;
						}
				}
				ListNode* Reverse(ListNode *head)
				{
						ListNode *tHead=head;
						if(!head)
								return head;
						ListNode *mid=head->next;
						if(!mid)
							return head;
						head->next=NULL;
						ListNode *next;
						while(mid)
						{
							next=mid->next;
							mid->next=tHead;
							tHead=mid;
							mid=next;
						}
						return tHead;
				}
				void Show(ListNode *node)
				{
						cout<<"_____"<<endl;
						while(node)
						{
								cout<<node->val<<endl;
								node=node->next;
						}
						cout<<"_____"<<endl;
				}
				void Test()
				{
						ListNode *node =new ListNode(1);
						ListNode *node1=new ListNode(2);
						ListNode *node2=new ListNode(3);
						ListNode *node3=new ListNode(4);
						ListNode *node4=new ListNode(5);
						node->next=node1;
						node1->next=node2;
						node2->next=node3;
						node3->next=node4;
						reorderList(node);
				}
				
};
int main()
{
		Solution s;
		s.Test();
		return 0;

}
