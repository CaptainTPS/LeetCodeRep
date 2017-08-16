class Solution274 {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
        	return 0;

        int n = citations.size();
        vector<int> bucket( n + 1, 0);
        for(auto x : citations){
        	if(x <= n){
        		bucket[x]++;
        	}else
        		bucket[n]++;
        }

        int cnt = 0;
        for(int i = n; i>=0; i--){
        	cnt += bucket[i];
        	if(cnt >=i){
        		return i;
        	}
        }
        return 0;


    }
};