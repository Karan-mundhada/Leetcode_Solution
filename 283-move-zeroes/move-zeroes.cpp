class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z = 0; int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
            {   
                continue;
            }
            else
            {
                swap(nums[i], nums[z]);
                z++;
            }
        }
    }
};