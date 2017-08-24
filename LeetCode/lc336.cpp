#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;

int main(){
	unordered_set<int> test = { 5, 2, 23, 6, 8, 4, 56, 3, 6 };
	for (auto x : test){
		cout << x << " " << endl;
	}
	return 0;
}