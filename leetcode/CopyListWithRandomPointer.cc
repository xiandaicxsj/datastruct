#include<iostream> 
//这个到底是在哪里出现了错误？？
struct RandomListNode {
	     int label;
	     RandomListNode *next, *random;
	     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
			};
class Solution {
	public:
		    RandomListNode *copyRandomList(RandomListNode *head)
				{
					RandomListNode *tHead=head;
					while(tHead)
					{
							RandomListNode * newNode=new RandomListNode(tHead->label);
							newNode->next=tHead->next;
							tHead->next=newNode;
							tHead=tHead->next->next;
					}
					tHead=head;
					while(tHead)
					{
						if(tHead->random)
						{
							tHead->next->random=tHead->random->next;
						}
						tHead=tHead->next->next;
					}
					tHead=head;
					RandomListNode *tmp;
					RandomListNode *resHead=tHead->next;
					while(tHead)
					{
							if(tHead->next->next)
							{
									tmp=tHead->next->next;
									tHead->next->next=tHead->next->next->next;
									tHead=tmp;
							}
							else
								break;
					}
					return resHead;
				}
				void Show(RandomListNode *head)
				{
						while(head)
						{
							std::cout<<head->label<<std::endl;
							head=head->next;
						}
				}
};
int main()
{
		RandomListNode *t1=new RandomListNode(1);
		RandomListNode *t2=new RandomListNode(2);
		RandomListNode *t3=new RandomListNode(3);
		t1->next=t2;
		t2->next=t3;
		t2->random=t1;
		t1->random=t3;
		Solution s;
		RandomListNode* t4=s.copyRandomList(t1);
		while(t4)
		{
			std::cout<<t4->label<<" ";
			if(t4->random)
			std::cout<<t4->random->label;
			std::cout<<std::endl;
			t4=t4->next;
		}
}

