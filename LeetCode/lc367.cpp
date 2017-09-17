class Solution367 {
public:
    bool isPerfectSquare(int num) {
        typedef long long ll;
        for(ll i = 1; i*i<=num; i++){
        	if(i*i == num)
        		return true;
        }
        return false;
    }
};