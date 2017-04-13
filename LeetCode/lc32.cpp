#include <cstdlib>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int longestValidParentheses(string s) {
	int re = 0;
	int lastRight = 0;
	stack<int> index;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			index.push(i);
		}
		else
		{
			if (index.empty())
			{
				lastRight = i + 1;
			}
			else
			{
				
				index.pop();
				if (index.empty())
				{
					re = re < i - lastRight + 1 ? i - lastRight + 1 : re;
				}
				else
				{
					int in = index.top();
					re = re < i - in ? i - in : re;
				}
			}
		}
	}
	return re;
}

int main32(){
	string s = "(()()";
	int n = longestValidParentheses(s);
	return 0;
}