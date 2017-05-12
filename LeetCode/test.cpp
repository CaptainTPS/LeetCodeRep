#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef unordered_map<int, int> um;

um tum;
set<int> ts;


bool cmp(char a, char b){
	if (a - b > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int maint(){
	string test = "djklsajf";

	sort(test.begin(), test.end(), cmp);

	return 0;
}