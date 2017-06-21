#include <vector>

using namespace std;

class Solution134 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		if (n == 0)
			return -1;


		for (int start = 0; start < n; start++)
		{
			int gas_now = 0;
			int now = start;
			bool flag = true;
			while (1){
				gas_now += gas[now];
				gas_now -= cost[now];
				if (gas_now < 0){
					flag = false;
					if (now > start)
						start = now;
					break;
				}
				now = (now + 1) % n;
				if (now == start)
					break;
			}
			
			if (flag)
				return start;
		}
		return -1;
	}
};