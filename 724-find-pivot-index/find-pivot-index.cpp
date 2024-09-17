class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> back(n, 0);
        back[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--)
            back[i] = back[i+1] + nums[i];
        
        for(int i = 1; i<n; i++)
            nums[i] = nums[i] + nums[i-1];

        for(int i=0; i<n; i++)
        {
            if(back[i] == nums[i])
                return i;
        }

        return -1;
    }
};