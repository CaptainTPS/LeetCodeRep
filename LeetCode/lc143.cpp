#include <cstdlib>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

#ifdef LTE
class Solution {
public:
	void findn(ListNode **ptr, int n){
		for (size_t i = 0; i < n; i++)
		{
			if (*ptr == nullptr)
				return;
			*ptr = (*ptr)->next;
		}
	}

	void reorderList(ListNode* head) {
		if (head == nullptr)
			return;
		
		int n = 0;
		ListNode* ptr = head;
		while (ptr != nullptr){
			n++;
			ptr = ptr->next;
		}

		ListNode *ptr2 = head;
		ptr = head;
		n -= 1;
		while (n > 1){
			findn(&ptr2, n);
			ptr2->next = ptr->next;
			ptr->next = ptr2;
			ptr = ptr2->next;
			ptr2 = ptr;
			n -= 2;
		}
		for (size_t i = 0; i < n; i++)
		{
			ptr2 = ptr2->next;
		}
		ptr2->next = nullptr;
	}
};
#endif
class Solution143 {
public:
	void reverseList(ListNode **node){
		if (*node == nullptr)
		{
			return;
		}
		ListNode *ln = new ListNode(0);
		ListNode *now = *node, *temp, *temp2;
		while (now != nullptr){
			temp = ln->next;
			temp2 = now->next;
			ln->next = now;
			now->next = temp;
			now = temp2;
		}
		*node = ln->next;

	}

	void reorderList(ListNode* head) {
		if (head == nullptr)
		{
			return;
		}
		ListNode *slow, *fast, *temp = nullptr , *temp2;
		slow = fast = head;
		while (fast){
			temp = slow;
			slow = slow->next;
			fast = fast->next;
			if (fast)
				fast = fast->next;
			
		}

		reverseList(&slow);
		temp->next = nullptr;

		fast = head;
		while (fast && slow){
			temp = fast->next;
			temp2 = slow->next;
			fast->next = slow;
			slow->next = temp;

			fast = temp;
			slow = temp2;
		}

	}
};

# if 0
int main(){
	ListNode n[4] = { ListNode(1), ListNode(2), ListNode(3), ListNode(4) };
	n[0].next = &n[1];
	n[1].next = &n[2];
	n[2].next = &n[3];
	Solution143().reorderList(n);
	return 0;
}
#endif