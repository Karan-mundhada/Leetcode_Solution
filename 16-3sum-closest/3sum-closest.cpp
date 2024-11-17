class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Sort the array
        int n = nums.size();
        int closestSum = INT_MAX / 2;  // Initialize with a large value
        
        for (int i = 0; i < n - 2; i++) {  // Fix the first number
            int left = i + 1;             // Initialize the left pointer
            int right = n - 1;            // Initialize the right pointer
            
            while (left < right) {        // Two-pointer approach
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Update closest sum if the current sum is closer to the target
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }
                
                // Move the pointers based on the comparison
                if (currentSum < target) {
                    left++;  // Increase the sum by moving the left pointer
                } else if (currentSum > target) {
                    right--; // Decrease the sum by moving the right pointer
                } else {
                    return target;  // Exact match found
                }
            }
        }
        
        return closestSum;  // Return the closest sum
    }
};