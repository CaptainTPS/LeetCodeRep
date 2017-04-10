#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> re;
	if (nums.size() < 4)
	{
		return re;
	}
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] * 4 > target)
		{
			break;
		}
		while (i != 0 && i < nums.size() && nums[i] == nums[i - 1]){
			i++;
		}
		for (int j = i+1; j < nums.size(); j++)
		{
			while (j != i+1 && j < nums.size() && nums[j] == nums[j - 1]){
				j++;
			}
			int left = j + 1;
			int right = (int)nums.size() - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum == target)
				{
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);
					re.push_back(temp);

					do{
						left++;
					} while (nums[left] == nums[left - 1] && left < right);
					do{
						right--;
					} while (nums[right] == nums[right + 1] && left < right);

				}
				else if (sum < target)
				{
					do{
						left++;
					} while (nums[left] == nums[left - 1] && left < right);
				}
				else if (sum > target)
				{
					do{
						right--;
					} while (nums[right] == nums[right + 1] && left < right);
				}
				
			}
		}
	}
	return re;
}

int main18(){
	vector<int> num;
	int S[4] = { 0,0,0,0 };
	for (int i = 0; i < 4; i++)
	{
		num.push_back(S[i]);
	}
	vector<vector<int>> re = fourSum(num, 0);
	return 0;
}