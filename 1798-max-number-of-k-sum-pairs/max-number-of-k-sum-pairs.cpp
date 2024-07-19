class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int j = nums.size() - 1, i = 0, t, cnt = 0;
        while(i < j)
        {
            t = nums[i] + nums[j];
            if(t < k)
                i++;
            else if(t == k)
            {
                i++; 
                j--; 
                cnt++;
            }
            else
                j--;
        }

        return cnt;
    }
};