#include <cstdlib>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	int low = 0;
	int high = nums.size() - 1;
	int mark = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (nums[mid] == target)
		{
			mark = mid;
			break;
		}
		else if (nums[mid] < target)
		{
			low = mid + 1;
		}
		else if (nums[mid] > target)
		{
			high = mid - 1;
		}
	}

	vector<int> re;
	re.push_back(mark);
	re.push_back(mark);
	if (mark != -1)
	{
		while (re[0] >=0)
		{
			if (nums[re[0]-1] != nums[mark])
			{
				break;
			}
			else
			{
				re[0]--;
			}
		}
		if (re[0] == -1)
		{
			re[0] = 0;
		}
		while (re[1] < nums.size())
		{
			if (nums[re[1] + 1] != nums[mark])
			{
				break;
			}
			else
			{
				re[1]++;
			}
		}
		if (re[1] == nums.size())
		{
			re[1]--;
		}
	}
	return re;
}

int main34(){
	int data[6] = { 5, 7, 7, 8, 8, 10 };
	vector<int> temp(data, data + 6);
	vector<int> re = searchRange(temp, 8);
	return 0;
}