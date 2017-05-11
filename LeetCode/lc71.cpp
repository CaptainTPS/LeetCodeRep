#include <cstdlib>
#include <string>
#include <stack>

using std::string;

string simplifyPath(string path) {
	if (path.length() <=1)
	{
		return path;
	}
	int ptr = 0;
	string temp = "";
	std::stack<string> p;
	while (ptr < path.length())
	{
		string ss;

		while (path[ptr] == '/' && ptr < path.length())
		{
			ptr++;
		}

		while (path[ptr] != '/' && ptr < path.length())
		{
			ss += path[ptr];
			ptr++;
		}
		if (".."== ss&& !p.empty())
		{
			p.pop();
		}
		else if (ss != "" && ss != "." && ss != "..")
		{
			p.push(ss);
		}
	}
	string result = "";
	if (p.empty())
	{
		result += '/';
	}
	while (!p.empty())
	{
		result = '/' + p.top() + result;
		p.pop();
	}
	return result;
}

int main71(){
	string p = "/c/";
	string re = simplifyPath(p);
	return 0;
}