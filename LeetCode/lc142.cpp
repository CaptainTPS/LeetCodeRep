#include <cstdlib>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution142 {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow, *fast;
		if (head == nullptr)
		{
			return nullptr;
		}
		slow = fast = head;
		do{
			slow = slow->next;
			fast = fast->next;
			if (fast)
				fast = fast->next;
		} while (fast != nullptr && fast != slow);

		if (fast == nullptr)
		{
			return nullptr;
		}

		int cnt = 0;
		do{
			cnt++;
			slow = slow->next;
			fast = fast->next;
			fast = fast->next;
		} while (fast != slow);

		slow = fast = head;
		for (size_t i = 0; i < cnt; i++)
		{
			fast = fast->next;
		}
	
		while (fast != slow){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};