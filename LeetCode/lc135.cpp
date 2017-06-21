#include <vector>
#include <algorithm>

using namespace std;

class Solution135 {
public:
	int candy(vector<int>& ratings) {
		if (ratings.empty())
		{
			return 0;
		}
		vector<int> num(ratings.size(), 1);

		for (int i = 1; i < ratings.size(); i++){
			if (ratings[i] > ratings[i - 1])
				num[i] = num[i - 1] + 1;
		}
		int s = 0;
		for (int i = ratings.size() - 2; i >=0; i--){
			if (ratings[i] > ratings[i + 1])
				num[i] = max(num[i + 1] + 1, num[i]);
			s += num[i];
		}
		s += num[ratings.size() - 1];
		return s;
	}
};