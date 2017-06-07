#include <cstdlib>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *pre, *first, *last;

	void visit(TreeNode* root){
		if (pre == NULL)
		{
			pre = root;
			return;
		}
		if (pre->val > root->val)
		{
			if (first == NULL)
			{
				first = pre;
				last = root;
			}
			else
			{
				last = root;
			}
		}

		pre = root;

	}

	void dfs(TreeNode* root){
		if (root==NULL)
		{
			return;
		}
		dfs(root->left);
		visit(root);
		dfs(root->right);
	}

	void recoverTree(TreeNode* root) {
		pre = first = last = NULL;
		dfs(root);
		int t = first->val;
		first->val = last->val;
		last->val = t;
	}
};