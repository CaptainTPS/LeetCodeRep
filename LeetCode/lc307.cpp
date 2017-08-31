#include <vector>

using std::vector;


class NumArray {
public:
	typedef long long ll;

	NumArray(vector<int> nums) {
		int n = nums.size();
		root = buildTree(nums, 0, n - 1);
	}

	void update(int i, int val) {
		updateTree(i, val, root);
	}

	int sumRange(int i, int j) {
		return treeRange(i, j, root);
	}
private:
	//use segment tree
	struct SegNode
	{
		ll start, end, sum;
		SegNode *left, *right;
	
		SegNode(ll s, ll e, ll su){
			start = s;
			end = e;
			sum = su;
			left = right = nullptr;
		}
	};

	SegNode* buildTree(vector<int>& nums, int s, int e){
		if (e < s)
			return nullptr;
		if (s == e){
			return (new SegNode(s, e, nums[s]));
		}

		ll mid = s + (e - s) / 2;
		SegNode* temp = new SegNode(s, e, 0);
		temp->left = buildTree(nums, s, mid);
		temp->right = buildTree(nums, mid + 1, e);
		temp->sum = temp->left->sum + temp->right->sum;
		return temp;
	}

	ll updateTree(int i, int val, SegNode* now){
		if (now->start == i && now->end == i){
			ll diff = val - now->sum;
			now->sum = val;
			return diff;
		}

		ll mid = now->start + (now->end - now->start) / 2;
		ll diff;
		if (i <= mid)
			diff = updateTree(i, val, now->left);
		else
			diff = updateTree(i, val, now->right);
		now->sum += diff;
		return diff;
	}

	ll treeRange(int i, int j, SegNode* now){
		if (now->start == i && now->end == j){
			return now->sum;
		}

		ll mid = now->start + (now->end - now->start) / 2;
		if (i <= mid && j <= mid)
			return treeRange(i, j, now->left);
		else if (i >mid && j > mid)
			return treeRange(i, j, now->right);
		else
			return treeRange(i, mid, now->left) + treeRange(mid + 1, j, now->right);
	}

	SegNode* root;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* obj.update(i,val);
* int param_2 = obj.sumRange(i,j);
*/