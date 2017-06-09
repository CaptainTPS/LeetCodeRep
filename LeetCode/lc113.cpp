#include <cstdlib>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution113 {
public:
	int sum_;
	vector<vector<int>> result;
	void dfs(TreeNode* root, int s, vector<int>& temp){
		if (root == NULL)
		{
			return;
		}
		if (root->left == NULL && root->right == NULL)
		{
			s += root->val;
			temp.push_back(root->val);
			if (s == sum_)
			{
				result.push_back(temp);
			}
			temp.pop_back();
			return;
		}

		temp.push_back(root->val);
		dfs(root->left, s + root->val, temp);
		dfs(root->right, s + root->val, temp);
		temp.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		sum_ = sum;
		vector<int> t;
		dfs(root, 0, t);
		return result;
	}
};