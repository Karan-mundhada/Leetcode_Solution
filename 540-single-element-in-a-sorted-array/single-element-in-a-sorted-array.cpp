class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int mid = 0;

        while(low <= high)
        {
            mid = low + (high - low)/2;
            if(mid%2 != 0)
            {
                if(mid < n-1 && nums[mid+1] == nums[mid])
                    high = mid - 1;
                else if(mid > 0 && nums[mid-1] == nums[mid])
                    low = mid + 1;  
                else
                    break;        
            }
            else
            {
                if(mid < n-1 && nums[mid+1] == nums[mid])
                    low = mid + 1;
                else if(mid > 0 && nums[mid-1] == nums[mid])
                    high = mid - 1;
                else
                    break;
            }
        }
        return nums[mid];
    }
};