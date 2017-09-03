#include <vector>
#include <list>

using namespace std;

struct Interval {
    int start;
	int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		auto itr = data.begin();
		auto pre = data.end();
		while( itr != data.end()){
			if (itr->start <= val && itr->end >= val)
				return;

			if (itr->start > val)
				break;

			pre = itr;
			itr++;
		}
		if ((pre == data.end() || pre->end < val - 1) && (itr == data.end() || itr->start > val + 1)){
			data.insert(itr, Interval(val, val));
			return;
		}


		if (pre != data.end() && pre->end == val - 1){
			pre->end = val;
		}
		if (itr != data.end() && itr->start == val + 1){
			itr->start = val;
		}
		if (itr != data.end() && pre != data.end() && pre->end == itr->start){
			pre->end = itr->end;
			data.erase(itr);
		}

	}

	vector<Interval> getIntervals() {
		vector<Interval> re(data.begin(), data.end());
		return re;
	}

private:
	list<Interval> data;
};

/**
* Your SummaryRanges object will be instantiated and called as such:
* SummaryRanges obj = new SummaryRanges();
* obj.addNum(val);
* vector<Interval> param_2 = obj.getIntervals();
*/