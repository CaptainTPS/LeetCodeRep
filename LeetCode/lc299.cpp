#include <string>
#include <unordered_map>
using namespace std;

class Solution299 {
public:
	typedef long long ll;

	string getHint(string secret, string guess) {
		unordered_map<char, ll> ctocnt;
		
		ll bulls = 0;
		for (ll i = 0; i < secret.size(); i++){
			auto finder = ctocnt.find(secret[i]);
			if (finder == ctocnt.end()){
				ctocnt.insert({ secret[i], 1 });
			}
			else
			{
				finder->second++;
			}

			if (secret[i] == guess[i])
				bulls++;
		}

		ll cows = 0;
		for (ll i = 0; i < guess.size(); i++){
			auto finder = ctocnt.find(guess[i]);
			if (finder == ctocnt.end() || finder->second == 0)
				continue;

			finder->second--;
			cows++;
		}
		cows -= bulls;
		string result = to_string(bulls) + "A" + to_string(cows) + "B";
		return result;
	}
};