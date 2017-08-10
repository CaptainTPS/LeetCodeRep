#include <string>
#include <stack>

using namespace std;

class Solution224 {
public:
	//Äæ²¨À¼Ê½ will TLE...
	string reversePolishNotation(string s){
		stack<string> s1;
		stack<string> s2;
		s1.push("#");
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '('){
				s1.push("(");
			}
			else if (s[i] == ')')
			{
				while (s1.top() != "(" && s1.top() != "#"){
					s2.push(s1.top());
					s1.pop();
				}
				if (s1.top() == "(")
					s1.pop();
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				int n = 0;
				while (i < s.length() && s[i] >= '0' && s[i] <= '9'){
					n = n * 10 + s[i++] - '0';
				}
				i--;
				s2.push(to_string(n));
			}
			else if (s[i] == '*' || s[i] == '//')
			{
				while (s1.top() != "(" && s1.top() != "#" && s1.top() != "+" && s1.top() != "-"){
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(string(1, s[i]));
				
			}
			else if (s[i] == '+' || s[i] == '-'){
				while (s1.top() != "(" && s1.top() != "#"){
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(string(1, s[i]));
			}
		}
		while (s1.top() != "#"){
			s2.push(s1.top());
			s1.pop();
		}

		string result = " ";
		while (!s2.empty()){
			result = " " +  s2.top() + result;
			s2.pop();
		}
		return result;
	}

	int calculateTLE(string s){
		if (s.empty())
			return 0;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == ' '){
				s.erase(s.begin() + i);
			}
		}
		
		string rpn = reversePolishNotation(s);

		stack<int> nums;
		for (int i = 0; i < rpn.length(); i++)
		{
			if (rpn[i] == ' ')
				continue;

			if (isdigit(rpn[i])){
				int n = 0;
				while (i < rpn.length() && isdigit(rpn[i])){
					n = n * 10 + rpn[i++] - '0';
				}
				nums.push(n);
			}
			else
			{
				int b = nums.top(); nums.pop();
				int a = nums.top(); nums.pop();
				switch (rpn[i])
				{
				case '+':
					nums.push(a + b);
					break;
				case '-':
					nums.push(a - b);
					break;
				case '*':
					nums.push(a * b);
					break;
				case '//':
					nums.push(a / b);
					break;
				default:
					break;
				}
			}
		}
		return nums.top();
	}

	int calculate(string s) {
		typedef long long ll;
		if (s.empty())
			return 0;
		stack<char> op;
		stack<ll> nums;
		for (ll i = 0; i < s.length(); i++){
			if (s[i] == ' '){
				s.erase(s.begin() + i);
			}
		}

		ll ptr = 0;
		while (ptr < s.length()){
			char c = s[ptr];
			if (isdigit(c)){
				ll n = 0;
				while (ptr < s.length() && isdigit(s[ptr])){
					n = n*10 + s[ptr++] - '0';
				}
				nums.push(n);
				ptr--;

				if (!op.empty() && op.top() != '('){
					char cc = op.top(); op.pop();
					ll b = nums.top(); nums.pop();
					ll a = nums.top(); nums.pop();
					ll re = (cc == '+' ? a + b : a - b);
					nums.push(re);
				}
			}
			else {
				switch (c)
				{
				case '+':
				case '-':
				case '(':
				{
					op.push(c);
					break;
				}
				case ')':
				{
					op.pop();
					if (!op.empty() && op.top() != '('){
						char cc = op.top(); op.pop();
						ll b = nums.top(); nums.pop();
						ll a = nums.top(); nums.pop();
						ll re = (cc == '+' ? a + b : a - b);
						nums.push(re);
					}
					break;
				}
				default:
					break;
				}
			}
			ptr++;
		}
		while (!op.empty()){
			ll a = nums.top(); nums.pop();
			ll b = nums.top(); nums.pop();
			if (op.top() == '+')
				nums.push(a + b);
			else
			{
				nums.push(b - a);
			}
			op.pop();
		}
		return nums.top();
	}
};