//129. Sum Root to Leaf Numbers
#include <cstdlib>


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution129 {
public:
	int sum;

	void dfs(int now, TreeNode* root){
		if (root == NULL)
		{
			return;
		}
		if (root->left == NULL && root->right == NULL)
		{
			sum += now * 10 + root->val;
			return;
		}

		now = now * 10 + root->val;
		dfs(now, root->left);
		dfs(now, root->right);

	}

	int sumNumbers(TreeNode* root) {
		sum = 0;
		dfs(0, root);
		return sum;
	}
};