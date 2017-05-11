#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> result;
	
	int cnt = 0;
	int length = 0;
	for (int now = 0; now < words.size();)
	{
		if (length + words[now].length() <= maxWidth)
		{
			length += words[now].length();
			length += 1;
			cnt++;
			now++;
			continue;
		}
		else
		{
			if (cnt == 1)
			{
				string temp = "";
				temp += words[now - 1];
				for (int j = 0; j < maxWidth - words[now-1].size(); j++)
				{
					temp += ' ';
				}
				result.push_back(temp);
			}
			else
			{
				string temp = "";
				temp += words[now - cnt];
				int each = (maxWidth + cnt - length) / (cnt-1);
				int first = (maxWidth + cnt - length) - each * (cnt - 1);
				string eachs = "";
				for (int j = 0; j < each; j++)
				{
					eachs += ' ';
				}
				for (int j = now - cnt + 1; j < now ; j++)
				{
					if (first > 0)
					{
						temp += ' ';
						first--;
					}
					temp += eachs;
					temp += words[j];
				}
				result.push_back(temp);
			}

			length = 0;
			cnt = 0;
		}
	}
	string temp = "";
	for (int j = words.size() - cnt; j < words.size(); j++)
	{
		temp += words[j];
		if (temp.length() < maxWidth)
		{
			temp += ' ';
		}
	}
	while (temp.length() < maxWidth)
	{
		temp += ' ';
	}
	result.push_back(temp);
	return result;
}

int main68(){
	string data[] = {
		"Don't", "go", "around", "saying", "the", "world", "owes", "you", "a", "living;", "the", "world"
	};
	vector<string> test(data, data + 12);
	vector<string> re = fullJustify(test, 30);
	for (int i = 0; i < re.size(); i++)
	{
		cout << re[i].length() << endl;
	}
	return 0;
}