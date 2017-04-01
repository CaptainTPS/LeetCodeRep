#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

string convert(string s, int numRows) {
	string temp = "";
	//row 1
	if (numRows == 1)
	{
		return s;
	}
	int step = (numRows - 1) * 2;
	int nowp = 0;
	while (nowp < s.length()){
		temp += s[nowp];
		nowp += step;
	}
	
	//row center
	for (int i = 1; i < numRows-1; i++)
	{
		int step2 = 2 * (i);
		int step1 = step - step2;
		nowp = i;
		while (nowp < s.length()){
			temp += s[nowp];
			nowp += step1;
			if (nowp < s.length())
			{
				temp += s[nowp];
				nowp += step2;
			}
		}
	}
	
	//row last
	nowp = numRows -1;
	while (nowp < s.length()){
		temp += s[nowp];
		nowp += step;
	}
	return temp;
}

int main6(){
	string t = "PAYPALISHIRING";
	t = convert(t, 3);
	cout << t << endl;
	return 0;
}