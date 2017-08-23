#include <vector>
#include <list>

using namespace std;

class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		list<int> seq1(nums1.begin(), nums1.end());
		list<int> seq2(nums2.begin(), nums2.end());

		vector<list<int>> alls1(nums1.size() + 1), alls2(nums2.size() + 1);
		alls1.back() = seq1;
		alls2.back() = seq2;
		for (int i = alls1.size() - 2; i > 0; i--){
			alls1[i] = alls1[i + 1];
			for (auto itr = alls1[i].begin(); itr != alls1[i].end();){
				auto ti = itr;

			}
		}
	}
};