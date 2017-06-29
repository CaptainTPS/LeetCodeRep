#include <cstdlib>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution150 {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (auto i : tokens){
			if (i == "+" || i == "-" || i == "*" || i == "/")
				doOperation(s, i);
			else
				doPush(s, i);
		}
		return s.top();
	}

private:
	void doOperation(stack<int>& s, string str){
		int b = s.top(); s.pop();
		int a = s.top(); s.pop();
		switch (str[0])
		{
		case '+':
			s.push(a + b);
			break;
		case '-':
			s.push(a - b);
			break;
		case '*':
			s.push(a*b);
			break;
		case '/':
			s.push(a / b);
			break;
		default:
			s.push(a); s.push(b);
			break;
		}
	}

	void doPush(stack<int>& s, string str){
		int m;
		stringstream ss;
		ss << str;
		ss >> m;
		s.push(m);
	}
};