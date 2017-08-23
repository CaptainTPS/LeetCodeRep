#include <sstream>
#include <string>

using namespace std;

class Solution331 {
public:
	bool searchTree(stringstream &ss){
		if (ss.eof())
			return false;
		string s;
		ss >> s;
		if (s == "#")
			return true;

		return searchTree(ss) && searchTree(ss);
	}

	bool isValidSerialization(string preorder) {
		for (auto& x : preorder){
			if (x == ',')
				x = ' ';
		}
		
		stringstream ss(preorder);
		
		bool flag = searchTree(ss);
		flag = flag && ss.eof();
		return flag;
	}
};