#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		st.push(x);
		int m = x;
		if (!mi.empty())
			m = min(m, mi.top());
		mi.push(m);
	}

	void pop() {
		if (st.empty())
			return;
		st.pop();
		mi.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return mi.top();
	}
private:
	stack<int> st;
	stack<int> mi;
};