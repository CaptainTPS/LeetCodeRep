#include <cstdlib>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution98 {
public:
	vector<int> seq;
	bool flag;
	void visit(int i){
		if (seq.empty() || i > seq.back())
		{
			seq.push_back(i);
		}
		else
		{
			flag = false;
		}

	}

	void dfs(TreeNode* root){
		if (root == NULL)
		{
			return;
		}
		if (flag == false)
		{
			return;
		}
		dfs(root->left);
		visit(root->val);
		dfs(root->right);
	}

	bool isValidBST(TreeNode* root) {
		flag = true;
		if (root == NULL)
		{
			return true;
		}
		dfs(root);
		return flag;
	}
};