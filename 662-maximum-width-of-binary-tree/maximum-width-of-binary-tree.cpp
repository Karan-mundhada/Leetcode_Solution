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
    int widthOfBinaryTree(TreeNode* root) {
        if(root->left == NULL and root->right == NULL)
            return 1;

        int dist = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while(!q.empty())
        {
            int s = q.size();
            unsigned long long mi = q.front().second, ma = mi;
            for(int i=0; i<s; i++)
            {
                auto temp = q.front();
                unsigned long long cur_id = temp.second;
                cout<<cur_id<<endl;
                q.pop();

                ma = cur_id;

                if(temp.first->left != NULL)
                    q.push({temp.first->left, cur_id*2 + 1});
                
                if(temp.first->right != NULL)
                    q.push({temp.first->right, cur_id*2 + 2});
            }

            dist = max(dist, static_cast<int>(ma - mi + 1));
        }

        return dist;
    }
};