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
class Solution {
public:
    TreeNode* pre(TreeNode* root, int val)
    {
        if(root == NULL)
        {
            return new TreeNode(val);
        }

        if(root->val > val)
            root->left = pre(root->left, val);
        else if(root->val < val)
            root->right = pre(root->right, val);

        return root;
    } 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=1; i<preorder.size(); i++)
        {
            root = pre(root, preorder[i]);
        }

        return root;
    }
};