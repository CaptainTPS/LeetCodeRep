#include <cstdlib>
#include <string>

using namespace std;
//KMP ALGORITHM

void getNextArray(int* next, string tplate){//next[8] wrong
	next[0] = tplate.length();
	if (next[0] == 0)
	{
		return;
	}
	else if (next[0] == 1)
	{
		next[1] = 0;
		return;
	}
	next[1] = 0;
	next[2] = 0;
	for (int i = 3; i < next[0]+1; i++)
	{
		int loc = i - 2;
		while (loc > 0)
		{
			loc = next[loc+1];
			if (tplate[i-2] == tplate[loc])
			{
				next[i] = loc + 1;
				break;
			}
			if (loc == 0)
			{
				next[i] = 0;
				break;
			}
		}
	}
}

int strStr(string haystack, string needle) {
	int *next = new int[needle.length() + 1];
	getNextArray(next, needle);
	if (next[0] == 0)
	{
		return 0;
	}
	//do compare
	int mark = 0;
	int inner = 0;
	while (mark < haystack.length())
	{
		
		if (haystack[mark] == needle[inner])
		{
			mark++;
			inner++;
		}
		else
		{
			if (inner == 0)
			{
				mark++;
			}
			else
			{
				inner = next[inner + 1];
			}
		}
		if (inner == needle.length())
		{
			return (mark - inner);
		}
	}

	delete[] next;
	return -1;
}

int main28(){
	string s1 = "aabaaabaaac";
	string s2 = "aabaaac";
	int t = strStr(s1, s2);
	return 0;
}