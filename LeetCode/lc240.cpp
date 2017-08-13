class Solution {
public:
	bool biSearch(int xs, int xe, int ys, int ye, int target, vector<vector<int>>& m){
		if(xs > xe || ys > ye)
			return false;
		int xm = (xs + xe)/2;
		int ym = (ys + ye)/2;
		if(m[ym][xm] == target)
			return true;
		if(m[ym][xm] < target)
			return (biSearch(xm + 1, xe, ym + 1, ye, target, m)||
				biSearch(xm + 1, xe, ys, ym, target, m)||
				biSearch(xs, xm, ym + 1, ye, target, m));
		else
			return (biSearch(xs, xm-1, ys, ym-1, target, m)||
				biSearch(xs, xm-1, ym, ye, target, m)||
				biSearch(xm, xe, ys, ym-1, target, m));
	}

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int row = matrix.size();
    	if(row == 0)
    		return false;
    	int col = matrix[0].size();
    	if(col == 0)
    		return false;
    	return biSearch(0,col-1, 0, row - 1, target, matrix); 
    }
};