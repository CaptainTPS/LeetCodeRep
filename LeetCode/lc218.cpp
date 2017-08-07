#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution218 {
public:
	struct onechange{
		int index;
		int inout;//1 for in
		int pos;
		onechange(int a, int b, int c){
			index = a;
			inout = b;
			pos = c;
		}
		onechange(){
			index = 0; inout = 0; pos = 0;
		}
	};

	static bool cmp(onechange a, onechange b){
		return a.pos < b.pos;
	}

	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		multiset<int> heights;
		vector<onechange> allchanges(buildings.size() * 2);
		for (int i = 0; i < buildings.size(); i++){
			allchanges[2 * i] = onechange(i, 1, buildings[i][0]);
			allchanges[2 * i + 1] = onechange(i, -1, buildings[i][1]);
		}

		sort(allchanges.begin(), allchanges.end(), cmp);

		int hpre = -1;
		int hnow = -1;
		int xpre = -1;
		int xnow = -1;
		vector<pair<int, int>> result;
		heights.insert(0);
		for (int i = 0; i < allchanges.size();i++){
			auto x = allchanges[i];
			int h = buildings[x.index][2];
			if (x.inout == 1){
				heights.insert(h);
			}
			else
			{
				heights.erase(heights.find(h));
			}

			if (i <= allchanges.size() - 2 && x.pos == allchanges[i+1].pos){
				continue;
			}

			//hnow = *(heights.rend());
			hnow = *(max_element(heights.begin(), heights.end()));
			xnow = x.pos;
			if (xnow != xpre && hnow != hpre)
				result.push_back({ xnow, hnow });
			xpre = xnow;
			hpre = hnow;
		}
		return result;
	}
};