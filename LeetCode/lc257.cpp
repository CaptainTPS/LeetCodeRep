/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution257 {
public:
    vector<string> result;
    
    void dfs(TreeNode* root, string temp){
        if(temp.empty())
                temp += to_string(root->val);
            else
                temp += "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            result.push_back(temp);
            return;
        }
        if(root->left)
            dfs(root->left, temp);
        if(root->right)
            dfs(root->right, temp);
           
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
            return vector<string>();
        string t="";
        dfs(root,t);
        return result;
    }
};