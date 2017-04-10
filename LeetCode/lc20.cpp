#include <cstdlib>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool isequal(char c1, char c2){
	if (c1 == '('&&c2==')')
	{
		return true;
	}
	else if (c1 == '{'&&c2 == '}')
	{
		return true;
	}
	else if (c1 == '['&&c2 == ']')
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool isValid(string s) {
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (st.empty())
		{
			st.push(s[i]);
			continue;
		}
		if (isequal (st.top() , s[i]))
		{
			st.pop();
		}
		else
		{
			st.push(s[i]);
		}
	}
	if (st.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main20(){
	bool t = isValid("()");
	return 0;
}