#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unordered_set>

using namespace std;

struct testS
{
	int operator()(int m){
	
		cout << "now is " << m << endl;
		return m;
	}
	
};


int maint(){
	vector<int> a, b;
	bool tttt = a == b;
	
	testS()(5);
	testS ts;
	ts(4);

	return 0;
}