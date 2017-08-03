#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution215 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		vector<int> temp;
		for (auto x : nums){
			if (temp.size() < k){
				temp.push_back(x); push_heap(temp.begin(), temp.end(), greater<int>());
			}
			else
			{
				if (temp.front() < x){
					pop_heap(temp.begin(), temp.end(), greater<int>()); temp.pop_back();
					temp.push_back(x); push_heap(temp.begin(), temp.end(), greater<int>());
				}
			}

		}
		return temp.front();
	}
};