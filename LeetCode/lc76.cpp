#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
	string temp = "";
	if (s.empty() || t.empty())
	{
		return temp;
	}

	unordered_map<char, int> Ttable;
	for (int i = 0; i < t.length(); i++)
	{
		if (Ttable.find(t[i]) != Ttable.end())
		{
			Ttable[t[i]] += 1;
		}
		else
		{
			Ttable.insert({ t[i], 1 });
		}
	}

	int left = 0;
	int right = 0;
	int cnt = 0;
	while (right < s.length())
	{
		if (Ttable.find(s[right]) != Ttable.end())
		{
			Ttable[s[right]] -= 1;
			if (Ttable[s[right]] >= 0)
			{
				cnt++;
			}
			if (cnt == t.length())
			{
				while (left <= right)
				{
					if (Ttable.find(s[left]) == Ttable.end())
					{
						left++;
					}
					else
					{
						Ttable[s[left]]++;
						if (Ttable[s[left]] == 1)
						{
							cnt--;
							string tt = s.substr(left, right + 1 - left);
							if (temp.empty())
							{
								temp = tt;
							}
							else
							{
								if (temp.length() > tt.length())
								{
									temp = tt;
								}
							}
							left++;
							break;
						}
						left++;
					}
				}
			}
		}
		right++;
		
	}
	return temp;
}


int main76(){
	string a = "abc";
	string b = "ab";
	string re = minWindow(a, b);
	return 0;
}