#include <cstdlib>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
	bool *tag = new bool[nums.size()];
	fill(tag, tag + nums.size(), false);
	tag[0] = true;
	for (int i = 0; i < nums.size(); i++)
	{
		if (tag[i] == false)
		{
			return false;
		}
		else
		{
			for (int j = nums[i]; j >= 1; j--)
			{
				tag[i + j] = true;
				if (i + j == nums.size() -1)
				{
					return true;
				}
			}
		}
	}
	delete[] tag;
	return true;
}