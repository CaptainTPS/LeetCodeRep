#include <cstdlib>

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode h(0);
	ListNode* now = &h;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			now->next = l1;
			l1 = l1->next;
		}
		else
		{
			now->next = l2;
			l2 = l2->next;
		}
		now = now->next;
	}
	if (l1 != NULL)
	{
		now->next = l1;
	}
	if (l2 != NULL)
	{
		now->next = l2;
	}
	return h.next;
}

