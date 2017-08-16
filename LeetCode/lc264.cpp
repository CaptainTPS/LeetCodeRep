class Solution264 {
public:
	int getmin(int a, int b, int c, vector<int>& index){
		int re = min(a, min(b, c));
		if(re == a)
			index.push_back(0);
		if(re == b)
			index.push_back(1);
		if(re == c)
			index.push_back(2);
		return re;
	}

    int nthUglyNumber(int n) {
    	if(n==0)
    		return 0;
        vector<int> result = {1};
        int ptr[3] = {0,0,0};
        while(result.size() < n){
        	vector<int> index;
        	int re = getmin(2 * result[ptr[0]], 3*result[ptr[1]], 5 * result[ptr[2]], index);
        	result.push_back(re);

        	for(auto x : index){
        		ptr[x]++;
        	}

        }
        return result.back();
    }
};