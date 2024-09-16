class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, n = nums.size();
        int ans = 0;
        while(end < n)
        {
            while(end < n && k < 1 && nums[end] == 0)
            {
                if(nums[start] == 0) k++;

                ans = max(ans, end - start);
                start++;
            }
            if(end < n && k > 0 && nums[end] == 0) k--;
            end++;
        }

        ans = max(ans, n - start);
        return ans;
    }
};