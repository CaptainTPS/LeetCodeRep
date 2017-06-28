#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

#ifdef RIGHT
class LRUCache{
	const int cap;
	unordered_map<int, list<pair<int, int> >::iterator> map;
	list<pair<int, int>> lst;
public:
	LRUCache(int capacity) :cap(capacity) {}

	int get(int key) {
		auto it = map.find(key);
		if (it == map.end()) return -1;

		lst.push_front(*it->second);

		lst.erase(it->second);
		it->second = lst.begin();
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = map.find(key);
		if (it == map.end()){  // insert new
			while (map.size() >= cap) {
				map.erase(lst.crbegin()->first);
				lst.pop_back();
			}
		}
		else  // reset existed
			lst.erase(it->second);

		lst.push_front({ key, value });
		map[key] = lst.begin();
	}
};
#endif

class LRUCache {
public:
	LRUCache(int capacity) {
		size = capacity;
		head = new biLinkNode(-1, 0);
		tail = new biLinkNode(-1, -1);
		head->next = tail;
		head->pre = tail;
		tail->next = tail->pre = head;
	}

	~LRUCache(){
		if (head != nullptr)
			delete head;
		if (tail != nullptr)
			delete tail;
	}

	int get(int key) {
		auto find = container.find(key);
		if (find == container.end())
			return -1;
		else{
			renewPosition(key);
			return find->second->value;
		}
	}

	void put(int key, int value) {
		auto find = container.find(key);
		if (find == container.end()){
			biLinkNode* temp = new biLinkNode(key, value);
			while (container.size() >= size){
				eraseLRU();
			}
			container.insert({ key, temp });
			
			biLinkNode *ptr = tail->pre;
			ptr->next = temp;
			temp->next = tail;
			tail->pre = temp;
			temp->pre = ptr;
		}
		else
		{
			find->second->value = value;
			renewPosition(key);
		}
	}

private:
	void renewPosition(int key){
		//O(1)
		biLinkNode* temp = container[key];
		temp->pre->next = temp->next;
		temp->next->pre = temp->pre;
		biLinkNode *ptr = tail ->pre;
		ptr->next = temp;
		temp->next = tail;
		tail->pre = temp;
		temp->pre = ptr;
	}
	void eraseLRU(){
		//O(n)
		biLinkNode *ptr = head->next;
		if (ptr == tail)
			return;
		head->next = ptr->next;
		ptr->next->pre = head;

		container.erase(ptr->key);
		delete ptr;
	}

	struct biLinkNode
	{
		int key, value;
		biLinkNode *pre, *next;

		biLinkNode(int k, int v){
			key = k;
			value = v;
		}
	};


	int size;
	unordered_map<int, biLinkNode*> container;
	biLinkNode *head, *tail;
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/

#if 0
int main(){
	int m = 0;
	LRUCache lru(2);
	lru.put(1, 1);
	lru.put(2, 2);
	m = lru.get(1);
	lru.put(3, 3);
	m =lru.get(2);
	return 0;
}
#endif