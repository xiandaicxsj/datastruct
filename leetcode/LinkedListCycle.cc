#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
	public:
		    bool hasCycle(ListNode *head) 
				{
						ListNode *slow=head;
						ListNode *fast=head;
						while(slow&&fast)
						{
								if(slow->next)
									slow=slow->next;
								else
									break;
								if(fast->next&&fast->next->next)
									fast=fast->next->next;
								else
									break;
								if(fast==slow)
								{
										ListNode *tmp=head;
										while(head!=slow)
										{
											head=head->next;
											slow=slow->next;
										}
										return slow;
								}
						}
						return NULL;

				}
					        
};

