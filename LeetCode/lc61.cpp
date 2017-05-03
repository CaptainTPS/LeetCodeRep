#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* rotateRight(ListNode* head, int k) {
	ListNode root(0);
	root.next = head;

	ListNode* ptr = head;
	int cnt = 0;
	while (ptr)
	{
		cnt++;
		ptr = ptr->next;
	}
	if (cnt == 0)
	{
		return head;
	}
	k = k % cnt;
	cnt = 0;
	ptr = head;
	while (cnt != k)
	{
		cnt++;
		ptr = ptr->next;
	}
	while (ptr->next)
	{
		head = head->next;
		ptr = ptr->next;
	}
	ptr->next = root.next;
	root.next = head->next;
	head->next = NULL;

	return root.next;
}