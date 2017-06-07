#include <cstdlib>
#include <vector>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution105 {
public:
	typedef vector<int>::iterator iter;

	TreeNode* dfs(iter left1, iter right1, iter left2, iter right2){
		if (left1 == right1 || left2 == right2)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(*left1);
		int cnt = 0;
		while (*(left2+cnt) != *left1 )
			cnt++;
		root->left = dfs(left1 + 1, left1 + cnt + 1, left2, left2 + cnt);
		root->right = dfs(left1 + cnt + 1, right1, left2 + cnt + 1, right2);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return dfs(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};