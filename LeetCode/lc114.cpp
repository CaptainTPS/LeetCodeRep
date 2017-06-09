#include <cstdlib>


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution114 {
public:

	TreeNode* dfs(TreeNode* root){
		if (root->left == NULL && root->right == NULL)
		{
			return root;
		}

		TreeNode *m;
		m = root;
		TreeNode *last = NULL;
		if (root ->left != NULL)
		{
			last = dfs(root->left);
			TreeNode *t;
			t = root->right;
			root->right = root->left;
			root->left = NULL;
			last->right = t;
			m = last;
		}
		if (m->right != NULL){
			last = dfs(m->right);
		}
		return last;
	}

	void flatten(TreeNode* root) {
		TreeNode t(0);
		t.right = root;
		dfs(&t);
	}
};