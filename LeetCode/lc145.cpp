#include <vector>
#include <cstdlib>
#include <stack>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution145 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> re;
		if (root == nullptr)
			return re;

		stack<TreeNode*> s;
		s.push(root);
		TreeNode *now = nullptr, *pre = nullptr;
		while (!s.empty()){
			now = s.top();
			if (now->left && ((pre == nullptr) || (pre != now->left && pre != now->right))){
				s.push(now->left);
				continue;
			}
			if (now->right&& pre != now->right){
				s.push(now->right);
				continue;
			}
			if ((now->left == nullptr && now->right == nullptr) || (pre == now->left && now->right == nullptr) || (pre == now->right)){
				re.push_back(now->val);
				pre = now;
				s.pop();
			}
		}
		return re;
	}
};