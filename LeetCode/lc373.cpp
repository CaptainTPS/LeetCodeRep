class piicmp{
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>& b){
		return (a.first + a.second) < (b.first + b.second);
	}

};

class Solution373 {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	if(k <= 0){
    		return vector<pair<int, int>>();
    	}

        int len1 = nums1.size();
        int len2 = nums2.size();

       	priority_queue<pair<int, int>, vector<pair<int, int>>, piicmp> pq;

       	for(int i = 0; i < k && i < len1; i++){
       		for(int j = 0; j < k && j < len2; j++){
       			pq.push({nums1[i], nums2[j]});
       			while(pq.size() > k)
       				pq.pop();
       		}
       	}

       	vector<pair<int,int>> result;
       	while(!pq.empty()){
       		result.push_back(pq.top());
       		pq.pop();
       	}
       	return result;
    }
};