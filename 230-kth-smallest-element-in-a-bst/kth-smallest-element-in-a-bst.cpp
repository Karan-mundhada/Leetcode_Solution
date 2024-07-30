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
    int l = 0;
    int m;
    void in(TreeNode* root, int k)
    {
        if(root != NULL)
        {
            in(root->left, k);
            l++;
            if(l == k)
                m = root->val;
            in(root->right, k); 
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        in(root, k);
        return m;
    }
};