#include <cstdlib>

int uniquePaths(int m, int n) {
	int max = m > n ? m : n;
	int min = m < n ? m : n;
	if (min <= 1)
	{
		return 1;
	}

	min -= 1;
	max -= 1;
	//C max+min min

	long long re = 1;
	long long cnt = min + max;
	while (cnt > max)
	{
		re = re * cnt;
		cnt--;
	}
	cnt = 1;
	while (cnt <=min)
	{
		re /= cnt;
		cnt++;
	}

	return re;

}