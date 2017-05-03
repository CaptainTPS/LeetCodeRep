#include <string>

using namespace std;

long long table[10];

bool flag60[10];

int total;

void dfs(int n, int k, string &re){
	if (n == 1)
	{
		for (int i = 1; i <= total; i++)
		{
			if (flag60[i] == true)
			{
				continue;
			}
			else
			{
				re = re + to_string(i);
				break;
			}
		}
		return;
	}


	int curr_num = (k-1) / table[n - 1];
	k = k - curr_num * table[n - 1];
	int cnt = 0;
	for (int i = 1; i <= total; i++)
	{
		if (flag60[i] == true)
		{
			continue;
		}
		if (cnt == curr_num)
		{
			cnt = i;
			flag60[i] = true;
			break;
		}
		else
		{
			cnt++;
		}
	}
	re += to_string(cnt);
	dfs(n - 1, k, re);
}

string getPermutation(int n, int k) {
	table[0] = 1;
	for (long long i = 1; i < 10; i++)
	{
		table[i] = table[i - 1] * i;
	}
	fill(flag60, flag60 + 10, false);
	string result = "";
	total = n;
	dfs(n, k, result);
	return result;
}

int main60(){
	string re = getPermutation(3, 3);
	return 0;
}