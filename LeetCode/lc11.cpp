#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
	int max = 0;
	int left = 0;
	int right = height.size() - 1;
	while (right > left)
	{
		int tempmax = (right - left) * min(height[left], height[right]);
		if (tempmax > max)
		{
			max = tempmax;
		}
		if (height[left] < height[right])
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	return max;
}

int main11(){
	vector<int> height;
	height.push_back(2);
	height.push_back(1);
	height.push_back(3);
	height.push_back(4);
	int n = maxArea(height);
	return 0;
}