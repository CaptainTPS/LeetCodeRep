#include <algorithm>

class Solution326 {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0)
			return false;

		int test = pow(3, 19);
		
		return test % n == 0;
	}
};