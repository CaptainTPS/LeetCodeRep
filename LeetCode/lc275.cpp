class Solution275 {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
        	return 0;
        int n = citations.size();
        int left =0, right = n - 1;
        while(left <= right){
        	int mid = (left + right) / 2;
        	if(citations[mid] == n - mid)
        		return citations[mid];
        	if(citations[mid] < n - mid)
        		left = mid + 1;
        	else
        		right = mid - 1;
        }
        return n - left;
    }
};