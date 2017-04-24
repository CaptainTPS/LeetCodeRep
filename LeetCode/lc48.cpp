#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int level = matrix.size() / 2;
	int size = matrix.size();
	for (int le = 0; le < level; le++)
	{
		int start = le;
		int end = matrix.size()  - le - 1;
		for (int s = start; s < end; s++)
		{
			int temp = matrix[le][s];
			matrix[le][s] = matrix[size - 1 - s][le];
			matrix[size - 1 - s][le] = matrix[size - 1 - le][size - 1 - s];
			matrix[size - 1 - le][size - 1 - s] = matrix[s][size - 1 - le];
			matrix[s][size - 1 - le] = temp;
		}
	}
}

ostream& operator<<(ostream& t, vector<vector<int>> data){
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			t << data[i][j] << " ";
		}
		t << endl;
	}
	return t;
}

int main48(){
	int data[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 ,14, 15,16};
	vector<int> t1(data, data + 4);
	vector<int> t2(data + 4, data + 8);
	vector<int> t3(data + 8, data + 12);
	vector<int> t4(data + 12, data + 16);
	vector<vector<int>> test; 
	test.push_back(t1);
	test.push_back(t2);
	test.push_back(t3);
	test.push_back(t4);

	cout << test << endl;

	rotate(test);

	cout << test << endl;

	return 0;
}