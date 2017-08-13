#include <deque>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution241 {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> result;
		for (int i = 0; i < input.size(); ++i)
		{
			if(input[i] == '+' ||input[i] == '*' ||input[i] == '-'){
				auto a = diffWaysToCompute(input.substr(0, i));
				auto b = diffWaysToCompute(input.substr(i+1,input.size() - i - 1));
				for(auto x : a)
					for(auto y : b){
						int re;
						if(input[i] == '+')
							re = x + y;
						if(input[i] == '-')
							re = x - y;
						if(input[i] == '*')
							re = x * y;
						result.push_back(re);
					}

			}
		}
		if(result.empty())
			result.push_back(atoi(input.data()));
		return result;
	}
};


#if 0
//not working well
class Solution {
public:
    set<int> result;

    void dfs(vector<int>& nums, vector<char>& ops){
        if(ops.empty()){
            int m = nums.back();
            result.insert(m);
            return;
        }
        for(auto x : nums)
            cout<<x<<endl;
        for(auto x: ops)
            cout<<x<<endl;

        auto nitr = nums.begin();
        for (auto opitr = ops.begin(); opitr != ops.end(); opitr++)
        {
            char c = *opitr;
            auto opt = ops.erase(opitr);
            int n1 = *nitr;
            nitr = nums.erase(nitr);
            int n2 = *nitr;
            nitr = nums.erase(nitr);
            int re;
            switch(c){
                case '+':
                    re = n1 + n2;
                    break;
                case '-':
                    re = n1 - n2;
                    break;
                case '*':
                    re = n1 * n2;
                    break;
                default:
                    re = 0;
                    break;
            }
            nitr = nums.insert(nitr, re);
            dfs(nums, ops);
            opitr = ops.insert(opt, c);
            nitr = nums.erase(nitr);
            nitr = nums.insert(nitr, n2);
            nitr = nums.insert(nitr, n1);

            nitr++;
        }

    }

    vector<int> diffWaysToCompute(string input) {
        if(input.empty())
            return vector<int>();

        vector<int> nums;
        vector<char> ops;
        for(int i = 0; i< input.size(); i++){
            if(input[i] == ' ')
                input.erase(input.begin() + i--);
        }

        for (int i = 0; i < input.size(); ++i)
        {
            if(isdigit(input[i])){
                int n = 0;
                while(i < input.size() && isdigit(input[i])){
                    n = n*10 + input[i++] - '0';
                }
                i--;
                nums.push_back(n);
            }else{
                ops.push_back(input[i]);
            }
        }

        dfs(nums, ops);

        vector<int> re(result.begin(), result.end());
        return re;

    }
};
#endif

