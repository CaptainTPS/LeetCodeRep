#include <cstdlib>
#include <string>

using namespace std;

string multiply(string num1, string num2) {
	if (num1.empty() || num2.empty())
	{
		return "";
	}
	int *re = new int[num1.length() + num2.length()];
	fill(re, re + num1.length() + num2.length(), 0);

	for (int i = 0; i < num1.length(); i++)
	{
		int x1 = (int)(num1[i] - '0');
		for (int j = 0; j <num2.length(); j++)
		{
			int x2 = (int)(num2[j] - '0');
			re[num1.length() + num2.length() - 2 - i - j] += x1 * x2;
		}
	}
	
	int next = 0;
	for (int i = 0; i < num1.length() + num2.length(); i++)
	{
		next += re[i];
		re[i] = next % 10;
		next /= 10;
	}
	string result = "";
	bool flag = true;
	for (int i = num1.length() + num2.length() -1; i >= 0; i--)
	{
		if (re[i] == 0 && flag)
		{
			continue;
		}
		flag = false;
		result += (char)(re[i] + (int)'0');
	}
	if (flag)
	{
		result = "0";
	}
	delete[] re;
	return result;
}

int main43(){
	string re = multiply("123456", "1123456");
	return 0;
}