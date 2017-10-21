//lc381
class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		auto finder = valmap.find(val);
		if (finder == valmap.end()){
			int n = nums.size();
			nums.push_back({ val, 0 });
			valmap.insert({ val, vector<int>(1, n) });
			return true;
		}
		else{
			vector<int>& mapvec = finder->second;
			int mn = mapvec.size();
			int n = nums.size();
			nums.push_back({ val, mn });
			mapvec.push_back(n);
		}
		return false;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		auto finder = valmap.find(val);
		if (finder == valmap.end()){
			return false;
		}
		else{
			auto& mapvec = finder->second;
			int pos = mapvec.back();
			auto lastv = nums.back().first;
			auto lastindex = nums.back().second;
			nums[pos] = { lastv, lastindex };
			valmap[lastv][lastindex] = pos;

			mapvec.pop_back();
			if (mapvec.empty()){
				valmap.erase(val);
			}
			nums.pop_back();
		}
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return nums[rand() % nums.size()].first;
	}

private:
	std::vector<pair<int, int>> nums;
	unordered_map<int, std::vector<int>> valmap;
};

/**
* Your RandomizedCollection object will be instantiated and called as such:
* RandomizedCollection obj = new RandomizedCollection();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/
