#include <cstdlib>
#include <algorithm>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution337 {
public:
	struct dpNode
	{
		int amount;
		dpNode *left, *right;
		dpNode() :amount(-1), left(NULL), right(NULL){};
		dpNode(int x) :amount(x), left(NULL), right(NULL) {}
	};


	void dfs(TreeNode* root, dpNode* dpr){
		if (root == NULL || dpr == NULL)
			return;
		if (dpr->amount != -1)
			return;
		
		if (root->left && dpr->left == NULL)
			dpr->left = new dpNode();
		if (root->right && dpr->right == NULL)
			dpr->right = new dpNode();

		int cnt1 = 0, cnt2 = 0;
		cnt1 += root->val;
		if (root->left){
			dfs(root->left, dpr->left);
			cnt2 += dpr->left->amount;
			if (root->left->left){
				dfs(root->left->left, dpr->left->left);
				cnt1 += dpr->left->left->amount;
			}
			if (root->left->right){
				dfs(root->left->right, dpr->left->right);
				cnt1 += dpr->left->right->amount;
			}
		}
		if (root->right){
			dfs(root->right, dpr->right);
			cnt2 += dpr->right->amount;
			if (root->right->left){
				dfs(root->right->left, dpr->right->left);
				cnt1 += dpr->right->left->amount;
			}
			if (root->right->right){
				dfs(root->right->right, dpr->right->right);
				cnt1 += dpr->right->right->amount;
			}
		}
		dpr->amount = max(cnt1, cnt2);
	}

	int rob(TreeNode* root) {
		dpNode dpr(-1);
		dfs(root, &dpr);
		if (dpr.amount == -1)
			dpr.amount = 0;
		return dpr.amount;
	}
};