#include <cstdlib>
#include <string>

using namespace std;

string countAndSay(int n) {
	if (n == 0)
	{
		return string();
	}
	string temp = "1";
	int cnt = 1;
	while (cnt < n)
	{
		string tt = "";
		for (int i = 0; i < temp.size();)
		{
			char c = temp[i];
			int m = 0;
			while (i+m < temp.size())
			{
				if (temp[i] != temp[i+ m])
				{
					break;
				}
				m++;
			}
			tt += (char)(m + (int)'0');
			tt += c;
			i += m;
		}
		temp = tt;
		cnt++;
	}
	return temp;
}

int main38(){
	string re = countAndSay(5);
	return 0;
}