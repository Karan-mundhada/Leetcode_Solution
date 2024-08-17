class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p(n, 0);
        for(int i=1; i<n; i++)
        {
            p[i] = p[i-1] + ((nums[i] == nums[i-1] + 1) ? 1 : 0);
        }
        vector<int> ans(n - k + 1);
        for(int i=0; i<n-k+1; i++)
        {
            if(p[i + k - 1] == p[i] + k - 1)
                ans[i] = nums[i + k - 1];
            else
                ans[i] = -1;
        }

        return ans;
    }
};