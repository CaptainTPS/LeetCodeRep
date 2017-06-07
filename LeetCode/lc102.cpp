#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution102 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector < vector<int>> result;
		
		queue<TreeNode*> q1, q2;
		queue<TreeNode*> *now, *next, *tt;
		now = &q1;
		next = &q2;
		if (root !=  NULL)
		{
			now->push(root);
		}

		while (!now->empty())
		{
			vector<int> temp;
			while (!now->empty())
			{
				temp.push_back(now->front()->val);
				if (now->front()->left != NULL)
					next->push(now->front()->left);
				if (now->front()->right != NULL)
					next->push(now->front()->right);
				now->pop();
			}
			if (!temp.empty())
			{
				result.push_back(temp);
			}
			tt = now; now = next; next = tt;
		}
		return result;
	}
};