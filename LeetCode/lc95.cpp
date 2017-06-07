#include <cstdlib>
#include <vector>

using namespace std;



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution95 {
public:
	vector<TreeNode*> dfs(int left, int right){
		vector<TreeNode*> temp;

		if (left == right)
		{
			temp.push_back(NULL);
			return temp;
		}

		for (int i = left; i < right; i++)
		{
			vector<TreeNode*> lroot = dfs(left, i);
			vector<TreeNode*> rroot = dfs(i+1, right);
			for (size_t k= 0; k < lroot.size(); k++)
			{
				for (size_t j = 0; j < rroot.size(); j++)
				{
					TreeNode* t = new TreeNode(i);
					t->left = lroot[k];
					t->right = rroot[j];
					temp.push_back(t);
				}
			}
		}
		return temp;
	}

	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
		{
			return vector<TreeNode*>();
		}
		return dfs(1, n + 1);
	}
};