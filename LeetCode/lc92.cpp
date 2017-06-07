#include <cstdlib>

using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution92 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode root(0);
		root.next = head;

		ListNode *ptr1, *ptr2;
		ptr1 = ptr2 = &root;

		for (size_t i = 1; i < m; i++)
		{
			ptr1 = ptr1->next;
		}
		ptr2 = ptr1->next;
		ListNode* curr = ptr2->next;
		for (size_t i = m; i < n; i++)
		{
			ptr2->next = curr->next;
			curr->next = ptr1->next;
			ptr1->next = curr;

			curr = ptr2->next;
		}

		return root.next;
	}
};