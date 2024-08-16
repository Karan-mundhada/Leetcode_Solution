class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = 1;
        int cnt = 1; int prev = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(prev == nums[i])
            {
                if(cnt < 2)
                {
                    cnt++;
                    nums[size++] = nums[i];
                }
                else continue;
            }
            else
            {
                prev = nums[i];
                cnt = 1;
                nums[size++] = nums[i];
            }
        }

        return size;
    }
};