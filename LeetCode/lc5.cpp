#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


string longestPalindrome(string s) {
	int x = 0;
	int length = 1;
	int lengthtemp;
	for (int i = 0; i < s.length(); i++)
	{
		lengthtemp = 1;
		while (i - lengthtemp >= 0 && i + lengthtemp< s.length()){
			if (s[i - lengthtemp] == s[i + lengthtemp])
			{
				lengthtemp++;
			}
			else{
				break;
			}
		}
		if (2 * lengthtemp - 1 > length)
		{
			x = i;
			length = 2 * lengthtemp - 1;
		}
	}

	for (int i = 0; i < s.length()-1; i++)
	{
		lengthtemp = 0;
		while (i - lengthtemp >= 0 && i + lengthtemp +1< s.length()){
			if (s[i - lengthtemp] == s[i + lengthtemp + 1])
			{
				lengthtemp++;
			}
			else{
				break;
			}
		}
		if (2 * lengthtemp > length)
		{
			x = i;
			length = 2 * lengthtemp;
		}
	}

	string re = "";
	if (length %2 ==0)
	{
		for (int i = x - length / 2 + 1; i <= x + length / 2; i++)
		{
			re += s[i];
		}
	}
	else
	{
		for (int i = x - (length - 1) / 2; i <= x + (length - 1) / 2; i++)
		{
			re += s[i];
		}
	}

	return re;
}


int main5(){
	string in = "cbbd";
	string out = longestPalindrome(in);
	cout << out << endl;

	return 0;
}