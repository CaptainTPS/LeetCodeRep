#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution282 {
public:
	typedef long long ll;

	vector<string> result;

	void dfs(string& num, ll now, ll sum, ll target, string re, char preop, ll pres){
		if (now == num.length()){
			if (sum == target)
				result.push_back(re);
			return;
		}

		for (int i = now; i < num.length(); i++)
		{
			string t = num.substr(now, i - now + 1);
			ll s = atol(t.data());
			if (t[0] == '0' && t.length() > 1)
				continue;
			int sumn;
			if (preop == '+'){
				sumn = sum - pres + pres * s;
			}
			else if (preop == '-'){
				sumn = sum + pres - pres * s;
			}
			else
			{
				sumn = sum*s;
			}
			dfs(num, i + 1, sumn, target, re + '*' + t, preop, pres * s);
			dfs(num, i + 1, sum + s, target, re + '+' + t, '+', s);
			dfs(num, i + 1, sum - s, target, re + '-' + t, '-', s);

		}
	}

	vector<string> addOperators(string num, int target) {
		for (int i = 1; i <= num.length(); i++)
		{
			string t = num.substr(0, i);
			ll s = atol(t.data());
			if (t[0] == '0' && t.length() > 1)
				continue;
			dfs(num, i, s, target, t, '*', s);
		}
		return result;
	}
};

#if 0
//not working

class Solution282 {
public:
	typedef long long ll;

	struct twoseg{
		ll begin[2];
		ll end[2];
		ll val[2];
		char op;

		twoseg(ll b1,ll e1,ll v1,ll b2,ll e2,ll v2, char c){
			begin[0] = b1;
			end[0] = e1;
			val[0] = v1;

			begin[1] = b2;
			end[1] = e2;
			val[1] = v2;

			op = c;
				
		}
		
	};

	set<string> dfs(string& num, vector<vector<multimap<ll, twoseg>>>& dp, int target, int b, int e){
        set<string> re;
		auto range = dp[b][e].equal_range(target);
        for(auto itr = range.first; itr != range.second; itr++){
            if(itr->second.op == '#'){
                re.insert(num.substr(b, e-b+1));
            }else{
                auto r1 = dfs(num, dp, itr->second.val[0], itr->second.begin[0], itr->second.end[0]);
                auto r2 = dfs(num, dp, itr->second.val[1], itr->second.begin[1], itr->second.end[1]);
                char c = itr->second.op;
                for(auto a : r1){
                    for(auto b : r2){
                        re.insert(a + c + b);
                    }
                }
            }
        }
        return re;
	}

	vector<string> addOperators(string num, int target) {

		int len = num.length();
		if (len == 0)
			return vector<string>();

		vector<vector<multimap<ll, twoseg>>> dp(len, vector<multimap<ll, twoseg>>(len));

		for (int l = 1; l <= len; l++)
		{
			for (int i = 0; i + l - 1 < len; ++i)
			{
				int j = i + l - 1;
				ll t = stol(num.substr(i, l));
				dp[i][j].insert({ t, twoseg(0, 0, 0, 0, 0, 0, '#') });

				for (int k = i; k < j; ++k)
				{
					int pre1 = -1;
					for (auto itr1 = dp[i][k].begin(); itr1 != dp[i][k].end(); itr1++){
						if (itr1->first == pre1)
							continue;
						pre1 = itr1->first;
						int pre2 = -1;
						for (auto itr2 = dp[k + 1][j].begin(); itr2 != dp[k + 1][j].end(); itr2++){
							if (itr2->first == pre2)
								continue;
							pre2 = itr2->first;

							dp[i][j].insert({ pre1 * pre2, twoseg(i, k, pre1, k + 1, j, pre2, '*') });
							dp[i][j].insert({ pre1 - pre2, twoseg(i, k, pre1, k + 1, j, pre2, '-') });
							dp[i][j].insert({ pre1 + pre2, twoseg(i, k, pre1, k + 1, j, pre2, '+') });
						}
					}
				}
			}
		}

        auto re = dfs(num, dp, target, 0, len-1);
        vector<string> result(re.begin(), re.end() );
        return result;
    }
};

int main(){
	Solution282().addOperators("123", 6);
	return 0;
}

#endif
