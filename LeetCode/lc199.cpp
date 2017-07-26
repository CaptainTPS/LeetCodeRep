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

class Solution199 {
public:
	vector<int> rightSideView(TreeNode* root) {
		typedef queue<TreeNode*> qt;

		vector<int> result;
		if (root == NULL)
			return result;

		qt q1, q2;
		qt *now = &q1, *next = &q2, *temp;
		now->push(root);
		while (!now->empty()){
			int m;
			while (!now->empty()){
				m = now->front()->val;
				if (now->front()->left != NULL)
					next->push(now->front()->left);
				if (now->front()->right != NULL)
					next->push(now->front()->right);
				now->pop();
			}
			temp = now;
			now = next;
			next = temp;
			result.push_back(m);
		}
		return result;
	}
};