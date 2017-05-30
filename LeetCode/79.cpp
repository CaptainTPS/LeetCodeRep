//79. Word Search
class Solution {
public:
	bool dfs(vector<vector<char>>& v, int x, int y, int now, string& word){
		if (word[now]!= v[x][y])
		{
			return false;
		}
		if (now == word.length()-1)
		{
			return true;
		}
		char c = v[x][y];
		v[x][y] = '.';
		bool flag = false;
		if (x - 1 >= 0 &&!flag)
		{			
			flag |= dfs(v, x-1, y, now+1, word);
		}
		if (x + 1 < v.size() &&!flag)
		{			
			flag |= dfs(v, x+1, y, now+1, word);
		}
		if (y - 1 >= 0 &&!flag)
		{			
			flag |= dfs(v, x, y-1, now+1, word);
		}
		if (y + 1 < v[x].size() &&!flag)
		{			
			flag |= dfs(v, x, y+1, now+1, word);
		}
		v[x][y] = c;
		return flag;
	}

    bool exist(vector<vector<char>>& board, string word) {
       if (board.empty())
       {
       		return false;
       }
       bool flag = false;
       for (int i = 0; i < board.size(); ++i)
       {
       		for (int j = 0; j < board[i].size(); ++j)
       		{
       			flag |= dfs(board, i,j,0,word);
       		}
       }
       return flag;
    }
};