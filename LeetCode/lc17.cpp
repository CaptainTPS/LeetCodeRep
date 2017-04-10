#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void dfs(string &digits, int now, vector<string> &result, string tre, char table[10][4]){
	if (now == digits.length())
	{
		if (!tre.empty())
		{
			result.push_back(tre);
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int t = digits[now] - '0';
		if (t > 9)
		{
			continue;
		}
		if (table[t][i] == '.')
		{
			continue;
		}
		tre += table[t][i];
		dfs(digits, now + 1, result, tre, table);
		tre.erase(tre.end()-1);
	}

}

vector<string> letterCombinations(string digits) {
	char table[10][4] = {
		{ ' ', '.', '.', '.' },
		{ '.', '.', '.', '.' }, 
		{ 'a', 'b', 'c', '.' },
		{ 'd', 'e', 'f', '.' },
		{ 'g', 'h', 'i', '.' },
		{ 'j', 'k', 'l', '.' },
		{ 'm', 'n', 'o', '.' },
		{ 'p', 'q', 'r', 's' },
		{ 't', 'u', 'v', '.' },
		{ 'w', 'x', 'y', 'z' }
		
	};
	
	vector<string> re;
	dfs(digits, 0, re, "", table);
	return re;
}

int main17(){
	vector<string> re = letterCombinations("23");
	return 0;
}