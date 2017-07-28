#include <vector>
#include <unordered_map>

using namespace std;

class Solution210 {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> indegree(numCourses, 0);
		unordered_multimap<int, int> toC;
		vector<int> order;
		for (auto x : prerequisites){
			indegree[x.first]++;
			toC.insert({ x.second, x.first });
		}

		while (1){
			int index = -1;
			bool flag = false;
			for (int i = 0; i < numCourses; i++)
			{
				if (indegree[i] == 0){
					index = i;
					break;
				}
				if (indegree[i] > 0)
					flag = true;
			}
			if (index < 0 && flag){
				return vector<int>();
			}
			if (index < 0 && !flag){
				return order;
			}
			order.push_back(index);
			indegree[index] = -1;
			auto range = toC.equal_range(index);
			for (auto x = range.first; x != range.second; x++){
				indegree[x->second]--;
			}
		}
		return order;
	}
};