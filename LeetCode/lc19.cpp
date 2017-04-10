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

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode h(0);
	h.next = head;
	ListNode* pre = &h;
	ListNode* nextN = pre;
	for (int i = 0; i < n; i++)
	{
		nextN = nextN->next;
	}
	while (nextN -> next != NULL)
	{
		pre = pre->next;
		nextN = nextN->next;
	}
	//do delete
	ListNode* temp = pre->next->next;
	pre->next = temp;
	return h.next;
}

int main19(){

	return 0;
}