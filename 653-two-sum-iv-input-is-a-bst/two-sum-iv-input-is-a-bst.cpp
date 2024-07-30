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
    void in(TreeNode* root, vector<int>& arr)
    {
        if(root != NULL)
        {
            in(root->left, arr);
            arr.push_back(root->val);
            in(root->right, arr);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        in(root, arr);
        int i = 0, j = arr.size()-1;
        while(i < j)
        {
            int f = arr[i] + arr[j];
            if(f < k)
                i++;
            else if(f == k)
                return true;
            else
                j--;
        }

        return false;
    }
};