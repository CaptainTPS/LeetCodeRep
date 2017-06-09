#include <cstdlib>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution109 {
public:
	TreeNode* dfs(ListNode* begin, ListNode* end){
		if (begin == end)
		{
			return NULL;
		}
		ListNode *slow, *fast;
		slow = fast = begin;
		while (fast != end)
		{
			if (fast != end)
			{
				fast = fast->next;
			}
			if (fast != end)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}

		TreeNode *root = new TreeNode(slow->val);
		root->left = dfs(begin, slow);
		root->right = dfs(slow->next, end);
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		return dfs(head, NULL);
	}
};