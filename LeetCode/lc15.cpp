#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

	vector<vector<int>> all;

	sort(nums.begin(), nums.end());
	for (int i = 0; i < (int)nums.size()-2; i++)
	{
		cout << nums.size() - 2 << endl;

		while (i != 0 && nums[i] == nums[i - 1] && i < nums.size() - 2)
		{
			i++;
		}
		int front = i + 1;
		int last = nums.size() - 1;
		while (front < last)
		{
			if (nums[i] + nums[front] + nums[last] == 0)
			{
				vector<int> temp;
				temp.push_back(nums[i]);
				temp.push_back(nums[front]);
				temp.push_back(nums[last]);
				all.push_back(temp);
				front++;
				while (nums[front] == nums[front - 1] && front < last)
				{
					front++;
				}
				last--;
				while (nums[last] == nums[last + 1] && last >front)
				{
					last--;
				}
			}
			else
			{
				if (nums[i] + nums[front] + nums[last] > 0){
					last--;
					while (nums[last] == nums[last + 1] && last >front)
					{
						last--;
					}
				}
				else{
					front++;
					while (nums[front] == nums[front - 1] && front < last)
					{
						front++;
					}
				}	
			}
		}
	}
	return all;
}

int main15(){
	vector<int> temp;
	//temp.push_back(-1);
	//temp.push_back(0);
	//temp.push_back(1);
	//temp.push_back(2);
	//temp.push_back(-1);
	//temp.push_back(4);

	vector<vector<int>> re = threeSum(temp);
	
	return 0;
}