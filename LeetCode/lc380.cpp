//380. Insert Delete GetRandom O(1)
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto finder = sdata.find(val);
        if(finder != sdata.end())
        	return false;

        int n = vdata.size();
        sdata[val] = n;
        vdata.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(sdata.find(val) == sdata.end())
        	return false;

        int v = vdata.back();
        int pos = sdata[val];
        sdata[v] = pos;
        vdata[pos] = v;
        vdata.pop_back();
        sdata.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int pos = rand() % vdata.size();
        return vdata[pos];
    }

private:
	vector<int> vdata;
	unordered_map<int, int> sdata;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */