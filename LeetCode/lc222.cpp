#include <cstdlib>


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution222 {
public:
	typedef TreeNode* ptr;
	typedef long long ll;
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		ll levels = 0;
		ptr curr = root;
		while (curr){
			curr = curr->left;
			levels++;
		}
		if (levels == 1)
			return 1;
		ll result = (1 << (levels - 1)) - 1;

		ll last = biSearchNull(root, levels);

		return result + last;

	}
private:
	bool lastlevel(TreeNode* root, ll order, ll levels){
		ptr curr = root;
		levels -= 2;
		while (levels >= 0){
			if (order  & (1<< levels))
				curr = curr->right;
			else
				curr = curr->left;
			levels--;
		}
		if (curr)
			return true;
		else
			return false;
	}

	ll biSearchNull(ptr root, ll levels){
		ll left = 0, right = (1 << (levels - 1)) - 1;
		while (left <= right){
			ll mid = (left + right) / 2;
			if (lastlevel(root, mid, levels)){
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
		return left;
	}
};