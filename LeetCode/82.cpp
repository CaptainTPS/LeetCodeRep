//82. Remove Duplicates from Sorted List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
        {
        	return head;
        }
        vector<int> li;
        int now = head->val;
        int cnt = 1;
        head = head->next;
        
        while(head){
        	int v = head->val;
        	head = head->next;
        	if (v == now)
        	{
        		cnt++;
        		continue;
        	}
        	if (cnt == 1)
        	{
        		li.push_back(now);
        	}
        	now = v;
        	cnt = 1;
        }
		if (cnt == 1)
        {
        	li.push_back(now);
        }
        ListNode root(0);
        ListNode* ptr = &root;
        for (int i = 0; i < li.size(); ++i)
        {
        	ptr->next = new ListNode(li[i]);
        	ptr = ptr->next;
        }
        return root.next;
    }
};