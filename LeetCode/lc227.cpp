#include <string>
#include <stack>
#include <deque>

using namespace std;

class Solution227 {
public:
	typedef long long ll;
	int calculate(string s) {
		deque<ll> nums;
		deque<char> op;
		for (ll i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
				continue;
			if (isdigit(s[i])){
				int n = 0;
				while (i < s.length() && isdigit(s[i])){
					n = n * 10 + s[i++] - '0';
				}
				i--;
				nums.push_back(n);

				if (!op.empty() && (op.back() == '/' || op.back() == '*')){
					ll b, a, re;
					b = nums.back(); nums.pop_back();
					a = nums.back(); nums.pop_back();
					re = (op.back() == '/' ? a / b : a*b);
					nums.push_back(re);
					op.pop_back();
				}
			}
			else
			{
				ll b, a;
				op.push_back(s[i]);	
			}
		}
		while (!op.empty()){
			char c = op.front();
			ll a = nums.front(); nums.pop_front();
			ll b = nums.front(); nums.pop_front();
			ll re = (c == '+' ? a + b : a - b);
			nums.push_front(re);
			op.pop_front();
		}
		return nums.back();
	}
};