//388. Longest Absolute File Path

class Solution {
public:
    int lengthLongestPath(string input) {
        int maxlen = 0;
        vector<int> levels(200, 0);
        for(int i = 0; i< input.size(); i++){
        	int le = 1;
        	while(input[i] == '\t'){
        		le++;
        	}

        	bool isfile = false;
        	int cnt = 0;
        	while(i < input.size() && input[i] != '\n'){
        		if(input[i] == '.')
        			isfile = true;
        		cnt++;
        	}

        	if(isfile){
        		maxlen = max(maxlen, levels[le - 1] + cnt);
        	}else{
        		levels[le] = levels[le - 1] + cnt + 1;
        	}
        }
        return maxlen;
    }
};