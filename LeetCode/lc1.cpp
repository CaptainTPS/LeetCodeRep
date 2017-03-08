#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;



	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> re;
		for (int i = 0; i < nums.size(); i++) {
			if (!re.empty())
				break;
			for (int j = i+1; j<nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					re.push_back(i);
					re.push_back(j);
					break;
				}

			}

		}
		return re;
	}


int main1() {
	vector<int> data;
	data.push_back(3); 
	data.push_back(2); 
	data.push_back(4);
	data = twoSum(data, 6);

	return 0;
}