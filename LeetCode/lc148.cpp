//148. Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* sortList(ListNode* head) {
        int cnt = 0;
        ListNode *temp = head;
        while(temp != nullptr){
        	temp = temp->next;
        	cnt++;
        }
        return mergeSort(head, cnt);
    }
private:
	ListNode* sortList(ListNode *begin, ListNode *end){
		if(begin == end)
			return begin;
		ListNode f(0);
		int p = begin->val;
		ListNode *front = &f, *tail, *now, *temp, *temp2;
		now = begin;
		tail = front;
		while(now != end){
			temp = now->next;
			if(now->val<p){
				temp2 = front->next;
				front->next = now;
				now->next = temp2;
			}else{
				temp2 = tail->next;
				tail->next = now;
				now->next = temp2;
				tail = tail->next;
			}
			now = temp;
		}
		tail->next = end;
		front->next = sortList(front->next, begin);
		begin->next = sortList(begin->next, end);
		return front->next;
	}
	ListNode* merge(ListNode *s1, ListNode *s2){
		ListNode n(0);
		ListNode* now = &n, *temp;
		while(s1!= nullptr && s2!=nullptr){
			temp = now->next;
			if(s1->val < s2->val){
				now->next = s1;
				s1 = s1->next;
			}else{
				now->next = s2;
				s2 = s2->next;
			}
			now->next->next = temp;
			now = now->next;
		}
		if(s1 != nullptr)
			now->next = s1;
		if(s2 != nullptr)
			now->next = s2;
		return n.next;
	}

	ListNode* mergeSort(ListNode *begin, int n){
		if(n == 0)
			return nullptr;
		if(n == 1){
			begin->next = nullptr;
			return begin;
		}

		int cnt = 0;
		ListNode* half = begin;
		while(cnt < n/2){
			half = half->next;
			cnt++;
		}
		ListNode *first = mergeSort(begin, n/2);
		ListNode *second = mergeSort(half, n - n/2);
		return merge(first, second);
	}
};