#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };


vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> vi;
	int now = 0;
	if (now < intervals.size() && newInterval.end < intervals[now].start)
	{
		vi.push_back(newInterval);
		for (int i = 0; i < intervals.size(); i++)
		{
			vi.push_back(intervals[i]);
		}
		return vi;
	}
	while (now < intervals.size() && intervals[now].end < newInterval.start)
	{
		vi.push_back(intervals[now++]);
	}

	vi.push_back(newInterval);

	while (now < intervals.size() && intervals[now].start <= vi[vi.size() -1].end)
	{
		vi[vi.size() - 1].start = intervals[now].start < vi[vi.size() - 1].start ? intervals[now].start : vi[vi.size() - 1].start;
		vi[vi.size() - 1].end = intervals[now].end > vi[vi.size() - 1].end ? intervals[now].end : vi[vi.size() - 1].end;
		now++;
	}
	while (now < intervals.size())
	{
		vi.push_back(intervals[now++]);
	}
	return vi;
}


int main57(){
	vector<Interval> input;
	input.push_back(Interval(1, 5));
	input.push_back(Interval(6, 8));

	input = insert(input, Interval(5, 6));
	return 0;
}