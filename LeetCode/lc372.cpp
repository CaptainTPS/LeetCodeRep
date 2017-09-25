class Solution372 {
public:
    int superPow(int a, vector<int>& b) {
        const int mode = 1337;
        a = a % mode;
        
        int result = 1;
        for(int i = 0; i< b.size(); i++){
        	int re = mypow(a, b[i], mode);
        	result = mypow(result, 10, mode);
        	result *= re;
        	result %= mode;
        }
        return result;
    }

private:
	int mypow(int a, int pw, const int mod){
		if(a == 0)
			return 0;
		if(a == 1 || pw == 0)
			return 1;
		if(pw == 1)
			return (a % mod);
		
		int temp = mypow(a, pw/2, mod);
		temp *=temp;
		temp %= mod;
		if(pw % 2 == 1){
			temp *= a;
			temp %= mod;
		}
		return temp;
	}
};