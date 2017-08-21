class Solution {
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

	set<string> result;

	void dfs(vector<vector<multimap<ll, twoseg>>>& dp, int target){
		
	}

    vector<string> addOperators(string num, int target) {
    	
    	int len = num.length();
    	if(len==0)
    		return result;


        vector<vector<multimap<ll, twoseg>>> dp(len, vector<multimap<ll, twoseg>>(len));

        for (int i = 0; i < len; ++i)
        {
        	for (int j = i; j < len; ++j)
        	{
        		ll t = stol(num.substr(i, j - i + 1));
        		dp[i][j].insert({t, twoseg(0,0,0,0,0,0, '#')});

        		for (int k = i; k < j; ++k)
        		{
        			int pre1 = -1;
        			for ( auto itr1 = dp[i][k].begin(); itr1 != dp[i][k].end(); itr1++){
        				if(itr1.first == pre1)
        					continue;
        				pre1 = itr1.first;
        				int pre2 = -1;
        				for(auto itr2 = dp[k + 1][j].begin(); itr2 != dp[k+ 1][j].end(); itr2++){
        					if(itr2.first == pre2)
        						continue;
        					pre2 = itr2.first;

        					di[i][j].insert({pre1 * pre2,twoseg(i,k,pre1,k+1,j,pre2, '*')});
        					di[i][j].insert({pre1 - pre2,twoseg(i,k,pre1,k+1,j,pre2, '-')});
        					di[i][j].insert({pre1 + pre2,twoseg(i,k,pre1,k+1,j,pre2, '+')});
        				}
        			}
        		}

        	}
        }

        dfs(dp, target);

    }
};