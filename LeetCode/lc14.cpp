#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty())
	{
		return "";
	}
	int n = 0;
	bool flag = true;
	char c;
	while (flag){
		if (n < strs[0].length())
		{
			c = strs[0][n];
		}
		else
		{
			break;
		}
		for (int i = 1; i < strs.size(); i++)
		{
			if (n >= strs[i].length())
			{
				flag = false;
				break;
			}
			if (strs[i][n] != c)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
		n++;
	}
	string t = "";
	for (int i = 0; i < n; i++)
	{
		t += strs[0][i];
	}
	return t;
}

int main14(){
	vector<string> str;
	str.push_back("abcd");
	str.push_back("abc");
	string re = longestCommonPrefix(str);

	return 0;
}