#include <cstdlib>
#include <queue>

using namespace std;


struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution116117 {
public:
	typedef queue<TreeLinkNode*> que;
	void connect(TreeLinkNode *root) {
		que q1, q2;
		que *now, *next, *tq;
		now = &q1; next = &q2;
		if (root != NULL)
		{
			now->push(root);
		}
		while (!now->empty())
		{
			while (!now->empty())
			{
				TreeLinkNode* t = now->front();
				if (t->left != NULL)
					next->push(t->left);
				if (t->right != NULL)
					next->push(t->right);
				now->pop();
				if (!now->empty())
				{
					t->next = now->front();
				}
			}
			tq = now;
			now = next;
			next = tq;
		}
	}
};