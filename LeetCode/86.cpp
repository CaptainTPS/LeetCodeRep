//86. Partition List

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
    ListNode* partition(ListNode* head, int x) {
        ListNode a(0);
        ListNode b(0);
        ListNode* pa = &a;
        ListNode* pb = &b;

        while(head){
        	if (head->val < x)
        	{
        		pa->next = head;
        		pa = pa->next;
        		head = head->next;
        		pa->next = NULL;
        	}else{
        		pb->next = head;
        		pb = pb->next;
        		head = head->next;
        		pb->next = NULL;
        	}
        	
        }

        pa->next = b.next;
        return a.next;
    }
};