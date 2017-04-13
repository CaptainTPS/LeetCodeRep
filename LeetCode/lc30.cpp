#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> allWords;

vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> re;
	if (words.size() == 0)
	{
		return re;
	}
	int leng = words[0].length() * words.size();
	int perL = words[0].length();
	if (s.length() < leng)
	{
		return re;
	}
	for (int i = 0; i < words.size(); i++)
	{
		auto finder = allWords.find(words[i]);
		if (finder == allWords.end())
		{
			allWords.insert(unordered_map<string, bool>::value_type(words[i], 1));
		}
		else{
			finder->second += 1;
		}
	}

	for (int i = 0; i <= s.length() - leng; i++)
	{
		int cnt = 0;
		auto allWordsCopy = allWords;
		for (int j = 0; j < leng; j += perL)
		{
			string temp = s.substr(i+j, perL);
			auto finder = allWordsCopy.find(temp);
			if (finder == allWordsCopy.end())
			{
				break;
			}
			else if (finder->second == 0)
			{
				break;
			}
			else
			{
				finder->second -= 1;
				cnt++;
			}
		}
		if (cnt == words.size())
		{
			re.push_back(i);
		}
	}
	return re;
}

int main30(){
	vector<int> re; 
	string s1 = "wordgoodgoodgoodbestword";
	vector<string> s2;
	s2.push_back("word");
	s2.push_back("good");
	s2.push_back("best");
	s2.push_back("good");
	re = findSubstring(s1, s2);
	return 0;
}