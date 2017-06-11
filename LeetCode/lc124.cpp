//124. Binary Tree Maximum Path Sum

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

#include <vector>

class Solution {
public:
	int gmax;
	int dfs(TreeNode* root){
		if (root==NULL)
		{
			return 0;
		}
		int left = dfs(root->left);
		int right = dfs(root->right);
		int m = left > right ? left : right;
		m += root->val;
		if (gmax < left + right + root->val)
		{
			gmax = left + right + root->val;
		}
		m = m>0? m:0;
		return m;
	}

    int maxPathSum(TreeNode* root) {
        gmax = INT_MIN;
        dfs(root);
        return gmax;
    }
};
