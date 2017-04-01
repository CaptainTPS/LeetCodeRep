#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int myAtoi(string str) {
	long long sign = 1;
	long long temp = 0;
	int i = 0;
	while (i < str.length()){
		if (str[i] == ' '){
			i++;
			continue;
		}
		else
			break;
	}
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (i < str.length())
	{
		if (str[i] >='0'&&str[i] <= '9')
		{
			temp = temp * 10 + (int)(str[i] - '0');
			i++;
			if (temp > INT_MAX)
			{
				break;
			}
		}
		else{
			break;
		}
	}
	temp *= sign;
	if (temp > INT_MAX)
	{
		return INT_MAX;
	}
	else if (temp < INT_MIN)
	{
		return INT_MIN;
	}
	return temp;
}

int main8(){
	cout << myAtoi("9223372036854775809") << endl;
	return 0;
}