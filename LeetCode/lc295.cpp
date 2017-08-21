#include <algorithm>
#include <vector>
#include <functional>

using namespace std;


class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (!bighalf.empty() && num < bighalf.front()){
			smallhalf.push_back(num);
			push_heap(smallhalf.begin(), smallhalf.end(), less<int>());
		}
		else
		{
			bighalf.push_back(num);
			push_heap(bighalf.begin(), bighalf.end(), greater<int>());
		}

		if (smallhalf.size() > bighalf.size()){
			int n = smallhalf.front();
			pop_heap(smallhalf.begin(), smallhalf.end(), less<int>()); 
			smallhalf.pop_back();
			
			bighalf.push_back(n); 
			push_heap(bighalf.begin(), bighalf.end(), greater<int>());
		}
		else if (bighalf.size() > smallhalf.size() + 1){
			int n = bighalf.front();
			pop_heap(bighalf.begin(), bighalf.end(), greater<int>());
			bighalf.pop_back();

			smallhalf.push_back(n);
			push_heap(smallhalf.begin(), smallhalf.end(), less<int>());
		}
	}

	double findMedian() {
		double re = 0;
		if (smallhalf.size() == bighalf.size()){
			re += smallhalf.front();
			re += bighalf.front();
			re /= 2;
		}
		else
		{
			re += bighalf.front();
		}
		return re;
	}

private:
	vector<int> bighalf;
	vector<int> smallhalf;
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/