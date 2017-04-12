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

ListNode* swapPairs(ListNode* head) {
	ListNode h(0);
	ListNode* pre = &h;
	pre->next = head;
	ListNode *l1 = NULL, *l2 = NULL;
	do
	{
		if (pre->next != NULL)
		{
			l1 = pre->next;
			l2 = l1->next;
		}
		else
		{
			break;
		}
		if (l1!=NULL && l2!=NULL)
		{
			l1->next = l2->next;
			l2->next = l1;
			pre->next = l2;
		}
		pre = l1;
	} while (pre!=NULL && l1!=NULL && l2!=NULL);

	return h.next;
}

int main24(){
	int data[2] = {
		1, 2
	};
	ListNode* root = new ListNode(data[0]);
	ListNode* pre = root;
	for (int i = 1; i < 2; i++)
	{
		pre->next = new ListNode(data[i]);
		pre = pre->next;
	}
	root = swapPairs(root);

	return 0;
}