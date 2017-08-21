#include <vector>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		itr = new Iterator(nums);
		if (itr->hasNext())
			n = itr->next();
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return n;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (itr->hasNext())
			n = itr->next();
		return Iterator::next();
	}

	bool hasNext() const {
		return Iterator::hasNext();
	}

private:
	Iterator* itr;
	int n;
};