#include <cstdlib>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

bool isMatchCheat(string s, string p) {
	regex expression(p);

	bool t = regex_match(s, expression);
	return t;
}

bool isMatch(string s, string p) {
	if (s.empty())
	{
		if (p.empty())
		{
			return true;
		}
		else if (p.size()== 1)
		{
			return false;
		}
		else if (p[1] != '*')
		{
			return false;
		}
		else{
			p.erase(p.begin(), p.begin() + 2);
			return isMatch(s, p);
		}
	}
	else{
		if (p.empty())
		{
			return false;
		}
		else if (p.size() == 1)
		{
			if (p[0] == '.')
			{
				p[0] = s[0];
			}

			if (p[0] == s[0])
			{
				s.erase(s.begin());
				p.erase(p.begin());
				return isMatch(s, p);
			}
			else
			{
				return false;
			}
		}
		else if (p[1] != '*')
		{
			if (p[0] == '.')
			{
				p[0] = s[0];
			}

			if (p[0] == s[0])
			{
				s.erase(s.begin());
				p.erase(p.begin());
				return isMatch(s, p);
			}
			else
			{
				return false;
			}
		}
		else{
			string tp = p;
			tp.erase(tp.begin(), tp.begin() + 2);
			if (isMatch(s,tp))
			{
				return true;
			}
			while (!s.empty())
			{
				if (s[0] != p[0]&& p[0] !='.')
				{
					break;
				}
				s.erase(s.begin());
				if (isMatch(s,tp))
				{
					return true;
				}
			}
			return false;
		}
	}
}

int main10(){
	string str = "aaaa";
	string pattern = "a*a";
	
	bool t = isMatch(str, pattern);

	cout << t << endl;
	
	return 0;
}