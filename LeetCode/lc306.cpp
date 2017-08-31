#include <string>

using namespace std;

string operator+(string &a, string &b){
	if (a.length() < b.length())
		return  b + a;

	string result = a;
	int tonext = 0;
	int ln = result.length();
	for (int i = 0; i < ln; i++){
		int now = a[ln - i - 1] - '0';
		if (i < b.length())
			now += b[b.length() - i - 1] - '0';
		now += tonext;
		if (now >= 10){
			tonext = 1;
			now %= 10;
		}
		else
		{
			tonext = 0;
		}
		result[ln - i - 1] = '0' + now;
	}
	if (tonext)
		result = "1" + result;
	return result;
}

class Solution306 {
public:
	bool isAdditiveNumber(string num) {
		int n = num.length();
		if (n <= 2)
			return false;

		for (int len = 1; len <= n; len++){
			for (int i = 1; i <= n - len; i++){
				int ptr = len + i;
				if (ptr >= n)
					continue;
				string a = num.substr(0, len);
				string b = num.substr(len, i);
				if ((a.length() > 1 && a[0] == '0') ||(b.length() >1 && b[0] == '0'))
					continue;
				string now = a + b;
				while (ptr < n){
					if (now != num.substr(ptr, now.length()))
						break;
					ptr += now.length();
					a = b;
					b = now;
					now = a + b;
				}
				if (ptr == n)
					return true;
			}
		}
		return false;
	}
	
};