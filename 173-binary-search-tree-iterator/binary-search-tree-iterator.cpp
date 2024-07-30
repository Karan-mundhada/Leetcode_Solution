/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> arr;
    int top, s;
    void in(TreeNode* r)
    {
        if(r != NULL)
        {
            in(r->left);
            arr.push_back(r->val);
            in(r->right);
        }
    }
    BSTIterator(TreeNode* root) {
        top = 0;
        in(root);
        s = arr.size();
    }
    
    int next() {
        return arr[top++];
    }
    
    bool hasNext() {
        if(top<s)
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */