#include <cstdlib>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		if (root == NULL)
			return;
		fathers.push(root);
		while (fathers.top()->left)
			fathers.push(fathers.top()->left);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !fathers.empty();
	}

	/** @return the next smallest number */
	int next() {
		int now = fathers.top()->val;
		TreeNode* t = fathers.top();
		fathers.pop();
		if (t->right){
			fathers.push(t->right);
			t = t->right;
			while (t->left){
				fathers.push(t->left);
				t = t->left;
			}
		}
		return now;
	}

private:
	stack<TreeNode*> fathers;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/