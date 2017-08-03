#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

#if 0
//TLE

pair<int, int> operator+(pair<int, int> a, const pair<int, int> b){
	return pair<int, int>(a.first + b.first, a.second + b.second);
}

class Solution212 {
public:
	unordered_multimap<char, pair<int, int>> charmap;

	bool judge(pair<int, int> to, int row, int col){
		if (to.first >= 0 && to.first < row && to.second >= 0 && to.second < col)
			return true;
		else
			return false;
	}

	void dfs(string &x, int index, pair<int, int> now, vector<vector<bool>> &used, vector<vector<char>> &board, bool &flag, const vector<pair<int, int>> &to){
		if (flag)
			return;
		if (index >= x.length()){
			flag = true;
			return;
		}

		for (int i = 0; i < to.size(); i++)
		{
			pair<int, int> towhere = now + to[i];
			if (judge(towhere, used.size(), used[0].size()) && used[towhere.first][towhere.second] == false && board[towhere.first][towhere.second] == x[index]){
				used[towhere.first][towhere.second] = true;
				dfs(x, index + 1, towhere, used, board, flag, to);
				used[towhere.first][towhere.second] = false;
			}
		}
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> re;
		if (board.empty() || words.empty())
			return re;
		
		vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
		vector<pair<int, int>> to = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				charmap.insert({ board[i][j], { i, j } });
			}
		}
		unordered_set<string> tempre;
		for (auto x : words){
			bool flag = false;
			auto range = charmap.equal_range(x[0]);
			for (auto pos = range.first; pos != range.second; pos++)
			{
				used[pos->second.first][pos->second.second] = true;
				dfs(x, 1, pos->second, used, board, flag, to);
				used[pos->second.first][pos->second.second] = false;
				if (flag)
					break;
			}
			if (flag)
				tempre.insert(x);
		}
		re = vector<string>(tempre.begin(), tempre.end());
		return re;
	}
};

int main(){
	vector<vector<char>> board =
	{ { 'o','a','a','n' }, { 'e','t','a','e' }, { 'i','h','k','r' }, { 'i','f','l','v' } };
	vector<string> s = { "oath", "pea", "eat", "rain" };
	auto re = Solution212().findWords(board, s);
	//not working now !
	return 0;
}

#endif

class Solution212 {

private:
	struct TrieNode
	{
		typedef TrieNode* ptr;
		bool isend;
		vector<ptr> next;

		TrieNode(){
			isend = false;
			next = vector<ptr>(26, nullptr);
		}
	};

	class Trie
	{
		typedef TrieNode* ptr;
	public:
		ptr getroot(){
			return root;
		}
		
		Trie(vector<string>& words){
			root = new TrieNode();
			for (auto x : words){
				ptr curr = getroot();
				for (int i = 0; i < x.length(); i++)
				{
					if (curr->next[x[i] - 'a'] == nullptr)
						curr->next[x[i] - 'a'] = new TrieNode();
					curr = curr->next[x[i] - 'a'];
				}
				curr->isend = true;
			}
		}

		
	private:
		ptr root;

	};
public:
	typedef TrieNode* ptr;

	void dfs(ptr root, vector<vector<char>>& board, int i, int j, string temp, unordered_set<string> &result){
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
			return;
		if (board[i][j] == ' ')
			return;
		int index = board[i][j] - 'a';
		if (root->next[index] == nullptr)
			return;

		char cc = board[i][j];
		root = root->next[index];
		temp += cc;
		if (root->isend)
			result.insert(temp);
		board[i][j] = ' ';
		dfs(root, board, i + 1, j, temp, result);
		dfs(root, board, i, j + 1, temp, result);
		dfs(root, board, i - 1, j, temp, result);
		dfs(root, board, i, j - 1, temp, result);
		board[i][j] = cc;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie TN(words);
		ptr root = TN.getroot();

		unordered_set<string> re;
		string t;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				dfs(root, board, i, j, t, re);
			}
		}
		
		vector<string> result(re.begin(), re.end());
		return result;
	}

};