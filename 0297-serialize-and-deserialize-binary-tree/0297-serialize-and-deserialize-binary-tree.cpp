/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<string> v;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //convert
        if(!root) return "|";
        return to_string(root->val) + "|" + serialize(root->left) + serialize(root->right);
    }
    TreeNode* buildTree(stringstream &ss){
        string token;
        getline(ss,token,'|');
        if(token == ""){
            return nullptr;
        }
        TreeNode* n = new TreeNode(stoi(token));
        n->left = buildTree(ss);
        n->right = buildTree(ss);
        return n;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        TreeNode *root = buildTree(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));