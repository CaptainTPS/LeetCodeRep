#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution93 {
public:
	int isValid(string s){
		if (s.size() == 1)
		{
			return s[0] - '0';
		}
		else
		{
			if (s[0] == '0')
			{
				return -1;
			}
			int m = stoi(s);
			return m;
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		vector<int> store(4, -1);
		for (size_t m1 = 0; m1 < 3; m1++)
		{
			if (m1>= s.length())
				continue;
			string s1 = s.substr(0, m1 + 1);
			int v = isValid(s1);
			if (v > 255 || v < 0 ||  v == store[0])
				continue;
			store[0] = v;
			fill(store.begin() + 1, store.begin() + 4, -1);
			for (size_t m2 = m1 + 1; m2 < m1 + 4; m2++)
			{
				if (m2 >= s.length())
					continue;
				string s2 = s.substr(m1 + 1, m2 - m1);
				v = isValid(s2);
				if (v >255 || v < 0 || v == store[1])
					continue;
				store[1] = v;
				fill(store.begin() + 2, store.begin() + 4, -1);
				for (size_t m3 = m2 + 1; m3 < m2 + 4; m3++)
				{
					if (m3 >= s.length())
						continue;
					string s3 = s.substr(m2 + 1, m3 - m2);
					v = isValid(s3);
					if (v >255 || v < 0 || v == store[2])
						continue;
					store[2] = v;
					fill(store.begin() + 3, store.begin() + 4, -1);
					for (size_t m4 = m3 + 1; m4 < m3 + 4; m4++)
					{
						if (m4 != s.length() - 1)
							continue;
						string s4 = s.substr(m3 + 1, m4 - m3);
						v = isValid(s4);
						if (v >255 || v < 0 || v == store[3])
							continue;
						store[3] = v;
						result.push_back(to_string(store[0]) + '.' + to_string(store[1]) + '.' + to_string(store[2]) + '.' + to_string(store[3]));
					}
				}
			}
		}
		return result;
	}
};
