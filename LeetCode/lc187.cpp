#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution187 {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> re;
		if (s.empty())
			return re;
		set<string> ss;
		set<string> tr;
		for (int i = 0; i <= (int)s.length() - 10; i++)
		{
			string t = s.substr(i, 10);
			if (ss.find(t) != ss.end())
				tr.insert(t);
			else
				ss.insert(t);
		}
		for (auto x : tr)
			re.push_back(x);
		return re;
	}
};