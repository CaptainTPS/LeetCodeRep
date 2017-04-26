#include <cstdlib>

#ifndef INT_MAX
#define INT_MAX INTMAX_MAX
#endif

#ifndef INT_MIN
#define INT_MIN INTMAX_MIN
#endif

int divide(int dividend, int divisor) {
	long long a = dividend;
	long long b = divisor;
	int flag = 1;
	if ((a < 0 && b > 0) || (a > 0 && b < 0))
	{
		flag = -1;
	}
	a = abs(a);
	b = abs(b);

	if (b == 0)
	{
		return INT_MAX;
	}

	if (a == 0)
	{
		return 0;
	}

	long long nums[34];
	nums[0] = b;
	long long times[34];
	times[0] = 1;

	int i = 0;
	while (nums[i] <= a)
	{
		nums[i + 1] = nums[i] + nums[i];
		times[i + 1] = times[i] + times[i];
		i++;
	}
	long long sum = 0;
	for (int j = i; j >=0; j--)
	{
		if (a >= nums[j])
		{
			a -= nums[j];
			sum += times[j];
		}
	}
	sum = flag == 1 ? sum : -sum;
	if (sum > INT_MAX || sum < INT_MIN)
	{
		return INT_MAX;
	}
	return sum;
}


int main29(){
	int m = divide(2, 2);
	return 0;
}