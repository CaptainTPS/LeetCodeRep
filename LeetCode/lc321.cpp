#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Solution321 {
public:
	bool cmp(list<int>& a, list<int>& b){
		auto itr1 = a.begin();
		auto itr2 = b.begin();
		while (itr1 != a.end() && itr2 != b.end()){
			if (*itr1 > *itr2)
				return true;
			if (*itr1 < *itr2)
				return false;
			itr1++;
			itr2++;
		}
		return false;
	}

	list<int> merge(list<int>& a, list<int>& b){
		list<int> re;
		auto itr1 = a.begin();
		auto itr2 = b.begin();
		while (itr1 != a.end() && itr2 != b.end()){
			if (*itr1 > *itr2){
				re.push_back(*itr1);
				itr1++;
			}
			else if (*itr1 < *itr2){
				re.push_back(*itr2);
				itr2++;
			}
			else{
				auto i1 = itr1, i2 = itr2;
				while (i1 != a.end() && i2 != b.end() && *i1 == *i2){
					i1++; i2++;
				}
				if (i1 == a.end()){
					re.push_back(*itr2);
					itr2++;
				}
				else if (i2 == b.end()){
					re.push_back(*itr1);
					itr1++;
				}
				else if (*i1 > *i2){
					re.push_back(*itr1);
					itr1++;
				}
				else
				{
					re.push_back(*itr2);
					itr2++;
				}

			}
		}
		while (itr1 != a.end())
		{
			re.push_back(*itr1);
			itr1++;
		}
		while (itr2 != b.end())
		{
			re.push_back(*itr2);
			itr2++;
		}
		return re;
	}

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
				itr++;
				if (itr == alls1[i].end() || *itr > *ti){
					alls1[i].erase(ti);
					break;
				}
			}
		}

		for (int i = alls2.size() - 2; i > 0; i--){
			alls2[i] = alls2[i + 1];
			for (auto itr = alls2[i].begin(); itr != alls2[i].end();){
				auto ti = itr;
				itr++;
				if (itr == alls2[i].end() || *itr > *ti){
					alls2[i].erase(ti);
					break;
				}
			}
		}

		list<int> result;
		int n1 = nums1.size();
		int n2 = nums2.size();
		n2 = k - n2;
		for (int i = max(0, n2); i <= min(k, n1); i++){
			auto re = merge(alls1[i], alls2[k - i]);
			if (result.empty() || cmp(re, result))
				result = re;
		}

		vector<int> rrr(result.begin(), result.end());

		return rrr;

	}
};