class Solution233 {
public:
	typedef long long ll;
	int calIndex(int n, int index){
		ll p10 = pow(10, index);
		ll front = n / p10;
		ll now = n %p10;
		ll tail = now %(p10 / 10);
		now /= (p10 / 10);
		if(now == 0)
			return front *(p10 / 10);
		else if (now == 1){
			if(front == 0)
				return 1 * (tail + 1);
			else
				return (front * (p10 / 10) + 1 * (tail + 1));
		}
		else
			return (front + 1) * (p10 / 10);
	}

    int countDigitOne(int n) {
        ll index = 1;
        ll sum = 0;
        ll lp = n;
        while(lp>0){
        	sum += calIndex(n, index);
        	lp /= 10;
        	index++;
        }
        return sum;
    }
};