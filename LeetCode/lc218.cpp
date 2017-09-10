#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#if 1
//a better version
struct bld{
    pair<int, int> range;
    int h;
    bld(pair<int, int> a, int b): range(a), h(b){};
};

bool cmp(bld& a, bld& b){
    return a.range < b.range;
}

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        int len = buildings.size();
        vector<bld> all;
        for(int i = 0; i< len; i++){
            auto& x = buildings[i];
            all.push_back(bld({x[0],x[1]}, x[2]));
            all.push_back(bld({x[1],x[1]}, 0));
        }

        sort(all.begin(), all.end(), cmp);
        vector<pair<int,int>> result;
        priority_queue<pair<int, int>> pq;
        int preh = 0;
        for(int i = 0; i<all.size();){
            int now = all[i].range.first;
            while(!pq.empty() && pq.top().second <= now){
                pq.pop();
            }
            while(i < all.size() && all[i].range.first == now){
                pq.push({all[i].h, all[i].range.second});
                i++;
            }
            int nowh = pq.top().first;
            if(nowh != preh){
                result.push_back({now, nowh});
            }
            preh = nowh;
        }
        return result;
    }
};
#else

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

#endif