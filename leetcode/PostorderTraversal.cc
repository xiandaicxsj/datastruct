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
		    vector<int> postorderTraversal(TreeNode *root)
					{
							vector<int>res;
							stack<TreeNode*> treeStack;
							TreeNode *top=root;
							TreeNode *pre=NULL;	
							while(top||!treeStack.empty())
							{
								while(top)
								{
										treeStack.push(top);
										top=top->left;
								}
								top=treeStack.top();
								if(top->right==NULL||top->right==pre)
								{
										res.push_back(top->val);
										pre=top;
										treeStack.pop();
										top=NULL;
								}
								else
									top=top->right;
							}
						return res;
					 }
};
int main()
{
TreeNode*	root= new TreeNode(1);
TreeNode*l=new TreeNode(2);
TreeNode*r=new TreeNode(3);
root->right=l;
l->left=r;
Solution s;
vector<int> res=s.postorderTraversal(root);
cout<<"size"<<res.size()<<endl;
for (auto i :res)
	cout<<i<<endl;
return 1;
}
