class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // Pointer for the position of non-val elements

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];  // Overwrite nums[k] with nums[i]
                k++;  // Move the pointer for non-val elements
            }
        }

        return k;
    }
};