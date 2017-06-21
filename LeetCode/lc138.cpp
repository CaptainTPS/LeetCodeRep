#include <cstdlib>

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution138 {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *now = head, *temp, *re;
		if (now == nullptr)
		{
			return now;
		}

		while (now != nullptr){
			temp = new RandomListNode(now->label);
			temp->next = now->next;
			now->next = temp;
			now = temp->next;
		}

		now = head;
		while (now != nullptr){
			if (now->random != nullptr){
				now->next->random = now->random->next;
			}
			now = now->next->next;
		}
		
		temp = head;
		re = now = head->next;
		while (now != nullptr && now->next != nullptr){
			temp->next = temp->next->next;
			now->next = now->next->next;
			temp = temp->next;
			now = now->next;
		}
		temp->next = nullptr;
		return re;
	}
};