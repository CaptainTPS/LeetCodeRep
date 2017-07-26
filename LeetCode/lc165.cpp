#include <string>
#include <sstream>

using namespace std;

class Solution165 {
public:
	int compareVersion(string version1, string version2) {
		stringstream ss1(version1), ss2(version2);

		while (!ss1.eof() && !ss2.eof()){
			int a, b;
			ss1 >> a;
			ss2 >> b;
			if (a < b)
				return -1;
			else if (a>b)
				return 1;
			
			char c;
			if (!ss1.eof())
				ss1 >> c;
			if (!ss2.eof())
				ss2 >> c;
		}

		if (ss1.eof() && ss2.eof())
			return 0;
		else if (ss1.eof()){
			while (!ss2.eof()){
				int a;
				ss2 >> a;
				if (a != 0)
					return -1;
				char c;
				if (!ss2.eof())
					ss2 >> c;
			}
			return 0;
		}
		else
			while (!ss1.eof()){
				int a;
				ss1 >> a;
				if (a != 0)
					return 1;
				char c;
				if (!ss1.eof())
					ss1 >> c;
			}
			return 0;

	}
};