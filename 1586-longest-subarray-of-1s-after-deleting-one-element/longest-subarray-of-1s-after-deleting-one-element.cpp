class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, end = 0;
        int n = nums.size();
        int maxLength = 0;
        int zeroCount = 0;
        
        // Sliding window approach
        while (end < n) {
            if (nums[end] == 0) {
                zeroCount++;
            }
            
            // If there's more than one zero in the window, move the start
            while (zeroCount > 1) {
                if (nums[start] == 0) {
                    zeroCount--;
                }
                start++;
            }
            
            // Calculate the maximum length
            maxLength = max(maxLength, end - start);
            end++;
        }
        
        // If the whole array is 1s and we need to delete one element
        return maxLength == n ? maxLength - 1 : maxLength;
    }
};
