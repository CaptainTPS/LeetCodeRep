#include <vector>
#include <stack>

using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
   int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {

public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		if (nestedList.empty())
			return;
		const vector<NestedInteger> *ptr = &nestedList;
		int cnt = 0;
		addothers(ptr, cnt);
	}

	int next() {
		auto val = st.top();
		auto ptr = val.first;
		auto cnt = val.second;
		auto re = ptr->operator[](cnt).getInteger();
		cnt++;
		while (cnt >= ptr->size()){
			st.pop();
			val = st.top();
			ptr = val.first;
			cnt = val.second;
			cnt++;
		}
		st.top().second++;
		if (!ptr->operator[](cnt).isInteger()){
			ptr = &(ptr->operator[](cnt).getList());
			while (!ptr->empty() && !ptr->operator[](0).isInteger()){
				st.push({ ptr, 0 });
				ptr = &(ptr->operator[](0).getList());
			}
			if (!ptr->empty())
				st.push({ ptr, 0 });
		}

		return re;
	}

	bool hasNext() {
		return !st.empty();
	}

private:
	void addothers(const vector<NestedInteger> *ptr, int cnt){
		while (1){
			while (cnt < ptr->size() && !ptr->operator[](cnt).isInteger() && ptr->operator[](cnt).getList().empty()){
				cnt++;
			}
			if (cnt < ptr->size()){
				if (ptr->operator[](cnt).isInteger())
				{
					st.push({ ptr, cnt });
					break;
				}
				else
				{
					st.push({ ptr, cnt });
					ptr = &(ptr->operator[](cnt).getList());
					cnt = 0;
					continue;
				}
			}
			else
			{
				if (st.empty())
					break;
				else
				{
					auto val = st.top();
					ptr = val.first;
					cnt = val.second + 1;
					st.pop();
				}
			}
		}
	}

	stack<pair<const vector<NestedInteger>*, int>> st;
};

/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/