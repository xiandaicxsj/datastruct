#include<iostream>
using namespace std;
struct TreeNode
{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x):val(x),left(NULL),right(NULL)
		{

		}
};
class Solution{
	public:
			int minDepth(TreeNode *root)
			{
					if(root==NULL)
						return 0;
					int min;
					int lMin;
					int rMin;
					if (root->left==NULL&&root->right==NULL)
						return 1;
					if(root->left==NULL)
					{
							rMin=minDepth(root->right);
							return rMin+1;
						}
					if(root->right==NULL)
					{
							lMin=minDepth(root->left);
							return lMin+1;
					}
					 lMin=minDepth(root->left);
					 rMin=minDepth(root->right);
					 min=lMin>rMin?rMin+1:lMin+1;
					return min;
			}
};

int main()
{
	TreeNode *r=new TreeNode(1);
	TreeNode *l1=new TreeNode(2);
	r->left=l1;
	Solution s;
	cout<<s.minDepth(r);
	return 0;
}

