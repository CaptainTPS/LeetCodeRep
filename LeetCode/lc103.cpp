#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution103 {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> re;

		stack<TreeNode*> s1, s2;
		stack<TreeNode*> *now, *next, *tt;
		now = &s1; next = &s2;
		bool flag = false;
		if (root != NULL)
		{
			now->push(root);
		}
		while (!now->empty())
		{
			vector<int> temp;
			while (!now->empty())
			{
				temp.push_back(now->top()->val);
				if (flag)
				{
					if (now->top()->right != NULL)
						next->push(now->top()->right);
					if (now->top()->left != NULL)
						next->push(now->top()->left);
				}
				else
				{
					if (now->top()->left != NULL)
						next->push(now->top()->left);
					if (now->top()->right != NULL)
						next->push(now->top()->right);
				}
				now->pop();
			}
			re.push_back(temp);
			flag = !flag;
			tt = now; now = next; next = tt;
		}
		return re;
	}
};