#include <cstdlib>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution328 {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode odd(0), even(0);
		ListNode *op = &odd, *ep = &even, *temp = head;

		bool flag = true;
		while (temp){
			if (flag){
				op->next = temp;
				temp = temp->next;
				op = op->next;
				op->next = NULL;
			}
			else
			{
				ep->next = temp;
				temp = temp->next;
				ep = ep->next;
				ep->next = NULL;
			}

			flag =!flag;
		}

		if (even.next)
			op->next = even.next;

		return odd.next;

		

	}
};