#include <string>
#include <set>
#include <vector>
#include <queue>

using namespace std;

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new node('-', false);
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		node *curr = root;
		for (int i = 0; i < word.length(); i++)
		{
			bool flag = false;
			for (auto x : curr->next){
				if (x->c == word[i]){
					flag = true;
					curr = x;
					break;
				}
			}
			if (!flag){
				node* t = new node(word[i], false);
				curr->next.push_back(t);
				curr = t;
			}
		}
		curr->end = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		queue<node*> q1, q2;
		queue<node*> *now = &q1, *next = &q2, *temp;
		node *t;
		now->push(root);
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == '.'){
				while (!now->empty()){
					t = now->front();
					now->pop();
					for (auto x : t->next){
						next->push(x);
					}
				}
			}
			else{
				while (!now->empty()){
					t = now->front();
					now->pop();
					for (auto x : t->next){
						if (x->c == word[i])
							next->push(x);
					}
				}
			}
			
			temp = now;
			now = next;
			next = temp;
			if (now->empty())
				return false;
		}
		while (!now->empty()){
			t = now->front();
			now->pop();
			if (t->end == true)
				return true;
		}
		return false;
		
	}
private:
	struct node
	{
		char c;
		bool end;
		vector<node*> next;
		node(char cc, char ee){
			c = cc;
			end = ee;
		}
	};
	node *root;
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/