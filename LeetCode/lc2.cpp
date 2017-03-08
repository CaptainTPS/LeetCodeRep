#include <cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int flag = 0;
	int sum = 0;
	ListNode *root = NULL;
	ListNode *pre = NULL;
	ListNode *p1, *p2;
	p1 = l1;
	p2 = l2;
	while (p1 != NULL || p2 != NULL || flag != 0)
	{
		sum = 0;
		if (p1 != NULL)
			sum += p1->val;
		if (p2 != NULL)
			sum += p2->val;
		sum += flag;
		if (sum >= 10) {
			flag = 1;
			sum -= 10;
		}
		else {
			flag = 0;
		}


		if (pre == NULL) {
			root = pre = new ListNode(sum);
		}
		else {
			pre->next = new ListNode(sum);
			pre = pre->next;
		}
		if (p1 != NULL)
			p1 = p1->next;
		if (p2 != NULL)
			p2 = p2->next;

	}
	return root;
}


int main2() {
	ListNode* p1 = new ListNode(5);

	ListNode* p2 = new ListNode(5);

	ListNode* re =	addTwoNumbers(p1, p2);

	return 0;
}