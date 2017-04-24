#include <cstdlib>
#include <string>

/* 
'?' Matches any single character.
'*' Matches any sequence of characters(including the empty sequence).
*/

using std::string;
namespace lc44{
	bool isMatchT(string s, string p) 
	{
		//Time Limit Exceeded 
		if (s.empty() && p.empty())
		{
			return true;
		}
		else
		{
			if (p.empty())
			{
				return false;
			}
		}
		if (s.empty())
		{
			if (p.back() == '*')
			{
				p.pop_back();
				return isMatchT(s, p);
			}
			else
			{
				return false;
			}
		}

		if (p.back() == '?')
		{
			s.pop_back();
			p.pop_back();
			return isMatchT(s, p);
		}
		if (p.back() == '*')
		{
			bool re = false;
			p.pop_back();
			re = re || isMatchT(s, p);
			p.push_back('*');
			s.pop_back();
			re = re || isMatchT(s, p);
			return re;
		}
		if (p.back() == s.back())
		{
			s.pop_back();
			p.pop_back();
			return isMatchT(s, p);
		}
		else
		{
			return false;
		}
	}

	bool isMatch(string s, string p){
		int sptr = 0;
		int pptr = 0;
		int start = -1;
		int ss = -1;
		while (sptr != s.length())
		{
			if (s[sptr] == p[pptr] || p[pptr] == '?')
			{
				sptr++; pptr++;
				continue;
			}
			if (p[pptr] == '*')
			{
				start = pptr;
				pptr++;
				ss = sptr;
				continue;
			}
			if (start >=0)
			{
				pptr = start;
				sptr = ++ss;
			}
			else
			{
				return false;
			}
		}

		if (sptr == s.length() && pptr == p.length())
		{
			return true;
		}
		else
		{
			if (pptr == p.length())
			{
				return false;
			}
			if (sptr == s.length())
			{
				while (pptr != p.length() && p[pptr] == '*')
				{
					pptr++;
				}
				if (pptr == p.length())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}


}
int main44(){
	string test = "aa";
	string p = "*";
	bool re = lc44::isMatch(test, p);
	return 0;
}