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
    int hh(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int l = hh(root->left) + 1;
        int r = hh(root->right) + 1;

        return max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;

        int l = hh(root->left);
        int r = hh(root->right);


        if(l+1 == r || l-1 == r || l == r)
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return false;
    }
};