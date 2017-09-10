#include <string>
#include <vector>

using namespace std;

#if 0
//a better one

struct TrieNode{
    vector<TrieNode*> next;
    bool isWord;
    TrieNode(bool f = false){
        isWord= f;
        next = vector<TrieNode*>(26, NULL);
    }
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto ptr = root;
        for(int i = 0; i< word.length(); i++){
            int index = word[i] - 'a';
            if(ptr->next[index] ==NULL)
                ptr->next[index] = new TrieNode();
            ptr = ptr->next[index];
        }
        ptr->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto result = find(word);
        if(result != NULL && result->isWord)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto result = find(prefix);
        return result != NULL;
    }
private:
    TrieNode* root;

    TrieNode* find(string s){
        auto ptr = root;
        for(int i = 0; i<s.length(); i++){
            int index = s[i] - 'a';
            ptr = ptr->next[index];
            if(ptr == NULL)
                return ptr;
        }
        return ptr;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

#endif

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new node('_', false);
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		node* curr = root;
		for (int i = 0; i < word.length(); i++)
		{
			bool exist = false;
			for (auto x : curr->next){
				if (x->c == word[i]){
					exist = true;
					curr = x;
					break;
				}
			}
			if (!exist){
				node* t = new node(word[i], false);
				curr->next.push_back(t);
				curr = t;
			}
		}
		curr->end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		node* curr = root;
		for (int i = 0; i < word.length(); i++)
		{
			bool exist = false;
			for (auto x : curr->next){
				if (x->c == word[i]){
					exist = true;
					curr = x;
					break;
				}
			}
			if (!exist){
				return false;
			}
		}
		if (curr->end == true)
			return true;
		else
			return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		node* curr = root;
		for (int i = 0; i < prefix.length(); i++)
		{
			bool exist = false;
			for (auto x : curr->next){
				if (x->c == prefix[i]){
					exist = true;
					curr = x;
					break;
				}
			}
			if (!exist){
				return false;
			}
		}
		return true;
	}

	struct node
	{
		char c;
		bool end;
		vector<node*> next;
		node(char cc, bool ee){ c = cc; end = ee; }
	};

private:
	node* root;
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/