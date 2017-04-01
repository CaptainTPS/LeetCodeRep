#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int reverse(int x) {
	int sign = 1;
	if (x < 0)
	{
		sign = -1;
		x = abs(x);
	}
	stack<int> all;
	long long temp = 0;
	while (x > 0)
	{
		all.push(x % 10);
		x = x / 10;
	}
	long long f = 1;
	while (!all.empty())
	{
		temp += all.top()* f;
		all.pop();
		f *= 10;
	}

	if (temp >= (((long long)1)<<31))
	{
		temp = 0;
	}

	temp *= sign;
	return temp;
}

int main7(){
	
	cout << reverse(1534236469) << endl;
	return 0;
}