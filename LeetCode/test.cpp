#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long long n;
	cin >> n;
	vector<int> all(n, 0);
	for (long long i = 0; i< n; i++){
		cin >> all[i];
	}

	long long begin = 1;
	long long end = 2;
	bool flag = true;
	int cnt = 0;
	do{
		if (begin >= n)
			break;

		for (long long i = begin; i < min(end, n); i++){
			if (all[0] < all[i]){
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
		begin = begin << 1;
		end = end << 1;
	} while (flag);
	cout << cnt << endl;
	return 0;
}