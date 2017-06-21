#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution133 {
public:
	unordered_map<int, vector<int>> all;
	unordered_map<int, UndirectedGraphNode*> map;

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr)
			return node;
		UndirectedGraphNode *p;
		queue<UndirectedGraphNode*> que;
		que.push(node);

		UndirectedGraphNode *re = nullptr;

		while (!que.empty()){
			p = que.front();
			que.pop();
			auto find = all.find(p->label);
			if (find != all.end())
				continue;

			UndirectedGraphNode* temp = new UndirectedGraphNode(p->label);
			if (re == nullptr)
				re = temp;

			map.insert({ p->label, temp });
			all.insert({ p->label, vector<int>() });
			for (auto m : p->neighbors){
				all[p->label].push_back(m->label);
				que.push(m);
			}
		}

		for (auto itr : map){
			for (auto r : all[itr.first]){
				itr.second->neighbors.push_back(map[r]);
			}
		}
		return re;
	}
};