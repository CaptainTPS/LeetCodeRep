#include <cstdlib>

class Solution201 {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (m == 0 || n == 0)
			return 0;
		
		typedef long long ll;
		ll mm = m;
		ll nn = n;
		int index = 0;
		while (mm!=nn){
			mm = (mm >> index) << index;
			nn = (nn >> index) << index;
			index++;
		}
		return mm;
	}
};