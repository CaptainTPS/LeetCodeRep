
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution230 {
public:
	int kth;

	void dfs(TreeNode* root, int& now, int k){
		
		if(now > k)
			return;

		if(root->left)
			dfs(root->left, now, k);
			now+=1;
		if(now == k){
			kth = root->val;
			return;
		}
		if(root->right)
			dfs(root->right, now, k);
	}


    int kthSmallest(TreeNode* root, int k) {
    	int now = 0;
    	if(root == NULL)
    		return 0;
    	dfs(root, now, k);
    	return kth;
    }
};