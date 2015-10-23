#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
      int val;
  	  TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
	public:
				vector<int> inorderTraversal(TreeNode *root)
				{
						vector<int>res;
						stack<TreeNode*>treeStack;
						TreeNode *top=root;
						TreeNode *tmp=NULL;
						while(top||!treeStack.empty())
						{
								while(top)
								{
										treeStack.push(top);
										top=top->left;
								}
								tmp=treeStack.top();
								res.push_back(tmp->val);
								treeStack.pop();
								if(tmp->right)
								{
										top=tmp->right;
								}
						}
						return res;
				}
		    vector<int> preorderTraversal(TreeNode *root)
					{
							vector<int>res;
							stack<TreeNode*> treeStack;
							TreeNode *top=root;
							TreeNode *pre=NULL;	
						/*	while(top||!treeStack.empty())
							{
								while(top)
								{
										res.push_back(top->val);
										if(top->right)
											treeStack.push(top->right);
										top=top->left;	
								}
								top=treeStack.top();
								treeStack.pop();
							}*/
							treeStack.push(root);
							while(!treeStack.empty())
							{
								TreeNode* tmp=treeStack.top();
								res.push_back(tmp->val);				
								treeStack.pop();
								if(tmp->right) treeStack.push(tmp->right);
								if(tmp->left)  treeStack.push(tmp->left);
							}
							return res;
					 }
};
int main()
{
TreeNode*	root= new TreeNode(1);
TreeNode*l=new TreeNode(2);
TreeNode*r=new TreeNode(3);
root->left=l;
root->right=r;
Solution s;
vector<int> res=s.inorderTraversal(root);
cout<<"size"<<res.size()<<endl;
for (auto i :res)
	cout<<i<<endl;
return 1;
}
