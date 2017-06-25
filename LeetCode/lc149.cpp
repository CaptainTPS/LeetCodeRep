// 149. Max Points on a Line

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
    	if(points.empty())
    		return 0;
    	if(points.size() == 1)
    		return 1;
    	int gmax = 0;
    	for(int i = 0; i< points.size(); ++i){
    		map<pair<int,int>, int> slope;
    		int same = 0;
    		int ysame = 0;
    		int xsame = 0;
    		for(int j = 0; j < points.size(); ++j){
    			if(j == i)
    				continue;
    			int a = points[i].x - points[j].x;
    			int b = points[i].y - points[j].y;
    			if(a==0 && b==0){
    				same++;
    			}else if(a==0)
    				xsame++;
    			else if(b==0)
    				ysame++;
    			else{
    				int gcd = GCD(a,b);
    				auto find = slope.find(make_pair(a/gcd, b/gcd));
    				if(find == slope.end()){
    					slope.insert({make_pair(a/gcd, b/gcd), 2});
    				}else
    					slope[make_pair(a/gcd, b/gcd)]++;
    			}
    		}
    		gmax = max(xsame + same + 1, gmax);
    		gmax = max(ysame + same + 1, gmax);
    		for(auto i : slope)
    			gmax = max(gmax, i.second + same);
    	}
    	return gmax;
    }
private:
	int GCD(int a, int b){
		if(b==0) return a;
		return GCD(b, a%b);
	}

};