#include <vector>

using namespace std;

class Solution335 {
public:
	bool isSelfCrossing(vector<int>& x) {
		for (int i = 0; i < x.size(); i++){
			// i cross with i-3
			if (i >= 3 && x[i - 1] <= x[i - 3] && x[i] >= x[i - 2])
				return true;
			// i cross with i-4
			if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
				return true;
			//i cross with i-5
			if (i >= 5 && x[i - 1] <= x[i - 3] && x[i - 1] >= x[i - 3] - x[i - 5] && x[i - 2]> x[i - 4] && x[i - 2] <= x[i] + x[i - 4])
				return true;
		}

		return false;
	
	}
};