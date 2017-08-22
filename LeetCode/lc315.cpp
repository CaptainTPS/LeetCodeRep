#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Solution315 {
public:

	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return vector<int>();
		vector<int> con(n, 0);
		vector<int> counts(n);
		counts[n - 1] = 0;
		con[0] = nums[n-1];
		int ptr = 1;
		for (int i = n - 2; i >= 0; i--){
			int p = ptr;
			while (p >= 1 && con[p - 1] >= nums[i]){
				swap(con[p], con[p - 1]);
				p--;
			}
			con[p] = nums[i];
			counts[i] = p;
			ptr++;
		}
		return counts;
	}
};