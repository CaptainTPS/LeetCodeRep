//84. Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
        {
        	return 0;
        }
        heights.push_back(0);
        int count = heights.size();
        int maxn = 0;

        stack<int> s;
        int i = 0;
        while(i<count){
        	if (s.empty() || heights[i] >= heights[s.top()])
        	{
        		s.push(i);
        		i++;
        	}else{
        		int h = s.top(); s.pop();
        		int left = s.empty() ? -1: s.top();
        		int m = (i - left - 1) * heights[h];
        		maxn = max(maxn, m);
        	}
        }
        return maxn;
#if 0
 		//TLE
        for (int i = 0; i < count; ++i)
        {
        	int left = i;
        	while(left >= 0 && heights[left] >= heights[i]){
        		left--;
        	}
        	int right = i;
        	while(right < count && heights[right] >= heights[i]){
        		right++;
        	}
        	int m = (right - left - 1) * heights[i];
        	max = max < m? m: max;
        }

        return max;
#endif
#if 0
		//not working
        std::vector<int> left(heights.size(), 0);
        std::vector<int> right(heights.size(), heights.size() - 1);
        int now = heights[0];
        int index = 0;
        for (int i = 1; i < heights.size(); ++i)
        {
        	if (now >= heights[i])
        	{
        		left[i] = index;
        		now = heights[i];
        	}else{
        		index = i;
        		left[i] = index;
        		now = heights[i];
        	}
        }

        now = heights[heights.size() -1 ];
        index = heights.size() -1;
        for (int i = heights.size() -2; i >= 0; i--)
        {
        	if (now >= heights[i])
        	{
        		right[i] = index;
        		now = heights[i];
        	}else{
        		index = i;
        		right[i] = index;
        		now = heights[i];
        	}
        }

        int max = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
        	if (max < heights[i] * (right[i] - left[i] + 1))
        	{
        		max = heights[i] * (right[i] - left[i] + 1);
        	}
        }
        return max;
#endif
    }
};