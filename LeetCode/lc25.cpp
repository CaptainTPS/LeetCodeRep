#include <cstdlib>
#include <vector>

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode h(0);
	h.next = head;
	ListNode* pre = &h;
	ListNode* pre2;
	vector<ListNode*> all;
	do
	{
		all.clear();
		int m = 0;
		pre2 = pre;
		while (m < k)
		{
			if (pre->next != NULL)
			{
				all.push_back(pre->next);
				pre = pre->next;
			}
			else
			{
				break;
			}
			m++;
		}
		if (all.size() != k)
		{
			break;
		}
		pre2->next = pre;
		all[0]->next = pre->next;
		for (int i = all.size()-1; i > 0; i--)
		{
			all[i]->next = all[i - 1];
		}
		pre = all[0];
	} while (pre->next != NULL);
	return h.next;
}

int main25(){
	int data[6] = {
		1, 2,3,4,5,6
	};
	ListNode* root = new ListNode(data[0]);
	ListNode* pre = root;
	for (int i = 1; i < 6; i++)
	{
		pre->next = new ListNode(data[i]);
		pre = pre->next;
	}

	root = reverseKGroup(root, 3);

	return 0;
}