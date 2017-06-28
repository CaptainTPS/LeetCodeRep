#include <cstdlib>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution147 {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr)
		{
			return head;
		}
		
		ListNode r(0);
		ListNode *root = &r;

		ListNode *ptr = head, *temp;
		while (ptr != nullptr){
			ListNode *pre = root, *now = root->next;
			while (now != nullptr && now->val < ptr->val){
				pre = now;
				now = now->next;
			}
			temp = ptr->next;
			ptr->next = pre->next;
			pre->next = ptr;
			ptr = temp;
		}
		return root->next;
	}
};