#include <string>
#include <sstream>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream ss;
		se(root, ss);
		return ss.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream is(data);
		return de(is);
	}

private:
	void se(TreeNode* root, ostringstream& os){
		if (root){
			os << root->val << " ";
			se(root->left, os);
			se(root->right, os);
		}
		else
		{
			os << "# ";
		}
	}

	TreeNode* de(istringstream& is){
		string t;
		is >> t;
		if (t == "#"){
			return NULL;
		}
		TreeNode* now = new TreeNode(atoi(t.data()));
		now->left = de(is);
		now->right = de(is);
		return now;
	}


};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));