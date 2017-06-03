#include <vector>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> all;
		all.push_back(0);
		int m = 1;
		for (int level = 0; level < n; level++)
		{
			for (int i = all.size() -1 ; i >= 0; i--)
			{
				int temp = all[i];
				temp = temp | m;
				all.push_back(temp);
			}
			m = m << 1;
		}
		return all;
	}
};

int main89(){
	Solution().grayCode(1);
	return 0;
}