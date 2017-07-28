#include <vector>
#include <unordered_map>

using namespace std;

class Solution207 {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> indegree(numCourses, 0);
		unordered_multimap<int, int> toCourses;
		for (auto x : prerequisites){
			toCourses.insert({ x.second, x.first });
			indegree[x.first]++;
		}

		while (1){
			int index = -1;
			bool flag = false;
			for (int i = 0; i < numCourses; i++)
			{
				if (indegree[i] == 0)
				{
					index = i;
					break;
				}
				if (indegree[i] > 0)
					flag = true;
			}
			if (index == -1 && flag)
				return false;
			if (index == -1 && !flag)
				return true;

			indegree[index] = -1;

			auto range = toCourses.equal_range(index);
			for (auto x = range.first; x != range.second; x++){
				indegree[x->second]--;
			}

		}
		return true;
	}
};