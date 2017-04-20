#include <cstdlib>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
	if (height.size() <= 2)
	{
		return 0;
	}
	int *left = new int[height.size()];
	int *right = new int[height.size()];

	int lmax = 0;
	for (int i = 0; i < height.size(); i++)
	{
		lmax = lmax > height[i] ? lmax : height[i];
		left[i] = lmax;
	}
	int rmax = 0;
	for (int i = height.size() -1; i >=0; i--)
	{
		rmax = rmax > height[i] ? rmax : height[i];
		right[i] = rmax;
	}
	int sum = 0;
	for (int i = 0; i < height.size(); i++)
	{
		int m = left[i] < right[i] ? left[i] : right[i];
		if (m > height[i])
		{
			sum += m - height[i];
		}
	}
	return sum;
}

int main42(){

	return 0;
}