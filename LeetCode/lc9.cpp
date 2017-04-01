#include <cstdlib>
#include <iostream>

using namespace std;

bool isPalindrome(int x) {
	if (x < 0)
	{
		return false;
	}
	int temp = 0;
	int temp2 = x;
	while (x>0)
	{
		temp = temp * 10 + x % 10;
		x /= 10;
	}
	if (temp == temp2)
	{
		return true;
	}
	else
		return false;
}

int main9(){
	cout << isPalindrome(1) << endl;
	return 0;
}