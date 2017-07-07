#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution164 {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2)
			return 0;
		int s = nums.size();

		int mi, ma;
		mi = ma = nums[0];
		for (auto i : nums){
			mi = min(mi, i);
			ma = max(ma, i);
		}

		if (ma == mi)
			return 0;

		int bu_len = ceil((ma - mi)*1.0 / (s - 1));
		int bu_size = (ma - mi) / bu_len + 1;
		vector<int> bu_min(bu_size, INT_MAX);
		vector<int> bu_max(bu_size, INT_MIN);

		for (int i = 0; i < s; i++){
			int index = (nums[i] - mi) / bu_len;
			bu_min[index] = min(bu_min[index], nums[i]);
			bu_max[index] = max(bu_max[index], nums[i]);
		}

		int gmax = -1;
		for (int i = 0; i < bu_size; i++)
		{
			while (bu_max[i] < 0)
				i++;
			int j = i + 1;
			while (bu_max[j] < 0)
				j++;

			gmax = max(gmax, bu_min[j] - bu_max[i]);
		}
		return gmax;
	}
};
