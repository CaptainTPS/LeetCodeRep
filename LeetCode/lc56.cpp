#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
   int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool compare(Interval a, Interval b){
	if (a.start < b.start)
	{
		return true;
	}
	if (a.start == b.start && a.end<b.end)
	{
		return true;
	}
	return false;
}

vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> re;
	if (intervals.empty())
	{
		return re;
	}
	sort(intervals.begin(), intervals.end(), compare);
	Interval temp = intervals[0];
	for (int i = 1; i < intervals.size(); i++)
	{
		if (temp.end >= intervals[i].start)
		{
			temp.end = intervals[i].end > temp.end ? intervals[i].end : temp.end;
		}
		else
		{
			re.push_back(temp);
			temp = intervals[i];
		}
	}
	re.push_back(temp);
	return re;
}