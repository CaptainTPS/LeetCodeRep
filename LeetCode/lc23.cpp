#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool static cmp(ListNode* a, ListNode* b){
	return a->val > b->val;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode h(0);
	ListNode* pre = &h;
	vector<ListNode*> tl;
	for (int i = 0; i < lists.size(); i++)
	{
		if (lists[i] != NULL)
		{
			tl.push_back(lists[i]);
		}
	}
	make_heap(tl.begin(), tl.end(), cmp);
	while (!tl.empty())
	{
		pre->next = tl.front();
		pre = pre->next;
		ListNode* temp = tl.front()->next;
		pop_heap(tl.begin(), tl.end(), cmp);
		tl.pop_back();
		if (temp != NULL)
		{
			tl.push_back(temp);
			push_heap(tl.begin(), tl.end(), cmp);
		}
	}
	return h.next;
}



int main23(){
	vector<ListNode*> lists;
	ListNode* re = mergeKLists(lists);
	return 0;
}
