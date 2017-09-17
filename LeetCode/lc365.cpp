class Solution365 {
public:
    bool canMeasureWater(int x, int y, int z) {
    	if(z == 0)
    		return true;
    	if(x == 0 || y== 0){
    		if(z == x + y)
    			return true;
    		else
    			return false;
    	}

        int g = gcd(x,y);
        x /= g;
        y /= g;
        if(z % g != 0)
        	return false;
        else
        	z = z/g;
        if(z <= x+y)
        	return true;
        return false;
    }
private:
	int gcd(int a, int b){
		if(a < b)
			return gcd(b, a);
		if(b == 0)
			return a;
		return gcd(a%b, b);
	}
};