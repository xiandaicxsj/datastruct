#include<iostream>
//这没写完
struct ListNode {
         int val;
          ListNode *next;
          ListNode(int x) : val(x), next(NULL) {}
       };
class Solution
{
		public:
			ListNode *sortList(ListNode *head)
			{
					
					
			}
			void SortList(ListNode* head,ListNode *end)
			{
					int tmp;
					if(head->next==end)
					{
							if(head->val>end->val)
							{
									
									tmp=head->val;
									head->val=end->val;
									end->val=tmp;
							}
							return ;
					}
					int len=GetLen(head,end);
					ListNode *mid=GetMidNode(head,len/2);
					SortList(head,mid);
					SortList(mid->next,end);
					
			}
};
int main()
{
		
}
